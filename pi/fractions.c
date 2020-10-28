#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>
#include "fractions.h"

double PGDC(fract *x);
fract *fractIrre(fract *x);

fract *fractCreate(double x, double y)
{
    fract *f = malloc(sizeof(fract));
    f->numerateur = x;
    f->denominateur = y;
    return fractIrre(f);
}

void displayFract(fract *x)
{
    printf("La valeur approximative de pi est %lf / %lf \n", x->numerateur, x->denominateur);
    double d = fract_ToDouble(x);
    printf("La valeur approximative de pi est %lf \n", d);
}

double PGDC(fract *x)
{
    double pgdc = 1;

    for (double div = x->numerateur; div >= 2; div--)
    {
        if (fmod(x->numerateur, div) == 0  && fmod(x->denominateur, div) == 0)
        {
            pgdc = div;
            break;
        }
    }
    return pgdc;
}

fract *fractIrre(fract *x)
{
    double pgdc = PGDC(x);

    fract *fracirr = malloc(sizeof(fract));
    fracirr->numerateur = x->numerateur / pgdc;
    fracirr->denominateur = x->denominateur / pgdc;

    free(x);
    return fracirr;
}

fract *powFract(fract *x, int p)
{
    fract *res = malloc(sizeof(fract));
    res->numerateur = pow(x->numerateur, p);
    res->denominateur = pow(x->denominateur, p);

    return fractIrre(res);
}

fract *fract_add(fract *x, fract *y)
{
    fract *res = malloc(sizeof(fract));
    res->numerateur = x->numerateur * y->denominateur + y->numerateur * x->denominateur;
    res->denominateur = x->denominateur * y->denominateur;
    return fractIrre(res);
}

fract *fract_sub(fract *x, fract *y)
{
    fract *res = malloc(sizeof(fract));
    res->numerateur = x->numerateur * y->denominateur - y->numerateur * x->denominateur;
    res->denominateur = x->denominateur * y->denominateur;
    return fractIrre(res);
}

fract *fract_mul(fract *x, fract *y)
{
    fract *res = malloc(sizeof(fract));
    res->numerateur = x->numerateur * y->numerateur;
    res->denominateur = x->denominateur * y->denominateur;
    return fractIrre(res);
}

fract *fract_div(fract *x, fract *y)
{
    fract *res = malloc(sizeof(fract));
    res->numerateur = x->numerateur * y->denominateur;
    res->denominateur = x->denominateur * y->numerateur;
    return fractIrre(res);
}

fract *fract_neg(fract *x)
{
    fract *res = malloc(sizeof(fract));
    res->numerateur = -x->numerateur;
    res->denominateur = x->denominateur;
    return res;
}

double fract_ToDouble(fract *x)
{
    double res = x->numerateur * 1.0 / x->denominateur;
    return res;
}
