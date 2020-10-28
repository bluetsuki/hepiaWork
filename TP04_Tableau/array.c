#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

void addValue(int size, int tab[size]){
     for (int i = 0; i < size; i++) {
          tab[i] = rand() % 10;
          // printf("tab[%d] = %d\n", i, tab[i]);
     }
}

void orderTab(int size, int tab[size]){
     int i;
     int j;
     int a;

     for (i = 0; i < size; ++i)
     {
          for (j = i + 1; j < size; ++j)
          {
               if (tab[i] > tab[j])
               {
                    a =  tab[i];
                    tab[i] = tab[j];
                    tab[j] = a;
               }
          }
          // printf("tab[%d] = %d\n", i, tab[i]);
     }
}

int searchValue(int size, int tab[size], int nbUser){
     for (int i = 0; i < size; i++) {
          if (nbUser ==   tab[i]) {
               return tab[i];
          }
     }
     return false;
}

double getAverage(int size, int tab[size]){
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
