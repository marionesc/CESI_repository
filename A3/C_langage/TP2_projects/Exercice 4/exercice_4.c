/***********************************************************************/
/*** TP 2 - LES TABLEAUX                                             ***/
/*** Use of basic function                                           ***/
/*** Created by Marion ESCOUTELOUP, nov 3rd 2021                     ***/
/*** Update : nov. 8th 2021                                          ***/
/***                                                                 ***/
/***********************************************************************/
#include <stdio.h>
#include <stdlib.h>


/******************/
/**** Variable ****/
/******************/
int tab[50] = {};       //tableau des valeurs d'origines

int N = 0;              //nombre de composantes dans le tableau d origine
int exchange = 0;       //variable d'aide pour l'inversion des elements du tableau

/******************/
/**** FUNCTION ****/
/******************/

/*******************/
/*****   MAIN   ****/
/*******************/
main(){
    // Entrée du nombre de composantes du tableau
    printf("Dimension N (max 50) : ");
    scanf("%d", &N);

    // Entrée des paramètres globale et inversion du sens
    for(int i = 0; i < N; i++){
        printf("Element %d : ", i);
        scanf("%d", &tab[i]);
    }

    // Affichage du tableau d'origine
    printf("\n Original tab[ %d ] : ", N);
    for(int i = 0; i < N; i ++)
        printf(" %d ", tab[i]);

    // Inversion du sens du tableau
    for(int i = 0, int j = N - 1; i < j; i++, j--){
        exchange = tab[i];
        tab[i] = tab[j];
        tab[j] = exchange;
    }
    // Affichage du tableau inverse
    printf("\n  Inverse tab[ %d ] : ", N);
    for(int i = 0; i < N; i++)
        printf(" %d ", tab[i]);
    printf("\n");
}
