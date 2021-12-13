/***********************************************************************/
/*** TP 2 - LES TABLEAUX                                             ***/
/*** Use of basic function                                           ***/
/*** Created by Marion ESCOUTELOUP, oct. 29th 2021                   ***/
/*** Update : nov. 8th 2021                                          ***/
/***                                                                 ***/
/***********************************************************************/
#include <stdio.h>
#include <stdlib.h>


/******************/
/**** Variable ****/
/******************/

int tab[50] = {};       // Tab le tableau globale de l'exercice
int N = 0;              // N le nombre de composantes
int addition = 0;       // addition la variable stockant la somme des valeurs

/******************/
/**** FUNCTION ****/
/******************/

/*******************/
/*****   MAIN   ****/
/*******************/
main(){
    printf(" Adiu petiote ! \n");

    // Entrée du nombre de composantes du tableau
    printf(" Dimension N (max 50) : ");
    scanf("%d", &N);

    // entree des parametres du tableau et somme des valeurs
    for(int i = 0; i < N; i++){
        printf(" element %d : ", i); scanf("%d", &tab[i]);
        addition += tab[i];
    }

    // Affichage du tableau, des valeurs et des differents elements demandes
    printf(" tab[%d] = \{ ", N);
    for(int j = 0; j < N; j++)
        printf(" %d ", tab[j]);
    printf(" \} \n");

    printf(" Taille : %d \n", N);
    printf(" Somme : %d \n", addition);
}
