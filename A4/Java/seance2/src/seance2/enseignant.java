package seance2;

public class enseignant extends personne{
    public int echelon;
    public int nbheures;
    public static int[] tauxsalaire = {10,11,12,13,14,15,16,17,18,19};

    public enseignant(String nom, String prenom, String adresse, int echelon, int nbheures) {
        super(nom, prenom, adresse);
        this.echelon = echelon;
        this.nbheures = nbheures;
    }
    public static void modiftaux(int echelon, int newtaux){
        tauxsalaire[echelon] = newtaux;
    }
    

    public int getEchelon() {
        return echelon;
    }
    public int getNbheures() {
        return nbheures;
    }
    
    //Setters
    public void setEchelon(int echelon) {
        this.echelon = echelon;
    }
    public void setNbheures(int nbheures) {
        this.nbheures = nbheures;
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
    //Calculs
    public int getprixheure(){
        return tauxsalaire[this.echelon];
    }
    public int getsalaire(){
        return this.nbheures * this.getprixheure();
    }
    public void modifechelon(int newechelon){
        this.echelon = newechelon;
    }
}