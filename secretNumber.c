#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
  srand(time(NULL));
  int rnd = rand();
  int rnd2 = 0;
  int avgTry = 0;
  int maxNb = 0;
  int userNb = 0;
  int nbTry = 0;

  printf("Entrer un nombre maximum : ");
  scanf("%d", &maxNb);

  int secretNb = rnd % maxNb + 1;
  rnd2 = secretNb;

  while (rnd2 != 0) {
    rnd2 /= 2;
    avgTry++;
  }

  do {
    nbTry++;
    printf("Entrer un nombre : ");
    scanf("%d", &userNb);
    if (userNb == secretNb) {
      printf("Bravo vous avez gagne ! Vous avez fait %d essais \n", nbTry);
      printf("Le nombre d'essaie optimale est de %d\n", avgTry);
      break;
    }else{
      if (userNb < secretNb && userNb > 0) {
        printf("Plus grand \n");
      }else{
        printf("Plus petit \n");
      }
    }
  }
  while (userNb != secretNb);
}
