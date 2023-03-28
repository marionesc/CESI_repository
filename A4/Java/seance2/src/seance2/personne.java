package seance2;

public class personne {
    public String nom;
    public String prenom;
    public String adresse;

    public personne(String nom, String prenom, String adresse) {
        this.nom = nom;
        this.prenom = prenom;
        this.adresse = adresse;
    }

    @Override
    public String toString() {
        return "personne{" +
                "nom = '" + nom + '\'' +
                ", prenom = '" + prenom + '\'' +
                ", adresse = '" + adresse + '\'' +
                '}';
    }
}