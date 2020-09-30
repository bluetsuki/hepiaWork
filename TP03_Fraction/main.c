#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>
#include "fraction.h"

int main(int argc, char **argv){
     struct fract nb1;
     struct fract nb2;
     char operator;
     int p;

     sscanf(argv[1], "%d", &nb1.numerateur);
     sscanf(argv[2], "%d", &nb1.denominateur);
     if (argc == 5) {
          sscanf(argv[4], "%d", &p);
     }else{

          sscanf(argv[4], "%d", &nb2.numerateur);
          sscanf(argv[5], "%d", &nb2.denominateur);
     }
     sscanf(argv[3], "%c", &operator);

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
          displayFract(powFract(nb1, p));
          break;
     }
}
