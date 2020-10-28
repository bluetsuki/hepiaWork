#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>
#include "fractions.h"

int main()
{
    fract *fractA = fractCreate(1, 1);
    fract *fractB = fractCreate(1, 1);

    for (int i = 2; i < 20; i++){
        printf("%d", i);
        fractB->denominateur=pow(i, 4);

        fractA = fract_add(fractA, fractB);
    }

    // fractA->denominateur /= 90;
    // fractA->numerateur = pow(fractA->numerateur, 0.25);

    free(fractB);
    displayFract(fractA);
    free(fractA);
}