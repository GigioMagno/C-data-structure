#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

main() {
   int *v, i, dim;

   printf("dim vettore ? ");
   scanf("%d", &dim);

   v = (int *) malloc(sizeof(int)*dim);


   v = (int *) calloc(dim,sizeof(int));

   for(i=0; i < dim; i++)
     v[i] = rand() % 100;
   for(i=0; i < dim; i++)
      printf("%d\n", v[i]);
   free(v);


}

