/****************************************************************************/
/*  Ceci est un main programmé en language C                                */
/*  Il a été réalisé dans le cadre des enseignements de développement       */
/*  en language C au sein du CESI Toulouse - cycle ingénieur                */
/*  filières "Systèmes Electriques et Electroniques Embarqués"              */
/*                                                                          */
/*                                                                          */
/*  Correction examen rattrapage Language C / A3  [06/04/22]                */
/*  Développeur     Marion ESCOUTELOUP                                      */
/*  Github          maesc                                                   */
/*                                                                          */
/****************************************************************************/
/************************/
/**** INITIALISATION ****/
/************************/
/* Librarie(s) gloable(s) */
#include <stdio.h>
#include <stdlib.h>

/* Variables constantes */
#define NB_COLONNE_MAX 100
#define NB_LIGNE_MAX 100


/* Variable(s) globale(s) */
int tab[NB_LIGNE_MAX][NB_COLONNE_MAX] = {};
int nombreDeLigneReel = 0;

/****************************/
/** Fonction(s) globale(s) **/
/****************************/
/*  Permet de demander à l'utilisateur quel jour de la semain il souhaite affiche
    puis l'affiche
    no @param
    no @return
*/
void setDayName(){
    int userChoice = 0;
    retour :
    printf(" Choississez le numero du jour comme ci-dessous : \n"
           "    (1) Lundi \n"
           "    (2) Mardi \n"
           "    (3) Mercredi \n"
           "    (4) Jeudi \n"
           "    (5) Vendredi \n"
           "    (6) Samedi \n"
           "    (7) Dimanche \n");
    printf("        CHOICE : ");
    scanf("%d", &userChoice);

    switch(userChoice){
    case 1 :
            printf("\n LUNDI \n\n");
            break;
        case 2 :
            printf("\n MARDI \n\n");
            break;
        case 3 :
            printf("\n MERCREDI \n\n");
            break;
        case 4 :
            printf("\n JEUDI \n\n");
            break;
        case 5 :
            printf("\n VENDREDI \n\n");
            break;
        case 6 :
            printf("\n SAMEDI \n\n");
            break;
        case 7 :
            printf("\n DIMANCHE \n\n");
            break;
        default :
            // la fonction goto est un fonction générique en C
            // Elle permet de revenir à un point souhaite (ici point "retour" ligne 39)
            goto retour;
    }
    printf(" end \n ");
}
/**************/
/**** MAIN ****/
/**************/
int main(){
    setDayName();

}
