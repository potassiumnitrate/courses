package sce.cz2002.nrxb.third;

import java.util.Scanner;

public class PlaneApp {

	public static void main(String[] args) {
		Plane planeApp = new Plane();
		int choice;
		Scanner scan = new Scanner(System.in);
		
		System.out.printf("(1) Show number of empty seats\n"
						+ "(2) Show the list of empty seats\n"
						+ "(3) Show the list of seat assignments by seat ID\n"
						+ "(4) Show the list of seat assignments by customer ID\n"
						+ "(5) Assign a customer to a seat\n"
						+ "(6) Remove a seat assignment\n"
						+ "(7) Exit\n");
		System.out.println("");
		
		do {
			System.out.println("  Enter the number of your choice: ");
			choice = scan.nextInt();
			switch(choice) {
				case 1:
					planeApp.showNumEmptySeats();
					break;
				case 2:
					planeApp.showEmptySeats();
					break;
				case 3:
					planeApp.showAssignedSeats(true);
					break;
				case 4:
					planeApp.showAssignedSeats(false);
					break;
				case 5:
					System.out.println("Assigning Seat ..");
					System.out.println("  Please enter SeatID: ");
					int seatId = scan.nextInt();
					System.out.println("  Please enter Customer ID: ");
					int cust_id = scan.nextInt();
					
					planeApp.assignSeat(seatId, cust_id);
					break;
				case 6:
					System.out.println("  Enter SeatID to unassign customer from: ");
					seatId = scan.nextInt();
					
					planeApp.unAssignSeat(seatId);
					break;
				default:
					break;
			}
		} while (choice < 7);
		scan.close();
	}

}
