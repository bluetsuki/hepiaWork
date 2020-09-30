#ifndef _FRACTION_H_
#define _FRACTION_H_


struct fract{
     int numerateur;
     int denominateur;
};

void displayFract(struct fract x);
struct fract powFract(struct fract x, int p);
struct fract userFunct();

struct fract fract_add(struct fract x, struct fract y);
struct fract fract_sub(struct fract x, struct fract y);
struct fract fract_mul(struct fract x, struct fract y);
struct fract fract_div(struct fract x, struct fract y);
struct fract fract_neg(struct fract x);
double fract_ToDouble(struct fract x);

#endif
