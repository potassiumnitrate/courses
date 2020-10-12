package sce.cz2002.nrxb.fourth;
/*
public class Cone extends Shape {
	private double radius;
	private double height;
	
	public Cone(double radius, double height) {
		this.radius = radius;
		this.height = height;
	}
	
	public double area() {
		return Math.PI * radius * (radius + Math.sqrt((height * height) + (radius * radius)));
	}
}
*/
public class Cone extends Circle {
	private double radius;
	private double height;
	
	public Cone(double radius, double height) {
		super(radius);
		this.radius = radius;
		this.height = height;
	}
	
	public double area() {
		return super.area() + Math.PI * radius * Math.sqrt((height * height) + (radius * radius));
	}
}