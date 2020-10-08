package sce.cz2002.nrxb.first;

import java.util.Scanner;

public class P2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Scanner scan = new Scanner(System.in);
		int salary = scan.nextInt();
		int merit = scan.nextInt();
		scan.close();
		
		/*
		String grade = "A";
		if (salary >= 500 && salary < 649) {
			grade = "C";
			if (salary > 600 && merit >= 10) {
				grade = "B";
			}
		}
		else if (salary > 600 && salary < 799) {
			grade = "B";
			if (salary > 700 && merit >= 20) {
				grade = "A";
			}
		}
		*/
		
		String grade = "A";
		// Grade C
		if (salary >= 500 && salary <= 600) {
			grade = "C";
		}
		// Grade B overlap with C
		else if (salary > 600 && salary < 649 && merit < 10) {
			grade = "C";
		}
		// Grade B
		else if (salary > 600 && salary < 799 && merit >= 10) {
			grade = "B";
		}
		// Grade B overlap with A
		else if (salary > 700 && salary < 799 && merit < 20) {
			grade = "B";
		}
		// Grade A
		else if (salary > 700 && salary < 899 && merit >= 20) {
			grade = "A";
		}
		
		System.out.printf("salary : %d, merit : %d - Grade %s", salary, merit, grade);
	}

}
