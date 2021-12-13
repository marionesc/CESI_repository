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
#define NUMBER_OF_VALUE 18


int menuEnter = 0;
int value = 0;

int tableau[NUMBER_OF_VALUE] = {};

/******************/
/**** FUNCTION ****/
/******************/
/*  Cette fonction a pour but
    no @param
    no @return
*/
void afficherTableau(){
    printf("        Tableau [%d] = { ", NUMBER_OF_VALUE);
    for(int i = 0; i < NUMBER_OF_VALUE; i++){
        printf("%d", tableau[i]);
        if(i != (NUMBER_OF_VALUE-1))
            printf(", ");
    }
    printf(" } \n");
}

/*  Cette fonction a pour but de calculer la moyenne du tableau
    no @param
    @return la moyenne calculé
*/
double calculeMoyenne(){
    double value = 0;
    double moyenne = (double)tableau[0];
    for(int i = 1; i < NUMBER_OF_VALUE; i++){
        value = tableau[i];
        moyenne = (moyenne + value) / 2;
    }
    return moyenne;
}

/*  Cette fonction a pour but de trouver la plus petite valeur de tableau
    no @param
    @return la valeur minumum dans le tableau
*/
int trouverMin(){
    int valueMin = tableau[0];
    for(int i = 1; i < NUMBER_OF_VALUE; i++){
        (valueMin > tableau[i]) ? (valueMin = tableau[i]) : (valueMin = valueMin);
    }
    return valueMin;
}

/*  Cette fonction a pour but de trouver la plus grande valeur du tableau
    no @param
    @return la valeur maximum dans le tableau
*/
int trouverMax(){
    int valueMax = tableau[0];
    for(int i = 1; i < NUMBER_OF_VALUE; i++){
        (valueMax < tableau[i]) ? (valueMax = tableau[i]) : (valueMax = valueMax);
    }
    return valueMax;
}

/*  Cette fonction a pour but d inverser le sens du tableau
    no @param
    no @return
*/
void inverserTableau(){
    int exchange = 0;
    int j = 0;
    for(int i = 0, j = NUMBER_OF_VALUE - 1; i < j; i++, j--){
        exchange = tableau[i];
        tableau[i] = tableau[j];
        tableau[j] = exchange;
    }
}



/*******************/
/*****   MAIN   ****/
/*******************/
main(){
    printf(" Bonjour jeune entrepreneur ! \n"
           " Rentrons les valeurs du tableau : \n");
    for(int i = 0; i < NUMBER_OF_VALUE; i++){
        printf(" tableau[%d] : ", i); scanf("%d", &tableau[i]);
    }


    printf("\n Tableau origine : \n");
        afficherTableau();

    printf("\n Tableau inverse : \n");
        inverserTableau();
        afficherTableau();

    printf("\n    Moyenne : %lf ", calculeMoyenne());
    printf("\n Valeur Min : %d  ", trouverMin());
    printf("\n Valeur max : %d  ", trouverMax());


}
