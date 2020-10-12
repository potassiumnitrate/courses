package sce.cz2002.nrxb.fourth;

public class Rectangle extends Shape{
	private double length;
	private double breadth;
	
	public Rectangle(double length, double breadth) {
		this.length = length;
		this.breadth = breadth;
	}
	
	public double area() {
		return length * breadth;
	}
}
