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
int tableau[50][50] = {};               //tableau regroupant les valeurs initiales
int max[50] = {};                       //tableau regroupant les maximums de chaque ligne
int MAX[50][50] = {};

int min[1] = {};                        //tableau regroupant les minimums de chaque colonnes
int MIN[50][50] = {};

int pointColtab[50] = {};

int pointCol = 0;
int Nl, Nc, NlpointCol, NcpointCol;     //variable Lignes et colonnes
int aide;                               //variable utile pour la transmission de valeurs entre plusieurs tableaus


/******************/
/**** FUNCTION ****/
/******************/

/*******************/
/*****   MAIN   ****/
/*******************/
main(){
    // Entrée du nombre de composantes du tableau et des éléments
    printf(" Dimension N (max 50 lignes) : ");
    scanf("%d", &Nl);
    printf(" Dimension N (max 50 colonnes) : ");
    scanf("%d", &Nc);

    // Entrée des paramètres globaux
    printf("rentrez les elements du tableau : \n");
    for(int i = 0; i < Nl; i++){
        for(int j = 0; j < Nc; j++){
            printf(" tableau [%d][%d] : ", i, j);
            scanf("%d", &tableau[i][j]);
        }
        printf("\n");
    }

    // Affichage du tableau
    printf("\n tableau[%d][%d] : ", Nc, Nl);
    for(int i = 0; i < Nl; i++){
        for(int j = 0; j < Nc; j++){
            printf(" %d ", tableau[i][j]);
        }
        (i < Nl-1) ? (printf("\n                 ")) : (printf(""));
    }
    printf("\n \n");

    // Calcul et affichage des maxima de chaque ligne
    for(int i = 0; i < Nl; i++){
        aide = tableau[i][0];
        for(int j = 1; j < Nc; j++){
            if(aide < tableau[i][j])
                aide = tableau[i][j];
        }
        for(int j=0; j < Nc; j++){
            if(tableau[i][j] == aide)
                MAX[i][j] = 1;
            else
                MAX[i][j] = 0;
        }
    }

    // Calcul et affichage des minima de chaque colonne
    for(int i = 0; i < Nc; i++){
        aide = tableau[0][i];
        for(int j = 1; j < Nl; j++){
            if(aide > tableau[j][i])
                aide = tableau[j][i];
        }
        for(int j = 0; j < Nl; j++){
            if(tableau[j][i] == aide)
                MIN[j][i] = 1;
            else
                MIN[j][i] = 0;
        }
    }
    printf(" Calculs termines. \n Affichage des points des points-cols en cours ... \n");

    // Calcul et affichage des points-cols
    for(int i = 0; i < Nc; i++ ){
        for(int j = 0; j < Nl; j++){
            if((MAX[i][j] == 1) &&  (MIN[i][j] == 1)){
                printf(" Point-col en [%d][%d] : valeur = %d \n", i, j, tableau[i][j]);
                pointCol++;
            }
        }
    }

printf("\n Au total, nous avons detecte %d point-cols \n\n", pointCol);
}
