package sce.cz2002.nrxb.fourth;

public class Sphere extends Circle{
	/* for extends Shape
 	private double radius;
	
	public Sphere(double radius) {
		this.radius = radius;
	}
	
	public double area() {
		return 4 * Math.PI * radius * radius;
	}
	*/
	
	public Sphere(double radius) {
		super(radius);
	}

	public double area() {
		return 4 * super.area();
	}
}
