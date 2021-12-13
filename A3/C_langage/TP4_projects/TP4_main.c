/***********************************************************************/
/*** TP 4 - LES POINTEURS                                            ***/
/*** Library of TP4 function                                          ***/
/*** Created by Marion ESCOUTELOUP, nov. 29th 2021                   ***/
/*** Update :                                                        ***/
/***                                                                 ***/
/***********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/******************/
/**** VARIABLE ****/
/******************/

/******************/
/**** FUNCTION ****/
/******************/
/*  Cette fonction a pour but d'inverser les valeur de deux pointeurs
    @param int *a et *b les valeurs des deux pointeurs
    no @return
*/
void setExchangeValue(int *a, int *b){
    int c = *a;
    int *a = *b;
    int *b = *c

}

/**** FUNCTION ****/
/******************/
/*  Cette fonction a pour but d'inverser les valeur de deux pointeurs
    @param int *a et *b les valeurs des deux pointeurs
    no @return
*/
void setExchangeValue(int *a, int *b){
    int c = *a;
    int *a = *b;
    int *b = *c

}


/* Cette fonction a pour but d'inverser les valeur de deux pointeurs
    @param int *a et *b les valeurs des deux pointeurs
    no @return
*/
void remplirTab(int* tab, int N){
    for(int  i = 0; i < N, i++){
        printf("rentrez la valeur de tab[%d] : ", i);
        scanf("%d", (tab+i));
    }

}


/*  Cette fonction a pour but d'inverser les valeur de deux pointeurs
    @param int *a et *b les valeurs des deux pointeurs
    no @return
*/
void afficherTab(int* tab, int N){
    printf("tab[%d] = {", N);
    for(int i =  0; i < N; i ++){
        printf(" %d " (tab+1));

        ( i < N-1 ) ? (printf(" , ")) : (printf(" } "));
    }

}


/*  Cette fonction a pour but d'inverser les valeur de deux pointeurs
    @param int *a et *b les valeurs des deux pointeurs
    no @return
*/
void inverserTab(int* tab, int N){
    int K;
    for(int i = 0; i < N; i++){
        K = *(tab+i);
        *(tab+i) = *(tab+N-1-i);
        *(tab+N-i) = K;
    }
}

/*  Cette fonction a pour but d'inverser les valeur de deux pointeurs
    @param int *a et *b les valeurs des deux pointeurs
    no @return
*/
void rangerTab(int* tab, int N){

}

/*  Cette fonction a pour but d'inverser les valeur de deux pointeurs
    @param int *a et *b les valeurs des deux pointeurs
    no @return
*/
int comparerChaine(char* ch, char* ch1){
    int lch = strlen(ch);
    int lch1 = strlen(ch1);
    int i = 0;
    int comp = 0;

    while(*(ch + i) != '\0'){
        //on compare ch[i] avec ch1[i]
        if(ch1[i] == '\0'){
            comp = -1;
            break;
        }
        else if(ch[i] != ch1[i]){
            comp = 2;
            break;
        }
        i++;
    }
    if(comp == -1)
        return comp;
    if (comp == 0)
        (ch1[i] == '\0') ? (return 0) : (return -1);
    if (comp == 2)
        (ch[i] < ch1[i]) ? (return -1) : (return 0);
}

/*******************/
/*****   MAIN   ****/
/*******************/
main(){



}
