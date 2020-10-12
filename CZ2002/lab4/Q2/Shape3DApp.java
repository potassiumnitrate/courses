package sce.cz2002.nrxb.fourth;

import java.util.Scanner;

public class Shape3DApp {
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
			System.out.printf("1: Sphere\n"
					        + "2: Pyramid\n"
						    + "3: Cuboid\n"
						    + "4: Cone\n"
						    + "5: Cylinder\n"
						    + "Please choose type of shape for shape no. %d:\n", (i+1));
			whichShape = scan.nextInt();
			
			switch (whichShape) {
				case 1:
					// sphere
					System.out.println("Radius: ");
					double radius = scan.nextDouble();
					shapes[i] = new Sphere(radius);
					break;
				case 2:
					// pyramid
					System.out.println("SqLength: ");
					double sqLength = scan.nextDouble();
					System.out.println("Slant Height: ");
					double slantHeight = scan.nextDouble();
					shapes[i] = new Pyramid(sqLength, slantHeight);
					break;
				case 3:
					// cuboid
					System.out.println("Length: ");
					double length = scan.nextDouble();
					System.out.println("Breadth: ");
					double breadth = scan.nextDouble();
					System.out.println("Height: ");
					double height = scan.nextDouble();
					shapes[i] = new Cuboid(length, breadth, height);
					break;
				case 4:
					// cone 
					System.out.println("Radius: ");
					double coneRadius = scan.nextDouble();
					System.out.println("Height: ");
					double coneHeight = scan.nextDouble();
					shapes[i] = new Cone(coneRadius, coneHeight);
					break;
				case 5:
					// cylinder
					System.out.println("Radius: ");
					double cylRadius = scan.nextDouble();
					System.out.println("Height: ");
					double cylHeight = scan.nextDouble();
					shapes[i] = new Cylinder(cylRadius, cylHeight);
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
