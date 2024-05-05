#include <stdio.h>
#define FALSE 0
#define TRUE 1



void bsort(double v[], int dim) {
  int i, ordinato=FALSE;
  double tmp;
  
  while(!ordinato) {
     dim--;
     ordinato=TRUE;
     for(i=0; i < dim; i++) 
           if (v[i] > v[i+1]) {
                tmp = v[i];
                v[i] = v[i+1];
		v[i+1]= tmp;
                ordinato = FALSE;
               }  

 }

}


void main() {
   double v[4] = {0.1, 3.1, 4.2, -1.0};
   int i;
   bsort(v,4);
   for(i=0; i < 4; i++)
        printf("%lf\n", v[i]);
}
