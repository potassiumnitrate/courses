package sce.cz2002.nrxb.fourth;

import java.util.Scanner;
public class Strings
{
// --------------------------------------------
// Reads in an array of integers, sorts them,
// then prints them in sorted order.
// --------------------------------------------
	public static void main (String[] args)
	{
		Comparable[] strList;
		int size;
		Scanner scan = new Scanner(System.in);
		System.out.print ("\nHow many Strings do you want to sort? ");
		size = scan.nextInt();
		strList = new Comparable[size];
		System.out.println ("\nEnter the Strings...");
		for (int i = 0; i < size; i++)
			strList[i] = scan.next();
			Sorting.insertionSort(strList); // chg from selectionSort()
			System.out.println ("\nYour Strings in sorted order...");
		for (int i = 0; i < size; i++)
			System.out.print(strList[i] + " ");
		System.out.println ();
	}
}