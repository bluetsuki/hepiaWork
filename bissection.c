#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

double g(double x);
int bissect(double a1, double b1, double epsillon, double *zero);
bool sign(double x);

double a1;
double b1;
double e;
double zero;
int count;

int main(){
     printf("Entrer un nombre minimum : ");
     scanf("%lf", &a1);

     printf("Entrer un nombre maximum : ");
     scanf("%lf", &b1);

     printf("Entrer la precision : ");
     scanf("%lf", &e);

     if (a1 >= b1 || e <= 0 || sign(g(a1)) == sign(g(b1)))
     {
          printf("Les nombres que vous avez entre sont incoherents ! \n");
          exit(1);
     }

     count = bissect(a1, b1, e, &zero);
     printf("a1 = %f b1 = %f et le zero est de %f. Trouvé en %d tentatives\n", a1, b1, zero, count);
}

//Function of G
double g(double x){
     return pow(x, 4) + pow(x, 3) + pow(x, 2) - 1;
}

//Function to know the sign of the variable
bool sign(double x){
     //return x/abs(x);
     return (x > 0) ? true : false;
}

int bissect(double a1, double b1, double e, double *zero){
     int i = 0;
     double c1;
     while (b1 - a1 > e || i > 300)
     {
          i++;
          c1 = (b1 + a1) / 2;
          if (sign(g(c1)) != sign(g(b1)))
          {
               a1 = c1;
          }else{
               b1 = c1;
          }
     }
     if(i<300){
          return -1;
     }
     *zero = c1;
     return i;
}
