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
int tab[50][50] = {};       //tableau des valeurs d origines
int Nl, Nc;                 //nombre respective de lignes et colonnes dans le tableau d origine
int Somme, SommeL, SommeC;  //Somme total, somme par ligne, somme par colonnes

/******************/
/**** FUNCTION ****/
/******************/

/*******************/
/*****   MAIN   ****/
/*******************/
main(){
    printf("Adiu petiote ! \n");

    // Entee du nombre de composantes du tableau
    printf("Dimension N (max 50 lignes) : "); scanf("%d", &Nl);
    printf("Dimension N (max 50 colonnes) : "); scanf("%d", &Nc);

    // Entree des paramètres globale et calcul de la somme
    for(int i = 0; i < Nl; i++){
        for(int j = 0; j < Nc; j++){
            printf("Element \[%d\]\[%d\] : ", i, j);
            scanf("%d", &tab[i][j]);
            Somme += tab[i][j];
        }
    }

    // Affichage du tableau et des somme de chaque ligne
    printf("\n tab[ %d ][ %d ] : ", Nc, Nl);
    for(int i = 0; i < Nl; i++){
        SommeL = 0;
        for(int j = 0; j < Nc; j++){
            printf(" %d ", tab[i][j]);
            SommeL += tab[i][j];
        }
        printf("  | Somme : %d \n", SommeL);
        if(i < Nl-1)
            printf("               : ");
    }

    // Affichage des sommes de chaque colonne
    printf("         Somme : ");
    for(int i = 0; i < Nc; i++){
        SommeC = 0;
        for(int j = 0; j < Nl; j++){
            SommeC += tab[j][i];
        }
        printf(" %d ", SommeC);
    }

    printf("\n \n Somme totale : %d \n", Somme);
}

