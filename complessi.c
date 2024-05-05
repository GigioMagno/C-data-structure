#include <stdio.h>
#include <math.h>
#include <stdlib.h>


typedef struct complex {
	double r, i;
} COMPLEX;



COMPLEX prod(COMPLEX a, COMPLEX b) {
	COMPLEX res;

	res.r = a.r*b.r - a.i*b.i;
	res.i = a.r*b.i + a.i*b.r;

	return res;
}

COMPLEX sum(COMPLEX a, COMPLEX b) {
	COMPLEX res;

	res.r = a.r+b.r;
	res.i = a.i+b.i;

	return res;
}

COMPLEX sub(COMPLEX a, COMPLEX b) {
	COMPLEX res;

	res.r = a.r-b.r;
	res.i = a.i-b.i;

	return res;
}

COMPLEX euler(double m, double t) {
	COMPLEX res;
	res.r = m*cos(t);
	res.i = m*sin(t);
	return res;
}


double arg(COMPLEX c) {
	return atan2(c.i, c.r);
}

double mod2(COMPLEX c) {
	return c.i*c.i + c.r*c.r;
}

double mod(COMPLEX c) {
	return sqrt(c.i*c.i + c.r*c.r);
}

COMPLEX conjugate(COMPLEX c) {
    COMPLEX res;
    res.r = c.r;
    res.i = -c.i;

    return res;
}

void printc(COMPLEX c) {
   printf("re = %lf, im = %lf\n", c.r, c.i);
}

#if 0
COMPLEX **loadCMat(char *fname, int *pnr, int *pnc) {
   FILE *fp;
   int chk, i, j;
   COMPLEX **m;
   fp = fopen(fname,"r");
   if (fp==NULL) {
      perror(fname);
      return NULL;
      }   
   chk = fscanf(fp,"%d %d", pnr, pnc);
   if (chk != 2) return NULL;
   m = (COMPLEX **) mymatalloc(*pnr, *pnc, sizeof(COMPLEX)); 
   for (i=0; i < *pnr;i++)
     for(j=0; j < *pnc; j++) {
         chk= fscanf(fp, "%lf %lf", &m[i][j].r, &m[i][j].i);
         if (chk != 2) return NULL;
     }

   fclose(fp);
   return m;   
}
#endif

int main() {
  COMPLEX x, y;
  x.r = 0.1;
  x.i=0.8;
  y.r = -0.9;
  y.i = 0.1;

  COMPLEX **v;
  v = (COMPLEX **) calloc(10, sizeof(COMPLEX *));

  return 0;
}
