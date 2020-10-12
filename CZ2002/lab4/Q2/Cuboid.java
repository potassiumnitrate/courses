package sce.cz2002.nrxb.fourth;
/*
public class Cuboid extends Shape {
	private double length;
	private double breadth;
	private double height;
	
	public Cuboid(double length, double breadth, double height) {
		this.length = length;
		this.breadth = breadth;
		this.height = height;
	}
	
	public double area() {
		return 2 * length * breadth 
			 + 2 * length * height
			 + 2 * breadth * height;
	}
}
*/
public class Cuboid extends Rectangle {
	private double length;
	private double breadth;
	private double height;
	
	public Cuboid(double length, double breadth, double height) {
		super(length, breadth);
		this.length = length;
		this.breadth = breadth;
		this.height = height;
	}
	
	public double area() {
		return 2 * super.area() 
			 + 2 * length * height
			 + 2 * breadth * height;
	}
}