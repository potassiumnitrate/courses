package sce.cz2002.nrxb.fourth;
/*
public class Cylinder extends Shape {
	private double radius;
	private double height;
	
	public Cylinder(double radius, double height) {
		this.radius = radius;
		this.height = height;
	}
	
	public double area() {
		return (2 * Math.PI * radius * height) + (2 * Math.PI * radius * radius);
	}
}
*/
public class Cylinder extends Circle {
	private double radius;
	private double height;
	
	public Cylinder(double radius, double height) {
		super(radius);
		this.radius = radius;
		this.height = height;
	}
	
	public double area() {
		return (2 * Math.PI * radius * height) + (2 * super.area());
	}
}