#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>
#include "tableau.h"

void tri_bulle_step(int size, int tab[size])
{
    for (int i = 0; i < size; i++) //Loop for ascending ordering
    {
        for (int j = 0; j < size; j++) //Loop for comparing other values
        {
            if (tab[j] > tab[i]) //Comparing other array elements
            {
                int tmp = tab[i]; //Using temporary variable for storing last value
                tab[i] = tab[j];  //replacing value
                tab[j] = tmp;     //storing last value
            }
        }
    }
}

bool value_exist(int size, int tab[size], int value)
{
    for (int i = 0; i < size; i++)
    {
        if (tab[i] == value)
        {
            return true;
        }
    }
    return false;
}

float getAverage(int size, int tab[size])
{
    float total;
    float average;

    for (int k = 0; k < size; k++)
    {
        total += tab[k];
    }

    average = total * 1.0 / size;
    return average;
}

float getVariance(int size, int tab[size])
{
    float variance = 1.0 / size;
    float Vaverage = getAverage(size, tab);
    float tempVariance = 0;

    for (int i = 0; i < size; i++)
    {
        tempVariance += pow((tab[i] - Vaverage), 2);
    }
    return variance * tempVariance;
}

float getMedian(int size, int tab[size])
{
    if (size % 2 == 0)
    {
        return (tab[(size - 1) / 2] + tab[size / 2]) / 2.0;
    }
    else
    {
        return tab[(size - 1) / 2];
    }
}