/****************************************************************************/
/*  Ceci est un main programmé en language C                                */
/*  Il a été réalisé dans le cadre des enseignements de développement       */
/*  en language C au sein du CESI Toulouse - cycle ingénieur                */
/*  filières "Systèmes Electriques et Electroniques Embarqués"              */
/*                                                                          */
/*  CE MAIN EST MON EXERCICE DE L'EXAMEN 1 DU 04-03-22                      */
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
#define TAB_MATRICE_LIGNE 2         //Normalement L = 50, on réduit pour l exercice
#define TAB_MATRICE_COLONNE 3     //Normalement C = 100, on réduit pour l exercice


/****  INITIALISATION FONCTIONS GLOBALES  ****/
/* Cette fonction a pour but d'afficher l'heure
    @param h pour le nombre d'heure
    @param m pour nombre de minutes
    @param s pour nombre de secondes
    no @return
*/
void affichageHeure(int h, int m, int s){
    printf(" Il est %d heure %d minutes et %d seconde. \n", h, m, s);
}

/* Cette fonction affiche le tableau des produits et sa légende
    @param tab le tableau des produits
    no @return
*/
void saisirHeure(int h, int m, int s){
}

/* Cette fonction permet de temporiser le code d'une seconde
    @param tab le tableau des produits
    no @return
*/
void tick(){
}

/****  MAIN  ****/
int main(){


    printf(" EXAMEN LANGUAGE C -- Exercice 2 \n\n");
    printf(" Le menu deroulant vous permet de selectionner l'action à réaliser. \n"
           "        Selectionnez 1 :  \n"
           "        Selectionnez 2 :  \n"
           "        Selectionnez 3 :  \n"
           "        Selectionnez 4 :  \n"
           "        Selectionnez 5 :  \n"
           " Tapez autres chose pour quitter. \n");
    printf(" choix : "); scanf("%d", &menu);

    switch(menu){
        case 1 :

        case 2 :

        case 3 :

        case 4 :

        case 5 :

        default :
    }

    return 0;
}
