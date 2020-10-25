#include "copyright.h"
#include "tlb.h"
#include "syscall.h"
#include "machine.h"
#include "thread.h"
#include "system.h"
#include "utility.h"

//----------------------------------------------------------------------
// UpdateTLB
//      Called when exception is raised and a page isn't in the TLB.
// Figures out what to do (get from IPT, or pageoutpagein) and does it.
//----------------------------------------------------------------------

void UpdateTLB(int possible_badVAddr)
{
  int badVAddr;
  unsigned int vpn;
  int phyPage;

  if(possible_badVAddr) // get the bad address from the correct location
    badVAddr=possible_badVAddr; // fault in kernel
  else
    badVAddr=machine->registers[BadVAddrReg]; // fault in userprog
  
  vpn=(unsigned)badVAddr/PageSize;
  
  if((phyPage=VpnToPhyPage(vpn))!=-1) {
    InsertToTLB(vpn, phyPage);
  } else {
    if(vpn>=currentThread->space->numPages && !GetMmap(vpn))
      machine->RaiseException(AddressErrorException, badVAddr);
    else
      InsertToTLB(vpn, PageOutPageIn(vpn));
  }
}

//----------------------------------------------------------------------
// VpnToPhyPage
//      Gets a phyPage for a vpn, if exists in ipt.
//----------------------------------------------------------------------

int VpnToPhyPage(int vpn)
{
  
  //your code here to get a physical frame for page vpn
  //you can refer to PageOutPageIn(int vpn) to see how an entry was created in ipt

  // Experiment 4

  // for every page in IPT, 
  // 	find valid physical page that exists in IPT, and compare pid & vpn
  // 	pid & vpn -> physical frame no
  // 	if found, return physical frame no
  // else return -1

  // DEBUG msg to display all values of a physical frame
  for (int i=0; i<NumPhysPages; i++)
  	DEBUG('p', "...IPT %i, pid, vpn, last used and valid is %i %i %i %i\n", i, memoryTable[i].pid, memoryTable[i].vPage, memoryTable[i].lastUsed, memoryTable[i].valid);

  for (int i=0; i<NumPhysPages; i++){	// no of entries in IPT = no of phys pages
  	if ((memoryTable[i].valid) && (memoryTable[i].pid == currentThread->pid) && (memoryTable[i].vPage == vpn)) {	// vpn = virtual page num
		DEBUG('p', ".....Found IPT %i, pid, vpn, last used and valid is %i %i %i %i \n", i, memoryTable[i].pid, memoryTable[i].vPage, memoryTable[i].lastUsed, memoryTable[i].valid);
		// page hit in IPT
		// i = phyPage   		
		return i;	
    	}
  }

  DEBUG('p', ".....IPT with matching pid and vpn NOT found!\n");
  // page fault in IPT or no valid entry
  return -1;
  
}

//----------------------------------------------------------------------
// InsertToTLB
//      Put a vpn/phyPage combination into the TLB. If TLB is full, use FIFO 
//    replacement
//----------------------------------------------------------------------

void InsertToTLB(int vpn, int phyPage)
{
  
  int i = 0; //entry in the TLB
  
  //your code to find an empty in TLB or to replace the oldest entry if TLB is full

  //Experiment 4
  
  bool emptyInTLB = false;
  static int FIFOPointer = 0;

  // find invalid entry in TLB
  for (i=0; i<TLBSize; i++){
  	if (!machine->tlb[i].valid){ // if not valid
		emptyInTLB = true;
		break;
	}
  }

  // if there is an invalid TLB entry, then i should point to it
  if (!emptyInTLB){
  	i = FIFOPointer;
  }
  
  // if there is no invalid entry, then i should point to the oldest entry
  // Simple FIFO: if an entry is just inserted, then the entry next to it is the oldest entry
  FIFOPointer = (i+1)%TLBSize;
  

  // copy dirty data to memoryTable
  if(machine->tlb[i].valid){
    memoryTable[machine->tlb[i].physicalPage].dirty=machine->tlb[i].dirty;
    memoryTable[machine->tlb[i].physicalPage].TLBentry=-1;
  }

  // show the TLB and respective values
  DEBUG('p', "Before updating TLB %i \n", i);
  for (int j=0; j<3; j++)
    DEBUG('p', "...TLB %i, vpn, phy and valid is %i %i %i \n", j, machine->tlb[j].virtualPage, machine->tlb[j].physicalPage, machine->tlb[j].valid);
  
  //update the TLB entry
  machine->tlb[i].virtualPage  = vpn;
  machine->tlb[i].physicalPage = phyPage;
  machine->tlb[i].valid        = TRUE;
  machine->tlb[i].readOnly     = FALSE;
  machine->tlb[i].use          = FALSE;
  machine->tlb[i].dirty        = memoryTable[phyPage].dirty;

  DEBUG('p', "After updating TLB %i \n", i);
  DEBUG('p', "...TLB %i, vpn, phy and valid is %i %i %i \n", i, machine->tlb[i].virtualPage, machine->tlb[i].physicalPage, machine->tlb[i].valid);

  
  //update the corresponding memoryTable
  memoryTable[phyPage].TLBentry=i;
  DEBUG('p', "The corresponding TLBentry for Page %i in TLB is %i ", vpn, i);
  //reset lastUsed to current ticks since it is being used at this moment.
  //for the implementation of LRU algorithm.
  memoryTable[phyPage].lastUsed = stats->totalTicks; 
  
  //increase the number of tlb misses
  stats->numTlbMisses++;
  
  
}

//----------------------------------------------------------------------
// PageOutPageIn
//      Calls DoPageOut and DoPageIn and handles memoryTable
// bookkeeping. Use lru algorithm to find the replacement page.
//----------------------------------------------------------------------

int PageOutPageIn(int vpn)
{
  int phyPage; 
  
  //increase the number of page faults
  stats->numPageFaults++;
  //call the LRU algorithm, which returns the freed physical frame
  phyPage=lruAlgorithm();
  
  //Page out the victim page to free the physical frame
  DoPageOut(phyPage);
  //Page in the new page to the freed physical frame
  DoPageIn(vpn, phyPage);
  
  //update memoryTable for this frame
  memoryTable[phyPage].valid=TRUE;
  memoryTable[phyPage].pid=currentThread->pid;
  memoryTable[phyPage].vPage=vpn;
  memoryTable[phyPage].dirty=FALSE;
  memoryTable[phyPage].TLBentry=-1;
  memoryTable[phyPage].lastUsed=0;
  memoryTable[phyPage].swapPtr=currentThread->space->swapPtr;
  
  return phyPage;
}

//----------------------------------------------------------------------
// DoPageOut
//      Actually pages out a phyPage to it's swapfile.
//----------------------------------------------------------------------

void DoPageOut(int phyPage)
{
  MmapEntry *mmapPtr;
  int numBytesWritten;
  int mmapBytesToWrite;

  if(memoryTable[phyPage].valid){           // check if pageOut possible
    if(memoryTable[phyPage].TLBentry!=-1){
      memoryTable[phyPage].dirty=
        machine->tlb[memoryTable[phyPage].TLBentry].dirty;
      machine->tlb[memoryTable[phyPage].TLBentry].valid=FALSE;
    }
    if(memoryTable[phyPage].dirty){        // pageOut is necessary
      if((mmapPtr=GetMmap(memoryTable[phyPage].vPage))){ // it's mmaped
        DEBUG('p', "mmap paging out: pid %i, phyPage %i, vpn %i\n",
          memoryTable[phyPage].pid, phyPage, memoryTable[phyPage].vPage);
        if(memoryTable[phyPage].vPage==mmapPtr->endPage)
          mmapBytesToWrite=mmapPtr->lastPageLength;
        else
          mmapBytesToWrite=PageSize;
        numBytesWritten=mmapPtr->openFile->
          WriteAt(machine->mainMemory+phyPage*PageSize, mmapBytesToWrite,
            (memoryTable[phyPage].vPage-mmapPtr->beginPage)*PageSize);
        ASSERT(mmapBytesToWrite==numBytesWritten);
      } else { // it's not mmaped
        DEBUG('p', "paging out: pid %i, phyPage %i, vpn %i\n",
          memoryTable[phyPage].pid, phyPage, memoryTable[phyPage].vPage);
        numBytesWritten=memoryTable[phyPage].swapPtr->
          WriteAt(machine->mainMemory+phyPage*PageSize, PageSize,
            memoryTable[phyPage].vPage*PageSize);
        ASSERT(PageSize==numBytesWritten);
      }
      
      //increase the number of page faults
      stats->numPageOuts++;
    }
    
    memoryTable[phyPage].valid=FALSE;
  }
}

//----------------------------------------------------------------------
// DoPageIn
//      Actually pages in a phyPage/vpn combo from the swapfile.
//----------------------------------------------------------------------

void DoPageIn(int vpn, int phyPage)
{
  MmapEntry *mmapPtr;
  int numBytesRead;
  int mmapBytesToRead;

  if((mmapPtr=GetMmap(vpn))){ // mmaped file
    DEBUG('p', "mmap paging in: pid %i, phyPage %i, vpn %i\n",
      currentThread->pid, phyPage, vpn);
    if(vpn==mmapPtr->endPage)
      mmapBytesToRead=mmapPtr->lastPageLength;
    else
      mmapBytesToRead=PageSize;
    numBytesRead=
      mmapPtr->openFile->ReadAt(machine->mainMemory+phyPage*PageSize,
                mmapBytesToRead,
                (vpn-mmapPtr->beginPage)*PageSize);
    ASSERT(numBytesRead==mmapBytesToRead);
  } else { // not mmaped
    DEBUG('p', "paging in: pid %i, phyPage %i, vpn %i\n", currentThread->pid,
      phyPage, vpn);
    numBytesRead=currentThread->space->swapPtr->ReadAt(machine->mainMemory+
                   phyPage*PageSize,
                   PageSize,
                   vpn*PageSize);
    ASSERT(PageSize==numBytesRead);
  }
}

//----------------------------------------------------------------------
// lruAlgorithm
//      Determine where a vpn should go in phymem, and therefore what
// should be paged out. This lru algorithm is the one discussed in the 
// lectures.
//----------------------------------------------------------------------

int lruAlgorithm(void)
{
  
  //your code here to find the physical frame that should be freed 
  //according to the LRU algorithm. 

  // Experiment 4

  int phyPage;
  
  phyPage = 0;
  
  // find free frame (in memoryTable)  
  // see memoryTable[i].lastUsed
  int last = memoryTable[0].lastUsed;

  // for every entry in memoryTable,
  // search for invalid entry 
  // 	if invalid entry found, return that to be used by the virtual page
  // 	otherwise, find a victim (entry with smallest lastUsed) --> return page number
  for (int i=0; i<NumPhysPages; i++){
  	if (!memoryTable[i].valid){	// free frame found
		phyPage = i;
	 	break;
	}
	if (memoryTable[i].lastUsed < last){	// no free frame found
		last = memoryTable[i].lastUsed;
		phyPage = i;
	}
  }

  return phyPage;
  
}

//----------------------------------------------------------------------
// GetMmap
//      Return an MmapEntry structure corresponding to the vpn.  Returns
// 0 if does not exist.
//----------------------------------------------------------------------

MmapEntry *GetMmap(int vpn)
{
  MmapEntry *mmapPtr;

  mmapPtr=currentThread->space->mmapEntries;
  while(mmapPtr->next){
    mmapPtr=mmapPtr->next;
    if(vpn>=mmapPtr->beginPage && vpn<=mmapPtr->endPage)
      return mmapPtr;
  }
  return 0;
}

//----------------------------------------------------------------------
// PageOutMmapSpace
//      Pages out stuff being mmaped (or just between beginPage and
// endPage.
//----------------------------------------------------------------------

void PageOutMmapSpace(int beginPage, int endPage)
{
  int vpn;
  int phyPage;

  for(vpn=beginPage; vpn<=endPage; vpn++){
    if((phyPage=VpnToPhyPage(vpn))==-1)
      continue;
    DoPageOut(phyPage);
  }
}
