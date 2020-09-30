#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include "fraction.h"

int main(int argc, char **argv){
    struct fract nb1;
    struct fract nb2;
    char operator;
    char pgdc[] = "pgdc";
    int p;


    sscanf(argv[1], "%d", &nb1.numerateur);
    sscanf(argv[2], "%d", &nb1.denominateur);
    if (argc == 5) {
        sscanf(argv[4], "%d", &p);
    }
    
    if (argc == 6) {

        sscanf(argv[4], "%d", &nb2.numerateur);
        sscanf(argv[5], "%d", &nb2.denominateur);
    }

    if (strcmp(pgdc, argv[3]) == 0) {
        operator = 'p';
    }else{
        sscanf(argv[3], "%c", &operator);
    }

    switch (operator) {
        case '+':
        printf("L'addition de votre fraction est : ");
        displayFract(fract_add(nb1, nb2));
        break;

        case '-':
        printf("La soustraction de votre fraction est : ");
        displayFract(fract_sub(nb1, nb2));
        break;

        case ':':
        printf("La division de votre fraction est : ");
        displayFract(fract_div(nb1, nb2));
        break;

        case 'x':
        printf("L'addition de votre fraction est : ");
        displayFract(fract_mul(nb1, nb2));
        break;

        case '^':
        printf("Votre fraction a la puissance de %d : ", p);
        displayFract(powFract(nb1, p));
        break;

        case 'd':
        printf("L'addition de votre fraction est : ");
        displayFract(fract_add(nb1, nb2));
        break;

        case 'p':
        printf("Le PGDC : %d\n", PGDC(nb1));
        break;
    }
}
