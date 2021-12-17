/***********************************************************************/
/*** TP 5 - LES STRUCTURES ET PILES                                  ***/
/*** Use structures type to replace objects                          ***/
/*** Created by Marion ESCOUTELOUP, dec. 13th 2021                   ***/
/*** Update :                                                        ***/
/***                                                                 ***/
/***********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/******************/
/**** VARIABLE ****/
/******************/

typedef struct Point{
    int x;
    int y;
    }Point;

/******************/
/**** FUNCTION ****/
/******************/
int getDistanceBetween2points(int Ax, int Ay, int Bx, int By){
    int distance = sqrt(pow((Ax - Bx), 2 ) + pow((Ay - By), 2));
    return distance;
}
/******************/
/****** MAIN ******/
/******************/
int main(){
    Point a = {0, 0};
    Point b = {0, 0};

    printf(" Rentrez les coordonnées X du point a: "); scanf("%d", &a.x);
    printf(" Rentrez les coordonnées Y du point a: "); scanf("%d", &a.y);
    printf(" Rentrez les coordonnées X du point b: "); scanf("%d", &b.x);
    printf(" Rentrez les coordonnées Y du point b: "); scanf("%d", &b.y);

    printf(" \n"
           " *********************************** "
           "\n Distance entre les deux points : %d ", getDistanceBetween2points(a.x, a.y, b.x, b.y));
    return 0;
}
