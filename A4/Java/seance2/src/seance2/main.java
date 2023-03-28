package seance2;

public class main {

	public static void main(String[] args) {
		enseignant ens1 = new enseignant("John", "Smith", "45 alle du michel",3,35);
	    System.out.println(ens1.getprixheure());
	    System.out.println(ens1.getsalaire());
	    ens1.modifechelon(4);
	    System.out.println(ens1.getprixheure());
	    System.out.println(ens1.getsalaire());
	}
}
