#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>
#include "fractions.h"

void displayHelp();

int main(int argc, char **argv)
{
     if (argc != 6 || argc != 5)
     {
          displayHelp();
          exit(1);
     }

     fract *fractA;
     fract *fractB = fractCreate(0, 0);
     fract *res;

     int num;
     int den;
     char oper;
     int pow;

     sscanf(argv[1], "%d", &num);
     sscanf(argv[2], "%d", &den);
     fractA = fractCreate(num, den);
     res = fractA;
     sscanf(argv[3], "%c", &oper);
     if (oper == 'p')
     {
          sscanf(argv[4], "%d", &pow);
     }
     else
     {
          sscanf(argv[4], "%d", &num);
          sscanf(argv[5], "%d", &den);
          free(fractB);
          fractB = fractCreate(num, den);
     }

     printf("%d / %d", fractA->numerateur, fractA->denominateur);
     printf(" %c ", oper);
     printf("%d / %d", fractB->numerateur, fractB->denominateur);
     printf(" = ");

     switch (oper)
     {
          case '+':
          res = fract_add(fractA, fractB);
          break;

          case '-':
          res = fract_sub(fractA, fractB);
          break;

          case ':':
          res = fract_div(fractA, fractB);
          break;

          case 'x':
          res = fract_mul(fractA, fractB);
          break;

          case 'p':
          res = powFract(fractA, pow);
          break;

          default:
          displayHelp();
          break;
     }

     printf("%d / %d\n", res->numerateur, res->denominateur);
     free(res);
     free(fractA);
     free(fractB);
}

void displayHelp()
{
     printf("Pour effectuer une opération avec la première fraction que vous avez entrée tabez le symbol correspondant\n");
     printf("Liste des symboles :\n ");
     printf("'+' : Addition avec une autre fraction\n ");
     printf("'-' : soustraction avec une autre fraction\n ");
     printf("'x' : multiplication\n ");
     printf("':' : division avec une autre fraction\n ");
     printf("'p' : met ls fraction à la puissance\n ");
}
