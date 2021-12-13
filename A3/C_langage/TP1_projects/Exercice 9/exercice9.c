/***********************************************************************/
/***                                                                 ***/
/*** Use of basic function 2                                         ***/
/*** Created by Marion ESCOUTELOUP, oct. 11th 2021                   ***/
/*** Update on oct. 29th 2021                                        ***/
/*** Update : nov. 8th 2021                                          ***/
/***                                                                 ***/
/***********************************************************************/

#include <stdio.h>
#include <stdlib.h>

/******************/
/**** VARIABLE ****/
/******************/
int numberOfLigns = 0;

/******************/
/**** FUNCTION ****/
/******************/
/*  Function to use the FOR methods
    @param n the lign's number
    no @return
*/
void setDraw(int numberOfLigns){
    int numberOfCaracterPerLign = 0;
    int numberOfSpacePerLign = 0;

    // We build the ligns context
    for(int l = 1; l <= numberOfLigns; l++){
        numberOfCaracterPerLign = l * 2 - 1;
        numberOfSpacePerLign = numberOfLigns - l;
        for(int space = 0; space <= numberOfSpacePerLign; space++){
            printf(" ");
        }
        //We create a special lign's caracters configuration
        if(l == numberOfLigns){
            for(int c = 1; c <= numberOfCaracterPerLign; c++){
                printf("*");
            }
        }
        else{
        //We create the normal lign's caracters configuration
           for(int c = 1; c <= numberOfCaracterPerLign; c++){
            if((c == 1) || (c == numberOfCaracterPerLign))
                printf("*");
            else
                printf("o");
            }
        }
    printf("\n");
    }

}

/*******************/
/*****   MAIN   ****/
/*******************/
main(){
    //entree du nombre de ligne souhaite par l utilisateur
    printf("Quel est le nombre de ligne ? \n");
    scanf("%d", &numberOfLigns);

    //affichage du symbole
    setDraw(numberOfLigns);
}
