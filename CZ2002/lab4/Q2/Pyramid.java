package sce.cz2002.nrxb.fourth;
/*
public class Pyramid extends Shape {
	private double sqLength;	// of square base
	private double slantHeight;
	
	public Pyramid(double sqLength, double slantHeight) {
		this.sqLength = sqLength;
		this.slantHeight = slantHeight;
	}
	
	public double area() {
		return (sqLength * sqLength) + 4 * (0.5 * sqLength * slantHeight);
	}
}
*/
public class Pyramid extends Square {
	private double sqLength;
	private double slantHeight;
	
	public Pyramid(double sqLength, double slantHeight) {
		super(sqLength);
		this.sqLength = sqLength;
		this.slantHeight = slantHeight;
	}
	
	public double area() {
		return super.area() + 4 * (0.5 * sqLength * slantHeight);
	}
}