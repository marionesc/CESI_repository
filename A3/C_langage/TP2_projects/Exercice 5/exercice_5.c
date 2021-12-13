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
int tab[50][50] = {};       //tableau des valeurs d'origines
int Nl, Nc;                 //nombre respective de lignes et colonnes dans le tableau d origine
int Somme;                  //somme des valeurs du tableau d origine

/******************/
/**** FUNCTION ****/
/******************/

/*******************/
/*****   MAIN   ****/
/*******************/
main(){
    // Entree du nombre de composantes du tableau
    printf("Dimension N (max 50 lignes) : "); scanf("%d", &Nl);
    printf("Dimension N (max 50 colonnes) : "); scanf("%d", &Nc);

    // Entree des parametres globaux et calcul de la somme
    for(int i = 0; i < Nl; i++){
        for(int j = 0; j < Nc; j++){
            printf("Element \[%d\]\[%d\] : ", i, j);
            scanf("%d", &tab[i][i]);
            Somme += tab[i][j];
        }
    }

    // Affichage du tableau d'origine
    printf("\n tab[ %d ][ %d ] : ", Nc, Nl);
    for(int i = 0; i < Nl; i++){
        for(int j = 0; j < Nc; j++){
            printf(" %d ", tab[i][j]);
        }
        if(i < Nl-1)
            printf("\n               : ");
        else
            printf("\n \n");
    }
    printf("Somme totale : %d \n", Somme);
}
