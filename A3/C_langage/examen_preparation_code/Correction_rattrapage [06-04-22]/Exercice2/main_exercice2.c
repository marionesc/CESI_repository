/****************************************************************************/
/*  Ceci est un main programmé en language C                                */
/*  Il a été réalisé dans le cadre des enseignements de développement       */
/*  en language C au sein du CESI Toulouse - cycle ingénieur                */
/*  filières "Systèmes Electriques et Electroniques Embarqués"              */
/*                                                                          */
/*                                                                          */
/*  Correction examen rattrapage Language C / A3  [06/04/22]                */
/*  Développeur     Marion ESCOUTELOUP                                      */
/*  Github          maesc                                                   */
/*                                                                          */
/****************************************************************************/
/************************/
/**** INITIALISATION ****/
/************************/
/* Librarie(s) gloable(s) */
#include <stdio.h>
#include <stdlib.h>

/* Variables constantes */
#define NB_COLONNE_MAX 2
#define NB_LIGNE_MAX 100


/* Variable(s) globale(s) */
int tab[NB_LIGNE_MAX][NB_COLONNE_MAX] = {};
int userLignChoice = 0;

/****************************/
/** Fonction(s) globale(s) **/
/****************************/
/*  Permet de demander à l'utilisateur le nombre de ligne du tableau
    puis les valeurs à rentrer dans le tableau
    no @param
    no @return
*/
void getUserTabValues(){
    printf(" ENTREE DES VALEURS UTILISATEURS : \n"
           " Choississez le nombre de ligne : ");
    scanf("%d", &userLignChoice);                   // userLignChoice initialise en variables globales ligne 27

    // Ecriture equivalente d'un if traditionnel
    if(userLignChoice > NB_LIGNE_MAX) (userLignChoice = NB_LIGNE_MAX);

    for(int i = 0; i < userLignChoice; i++){        // boucle d'incrementation des lignes
        printf("\n");
        for(int j = 0; j < NB_COLONNE_MAX; j++ ){   // boucle d'incrementation des colonnes
            printf(" Valeur ligne %d Colonne %d : ", i, j);
            scanf("%d", &tab[i][j]);                // tab initialise en variables globales ligne 26
        }
    }
}

/*  Permet de ranger les nombres croissants dans le tableau
    no @param
    no @return
*/
void setArrangeIncreasingNumbers(){
    int moreLittleNumber = tab[0][0];
    int numberOfValue = NB_COLONNE_MAX * userLignChoice;
    int tabConversion[numberOfValue];
    int compteur = 0;

    printf("\n\n RANGEMENT DU TABLEAU PAR NOMBRE CROISSANT : \n");
    // On converti la matrice en un tableau d'une ligne (pour faciliter le programme)
    for(int i = 0; i < userLignChoice; i++){        // boucle d'incrementation des lignes
        for(int j = 0; j < NB_COLONNE_MAX; j++ ){   // boucle d'incrementation des colonnes
                int value = tab[i][j];
                tabConversion[compteur] = value;
                compteur++;
        }
    }
    // On met dans l'ordre les valeurs du tableau ligne
    for(int m = 0; m < numberOfValue; m++){         // On refait la boucle autant qu'il y a de valeurs pour etre sure de l'ordre
        for(int n = 1; n < numberOfValue; n++){
            if(tabConversion[n-1] > tabConversion[n]){
                moreLittleNumber = tabConversion[n];
                tabConversion[n] = tabConversion[n-1];
                tabConversion[n-1] = moreLittleNumber;
                moreLittleNumber = 0;
            }
        }
    }
    // On retransforme le tableau ligne en tableau ligne colonne
    compteur = 0;
    printf(" AFFICHAGE TABLEAU %d LIGNES ET %d COLONNES \n", userLignChoice, NB_COLONNE_MAX);
    for(int i = 0; i < userLignChoice; i++){        // boucle d'incrementation des lignes
        for(int j = 0; j < NB_COLONNE_MAX; j++ ){   // boucle d'incrementation des colonnes
                int value = tabConversion[compteur];
                tab[i][j] = value;
                compteur++;
        }
    }
}

void searchValue(){
    int userSearchValue = 0;
    printf("\n\n Quel est le nombre que vous cherchez : ");
    scanf("%d", &userSearchValue);

    for(int i = 0; i < userLignChoice; i++){
        for(int j = 0; j < NB_COLONNE_MAX; j++){
            if(tab[i][j] == userSearchValue) printf("EQUIVALENCE : ligne %d      colonne %d \n", i, j);
        }
    }
}

/**************/
/**** MAIN ****/
/**************/
int main(){
    int userMenu = 0;

    getUserTabValues();
    retour:
    printf("\n Que souhaitez vous faire ? \n"
           "        1 : ranger les valeurs en ordre croissants \n"
           "        2 : trouver un nombre dans le tableau \n"
           "        3 : afficher le tableau \n"
           "    autre : quitter \n");
    scanf("%d", &userMenu);


    switch(userMenu){
        case 1 :
            setArrangeIncreasingNumbers();
            goto retour;

        case 2 :
            searchValue();
            goto retour;

        case 3:
            for(int i = 0; i < userLignChoice; i++){
                for(int j = 0; j < NB_COLONNE_MAX; j++){
                    printf(" %d ", tab[i][j]);
                }
                printf("\n");
            }
            goto retour;

        default :
            printf( "\n\n\n END ");
            break;
    }
}
