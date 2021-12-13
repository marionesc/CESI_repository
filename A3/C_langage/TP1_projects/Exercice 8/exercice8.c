
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
/**** Variable ****/
/******************/
int numberOfLigns = 0;
int draw = 1;
int drawAgain = 1;


char drawTypeChoice;

/***************************/
/**** SET DRAW FUNCTION ****/
/***************************/
/*  Function to draw the Draw 1
    @param n the lign's number
    no @return
*/
void setDraw1(int lignNumber){
    //We create a special lign's caracters configuration
    if(0 == lignNumber){
        printf(" A");
        for(int space = 1; space < numberOfLigns -1; space++)
            printf(" ");
    }
    else{
        for (int car = 1; car <= lignNumber; car++){
            printf("*");
        }
        for(int space = 1; space <= (numberOfLigns - lignNumber); space++){
            printf(" ");
        }
    }
}

/*  Function to draw the Draw 2
    @param n the lign's number
    no @return
*/
void setDraw2(int lignNumber){
    //We create a special lign's caracters configuration
    if(0 == lignNumber){
        printf(" B");
        for(int space = 1; space < numberOfLigns; space++)
            printf(" ");
    }
    else{
        for (int car = 1; car <= (numberOfLigns - lignNumber + 1); car++){
            printf("*");
        }
        for(int space = 1; space <= lignNumber; space++){
            printf(" ");
        }
    }
}

/*  Function to draw the Draw 2
    @param n the lign's number
    no @return
*/
void setDraw3(int lignNumber){
    //We create a special lign's caracters configuration
    if(0 == lignNumber){
        printf(" C");
        for(int space = 1; space < numberOfLigns; space++)
            printf(" ");
    }
    else{
        for(int space = 1; space <= lignNumber; space++){
            printf(" ");
        }
        for (int car = 1; car <= (numberOfLigns - lignNumber + 1); car++){
            printf("*");
        }
    }
}


/*  Function to draw the Draw 2
    @param n the lign's number
    no @return
*/
void setDraw4(int lignNumber){
    //We create a special lign's caracters configuration
    if(0 == lignNumber){
        printf(" D");
        for(int space = 2; space < numberOfLigns; space++)
            printf(" ");
    }
    else{
        for(int space = 1; space <= (numberOfLigns - lignNumber); space++){
            printf(" ");
        }
        for (int car = 1; car <= lignNumber; car++){
            printf("*");
        }
    }
}

/*****************************/
/**** DRAW STYLE FUNCTION ****/
/*****************************/
//DRAW IN LIGN
/*  Function to draw in lign
    @param n the lign's number
    no @return
*/
void setSignLign(int numberOfLigns){
    for(int lign = 0; lign <= numberOfLigns; lign++ ){
        //Draw 1
            setDraw1(lign);
            printf(" | ");
        //Draw 2
            setDraw2(lign);
            printf(" | ");
        //Draw 3
            setDraw3(lign);
            printf(" | ");
        //Draw 4
            setDraw4(lign);
            printf(" | \n");
    }
    printf("\n");
}
//DRAW IN COLUMN
/*  Function to draw in column
    @param n the lign's number
    no @return
*/
void setSignColumn(int numberOfLigns){
    //Draw 1
    printf("\n Draw A \n");
    for(int lign = 1; lign <= numberOfLigns; lign++ ){
        setDraw1(lign);
        printf("\n");
    }

    //Draw 2
    printf("\ Draw B \n");
    for(int lign = 1; lign <= numberOfLigns; lign++ ){
        setDraw2(lign);
        printf("\n");
    }

    //Draw 3
    printf("\n Draw C \n");
    for(int lign = 1; lign <= numberOfLigns; lign++ ){
        setDraw3(lign);
        printf("\n");
    }

    //Draw 4
    printf("\n Draw D \n");
    for(int lign = 1; lign <= numberOfLigns; lign++ ){
        setDraw4(lign);
        printf("\n");
    }
    printf("\n");
}

/*******************/
/*****   MAIN   ****/
/*******************/
main(){
    // Demande information a l utilisateur
   printf("Dessinons ensemble! \nDans quel sens voulez-vous dessiner? (c pour en colonne, l pour en ligne)\n");
   scanf("%c", &drawTypeChoice);
   if(drawTypeChoice == 'c' || drawTypeChoice == 'C'){
        //demande du nombre de ligne souhaite a l utilisateur
        printf("Quel est le nombre de lignes dans chaque dessin ? \n" );
        scanf("%d", &numberOfLigns);
        printf("\n\n");

        //affichage du dessin à la suite (en colonne)
        setSignColumn(numberOfLigns);
    }
    else if (drawTypeChoice == 'l' || drawTypeChoice == 'L'){
        //demande du nombre de ligne souhaite a l utilisateur
        printf("Quel est le nombre de lignes dans chaque dessin ? (Maximum 20) \n");
        scanf("%d", &numberOfLigns);
        printf("\n\n");
        if(numberOfLigns > 20)
            numberOfLigns = 20;

        //affichage de dessin a la suite (sur les memes lignes)
        setSignLign(numberOfLigns);
    }
    printf(" \n A la prochaine amigo ! \n");
}
