/***********************************************************************/
/*** TP 2 - LES TABLEAUX                                             ***/
/*** Use of basic function                                           ***/
/*** Created by Marion ESCOUTELOUP, nov 8th 2021                     ***/
/***                                                                 ***/
/***********************************************************************/
#include <stdio.h>
#include <stdlib.h>


/******************/
/**** Variable ****/
/******************/
int matrice1[10][10] = {};
int matrice2[10][10] = {};
int out[10][10] = {};

int Nl, Nc;

int a, b, c , d , e, f, g, h, i, j, k, l ;

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
    printf("rentrez les elements du premier tableau : \n");
    for(a = 0; a < Nl; a++){
        for(b = 0; b < Nc; b++){
            printf("Matrice 1 \[%d\]\[%d\] : ", a, b);
            scanf("%d", &matrice1[a][b]);
            printf("Matrice 2 \[%d\]\[%d\] : ", a, b);
            scanf("%d", &matrice2[a][b]);

            out[a][b] = matrice1[a][b] + matrice2[a][b];
            printf("Out 1 \[%d\]\[%d\] : %d \n\n", a, b, out[a][b]);
        }
    }

    //affichage du résultat
    for(c = 0; c < Nl; c++){
        (c == 0) ? (printf(" out[%d][%d] : ( ", Nc, Nl)) : (printf("             ( "));
        for(d = 0; d < Nc; d++){
            printf(" %d ",out[c][d]);
        }

        (c == 0) ? (printf(" ) = matrice1[%d][%d] : ( ", Nc, Nl)) : (printf(" )                    ( "));
        for(e = 0; e < Nc; e++){
            printf(" %d ",matrice1[c][e]);
        }

        (c == 0) ? (printf(" ) + matrice2[%d][%d] : ( ", Nc, Nl)) : (printf(" )                    ( "));
        for(f = 0; f < Nc; f++){
            printf(" %d ",matrice2[c][f]);
        }
        printf(" ) \n");
    }
}

