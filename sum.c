#include <stdio.h> 
#include <stdlib.h>

int sum(int a, int b) {
 int res;
 int s, r;

do {
   s = a ^ b;
   r = a & b;
   a = s;
   b = r << 1;
} while (r != 0);

  return a;
}

void main() {
 int i, x = 345, y=811;
 for(i=0; i < 100; i++) {
      x = rand() % 10000;
      y = rand() % 10000;
      x -= 5000;
      y -= 5000;
      printf("%d %d\n", x+y, sum(y,x));
      
      }

}
