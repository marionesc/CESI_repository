/***********************************************************************/
/***                                                                 ***/
/*** Use of basic function 2                                         ***/
/*** Created by Marion ESCOUTELOUP, oct. 11th 2021                   ***/
/***                                                                 ***/
/***********************************************************************/

#include <stdio.h>
#include <stdlib.h>

/******************/
/**** Variable ****/
/******************/
float celsus = 0 ;
float farenheit = 0 ;

/******************/
/**** FUNCTION ****/
/******************/
/*  Function to convert farenheit value in celsus degre value
    @param farenheit value
    @return celsus value
*/
float getCelsusFarenheitConverion(float farenheit){
    float celsus = (farenheit - 32) / 1.8;
    return celsus;
}

/*  Function to realize the conversion with FOR methods
    @param celsus, farenheit
    no @return
*/
void conversionWithForMethods(){
    printf("\n AFFICHAGE AVEC METHODE DU FOR \n");
    farenheit = 0;
        for(int i = 0; i <= 30; i++){
            farenheit = i*10;
            celsus = getCelsusFarenheitConverion(farenheit);
            printf(" i = %d ||| Farenheit : %f  | Celsus : %f \n", i, farenheit, celsus);
    }
}

/*  Function to realize the conversion with WHILE methods
    @param celsus, farenheit
    no @return
*/
void conversionWithWhileMethods(){
    printf("\n AFFICHAGE AVEC METHODE DU WHILE \n");
    farenheit = 0;
    while (farenheit <= 300){
        celsus = getCelsusFarenheitConverion(farenheit);
        printf(" Farenheit : %f  | Celsus : %f \n", farenheit, celsus);
        farenheit = farenheit + 10;
    }
}

/*  Function to realize the conversion with DO WHILE methods
    @param celsus, farenheit
    no @return
*/
void conversionWithDoWhileMethods(){
    printf("\n AFFICHAGE AVEC METHODE DU DO WHILE \n");
    farenheit = 0;
     do{
        celsus = getCelsusFarenheitConverion(farenheit);
        printf(" Farenheit : %f  | Celsus : %f \n", farenheit, celsus);
        farenheit = farenheit + 10;
    }while(farenheit <= 300);
}

/*******************/
/*****   MAIN   ****/
/*******************/
main(){
    printf("Affichons une liste de conversion de degres farenheit en degres celsus ! \n");
    conversionWithForMethods();
    conversionWithWhileMethods();
    conversionWithDoWhileMethods();
}
