/***********************************************************************/
/*** TP 2 - LES TABLEAUX                                             ***/
/*** Use of basic function                                           ***/
/*** Created by Marion ESCOUTELOUP, nov. 12th 2021                   ***/
/*** Update :                                                        ***/
/***                                                                 ***/
/***********************************************************************/
#include <stdio.h>
#include <stdlib.h>


/******************/
/**** Variable ****/
/******************/
int menuEnter = 0;
int value = 0;

int enterNumber, enterPower;

int enterOne = 0;
int enterTwo = 0;

/******************/
/**** FUNCTION ****/
/******************/
/*  Cette fonction a pour but de calculer le carre d'un nombre
    @param int enterNumber le nombre a mettre au carre
    @return int outNumber le carre du nombre carre
*/
int getCalculateCarreNumber(int enterNumber){
    int outNumber = 0;
    outNumber = enterNumber * enterNumber;

    return outNumber;
}

/*  Cette fonction a pour but de calculer la puissance d'un nombre
    @param int enterNumber le nombre a éléever au rang int powerNumber
    @return int outNumber l elevation du nombre
*/
int getCalculateNumberWithPower(int enterNumber, int powerNumber){
    int outNumber = 0;
    outNumber = pow(enterNumber, powerNumber);

    return outNumber;
}

/*  Cette fonction a pour but d echanger les valeurs de deux nombres reeles globales
    no @param
    no @return
*/
void getExchangeNumber(){
    int tampon = 0;

    tampon = enterOne;
    enterOne = enterTwo;
    enterTwo = tampon;

    return ;
}


/*******************/
/*****   MAIN   ****/
/*******************/
main(){
    printf(" Bonjour jeune entrepreneur ! \n"
           " Choisis quel exercice tu veux lancer ? \n"
           " exercice 1 : Calcul du carre d'un nombre (TAPE 1) \n"
           " exercice 2 : Calcul à la puissance n d'un nombre (TAPE 2) \n"
           " exercice 3 : Echange de variable (TAPE 3) \n");
    printf( " Choix : "); scanf("%d", &menuEnter);

    switch (menuEnter){
    case 1 :
        printf("\n Rentrez le nombre a mettre au carre : "); scanf(" %d", &enterNumber);

        value = getCalculateCarreNumber(enterNumber);
        printf("\n la valeur carre du nombre %d est : %d \n", enterNumber, value);
        break;

    case 2 :
        printf("\n Rentrez le nombre a mettre : "); scanf(" %d", &enterNumber);
        printf(" Rentrez la puissance : "); scanf(" %d", &enterPower);

        value = getCalculateNumberWithPower(enterNumber, enterPower);
        printf("\n la valeur du nombre %d a la puissance %d est : %d \n", enterNumber, enterPower, value);
        break;

    case 3 :
        printf(" Rentrez votre premier nombre (nombre reel seulement) : "); scanf("%d", &enterOne);
        printf(" Rentrez votre second nombre (nombre reel seulement) :  "); scanf("%d", &enterTwo);


        printf( "Initialement :  \n"
                "    Reel 1 : %d \n"
                "    Reel 2 : %d \n", enterOne, enterTwo);

        getExchangeNumber();
        printf( "\n Echange reussi : \n"
                "    Reel 1 : %d   \n"
                "    Reel 2 : %d   \n", enterOne, enterTwo);

        break;

    default :
        printf(" Desole, je n'ai pas compris votre demande, relancez le code, puis reessayez. ");
    }
}
