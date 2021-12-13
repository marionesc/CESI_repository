/***********************************************************************/
/***                                                                 ***/
/*** Use of basic function like printf and scanf                     ***/
/*** Created by Marion ESCOUTELOUP, oct. 11th 2021                   ***/
/*** Update : nov. 8th 2021                                          ***/
/***                                                                 ***/
/***********************************************************************/
#include <stdio.h>
#include <stdlib.h>

/******************/
/**** VARIABLE ****/
/******************/
int age = 0;

/**************/
/**** MAIN ****/
/**************/
main() {
    printf("Bonjour ! \n Quel age as-tu ? \n");
    scanf("%d", &age);
    printf("Wow, tu as donc %d ans ! INCROYABLE \n", age);
}

