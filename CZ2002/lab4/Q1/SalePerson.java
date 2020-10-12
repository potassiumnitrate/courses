package sce.cz2002.nrxb.fourth;

public class SalePerson implements Comparable {

	private String firstName;
	private String lastName;
	private int totalSales;
	
	public SalePerson(String firstName, String lastName, int totalSales) {
		this.firstName = firstName;
		this.lastName = lastName;
		this.totalSales = totalSales;
	}
	
	public String toString() {
		String x = String.format("%s, %s: %d", lastName, firstName, totalSales);
		return x;
	}
	
	public boolean equals(Object o) {
		if (((SalePerson) o).getFirstName()==this.firstName && ((SalePerson) o).getLastName()==this.lastName) {
			return true;
		}
		else {
			return false;
		}
	}
	
	public int compareTo(Object o) {
		if (this.getTotalSales() < ((SalePerson) o).getTotalSales()) {
			return -1;
		}
		else if (this.getTotalSales() > ((SalePerson) o).getTotalSales()) {
			return 1;
		}
		else {
			if (this.getLastName().compareTo(((SalePerson) o).getLastName()) < 0) {
				// lower in alphabetical order
				return 1;
			}
			else {
				return -1;
			}
		}
	}
	
	public String getFirstName() {
		return firstName;
	}
	
	public String getLastName() {
		return lastName;
	}
	
	public int getTotalSales() {
		return totalSales;
	}

}
