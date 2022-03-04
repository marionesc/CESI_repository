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


/****  INITIALISATION FONCTIONS GLOBALES  ****/
/* Cette fonction verifie si un nombre P donné et divisible par un nombre X donnée.
   Si P est divible par X, alors on l'affiche, sinon on affiche le reste de la division
   euclidienne de P par X.
    @param P le paramètre divise
    @param C le paraètre diviseur
    no @return
*/
void nombreDivisible(int P, int X){
    int compteur = 0;
    int recursive = P;
    int reste = 0;

    //Récursivité par soustraction
    while(P > X){
        recursive = recursive - X;
        compteur++;
    }
    // verifier le reste de la récursivité par soustraction pour adapter le message de sortie
    if(recursive > 0){
        reste = recursive;
        printf("%d n'est pas divisible par %d. Le reste de la division euclidienne est %d", P, X, reste);
    }
    else if (recursive == 0)
        printf(" %d est divisble par %d", P, X);
    else if(recursive < 0){
        reste = recursive + X;
        printf("%d n'est pas divisible par %d. Le reste de la division euclidienne est %d", P, X, reste);
    }
}



/****  MAIN  ****/
int main(){
    printf(" EXAMEN LANGUAGE C -- Exercice 3 \n\n");
    int P = 0, X = 0;

    printf("calculer nombre divisible \n");
    printf(" rentrer le nombre a diviser : "); scanf("%d", &P);
    printf(" rentrer le nombre diviseur  : "); scanf("%d", &X);
    nombreDivisible(P, X);

    printf("\n\n\n THIS IS THE END");

    return 0;
}
