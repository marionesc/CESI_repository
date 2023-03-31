package seance2;

public class main {

	public static void main(String[] args) {
		enseignant ens1 = new enseignant("mar", "escou", "195 rue du colombier",8,10);
		

	    System.out.println("Nombre d'heure 	  : " + ens1.getNbHeure() + " h ");
		System.out.println("Taux horaire brut : " + ens1.getprixheure() + " e/h" + "(echelon : " + ens1.getEchelon() + " )");
	    System.out.println("Salaire brut 	  : " + ens1.getsalaire() + " e \n\n");
	
	    // on modifie l echelon --> changement taux horaires 
	    ens1.echelonValide(4);

	    System.out.println("Nombre d'heure 	  : " + ens1.getNbHeure() + " h ");
	    System.out.println("Salaire brut 	  : " + ens1.getprixheure() + " e/h " + "(echelon : " + ens1.getEchelon() + " )");
	    System.out.println("Salaire brut 	  : " + ens1.getsalaire() + " e \n\n");
	}
}
