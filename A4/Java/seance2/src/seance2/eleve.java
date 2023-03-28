package seance2;

public class eleve extends personne{

    public eleve(String nom, String prenom, String adresse) {
        super(nom, prenom, adresse);
    }

    @Override
    public String toString() {
        return "eleve{" +
                "nom = '" + nom + '\'' +
                ", prenom = '" + prenom + '\'' +
                ", adresse = '" + adresse + '\'' +
                '}';
    }
}
