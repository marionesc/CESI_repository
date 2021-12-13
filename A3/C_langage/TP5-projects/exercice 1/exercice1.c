/***********************************************************************/
/*** TP 5 - LES STRUCTURES ET PILES                                  ***/
/*** Use structures type to replace objects                          ***/
/*** Created by Marion ESCOUTELOUP, dec. 13th 2021                   ***/
/*** Update :                                                        ***/
/***                                                                 ***/
/***********************************************************************/
#include <stdio.h>
#include <stdlib.h>


/******************/
/**** VARIABLE ****/
/******************/
typedef struct Hour {
    int h;
    int min;
    int sec;
    }Hour;

typedef struct Date{
    int day;
    char month[20];
    int year;
    }Date;

/******************/
/**** FUNCTION ****/
/******************/


/******************/
/****** MAIN ******/
/******************/
main(){
    Hour h = {10, 26, 37};
    Date d = {13, "december", 2021};

    printf("  date %2d : %s : %4d \n  heure : %2d : %2d : %2d " d.day, d.month, d.year, h.h, h.min, h.sec);
}
