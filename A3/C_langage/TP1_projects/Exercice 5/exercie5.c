/***********************************************************************/
/***                                                                 ***/
/*** Use of basic function 2                                         ***/
/*** Created by Marion ESCOUTELOUP, oct. 11th 2021                   ***/
/*** Update : nov. 8th 2021                                          ***/
/***                                                                 ***/
/***********************************************************************/

#include <stdio.h>
#include <stdlib.h>
/******************/
/**** VARIABLE ****/
/******************/
int numberDesired, multiplicationDesired;
int calculResult = 0;

/******************/
/**** FUNCTION ****/
/******************/
/*  Function to calculate a number with the good power
    @param
    @return
*/
int getMultiplicationByAddition(int number, int multiplication){
    int result = 0 ;     // variable incremented
    int i = 1;           // increamentation number

    printf("number : %d  | puissance  : %d \n", number, multiplication);
    while( i <= multiplication ){
        result = result + number;
        printf("incrementation n%d, resultat : %d \n", i, result);
        i++;
    }
    return result;
}

/*******************/
/*****   MAIN   ****/
/*******************/
main() {
    //entree des donnees utilisateurs
    printf("Quel est le nombre desire ? \n");
    scanf("%d", &numberDesired);

    printf("Quelle est la multiplication desiree ? \n");
    scanf("%d", &multiplicationDesired);

    //calcul et affichage des resultats
    calculResult = getMultiplicationByAddition(numberDesired, multiplicationDesired);
    printf("Resultat : %d ", calculResult);
}
