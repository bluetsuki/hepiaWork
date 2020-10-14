#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include "array.h"

int main(){
     srand(time(NULL));
     int size, a, i, j, nbUser, nbSearch, avg;

     printf("Entrer une taille pour le tableau : ");
     scanf("%d", &size);

     int tab[size];

     for (int i = 0; i < size; i++) {
          tab[i] = rand() % 10;
          printf("tab[%d] = %d\n", i, tab[i]);
     }
     printf("\n");

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
          printf("tab[%d] = %d\n", i, tab[i]);
     }

     printf("Entrer une valeur à trouver dans le tableau : ");
     scanf("%d", &nbUser);

     nbSearch = searchValue(size, tab, nbUser);
     if (nbSearch != false) {
          printf("%d\n", nbSearch);
     }else{
          printf("Valeur pas trouvé\n");
     }
     avg = getAverage(size, tab);
     printf("La moyenne est de %d\n", avg);
     printf("La variance est de %.2f\n", getVariance(size, tab, avg));
     printf("La mediane est de %d\n", getMedian(size, tab));

     for (int k = 0; k < size; k++) {
          /* code */
     }
}
