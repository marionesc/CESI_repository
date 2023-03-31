package seance2;

public class enseignant extends personne{
    public int echelon;
    public int nbheures;
    public static int[] tauxsalaire = {12,14,16,18,20,22,24,26,28,30};

    public enseignant(String nom, String prenom, String adresse, int echelon, int nbheures) {
        super(nom, prenom, adresse);
        this.echelon = echelon;
        this.nbheures = nbheures;
    }
    public static void modiftaux(int echelon, int newtaux){
        tauxsalaire[echelon] = newtaux;
    }
    public void echelonValide(int newechelon){
        this.echelon = newechelon;
    }

    // Attribution de nouvelles valeurs de parametres
    public void setEchelon(int echelon) {
        this.echelon = echelon;
    }
    public void setNbheures(int nbheures) {
        this.nbheures = nbheures;
    }
    
    // Recuperation des valeurs des parametres 
    public int getEchelon() {
        return echelon;
    }
    
    public int getNbheures() {
        return nbheures;
    }
    
    public String getName() {
    	String name = this.prenom + " " + this.nom;
    	return name; 
    }
    

    
    public String toString() {
        return "enseignant{" +
                "nom='" + nom + '\'' +
                ", prenom='" + prenom + '\'' +
                ", adresse='" + adresse + '\'' +
                ", echelon=" + echelon +
                ", nbheures=" + nbheures +
                '}';
    }
    // Calculs d'informations 
    public int getprixheure(){
        return tauxsalaire[this.echelon];
    }
    public int getsalaire(){
        return this.nbheures * this.getprixheure();
    }
    
    public int getNbHeure() {
    	return this.nbheures; 
    }

}