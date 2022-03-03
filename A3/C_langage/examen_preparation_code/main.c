/****************************************************************************/
/*  Ceci est un main programmé en language C                                */
/*  Il a été réalisé dans le cadre des enseignements de développement       */
/*  en language C au sein du CESI Toulouse - cycle ingénieur                */
/*  filières "Systèmes Electriques et Electroniques Embarqués"              */
/*                                                                          */
/*  Développeur     Marion ESCOUTELOUP                                      */
/*  Github          maesc                                                   */
/*                                                                          */
/****************************************************************************/

/**** INITIALISATION ****/
/* Librarie(s) gloable(s) */
#include <stdio.h>
#include <stdlib.h>

/* Variable(s) globale(s) */
#define TAB_ACHAT_LIGNE 4       //Normalement L = 100, on réduit pour l exercice
#define TAB_ACHAT_COLONNE 4     //Normalement C = 100, on réduit pour l exercice

#define CLNE_NUM 0
#define CLNE_REF 1
#define CLNE_PRIX 2
#define CLNE_QUANTITE 3

#define STOCK_WARNING 5         // Defini à partie de quelle quantité le stock est insuffisant
/* Fonction(s) globale(s) */
/* Cette fonction affiche le tableau des produits et sa légende
    @param tab le tableau des produits
    no @return
*/
void afficherTAB(int tab[TAB_ACHAT_LIGNE][TAB_ACHAT_COLONNE]){
        printf("| Num ||  Ref  ||Prix || Qtt |");
    printf("\n");
    for (int i = 0; i < TAB_ACHAT_LIGNE; i++) {
        for (int j = 0; j < TAB_ACHAT_COLONNE; j++) {
            printf("|  %d  |", tab[i][j]);
        }
        printf("\n");
    }
}

/* Cette fonction affiche le tableau des produits et sa légende
    @param
    @return
*/
void verifierStock(int tab[TAB_ACHAT_LIGNE][TAB_ACHAT_COLONNE]){
    int compteur = 0;
    for(int i = 0; i < TAB_ACHAT_LIGNE; i++){
        if(tab[TAB_ACHAT_LIGNE][CLNE_QUANTITE] <= STOCK_WARNING){
            printf(" Le stock du produit %d est insuffisant (%d)\n", tab[i][CLNE_NUM], tab[i][CLNE_QUANTITE]);
            compteur++;
        }
    }
    if(compteur == 0)
        printf("L'ensemble du stock est suffiant. \n");
}

/**** MAIN ****/
int main(){
    int achat[TAB_ACHAT_LIGNE][TAB_ACHAT_COLONNE] = {
                                                    { 1 , 135 , 3 , 4},
                                                    { 2 , 168 , 5 , 44},
                                                    { 3 , 187 , 8 , 5},
                                                    { 4 , 364 , 5 , 86}};

    printf("hello world, this is a test. \n");
    afficherTAB(achat);
    verifierStock(achat);
    printf("END");
    return 0;
}
