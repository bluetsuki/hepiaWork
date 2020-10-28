/*
* fibonacci
*/

#include <stdio.h>

void fibonacci(int t1, int t2, int n);

int main(){

     int n = 0;
     int t1 = 0;
     int t2 = 1;

     printf("Enter a positive number: ");
     scanf("%d", &n);
     printf("Fibonacci Series: ");   // ex : 0, 1, 1, 2, 3, 5, 8, 13, ...

     fibonacci(t1, t2, n);
}

void fibonacci(int t1, int t2, int n){
     int nextTerm;

     printf("%d, ", t1);
     nextTerm = t1 + t2;
     t1 = t2;
     t2 = nextTerm;

     if (nextTerm >= n) {
          printf("%d\n", t1);
     }else{
          fibonacci(t1, nextTerm, n);
     }
}
