package seance1;

public class main {

	// EXERCICE 2 : Creation d'un objet et ses attributs
	/*
	public static void main(String[] args) {
		student stud_1 = new student(1, "marion", "escouteloup"); 
		System.out.println(stud_1.toString_s());
		
		student stud_2 = new student(5, "Jonnhy", "Wilkinson"); 
		System.out.println(stud_2.toString_s());

	}
	*/
	// EXERCICE 2 : utilisation des arrayList
	public static void main(String[] args) {
        promotion p1 = new promotion();
        p1.addStudent("Marion", "Escouteloup");
        p1.addStudent("Yohann", "Delavaux");
        p1.addStudent("Jonatan", "Mora Moya");
        p1.addStudent("Sylvain", "Lisse");
        p1.afficher();
        p1.writeToFile("Promotion 1");
        
        System.out.println("nb d etudiant : " + p1.size() + "\n");
        
        System.out.println("\n ajout d'une nouvel etudiant : ");
        p1.addStudent("bruuuh", "broum");
        p1.afficher();
        p1.writeToFile("Promotion 1");
        System.out.println("nb d etudiant : " + p1.size());

        p1.readToFile(2);
        
	}

}
