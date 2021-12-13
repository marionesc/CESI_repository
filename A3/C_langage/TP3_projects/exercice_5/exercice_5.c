/***********************************************************************/
/*** TP 2 - LES TABLEAUX                                             ***/
/*** Use of basic function                                           ***/
/*** Created by Marion ESCOUTELOUP, nov. 15th 2021                   ***/
/*** Update :                                                        ***/
/***                                                                 ***/
/***********************************************************************/
#include <stdio.h>
#include <stdlib.h>


/******************/
/**** Variable ****/
/******************/
int menuEnter = 0;
int value = 0;

int A, B, C, x, x1, x2, delta;

/******************/
/**** FUNCTION ****/
/******************/
/*  Cette fonction a pour de relever les valeurs des coefficients
    no @param
    no @return
*/
void getPolynomesCoefficiant(){
    printf("\n Rentrez les valeurs pour le polynomes sachant Ax^2 + Bx + c = 0 \n");
        printf(" Valeur de A : "); scanf("%d", &A);
        printf(" Valeur de B : "); scanf("%d", &B);
        printf(" Valeur de C : "); scanf("%d", &C);
}

/*  Cette fonction a pour de calculer la valeur d'un polynomes en connaissant x
    no @param
    no @return le résultat du calcul du polynome
*/
int getPolynomesResultKnowX(){
    printf(" Valeur de X : "); scanf("%d", &x);
    int result = (A * pow(x, 2) + B * x + C);
    return result;
}


/*  Cette fonction a pour but d'afficher les resultats obtenus précédement
    no @param
    no @return
*/
void setPolynomeResultOnScreen(int x1, int polynome){
        printf(" Polynome : %d.x^2 + %d.x + %d \n"
               " valeur x : %d \n"
               " resultat : %d \n", A, B, C, x1, polynome);
}

/*  Cette fonction a pour but de calculer les valeur de x pour un polynome egale a 0
    no @param
    no @return le nombre de solution 0,(domaine Complexe), 1 (sol. unique) ou 2
*/
int getVariablePolynomesResult(){
    int delta = pow(B, 2) - ( 4 * A * C);

    if(delta > 0){
        x1 = ( (-B) - sqrt(delta)) / (2 * A);
        x2 = ( (-B) + sqrt(delta)) / (2 * A);
        printf("deux solutions reels : %d ou %d ! \n", x1, x2);
        return 2;
    }
    else if(delta == 0){
        x1 = (-B) / A;
        printf("une solution reel : %d \n", x1);
        return 1;
        }
    else {
        printf("Delta < 0, donc les solutions appartiennent au domaine des complexes");
        return 0;
    }

}


/*******************/
/*****   MAIN   ****/
/*******************/
main(){
    printf(" Bonjour jeune entrepreneur ! \n"
           " Quel exercice voulez-vous lancer ? \n"
           " exercice 1.1 : Resolution Polynome = 0 sans fonction (TAPEZ 1) \n"
           " exercice 1.2 : Resolution polynome = 0 avec fonction (TAPEZ 2) \n"
           " exercice 2.1 : Resolution d'un polynome connaissant X sans fonction (TAPEZ 3) \n"
           " exercice 2.2 : Resolution d'un polynome connasszant X avec fonction (TAPEZ 4) \n");
    printf( " Choix : "); scanf("%d", &menuEnter);

    switch (menuEnter){
    case 1 :
        printf("\n Rentrez les valeurs pour le polynomes sachant Ax^2 + Bx + c = 0 \n");
        printf(" Valeur de A : "); scanf("%d", &A);
        printf(" Valeur de B : "); scanf("%d", &B);
        printf(" Valeur de C : "); scanf("%d", &C);

        delta = pow(B, 2) - ( 4 * A * C);
        if(delta > 0){
            x1 = ( (-B) - sqrt(delta)) / (2 * A);
            x2 = ( (-B) + sqrt(delta)) / (2 * A);
            printf("deux solutions reels : %d ou %d ! \n", x1, x2);
        }
        else if( delta == 0){
            x1 = (-B) / A;
            printf("une solution reel : %d \n", x1);
        }
        else
            printf("Delta < 0, donc les solutions appartiennent au domaine des complexes");
        break;

    case 2 :
        getPolynomesCoefficiant();
        value = getVariablePolynomesResult();
        break;

    case 3 :
        printf("\n Rentrez les valeurs pour le polynomes sachant Ax^2 + Bx + c = 0 \n");
        printf(" Valeur de A : "); scanf("%d", &A);
        printf(" Valeur de B : "); scanf("%d", &B);
        printf(" Valeur de C : "); scanf("%d", &C);
        printf(" Valeur de X : "); scanf("%d", &x);

        int polynome = A * pow(x, 2) + B * x + C;
        printf(" Polynome : %d.x^2 + %d.x + %d \n"
               " valeur x : %d \n"
               " résultat : %d \n", A, B, C, x, polynome);
       break;



    case 4 :
        getPolynomesCoefficiant();
        value = getPolynomesResultKnowX(x);
        setPolynomeResultOnScreen(x, value);
        break;

    default :
        printf(" Desole, je n'ai pas compris votre demande, relancez le code, puis reessayez. ");
    }
}
