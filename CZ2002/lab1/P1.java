package sce.cz2002.nrxb.first;

import java.util.Scanner;

public class P1 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		// scan user input
		Scanner scan = new Scanner(System.in);
		String x = scan.nextLine();
		scan.close();
		
		switch(x) {
			case "A":
			case "a":
				System.out.println("Action movie fan\n");
				break;
			case "C":
			case "c":
				System.out.println("Comedy movie fan\n");
				break;
			case "D":
			case "d":
				System.out.println("Drama movie fan\n");
				break;
			default:
				System.out.println("Invalid choice\n");
		}
	}

}
