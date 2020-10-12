package sce.cz2002.nrxb.fourth;

import java.util.Scanner;

public class Shape2DApp {
	public static void main(String args[]) 
	{
		Scanner scan = new Scanner(System.in);
		int noOfShapes;
		int whichShape;
		int whichCalc;
		double totalArea = 0;
		
		System.out.println("Please enter number of shapes: ");
		noOfShapes = scan.nextInt();
		Shape[] shapes = new Shape[noOfShapes];
		
		for (int i=0; i<noOfShapes; i++) {
			System.out.printf("1: Circle\n"
					        + "2: Triangle\n"
						    + "3: Rectangle\n"
						    + "4: Square\n"
						    + "Please choose type of shape for shape no. %d:\n", (i+1));
			whichShape = scan.nextInt();
			
			switch (whichShape) {
				case 1:
					// circle
					System.out.println("Radius: ");
					double radius = scan.nextDouble();
					shapes[i] = new Circle(radius);
					break;
				case 2:
					// triangle
					System.out.println("Height: ");
					double height = scan.nextDouble();
					System.out.println("Base: ");
					double base = scan.nextDouble();
					shapes[i] = new Triangle(height, base);
					break;
				case 3:
					// rectangle
					System.out.println("Length: ");
					double length = scan.nextDouble();
					System.out.println("Breadth: ");
					double breadth = scan.nextDouble();
					shapes[i] = new Rectangle(length, breadth);
					break;
				case 4:
					// square
					System.out.println("Length: ");
					double sqLength = scan.nextDouble();
					shapes[i] = new Square(sqLength);
					break;
			}
			
		}
	
		System.out.println("Please choose type of calculation:\n"
				 + "1: Area");
		whichCalc = scan.nextInt();
		
		switch (whichCalc) {
			case 1:
				for (int i=0; i<noOfShapes; i++) {
					totalArea += shapes[i].area();
				}
				System.out.printf("Total area: %.2f\n", totalArea);
				break;
			default:
				break;
		}
		
	}
}
