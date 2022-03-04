/****************************************************************************/
/*  Ceci est un main programmé en language C                                */
/*  Il a été réalisé dans le cadre des enseignements de développement       */
/*  en language C au sein du CESI Toulouse - cycle ingénieur                */
/*  filières "Systèmes Electriques et Electroniques Embarqués"              */
/*                                                                          */
/*  CE MAIN EST MON EXERCICE DE L'EXAMEN 1 DU 04-03-22                      */
/*                                                                          */
/*  Développeur     Marion ESCOUTELOUP                                      */
/*  Github          maesc                                                   */
/*                                                                          */
/****************************************************************************/

/**** INITIALISATION VARIABLES ET LIBRAIRIES ****/
/* Librarie(s) gloable(s) */
#include <stdio.h>
#include <stdlib.h>

/* Variable(s) globale(s) */
#define TAB_MATRICE_LIGNE 2         //Normalement L = 50, on réduit pour l exercice
#define TAB_MATRICE_COLONNE 3     //Normalement C = 100, on réduit pour l exercice


/****  INITIALISATION FONCTIONS GLOBALES  ****/
/* Cette fonction demande à l'utilisateur de rentrer les valeurs dand la matrice
    @param tab le tableau des produits
    no @return
*/
void creationMatriceParUtilisateur(int tab[TAB_MATRICE_LIGNE][TAB_MATRICE_COLONNE]){
    for (int i = 0; i < TAB_MATRICE_LIGNE; i++) {
        for (int j = 0; j < TAB_MATRICE_COLONNE; j++) {
            printf("Rentrer la valeur matrice [%d][%d] : ", i, j );
            scanf("%d", &tab[i][j]);
        }
        printf("\n");
    }
    printf("fin de la creation de la matrice. \n \n");
}

/* Cette fonction affiche le tableau des produits et sa légende
    @param tab le tableau des produits
    no @return
*/
void afficherTab(int tab[TAB_MATRICE_LIGNE][TAB_MATRICE_COLONNE]){
    for (int i = 0; i < TAB_MATRICE_LIGNE; i++) {
        for (int j = 0; j < TAB_MATRICE_COLONNE; j++) {
            printf("|  %d  |", tab[i][j]);
        }
        printf("\n\n");
    }
}

/* Cette fonction calcule et affiche la somme et la moyenne de chaque ligne
    @param tab le tableau des produits
    no @return
*/
void afficherSommeMoyenne(int tab[TAB_MATRICE_LIGNE][TAB_MATRICE_COLONNE]){
    int moyenne = 0, somme = 0;

    for (int i = 0; i < TAB_MATRICE_LIGNE; i++) {
        for (int j = 0; j < TAB_MATRICE_COLONNE; j++) {
            somme += tab[i][j];
        }
        moyenne = somme / TAB_MATRICE_COLONNE;
        printf("Ligne %d : Somme %d \n "
               "         Moyenne %d \n", i, somme, moyenne);
    }
}


/* Cette fonction affiche la valeur max de chaque ligne
    @param tab le tableau des produits
    no @return
*/
void afficherMaxTab(int tab[TAB_MATRICE_LIGNE][TAB_MATRICE_COLONNE]){
    int max = 0, jMax = 0;

    for (int i = 0; i < TAB_MATRICE_LIGNE; i++) {
        for (int j = 0; j < TAB_MATRICE_COLONNE; j++) {
            if(tab[i][j] > max){
                max = tab[i][j];
                jMax = j + 1;
            }
        }
        printf("Valeur max ligne %d : %d (pos %d) \n", i, max, jMax);
        max = 0;
    }
    printf("\n" );
}

/* Cette fonction permute les valeurs de deux colonnes
    @param tab le tableau des produits
    no @return
*/
void permuterColonne(int tab[TAB_MATRICE_LIGNE][TAB_MATRICE_COLONNE], int c1, int c2){
    int colonneCoffre = 0;

    printf("\n\nPermutation des colonnes %d et %d \n", c1, c2);
    for (int i = 0; i < TAB_MATRICE_LIGNE; i++) {
        colonneCoffre = tab[i][c1];
        tab[i][c1] = tab[i][c2];
        tab[i][c2] = colonneCoffre;
    }
    printf("Permutation realise avec succes. \n \n" );
}

/****  MAIN  ****/
int main(){
    int matriceTab[TAB_MATRICE_LIGNE][TAB_MATRICE_COLONNE];
    int menu = 0;
    int end = 0;
    int c1 = 0, c2 = 0;

    printf(" EXAMEN LANGUAGE C -- Exercice 1 \n\n");
    printf(" Le menu deroulant vous permet de selectionner l'action à réaliser. \n"
           "        Selectionnez 1 : inserer les valeurs de la matrices ou les modifier \n"
           "        Selectionnez 2 : afficher la matrice \n"
           "        Selectionnez 3 : afficher le maximum de chaque ligne \n"
           "        Selectionnez 4 : Calculer et afficher la somme et moyenne de chaque ligne \n"
           "        Selectionnez 5 : Realiseez la permutation de deux colonnes \n"
           " Tapez autres chose pour quitter. \n");
    printf(" choix : "); scanf("%d", &menu);

    switch(menu){
        case 1 :
              creationMatriceParUtilisateur(matriceTab);

        case 2 :
            afficherTab(matriceTab);

        case 3 :
            afficherMaxTab(matriceTab);

        case 4 :
            afficherSommeMoyenne(matriceTab);

        case 5 :
            printf("renseigner les colonnes à permuter. \n ");
            printf("    Colonne 1 "); scanf("%d", &c1);
            printf("    Colonne 2 "); scanf("%d", &c2);
            permuterColonne(matriceTab, c1, c2);
            afficherTab(matriceTab);
        default :
            end == 1 ;
    }

    return 0;
}
