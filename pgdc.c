#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
     int n = 90;
     int m = 78;
     printf("n = %d et m = %d\n", n, m);

     int gdc = 1;
     for (int div=n; div>=2; div--) {
          if (n % div == 0 && m % div == 0) {
               gdc = div;
               break;
          }
     }
     printf("Le PGDC de %d et %d est %d\n", n, m, gdc);
}
