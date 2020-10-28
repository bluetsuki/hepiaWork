#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int ppmc_rec(int mult_n, int mult_m, int n, int m);
int puiss_ind(int a, int b);
int fib(int n);

int main() {
     printf("PPMC : %d\n", ppmc_rec(12, 15, 12, 15));
     printf("Puissance Indienne : %d\n", puiss_ind(3, 4));
     printf("Fibonacci : %d\n", fib(5));
}

int ppmc_rec(int mult_n, int mult_m, int n, int m){
     if (mult_n < mult_m) {
          return ppmc_rec(mult_n + n, mult_m, n, m);
     }else if (mult_m > mult_n) {
          return ppmc_rec(mult_n, mult_m + m, n, m);
     }else{
          return mult_n;
     }
}

int puiss_ind(int a, int b){
     if (0 == b) {
          return 1;
     }else if (b % 2 == 0) {
          int p = puiss_ind(a, b / 2);
          return p * p;
     }else{
          return puiss_ind(a, b - 1) * a;
     }
}

int fib(int n){
     switch (n) {
          case 0:
               return 0;
               break;

          case 1:
               return 1;
               break;

          default:
               return fib(n - 1) + fib(n - 2);
               break;
     }
}
