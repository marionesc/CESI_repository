/***********************************************************************/
/*** TP 2 - LES TABLEAUX                                             ***/
/*** Use of basic function                                           ***/
/*** Created by Marion ESCOUTELOUP, oct. 29th 2021                   ***/
/*** Update : nov. 12th 2021                                          ***/
/***                                                                 ***/
/***********************************************************************/
#include <stdio.h>
#include <stdlib.h>


/******************/
/**** Variable ****/
/******************/
double AxIN, AyIN, BxIN, ByIN;
int menuEnter = 0;

int parityNumberEnter;
int parityEvaluation;

int numberEnter;
/******************/
/**** FUNCTION ****/
/******************/
/*  Cette fonction a pour but de calculer la distance entre deux point A et B
    @param double Ax et Ay : les coordonnées du point A
    @param double Bx et By : les coordonnées du point B
    no @return
*/
void getDistance(double Ax, double Ay, double Bx, double By){
    double absXdiff = fabs(Bx - Ax);
    double absYdiff = fabs(By - Ay);
    printf(" Difference de X : %lf \n Difference de Y : %lf \n", absXdiff, absYdiff);

    double distance =  sqrt(pow(absXdiff,2) + pow(absYdiff,2));
    printf("\n \n La distance entre les deux point est : %lf ", distance);
}

/*  Cette fonction a pour but de déterminer la parité d'un nombre
    @param int intNumber : les coordonnées du point A
    @return int 1 si le nombre est pair, 0 sinon si impaire
*/
int getNumberParity(int intNumber){
    if(intNumber%2 == 0)
        return 1;
    else
        return 0;
}

/*  Cette fonction a pour but d'afficher la table de maultiplation du chiffre entrée
    @param int intNumber : les coordonnées du point A
    no @return
*/
void getMultiplicationTable(int numberEnter){

    printf(" Table de 9 : \n");
    int table = 0;

    for(int i = 0; i <= 10; i++){
        table = numberEnter * i;
        printf("     %d * %d = %d \n", numberEnter, i, table);
    }
}



/*******************/
/*****   MAIN   ****/
/*******************/
main(){
    printf(" Bonjour jeune entrepreneur ! \n"
           " Choisis quel exercice tu veux lancer ? \n"
           " exercice 1 : Calcul de la distance entre deux points (TAPE 1) \n"
           " exercice 2 : Etude de la parite d un nombre (TAPE 2) \n"
           " exercice 3 : Table de multiplication (TAPE 3) \n");
    scanf("%d", &menuEnter);

    switch (menuEnter){
    case 1 :
        printf(" Adiu petiote, donne moi les coordonnées de deux points !\n");
        printf(" Point Ax : "); scanf("%lf", &AxIN);
        printf(" Point Ay : "); scanf("%lf", &AyIN);
        printf(" Point Bx : "); scanf("%lf", &BxIN);
        printf(" Point By : "); scanf("%lf", &ByIN);

        getDistance(AxIN, AyIN, BxIN, ByIN);
        break;

    case 2 :
        printf(" Rentre le nombre donc tu veux evaluer la parite : ");
        scanf("%d", &parityNumberEnter);

        parityEvaluation = getNumberParity(parityNumberEnter);
        if(parityEvaluation == 1)
            printf(" Le nomber entree est PAIRE \n");
        else
            printf(" Le nombre entree est IMPAIRE \n");
        break;

    case 3 :
        printf("Quelle table de multiplication voulez vous afficher ? (entrer un chiffre entre 1 et 9) \n");
        scanf("%d", &numberEnter);
        getMultiplicationTable(numberEnter);
        // printf("Désolé, l exercice n a pas encore ete code ! \n");
        break;;

    default :
        printf(" Desole, je n'ai pas compris la demande, relance le code, et reessayes. ");
    }
}
