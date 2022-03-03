/*
#include <stdio.h>

// définition du type bool
#define bool unsigned int
#define true 1
#define false 0

//Definion du nombre de Colonne du Tableau
#define Colonne_tableau 4

// Définition des colonnes du tableau
#define numero 0
#define reference 1
#define prix 2
#define quantite 3


/**
 * Permet d'afficher la référence des produits ayant une quantité inférieure à 5
 * @param taille Correspond à la taille du tableau
 * @param produits Correspond au tableau de produit
 */
 /*
void verifier(int taille, int produits[][Colonne_tableau]) {
    // Pour chaque ligne du tableau
    printf("%d", taille);
    for(int ligne=0; ligne < taille; ligne++) {
        // si la quantité est inférieure à 5
        if(produits[ligne][quantite] < 5) {
            printf(
                "Il existe seulement %d pieces pour l'article  de reference %d\n",
                produits[ligne][quantite],
                produits[ligne][reference]
            );
        }
    }
}

/**
 * Permet d'afficher un produits à 2 dimension
 * @param produits Correspond au produits a afficher
 * @param taille Correspond a la taille du produits a afficher
 */
 /*
void afficherTab(int produits[][Colonne_tableau], int taille) {
    // Pour chaque Ligne du tableau
    for (int ligne = 0; ligne < taille; ligne++) {
        // Permet le retour a la ligne apres chaque ligne
        printf("\n");
        // Pour chaque colonne du produits
        for (int colonne = 0; colonne < Colonne_tableau; colonne++) {
            printf("%d ", produits[ligne][colonne]);
        }
    }
}

/**
 * Permet d'afficher le prix total de chaque produit en fonction du prix unitaire et du nombre en stock
 * @param taille Correspond a la taille du tableau
 * @param produits Correspond au tableau de produit
 */
 /*
void prixTotal(int taille, int produits[][Colonne_tableau]) {
    for(int ligne=0; ligne < taille; ligne++) {
        // Pour chaque ligne du tableau
        printf(
            "le produit %d en quantite %d possède un prix total de %d euros\n",
            produits[ligne][reference],
            produits[ligne][quantite],
            produits[ligne][quantite] * produits[ligne][prix]
        );
    }
}

/**
 *Permet de supprimer un ligne d'un tableau
 * @param taille Correspond a la taille du tableau
 * @param produits Correspond au tableau de produit
 * @param ligne_a_supp Correspond au numero de ligne a supprimer
 */
 /*
void supprimeLigne(int taille, int produits[][Colonne_tableau], int ligne_a_supp){
    int tableau[taille-1][Colonne_tableau];
    int ligne_actuelle=0;
    for(int ligne=0; ligne < taille; ligne++) {
        if(ligne != ligne_a_supp) {
            for (int colonne; colonne < Colonne_tableau; colonne++) {
                tableau[ligne_actuelle][colonne] = produits[ligne][colonne];
            }
            ligne_actuelle++;
        }
    }
    afficherTab(tableau,taille);
}

int main() {
    char* titre[4] = {"Num"," Ref"," Prix"," Quantiter"};
    int nb_produit;
    // Contruction du Tableau
    /*
    printf("Nb ref diffrente : ");
    scanf("%d",&nb_produit);
    int produit[nb_produit][4];
    for(int i = 1;i<nb_produit;i++){
        produit[0][i-1] = i;
        printf("Reference %d",i);
        scanf("%d",&produit[1][i-1]);
        printf("Prix %d",i);
        scanf("%d",&produit[2][i-1]);
        printf("Quantiter %d",i);
        scanf("%d",&produit[3][i-1]);
    }
    */
/*
    int test_array[2][4] = {{1,2,3,4}, {11,22,33,44}};
    int* taille = 2;
    int test_arraysup[1][4] = {};
    verifier(taille, test_array);
    supprimeLigne(taille, test_array, 1);
    afficherTab(test_array, taille);
    return 0;
}

*/
