/***********************************************************************/
/***                                                                 ***/
/*** Use of basic function 2                                         ***/
/*** Created by Marion ESCOUTELOUP, oct. 11th 2021                   ***/
/***                                                                 ***/
/***********************************************************************/

#include <stdio.h>
#include <stdlib.h>

/******************/
/**** VARIABLE ****/
/******************/
int numberDesired, powerDesired;
int calculResult = 0;

/*******************/
/***** FUNCTION ****/
/*******************/
/*  Function to calculate a number with the good power
    @param number, puissance
    @return result
*/
int getCalculResult(int number, int puissance){
    int result = number ;     // variable incremented
    int i = 1;          // increamentation number

    printf("number : %d  | puissance  : %d \n", number, puissance);
    while( i < puissance ){
        result = result * number;
        printf("incrementation n%d, resultat : %d \n", i, result);
        i++;
    }
    return result;
}

/*******************/
/*****   MAIN   ****/
/*******************/
main(){
    //entree du nombre desire pas l'utilisateur
    printf("Quel est le nombre desire ? \n");
    scanf("%d", &numberDesired);

    printf("Quelle est la puissance desiree ? \n");
    scanf("%d", &powerDesired);

    //calcul et affichage des donnees
    calculResult = getCalculResult(numberDesired, powerDesired);
    printf("Resultat : %d ", calculResult);
}
