
/***********************************************************************/
/***                                                                 ***/
/*** Use of basic function l                                         ***/
/*** Created by Marion ESCOUTELOUP, oct. 11th 2021                   ***/
/***                                                                 ***/
/***********************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define PI 3.1415
/******************/
/**** VARIABLE ****/
/******************/
int r = 20.0;  // r for the circle's radius
int d = 0.0;   // d for the circle's diameter
int p = 0.0 ;  // p for the circle's perimeter
int s = 0.0 ;  // s for the circle's surface


/*******************/
/***** FUNCTION ****/
/*******************/
/*  Function to calculate the circle's diameter [m]
    @param radius
    @return de diamter result
*/
float diameter(int radius){
    return(2*radius);
}

/*  Function to calculate the circle's perimeter [m]
    @param radius
    @return the perimeter result
*/
float perimeter (int radius){
    return(2*radius*PI);
}

/*  Function to calculate the circle's surface [m²]
    @param radius
    @return the surface result
*/
float surface (int radius){
    return (PI * radius * radius);
}


/**************/
/**** MAIN ****/
/**************/
main() {
    printf("Bonjour,\n "
           "nous allons calculer ensemble les donnees de ton cercle.\n");
    // scanf("%f", &r);

    //Calcul des donnees
    d = 2 * r;          // calcul du diametre
    p = 2 * PI * r;     // calcul du perimetre
    s = PI * r * r ;    // calcul de la surface

    //affichage des données
    printf("diametre : %d m \n", d);
    printf("Perimetre : %d m \n", p);
    printf("surface : %d m2", s);
}
