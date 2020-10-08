package sce.cz2002.nrxb.second;

import java.util.Scanner;

public class Lab2p1 {
	public static void main(String[] args)
	{
		int choice;
		Scanner sc = new Scanner(System.in);
		int m, n, digit, result;
		do {
			System.out.println("Perform the following methods:");
			System.out.println("1: miltiplication test");
			System.out.println("2: quotient using division by subtraction");
			System.out.println("3: remainder using division by subtraction");
			System.out.println("4: count the number of digits");
			System.out.println("5: position of a digit");
			System.out.println("6: extract all odd digits");
			System.out.println("7: quit");
			choice = sc.nextInt();
			
			switch (choice) {
				case 1: /* add mulTest() call */
					mulTest();
					break;
				case 2: /* add divide() call */
					System.out.println("Enter first int:");
					m = sc.nextInt();
					System.out.println("Enter second int:");
					n = sc.nextInt();
					System.out.printf("%d/%d = %d;\n", m, n, divide(m, n));
					break;
				case 3: /* add modulus() call */
					System.out.println("Enter first int:");
					m = sc.nextInt();
					System.out.println("Enter second int:");
					n = sc.nextInt();
					System.out.printf("%d %% %d = %d\n", m, n, modulus(m, n));
					break;
				case 4: /* add countDigits() call */
					System.out.println("Enter int:");
					n = sc.nextInt();
					result = countDigits(n);
					if (result < 0) {
						System.out.printf("n: %d - Error input!!\n", n);
					}
					else {
						System.out.printf("n: %d - count = %d\n", n, result);
					}
					break;
				case 5: /* add position() call */
					System.out.println("Enter int:");
					n = sc.nextInt();
					System.out.println("Enter digit:");
					digit = sc.nextInt();
					System.out.printf("position = %d\n", position(n, digit));
					break;
				case 6: /* add extractOddDigits() call */
					System.out.println("Enter int:");
					n = sc.nextInt();
					System.out.printf("oddDigits = %d\n", extractOddDigits(n));
					break; 
				case 7: System.out.println("Program terminating ....");
			}
		} while (choice < 7);
	}
	
	/* add method code here */
	public static void mulTest() {
		Scanner sc = new Scanner(System.in);
		int count = 0;
		int correct = 0;
		
		while (count < 5) {
			int x = (int)(Math.random()*9+1);
			int y = (int)(Math.random()*9+1);
			int correctMul = x*y;
			
			System.out.printf("How much is %d times %d?\n", x, y);
			
			int userMul = sc.nextInt();
			
			if (userMul == correctMul) {
				correct ++;
			}
			count++;
		}
		System.out.printf("%d answers out of 5 are correct.\n", correct);
		
	}
	
	public static int divide(int m, int n) {
		int result = 0;
		
		while (m - n >= 0) {
			m -= n;
			result++;
		}
		
		return result;
	}
	
	public static int modulus(int m, int n) {
		int result = m;
		
		while (result >= n) {
			result -= n;
		}
		
		return result;
	}
	
	public static int countDigits(int n) {
		int numDigits = 0;
		
		if (n<0) {
			numDigits = -1;
		}
		else if (n>0) {
			while (n>0) {
				n /= 10;
				numDigits++;
			}
		}
		return numDigits;
	}
	
	public static int position(int n, int digit) {
		int result = -1;
		int pos = 0;
		int findingDigit = 0;
		
		if (n<0) {
			result = -1;
		}
		else if (n>0) {
			while (n>0) {
				pos++;
				findingDigit = n % 10;
				n /= 10;
				if (findingDigit == digit) {
					result = pos;
					break;
				}
			}
		}
		return result;
	}
	
	public static long extractOddDigits(long n) {
		long oddDigits = 0;
		long temp = n;
		int tenth = 1; //tenth place, hundredth place, etc
		
		if (n<0) {
			oddDigits = -1;
		}
		else if (n>0) {
			while (n>0) {
				temp = n%10;
				if (temp%2==1) {
					oddDigits += tenth*temp;
					tenth *= 10;
				}
				n /= 10;
			}
		}
		return oddDigits;
	}
}
