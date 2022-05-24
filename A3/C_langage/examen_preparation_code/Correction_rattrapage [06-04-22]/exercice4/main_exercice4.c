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
        printf(" | Num ||  Ref  ||Prix || Qtt | \n ");
    for (int i = 0; i < TAB_ACHAT_LIGNE; i++) {
        for (int j = 0; j < TAB_ACHAT_COLONNE; j++) {
            printf("|  %d  |", tab[i][j]);
        }
        printf("\n ");
    }
}

/* Cette fonction affiche le tableau des produits et sa légende
    @param le tableau des produits
    no @return
*/
void verifierStock(int tab[TAB_ACHAT_LIGNE][TAB_ACHAT_COLONNE]){
    int compteur = 0;       //Cette variable nous permet d'adapter le message de la fonction

    printf("\n");
    for(int i = 0; i < TAB_ACHAT_LIGNE; i++){
        if( STOCK_WARNING >= tab[i][CLNE_QUANTITE]){
            printf(" Le stock du produit %d est insuffisant (%d)\n", tab[i][CLNE_NUM], tab[i][CLNE_QUANTITE]);
            compteur++;
        }
    }
    if(compteur == 0)
        printf(" L'ensemble du stock est suffisant. \n");
}

/* Cette fonction calcule et affiche le prix totale du stock de chaque produit
    @param le tableau des produits
    no @return
*/
void prixTotaleArticle(int tab[TAB_ACHAT_LIGNE][TAB_ACHAT_COLONNE]){
    int priceTotal = 0;

    printf("\n");
    for (int i = 0; i < TAB_ACHAT_LIGNE; i++) {
        priceTotal = tab[i][CLNE_PRIX] * tab[i][CLNE_QUANTITE];
        printf(" Prix total produit %d : %d euros \n", tab[i][CLNE_NUM], priceTotal);
    }
}

/* Cette fonction demande et effectue une suppression d'un produit de la liste
    @param le tableau des produits
    no @return
*/
void supprimerProduit(int tab[TAB_ACHAT_LIGNE][TAB_ACHAT_COLONNE]){
    int choixSupp = 1, choixProduit = 0, compteur = 0;

    printf("\n Souhaitez-vous supprimer un produit ? (1/0) ");
    scanf("%d", &choixSupp);

    while(choixSupp == 1){
        if(choixSupp == 1){
            printf(" Quel produit souhaitez-vous supprimer ? (entre le numero correspondant au produit) ");
            scanf("%d", &choixProduit);
            for(int i = choixProduit - 1; i < TAB_ACHAT_LIGNE-1; i++){
                tab[i][CLNE_NUM] = tab[i+1][CLNE_NUM]-1;
                tab[i][CLNE_REF] = tab[i+1][CLNE_REF];
                tab[i][CLNE_PRIX] = tab[i+1][CLNE_PRIX];
                tab[i][CLNE_QUANTITE] = tab[i+1][CLNE_QUANTITE];
            }
        compteur++;
        }
    printf(" Souhaitez-vous supprimer un autre produit ? (1/0) ");
    scanf("%d", &choixSupp);
    }
    printf(" Nouvelle liste de produit : \n \n");
    afficherTAB(tab);
}

/**** MAIN ****/
int main(){
    int achat[TAB_ACHAT_LIGNE][TAB_ACHAT_COLONNE] = {
                                                    { 1 , 135 , 3 , 4},
                                                    { 2 , 168 , 5 , 44},
                                                    { 3 , 187 , 8 , 5},
                                                    { 4 , 364 , 5 , 86}};

    printf(" hello world, this is a test. \n\n");
    afficherTAB(achat);
    verifierStock(achat);
    prixTotaleArticle(achat);
    supprimerProduit(achat);

    printf("\n END \n ");
    return 0;
}
