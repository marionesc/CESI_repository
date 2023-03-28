package seance1;


import java.util.ArrayList;
import java.io.*;


public class promotion {
    ArrayList<student> students;
    int maxStudents = 10;

    /**
     * permet de return le nombre d'étudiant dans la liste 
     * @return student.size(); 
     */
    public int size() {
        return students.size();
    }
    
    public promotion() {
    	students = new ArrayList<student>();
    }
    
    /**
     * Methode permettant de creer une nouvel etudiant et 
     * de l ajouter un etudiant dans la liste d'etudiant
     * 
     * @param firstName	
     * @param lastName
     */
    public void addStudent(String firstName, String lastName) {
        student stud = new student(size()+1, firstName, lastName);
        students.add(stud);
    }
    
    /**
     * Methode permettant d'afficher la liste d etudiants sur la console
     */
    public void afficher() {
        for (student stud : students) {
            System.out.println(stud.toString_s());
        }
    }
    
    
    /**
     * Constructeur permettant d'ecrire l'ensemble de la liste d etudiants dans une
     * fichier .txt
     * @param namePromo le nom de la promo (& nom du fichier)
     */
    public void writeToFile(String namePromo) {
        try {
            FileWriter writer = new FileWriter(namePromo + " students.txt");
            for (student stud : students) {
                writer.write(stud.toString_s() + "\n");
            }
            writer.close();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
    
    /**
     * 
     * @param id_s
     */
    public void readToFile(int id_s) {
        System.out.println("\n on recupere etudiant : " + students.get(id_s));
    }
}

