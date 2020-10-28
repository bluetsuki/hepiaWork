#ifndef _ARRAY_H_
#define _ARRAY_H

void addValue(int size, int tab[size]);
void orderTab(int size, int tab[size]);
int searchValue(int size, int tab[size], int nbUser);
double getAverage(int size, int tab[size]);
double getVariance(int size, int tab[size], int avg);
int getMedian(int size, int tab[size]);

#endif
