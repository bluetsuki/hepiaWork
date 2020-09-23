#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
     int n = 12;
     int m = 15;
     int multi_n = n;
     int multi_m = m;

     while (multi_n != multi_m) {
          if (multi_n > multi_m) {
               multi_m += m;
          }else if (multi_m > multi_n) {
               multi_n += n;
          }
     }
     printf("PPMC = %d", multi_m);
}
