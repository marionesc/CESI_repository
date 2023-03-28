package seance1;

public class student {
	public int id_s; 
	public String firstName_s; 
	public String lastName_s; 
	
	// Delegation des parametres
	public student(int id_s, String firstName_s, String lastName_s) {
		this.id_s = id_s; 
		this.firstName_s = firstName_s; 
		this.lastName_s = lastName_s; 
	}
	
	 public int getId() {
	        return id_s;
	 }

	 public String getFirstName() {
	        return firstName_s;
	 }

	 public String getLastName() {
		 return lastName_s;
	 }

	 public void setId(int id_s) {
		 this.id_s = id_s;
	 }

	 public void setFirstName(String firstName_s) {
		 this.firstName_s = firstName_s;
	 }

	 public void setLastName(String lastName_s) {
		 this.lastName_s = lastName_s;
	 }

	 public String toString_s() {
		 return (id_s + " : " + firstName_s + " " + lastName_s); 
	 }
}