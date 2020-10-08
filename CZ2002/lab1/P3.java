package sce.cz2002.nrxb.first;

import java.util.Scanner;

public class P3 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Scanner scan = new Scanner(System.in);
		int start = scan.nextInt();
		int end = scan.nextInt();
		int inc = scan.nextInt();
		scan.close();
		
		int i, j = start, k = start;
		double sgd;
		
		if (start > end) {
			System.out.println("Error input!!");
		}
		else {
			
			System.out.println("US$         S$");
			System.out.println("--------------");
			for (i = start; i <= end ; i += inc) {
				sgd = i * 1.82;
				String.format("%f",  sgd);
				System.out.printf("%d          %s\n", i, sgd);
			}
			
			
			System.out.println("US$       S$");
			System.out.println("--------------");
			while (j <= end) {
				sgd = j * 1.82;
				String.format("%f",  sgd);
				System.out.printf("%d         %s\n", j, sgd);
				j += inc;
			}
			
			System.out.println("US$       S$");
			System.out.println("--------------");
			do {
				sgd = k * 1.82;
				String.format("%f", sgd);
				System.out.printf("%d         %s\n", k, sgd);
				k += inc;
			}
			while (k <= end);
		}
		
 	}

}
