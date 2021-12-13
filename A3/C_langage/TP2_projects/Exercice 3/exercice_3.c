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
int tabPos[50] = {};    //tableau des valeurs strictement positives
int tabNeg[50] = {};    //tableau des valeurs strictement negatice

int N = 0;              //nombre de composantes dans le tableau d origine
int Npos = 0;           //nombre de composantes dans le tableau tabPos
int Nneg =0;            //nombre de composantes dans le tableau tabNeg

/******************/
/**** FUNCTION ****/
/******************/

/*******************/
/*****   MAIN   ****/
/*******************/
main(){
    // Entree du nombre de composantes du tableau
    printf("Dimension N (max 50) : ");
    scanf("%d", &N);

    // Entree des parametres globale et rangement dans tabPos et tabNeg
    for(int i = 0; i < N; i++){
        printf("Element %d : ", i);
        scanf("%d", &tab[i]);
        if(tab[i] < 0){
            tabNeg[Nneg] = tab[i];
            Nneg++;
        }
        else if (tab[i] > 0){
            tabPos[Npos] = tab[i];
            Npos++;
        }
    }

    //affichage des tableaux
    printf("\n    tab[ %d ] : ", N);
    for(int i = 0; i < N; i ++)
        printf(" %d ", tab[i]);


    printf("\n tabPos[ %d ] : ", Npos);
    for(int i = 0; i < Npos; i ++)
        printf(" %d ", tabPos[c]);


    printf("\n tabNeg[ %d ] : ", Nneg);
    for(int i = 0; i < Nneg; i ++)
        printf(" %d ", tabNeg[i]);
}

