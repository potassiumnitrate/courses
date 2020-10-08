package sce.cz2002.nrxb.first;

import java.util.Scanner;

public class P4 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Scanner scan = new Scanner(System.in);
		int height = scan.nextInt();
		scan.close();
		
		int i; 
		String str = "AA";
		
		if (height < 1) {
			System.out.println("Error input!!");
		}
		else {
			System.out.printf("%s\n", str);
			for (i=0; i<height-1; i++) {
				char first = str.charAt(0);
				if (first == 'A') {
					str = "BB" + str;
				}
				else if (first == 'B') {
					str = "AA" + str;
				}
				System.out.printf("%s\n", str);
			}
		}
	}

}
