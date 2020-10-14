#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

int searchValue(int size, int tab[size], int nbUser){
     for (int i = 0; i < size; i++) {
          if (nbUser ==   tab[i]) {
               return tab[i];
          }
     }
     return false;
}

int getAverage(int size, int tab[size]){
     int res;
     for (int i = 0; i < size; i++) {
          res = res + tab[i];
     }
     return res / size;
}

double getVariance(int size, int tab[size], int avg){
     double res;
     for (int i = 0; i < size; i++) {
          res = res + (pow(tab[i] - avg, 2));
     }
     res = res * (1.0 / size);
     return res;
}

int getMedian(int size, int tab[size]){
     if (size % 2 == 0) {
          return (tab[(size - 1) / 2] + tab[size / 2]) / 2.0;
     }else{
          return tab[(size - 1) / 2];
     }
}
