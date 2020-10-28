#ifndef _TABLEAU_H_
#define _TABLEAU_H_

void tri_bulle_step(int size, int tab[size]);
bool value_exist(int size, int tab[size], int value);
int index_min(int size, int tab[size], int i);
float getAverage(int size, int tab[size]);
float getVariance(int size, int tab[size]);
float getMedian(int size, int tab[size]);

#endif