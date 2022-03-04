/****************************************************************************/
/*  Ceci est un main programmé en language C                                */
/*  Il a été réalisé dans le cadre des enseignements de développement       */
/*  en language C au sein du CESI Toulouse - cycle ingénieur                */
/*  filières "Systèmes Electriques et Electroniques Embarqués"              */
/*                                                                          */
/*  CE MAIN EST MON EXERCICE DE L'EXAMEN 3 DU 04-03-22                      */
/*                                                                          */
/*  Développeur     Marion ESCOUTELOUP                                      */
/*  Github          maesc                                                   */
/*                                                                          */
/****************************************************************************/

/**** INITIALISATION VARIABLES ET LIBRAIRIES ****/
/* Librarie(s) gloable(s) */
#include <stdio.h>
#include <stdlib.h>

/* Variable(s) globale(s) */
#define CHAR_SIZE_DEFAULT 20
#define NB_ENFANT_MAX 2
#define bool unsigned int
#define true 1
#define false 0

typedef struct personne{
    char prenom[CHAR_SIZE_DEFAULT];
    char nom[CHAR_SIZE_DEFAULT];
    int age;
    bool sexe;
    int nombreEnfant;
    struct enfant1{
        char prenom[CHAR_SIZE_DEFAULT];
        char nom[CHAR_SIZE_DEFAULT];
        int age;
        bool sexe;
    }enfant1;

    struct enfant2{
        char prenom[CHAR_SIZE_DEFAULT];
        char nom[CHAR_SIZE_DEFAULT];
        int age;
        bool sexe;
    }enfant2;

    struct enfant3{
        char prenom[CHAR_SIZE_DEFAULT];
        char nom[CHAR_SIZE_DEFAULT];
        int age;
        bool sexe;
    }enfant3;

    struct enfant4{
        char prenom[CHAR_SIZE_DEFAULT];
        char nom[CHAR_SIZE_DEFAULT];
        int age;
        bool sexe;
    }enfant4;

    struct enfant5{
        char prenom[CHAR_SIZE_DEFAULT];
        char nom[CHAR_SIZE_DEFAULT];
        int age;
        bool sexe;
    }enfant5;
}personne;


/****  INITIALISATION FONCTIONS GLOBALES  ****/
/* Cette fonction permet de creer une profil.
    @param personne regroupe les infos du profil
    no @return
*/
void creationProfil(personne profil){
    printf("creation d'un nouveau profil \n");
    printf("Prenom          : "); scanf("%s", &profil.prenom);
    printf("Nom             : "); scanf("%s", &profil.nom);
    printf("age             : "); scanf("%d", &profil.age);
    printf("sexe (1/0)      : "); scanf("%d", &profil.sexe);
    printf("nombre d'enfants: "); scanf("%d", &profil.nombreEnfant);

    // Si la personne a 1 enfant
    if(profil.nombreEnfant >= 1){
        printf("Prenom          : "); scanf("%s", &profil.enfant1.prenom);
        printf("Nom             : "); scanf("%s", &profil.enfant1.nom);
        printf("age             : "); scanf("%s", &profil.enfant1.age);
        printf("Sexe            : "); scanf("%s", &profil.enfant1.sexe);

        // Si la personne a 2 enfants
        if(profil.nombreEnfant >= 2){
            printf("Prenom          : "); scanf("%s", &profil.enfant2.prenom);
            printf("Nom             : "); scanf("%s", &profil.enfant2.nom);
            printf("age             : "); scanf("%s", &profil.enfant2.age);
            printf("Sexe            : "); scanf("%s", &profil.enfant2.sexe);

                // Si la personne a 3 enfants
            if(profil.nombreEnfant >= 3){
                printf("Prenom          : "); scanf("%s", &profil.enfant3.prenom);
                printf("Nom             : "); scanf("%s", &profil.enfant3.nom);
                printf("age             : "); scanf("%s", &profil.enfant3.age);
                printf("Sexe            : "); scanf("%s", &profil.enfant3.sexe);

                // Si la personne a 4 enfants
                if(profil.nombreEnfant >= 4){
                    printf("Prenom          : "); scanf("%s", &profil.enfant4.prenom);
                    printf("Nom             : "); scanf("%s", &profil.enfant4.nom);
                    printf("age             : "); scanf("%s", &profil.enfant4.age);
                    printf("Sexe            : "); scanf("%s", &profil.enfant4.sexe);

                    // Si la personne a 5 enfants
                    if(profil.nombreEnfant >= 5){
                        printf("Prenom          : "); scanf("%s", &profil.enfant5.prenom);
                        printf("Nom             : "); scanf("%s", &profil.enfant5.nom);
                        printf("age             : "); scanf("%s", &profil.enfant5.age);
                        printf("Sexe            : "); scanf("%s", &profil.enfant5.sexe);
                    }
                }
            }
        }
    }
    printf("Profil de %s a ete cree. \n \n", profil.prenom);
}

/****  INITIALISATION FONCTIONS GLOBALES  ****/
/* Cette fonction calcule et affiche la moyenne d'age des enfants de la personne (s'il en a)
    @param personne regroupe les infos du profil
    no @return
*/
void moyenneAgeEnfant(personne profil){
    int moyenne = 0, somme =0;
        // Si la personne a 1 enfant
    if(profil.nombreEnfant >= 1){
        somme += profil.enfant1.age;

        // Si la personne a 2 enfants
        if(profil.nombreEnfant >= 2){
            somme += profil.enfant2.age;

                // Si la personne a 3 enfants
            if(profil.nombreEnfant >= 3){
                somme += profil.enfant3.age;

                // Si la personne a 4 enfants
                if(profil.nombreEnfant >= 4){
                    somme += profil.enfant4.age;

                    // Si la personne a 5 enfants
                    if(profil.nombreEnfant >= 5){
                        somme += profil.enfant5.age;
                    }
                }
            }
        }
    }
    moyenne = somme/profil.nombreEnfant;
    printf("%s a %d enfant(s) d'age moyen : %d \n ", profil.prenom, profil.nombreEnfant, moyenne);
}

/* Cette fonction permet de transformer en majuscule les noms des profils. (A FINIR)
    @param personne regroupe les infos du profil
    no @return
*/
void transformationNoms(personne profil){
    char name[CHAR_SIZE_DEFAULT];
    printf(" new : %s \n", profil.nom);
    for(int i = 0; i < CHAR_SIZE_DEFAULT; i ++){
        profil.nom[i] = toupper(profil.nom[i]);
    }
    printf(" new : %s \n", profil.nom);
}


/****  MAIN  ****/
int main(){
    int choix = 0, nombreProfil = 0;
    char nouveauProfNom[CHAR_SIZE_DEFAULT] = "";
    personne profil_1;


    printf(" EXAMEN LANGUAGE C -- Exercice 4 \n\n");
    printf("voulez-vous creer un nouveau profil ? (1/0) "); scanf("%d", &choix);
    if(choix == 1){
        creationProfil(profil_1);
        nombreProfil++;
    }
    transformationNoms(profil_1);
    moyenneAgeEnfant(profil_1);

    return 0;
}
