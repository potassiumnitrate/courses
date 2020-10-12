package sce.cz2002.nrxb.fourth;

public class Square extends Shape {
	private double length;
	
	public Square(double length) {
		this.length = length;
	}
	
	public double area() {
		return length * length;
	}
}
