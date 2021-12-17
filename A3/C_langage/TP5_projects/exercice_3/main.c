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
#define CHAR_SIZE_DEFAULT 20
#define MAXIMUM_NUMBER_OF_STUDENT 10

int numberOfStudent = 0;

typedef struct Student{
    char name[CHAR_SIZE_DEFAULT];
    char surname[CHAR_SIZE_DEFAULT];
    int note;
    }Student;



char studentCodeName[MAXIMUM_NUMBER_OF_STUDENT];
char studentCodeSurname[MAXIMUM_NUMBER_OF_STUDENT];
int studentCodeNote[MAXIMUM_NUMBER_OF_STUDENT];

/******************/
/**** FUNCTION ****/
/******************/


/******************/
/****** MAIN ******/
/******************/
int main(){
    Student s1, s2, s3, s4, s5, s6, s7, s8, s9, s10;

    printf(" rentrez les informations de 5 éleves ");
    printf(" etudiant 1 : Prenom "); scanf("%c", &s1.name);
    printf("                 Nom "); scanf("%c", &s1.surname);
    printf("                Note "); scanf("%d", &s1.note);

    printf(" etudiant 2 : Prenom "); scanf("%c", &s2.name);
    printf("                 Nom "); scanf("%c", &s2.surname);
    printf("                Note "); scanf("%d", &s2.note);

    printf(" etudiant 1 : Prenom "); scanf("%c", &s3.name);
    printf("                 Nom "); scanf("%c", &s3.surname);
    printf("                Note "); scanf("%d", &s3.note);

    printf(" etudiant 1 : Prenom "); scanf("%c", &s4.name);
    printf("                 Nom "); scanf("%c", &s4.surname);
    printf("                Note "); scanf("%d", &s4.note);

    printf(" etudiant 1 : Prenom "); scanf("%c", &s5.name);
    printf("                 Nom "); scanf("%c", &s5.surname);
    printf("                Note "); scanf("%d", &s5.note);



