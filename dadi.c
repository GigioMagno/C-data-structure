#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void dadi(int *a , int *b) {
  *a = (rand() % 6) + 1;
  *b = (rand() % 6) + 1;
 }

int main() {
  int i;
  int x, y;
  srand(time(NULL));

  for(i=0; i < 10; i++) {
     dadi(&x, &y);
     printf("%d %d\n", x, y);
   }
     
}
