#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>
#include "tableau.h"

int main()
{
    srand(time(NULL));
    int size;
    int maxRand = 1;
    float variance;
    float median;
    float average;

    printf("Veuillez entrer une taille pour votre tableau : ");
    scanf("%d", &size);

    int tab[size];

    maxRand = size / 2;

    //add random value in the tab
    for (int i = 0; i < size; i++)
    {
        tab[i] = rand() % (maxRand + 1);
        printf("tab[%d]: %d \n", i, tab[i]);
    }

    printf("TRI: \n");
    tri_bulle_step(size, tab);

    for (int i = 0; i < size; i++)
    {
        printf("tab[%d]: %d \n", i, tab[i]);
    }

    average = getAverage(size, tab);
    printf("Average : %lf \n", average);
    variance = getVariance(size, tab);
    printf("Variance : %lf \n", variance);
    median = getMedian(size, tab);
    printf("Mediane : %lf \n", median);

    float tabProba[maxRand + 1];
    for (int i = 0; i < maxRand + 1; i++)
    {
        tabProba[i] = 0;
    }

    for (int i = 0; i < size; i++)
    {
        tabProba[tab[i]]++;
    }

    for (int i = 0; i < maxRand + 1; i++)
    {
        printf("Quantitée de %d : %.2f %% \n", i, tabProba[i] / (size * 1.0) * 100);
    }

    for (int i = 0; i < 102; i++)
    {
        printf("|");
        for (int j = 0; j < maxRand + 2; j++)
        {
            if(tabProba[j]>100-i-1 || tabProba<100-i+1){
                printf("-");
            }else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}
