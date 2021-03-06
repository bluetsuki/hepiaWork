#ifndef _FRACTIONS_H_
#define _FRACTIONS_H_

typedef struct fractions
{
    double numerateur;
    double denominateur;
} fract;

fract *fractCreate(double x, double y);

fract *powFract(fract *x, int p);

fract *userFract();
fract *fract_add(fract *x, fract *y);
fract *fract_sub(fract *x, fract *y);
fract *fract_mul(fract *x, fract *y);
fract *fract_div(fract *x, fract *y);
fract *fract_neg(fract *x);
double fract_ToDouble(fract *x);
void displayFract(fract *x);

#endif