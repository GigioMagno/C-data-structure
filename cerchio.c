#include <stdio.h>
#include <math.h>
#include <malloc.h>
#include "netpbm.h"
#define RED 0
#define GREEN 1
#define BLUE 2

unsigned char *** writeCircle(int nr, int nc, int color) {
 int i, j, i0, j0, k;
 double dist, r;
 unsigned char ***m;

 m = (unsigned char***) calloc(3, sizeof(unsigned char**));

 for(i=0; i < 3; i++)
   m[i] = (unsigned char**) mymatalloc(nr, nc, sizeof(unsigned char));
 i0 = nr/2;
 j0 = nc/2;
 r = ((double) nr)/4.0;
 for(i=0; i < nr; i++) 
   for(j=0; j < nc; j++) {
       dist = sqrt((i-i0)*(i-i0) + (j-j0)*(j-j0));
       if (dist < r)
            m[color][i][j] = 255;     
       else 
           for(k=0; k < 3; k++)
             m[k][i][j] = 255;
       }

  writePPM(m, nr, nc);
  return m;
}

void main() {
 int nr=256,nc=256;

 writeCircle(nr, nc, RED);

}

