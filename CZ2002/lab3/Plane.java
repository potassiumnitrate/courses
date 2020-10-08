package sce.cz2002.nrxb.third;

import java.util.Arrays;
import java.util.Scanner;

public class Plane {

	private PlaneSeat[] seat = new PlaneSeat[12];
	private int numEmptySeat;
	
	Scanner scan = new Scanner(System.in);
	
	public Plane() {
		this.numEmptySeat = 12;
		
		for (int i=0; i<12; i++) {
			this.seat[i] = new PlaneSeat(i+1);
		}
	}
	
	private PlaneSeat[] sortSeats() {			// sort by ascending custid
		int i = 0;
		int numCustId = 12 - this.numEmptySeat;
		int[] new_cust_id = new int[numCustId];	// new custid array
		
		for (int j=0; j<12; j++) {				// for each seat
			if (this.seat[j].isOccupied()) {	// if seat is occupied
				// save this custId in new_cust_id[]
				new_cust_id[i] = this.seat[j].getCustomerID();
				i++;
			}
		}
		
		Arrays.sort(new_cust_id);				// to sort custid arr in ascending order
		
		PlaneSeat[] seat_asc_custid = new PlaneSeat[12]; // new seatid array
		for (i=0; i<12; i++) {
			seat_asc_custid[i] = new PlaneSeat(i+1);
		}
		
		
		for (i=0; i<numCustId; i++) {		// for each custid
			for (int j=0; j<12; j++) {		// iterate through all seats
				if (new_cust_id[i] == this.seat[j].getCustomerID()) {
					seat_asc_custid[j].assign(i); 
					break;
				}
			}
		}
		
		return seat_asc_custid;
	} 
	
	public void showNumEmptySeats() {
		System.out.printf("There are %d empty seats.\n", this.numEmptySeat);
	}
	
	public void showEmptySeats() {
		System.out.println("The following seats are empty: ");
		
		for (int i=0; i<12; i++) {
			if (this.seat[i].isOccupied() == false) {
				System.out.printf("SeatID %d\n", i+1);
			}
		}
	}
	
	public void showAssignedSeats(boolean bySeatId) {
		System.out.println("The seat assignments are as follow: ");
		
		if (bySeatId) {		// print in ascending seatId
			for (int i=0; i<12; i++) {
				if (this.seat[i].isOccupied()) {
					System.out.printf("SeatID %d assigned to CustomerID %d.\n", i+1, this.seat[i].getCustomerID());
				}
			}
		}
		else {				// print in ascending custId
			PlaneSeat[] seat2 = sortSeats();
			for (int i=0; i<(12 - this.numEmptySeat); i++) {
				for (int j=0; j<12; j++) {
					if (seat2[j].getCustomerID() == i && seat2[j].getCustomerID() != -1) {
						// custid = -1 means empty
						System.out.printf("SeatID %d assigned to CustomerID %d.\n", (j+1), this.seat[j].getCustomerID());
					}
				}
			}
		}
	}
	
	public void assignSeat(int seatId, int cust_id) {
		if (this.seat[seatId-1].isOccupied()) {
			System.out.println("Seat already assigned to a customer.");
		}
		else {
			this.seat[seatId-1].assign(cust_id);
			this.numEmptySeat--;
			System.out.println("Seat Assigned!");
		}
	}
	
	public void unAssignSeat(int seatId) {
		if (this.seat[seatId-1].isOccupied()) {
			this.seat[seatId-1].unAssign();
			this.numEmptySeat++;
			System.out.println("Seat Unassigned!");
		}
		else {
			System.out.println("Seat was already empty!");
		}
	}

}
