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
int tab[50] = {};               //tableau des valeurs d'origines
int tabWithoutZero[50] = {};    //tableau des valeurs sans les 0

int N = 0;                      //nombre de composantes dans le tableau d origine
int Nclean = 0;                 //nombre de composantes dans le tableau "netoye"
int addition = 0;               //somme de l'ensemble des elements du tableau d origine

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

    // entree des parametres du tableau
    for(int i = 0; i < N; i++){
            printf("element %d : ", i); scanf("%d", &tab[i]);
            addition += tab[i];
    }

    // on trie les valeurs et supprime quand = 0
    for(int i = 0; i < N; i++){
        if(tab[i] != 0){
            tabWithoutZero[Nclean] = tab[i];
            Nclean++;
        }
    }

    // Affichage des tableaux et de leurs elements lies
    printf(" Taille : %d \n            tab[%d] = \{ ",N, N);
    for(int i = 0; i < N; i++)
        printf(" %d ", tab[i]);
    printf(" \} \n\n");

    printf(" Taille : %d \n tabWithoutZero[%d] = \{ ", Nclean, N);
    for(int j = 0; j < Nclean; j++)
        printf(" %d ", tabWithoutZero[j]);
    printf(" \} \n \n");

    printf("Somme : %d \n", addition);
}
