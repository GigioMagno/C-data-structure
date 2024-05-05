#include <stdio.h>
#define FALSE 0
#define TRUE 1

int scompare(char *a, char *b) {
  char **sa, **sb;
  sa = (char **) a;
  sb = (char **) b;
  return strcmp(*sa, *sb);
}

int dcompare(char *a, char *b) {
    double *da, *db;

    da = (double *) a;
    db = (double *) b;
    if (*da == *db) return 0;
    return (*da < *db) ? -1 : 1;
    
}

void ubsort(char *v, int dim, int size, int (*compare)()) {
  int i, j, ordinato=FALSE;
  char tmp;
  char *w;
  
  while(!ordinato) {
     dim--;
     ordinato=TRUE;
     w = v;
     for(i=0; i < dim; i++, w+=size) 
           if ((*compare)(w, w + size) > 0) {
              for(j=0; j < size; j++) {
                tmp = w[j];
                w[j] = w[j+size];
		w[j + size]= tmp;
               }
            ordinato = FALSE;
           }  
     }
}


void main() {
   double v[4] = {0.1, 3.1, 4.2, -1.0};
   int i;
   ubsort((char *) v, 4, sizeof(double), dcompare);
   for(i=0; i < 4; i++)
        printf("%lf\n", v[i]);
}
