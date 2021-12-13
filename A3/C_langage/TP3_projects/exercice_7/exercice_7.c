/***********************************************************************/
/*** TP 2 - LES TABLEAUX                                             ***/
/*** Use of basic function                                           ***/
/*** Created by Marion ESCOUTELOUP, nov. 15th 2021                   ***/
/*** Update :                                                        ***/
/***                                                                 ***/
/***********************************************************************/
#include <stdio.h>
#include <stdlib.h>


/******************/
/**** Variable ****/
/******************/
int value = 0;

/******************/
/**** FUNCTION ****/
/******************/
/*  Cette fonction a pour but de calculer la somme des premieres puissances
    param int enterNumber le nombre entree par l'utilisateur
    @return
*/
int getDegreeSumn(int enterNumber){
    if(enterNumber == 1)
        return 1;
    else
        return (pow(enterNumber,2) + getDegreeSumn(enterNumber-1));
}

/*  Cette fonction a pour but de faire la multiplication de deux entier pas addition successive
    @param int enterNumber le nombre entree par l'utilisateur
    @param int enterPower la puissance entree par l'utilisateur
    @return
*/
int getMultiplicationBySumn(int enterNumber, int enterPower){
    if(enterNumber == 0)
        return 0;
    else
        return (enterPower + getMultiplicationBySumn(enterNumber-1, enterPower));
}

/*  Cette fonction a pour but
    @param int number le nombre rentre par l'utilisateur
    @return 1 si impair, 0 si pair
*/
int getParitySimple(int number){
    int reste = number - 2;
    if(reste == 1)
        return 1;
    else if ( reste == 0)
        return 0;
    else getParitySimple(reste);
}

/*******************/
/*****   MAIN   ****/
/*******************/
main(){
    printf(" Bonjour jeune entrepreneur ! \n");
    printf(" Rentrez un nombre : "); scanf("%d", &value);
    int parity = getParitySimple(value);
    if(parity == 1)
        printf(" Le nombre %d est IMPAIR \n", value);
    else if(parity == 0)
        printf(" Le nombre %d est PAIR \n", value);
    else
        printf(" oups, il y a une erreur");
}
