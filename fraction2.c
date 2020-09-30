#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

struct fract{
     int numerateur;
     int denominateur;
};

void displayFract(struct fract x);
int PGDC(struct fract x);
struct fract fractIrre(struct fract x);
struct fract powFract(struct fract x, int p);

struct fract userFunct();
struct fract fract_add(struct fract x, struct fract y);
struct fract fract_sub(struct fract x, struct fract y);
struct fract fract_mul(struct fract x, struct fract y);
struct fract fract_div(struct fract x, struct fract y);
struct fract fract_neg(struct fract x);
double fract_ToDouble(struct fract x);

int main(int argc, char **argv){
     struct fract nb1;
     struct fract nb2;
     char operator;

     sscanf(argv[1], "%d", &nb1.numerateur);
     sscanf(argv[2], "%d", &nb1.denominateur);
     sscanf(argv[4], "%d", &nb2.numerateur);
     sscanf(argv[5], "%d", &nb2.denominateur);
     sscanf(argv[3], "%c", &operator);

     switch (operator) {
          case '+':
          printf("L'addition de votre fraction est : ");
          displayFract(fract_add(nb1, nb2));
          break;

          case '-':
          printf("La soustraction de votre fraction est : ");
          displayFract(fract_sub(nb1, nb2));
          break;

          case ':':
          printf("La division de votre fraction est : ");
          displayFract(fract_div(nb1, nb2));
          break;

          case 'x':
          printf("L'addition de votre fraction est : ");
          displayFract(fract_mul(nb1, nb2));
          break;

          case '^':
          displayFract(fract_mul(nb1, nb2));
          break;


     }
}

void displayFract(struct fract x){
     printf("%d / %d \n", x.numerateur, x.denominateur);
}

int PGDC(struct fract x) {
     int pgdc = 1;
     if(x.numerateur == 0){
          pgdc = x.denominateur;
     }
     for (int div = x.numerateur; div >= 2 ;div--) {
          if (x.numerateur % div == 0 && x.denominateur % div == 0) {
               pgdc = div;
               break;
          }
     }
     if (pgdc == 0) {
          pgdc = x.denominateur;
     }
     return pgdc;
}

struct fract fractIrre(struct fract x){
     int pgdc = PGDC(x);
     x.numerateur /= pgdc;
     x.denominateur /= pgdc;
     return x;
}

struct fract powFract(struct fract x, int p){
     struct fract res;
     res.numerateur = pow(x.numerateur, p);
     res.denominateur = pow(x.denominateur, p);
     return fractIrre(res);
}

struct fract userFunct(){
     struct fract res;
     printf("Veuillez entrer un nombre pour le numerateur : ");
     scanf("%d", &res.numerateur);

     printf("Veuillez entrer un nombre pour le denominateur : ");
     scanf("%d", &res.denominateur);

     while (res.denominateur == 0) {
          printf("Veuillez entrer un nombre pour le denominateur : ");
          scanf("%d", &res.denominateur);
     }
     return res;
}

struct fract fract_add(struct fract x, struct fract y){
     struct fract res;
     res.numerateur = x.numerateur * y.denominateur + y.numerateur * x.denominateur;
     res.denominateur = x.denominateur * y.denominateur;
     return fractIrre(res);
}

struct fract fract_sub(struct fract x, struct fract y){
     struct fract res;
     res.numerateur = x.numerateur * y.denominateur - y.numerateur * x.denominateur;
     res.denominateur = x.denominateur * y.denominateur;
     return fractIrre(res);
}

struct fract fract_mul(struct fract x, struct fract y){
     struct fract res;
     res.numerateur = x.numerateur * y.numerateur;
     res.denominateur = x.denominateur * y.denominateur;
     return fractIrre(res);
}

struct fract fract_div(struct fract x, struct fract y){
     struct fract res;
     res.numerateur = x.numerateur * y.denominateur;
     res.denominateur = x.denominateur * y.numerateur;
     return fractIrre(res);
}

struct fract fract_neg(struct fract x){
     struct fract res;
     res.numerateur = -x.numerateur;
     res.denominateur = x.denominateur;
     return res;
}

double fract_ToDouble(struct fract x){
     return x.numerateur * 1.0 / x.denominateur;
}
