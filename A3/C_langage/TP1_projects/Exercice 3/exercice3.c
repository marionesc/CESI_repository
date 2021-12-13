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
int n1, n2;

/*******************/
/***** FUNCTION ****/
/*******************/
/*  Function to compare two number
    @param number1, number2
    @return bigNumber
*/
int getBigNumberComparaison(int number1, int number2){
    if(number1> number2)
        return number1;
    if(number1< number2)
        return number2;

printf("egal number");
return 0;
}

/*******************/
/*****   MAIN   ****/
/*******************/
main(){
    //entree utilisateur des deux nombres à comparer
    printf("Bonjour, Quel est ton premier nombre ? \n");
    scanf("%d", &n1);
    printf("Quel est ton second nombre? \n");
    scanf("%d", &n2);

    //calcul et affichage du plus grand nombre
    int bigNumber = getBigNumberComparaison(n1, n2);
    printf("Le plus gand nombre est %d ! \n", bigNumber);

}
