#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include "array.h"

int main(){
     srand(time(NULL));
     int size, nbUser, nbSearch;
     double avg;

     printf("Entrer une taille pour le tableau : ");
     scanf("%d", &size);

     int tab[size];
     addValue(size, tab);

     for (int i = 0; i < size; i++) {
          printf("tab[%d] = %d\n", i, tab[i]);
     }
     printf("\n");

     orderTab(size, tab);

     for (int i = 0; i < size; i++) {
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
     printf("La moyenne est de %.0f\n", round(avg));
     printf("La variance est de %.2f\n", getVariance(size, tab, avg));
     printf("La mediane est de %d\n", getMedian(size, tab));

     for (int k = 0; k < size; k++) {
          /* code */
     }
}
