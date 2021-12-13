/***********************************************************************/
/*** TP 2 - LES TABLEAUX                                             ***/
/*** Use of basic function                                           ***/
/*** Created by Marion ESCOUTELOUP, nov 3rd 2021                     ***/
/***                                                                 ***/
/***********************************************************************/
#include <stdio.h>
#include <stdlib.h>


/******************/
/**** Variable ****/
/******************/
int matrice[10][10] = {};
int tab[100] = {};

int Nl, Nc;
int Somme, SommeL, SommeC;

int a, b, c , d , e, f ;

/******************/
/**** FUNCTION ****/
/******************/

/*******************/
/*****   MAIN   ****/
/*******************/
main(){
    printf("Adiu petiote ! \n");

    // Entrée du nombre de composantes du tableau
    printf("Dimension N (max 50 lignes) : ");
    scanf("%d", &Nl);
    printf("Dimension N (max 50 colonnes) : ");
    scanf("%d", &Nc);

    // Entrée des paramètres globale et calcul de la somme
    for(a = 0; a < Nl; a++){
        for(b = 0; b < Nc; b++){
            printf("Element \[%d\]\[%d\] : ", a, b);
            scanf("%d", &matrice[a][b]);
            Somme += matrice[a][b];
        }
    }

    // Affichage du tableau
    printf("\n tab[ %d ][ %d ] : ", Nc, Nl);
    for(c = 0; c < Nl; c++){
        for(d = 0; d < Nc; d++){
            printf(" %d ", matrice[c][d]);
        }
        if(c < Nl-1)
            printf("\n               : ");
    }


    // conversion de la matrice en un tableau à ligne unique
    printf("\n\n     tab[ %d ] : ", Nc*Nl);
    f = 0;
    for(d = 0; d < Nc ; d++){
        for(e = 0; e < Nl; e++){
            tab[f] = matrice[d][e];
            printf(" %d ", tab[f]);
        }
    }

    printf("\n \n Somme totale : %d \n", Somme);
}

