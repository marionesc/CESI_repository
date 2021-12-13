
/***********************************************************************/
/***                                                                 ***/
/*** Use of basic function 2                                         ***/
/*** Created by Marion ESCOUTELOUP, oct. 11th 2021                   ***/
/*** Update : nov. 8th 2021                                          ***/
/***                                                                 ***/
/***********************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define UO 1
#define V0 0

/******************/
/**** Variable ****/
/******************/
int nPower = 0;

int u_n, u_n1, v_n, v_n1;

/******************/
/**** FUNCTION ****/
/******************/
/*  Function to calculate the Un suits
    @param n the suit's power
    @return unValue
*/
void setValueWithForMethod(int nPower){
    u_n = 0; u_n1 = 0;
    v_n = 0; v_n1 = 0;

    printf("AFFCHAGE AVEC METHODE DU FOR ");
    printf(" n 0 | Un : %d | Vn : %d\n", u_n, v_n);
    for(int i = 1; i <= nPower; i++){
        u_n1 = v_n + 1; v_n1 = 2 * u_n;
        u_n = u_n1; v_n = v_n1;

        printf(" n %d | Un : %d | Vn : %d\n", i, u_n, v_n);
    }
    printf("Puissance Niemes : %d | Un_f = %d | Vn_f = %d \n \n", nPower, u_n, v_n);
}


/*  Function to calculate the Vn suits
    @param n the suit's power
    @return unValue
*/
void setValueWithDoWhileMethod(int nPower){
    u_n = 0; u_n1 = 0;
    v_n = 0; v_n1 = 0;
    int i = 1;

    printf("AFFCHAGE AVEC METHODE DU DO WHILE ");
    printf(" n 0 | Un : %d | Vn : %d\n", u_n, v_n);
    do{
        u_n1 = v_n + 1; v_n1 = 2 * u_n;
        u_n = u_n1; v_n = v_n1;

        printf(" n %d | Un : %d | Vn : %d\n", i, u_n, v_n);
        i++;
    }
    while(i <= nPower);
    printf("Puissance Niemes : %d | Un_f = %d | Vn_f = %d \n \n", nPower, u_n, v_n);

}


/*******************/
/*****   MAIN   ****/
/*******************/
main(){
    printf("Calculons des niemes termes d'une suite! \n");
    printf("Quel est la puissance n-iemes ? \n");
    scanf("%d", &nPower);

    setValueWithForMethod(nPower);
    setValueWithDoWhileMethod(nPower);
}
