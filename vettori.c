#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double module(double v[], int dim) {
   double m=0;
   int i;
   for(i=0; i < dim; i++)
      m += v[i]*v[i];
   return sqrt(m);
}

double dot(double v[], double w[], int dim) {
    double d=0;
    int i;
     for(i=0; i < dim; i++)
       d += v[i]*w[i];
    return d;
}

double normalize(double v[], int dim) {
   double m;
   int i;
   m = module(v,dim);
   for(i=0; i < dim; i++)
     v[i] /= m;
   return m;
}

void inversion(double v[], int dim)  {
  double tmp;
  int i, j, hdim;
 
  hdim = dim/2;
  for(i=0, j=dim-1; i < hdim; i++, j--){
      tmp = v[i];
      v[i] = v[j];
      v[j] = tmp;
    }
}

double euclidean(double v[], double w[], int dim) {
 double dist=0, diff;
 int i;

 for(i=0; i < dim; i++) {
   diff = v[i]-w[i];
   diff *= diff;
   dist += diff;
  }
 return (sqrt(dist));
}

void mediavett(double *v, double res[], int dim) {
  int i;
  res[0] = 0;
  
  res[2] = v[0];
  res[3] = v[0];
  for (i=0; i < dim; i++) {
    res[0] += v[i];
    if (v[i] < res[2]) res[2] = v[i];
    if (v[i] > res[3]) res[3] = v[i]; 
  }
  res[1] = res[0];
  res[0] /= dim;   
}

void fillvett(double v[], int dim) {
  int i;
  
  for (i=0; i < dim; i++)
     v[i] = ((double) rand())/RAND_MAX;
}

void concat(double v[], double w[], double r[], int dim1, int dim2) {
   int i;
   for(i=0; i < dim1; i++)
     r[i] = v[i];
   for(i=dim1; i < dim1+dim2; i++)
     r[i] = w[i-dim1];
}

void plot(double v[], int dim, double a) {
  int i, j;
  int k;
  for(i=0; i < dim; i++) {
       k = (int) floor(0.5 + a*v[i]);
       printf("%2d ", i);
       for(j=0; j < k; j++)
           putchar('#');
       printf(" %3.2lf\n", v[i]);
       
  }   
  putchar('\n');
}

void printvett(double v[], int dim) {
  int i;
  for (i=0; i < dim; i++) {
     printf("%3.2lf ", v[i]);
     if (((i+1) % 40)==0) putchar('\n');
   }
   putchar('\n');
}

void loadvett(double v[], int dim) {
   int i;
   for(i=0; i < dim; i++)
      scanf("%lf", v + i);
} 

#define DIM 10

int main() {
 double v[DIM], res[4];
 double avg;
 srand(time(NULL));

 fillvett(v, DIM);
 //printvett(v, DIM);
 plot(v, DIM, 15);
 inversion(v, DIM);

 //printvett(v, DIM);
 plot(v, DIM, 15);
 
 //printvett(v,DIM);
 //mediavett(v,res, DIM); 

 return 0;
}
