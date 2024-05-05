#include <stdio.h>

double sommavalori(double v[], int dim) {
  double somma=0;
  int i;

  for(i=0; i < dim; i++)
    somma +=  v[i]; 

  return somma;
} 


main() {
   double vett[6] = {1.1, 0.9, 3.0, 3.2,1,0.01};
   double res;
   int dimensione;

   printf("quanti elementi ? ");
   scanf("%d", &dimensione);
   res = sommavalori(vett, dimensione);
     
   
   printf("la somma dei  primi %d valori del vettore è: %lf\n", dimensione, res);

}

