#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void matXvect(double** m, int nrows, int ncols, double* v, double* res) {
	int i, j;

	for (i = 0; i < nrows; i++) {
		res[i] = 0;
		for (j = 0; j < ncols; j++)
			res[i] += m[i][j] * v[j];
	}
}

void matXmat(double** m1, double** m2, double** mres, int nrows, int ncols, int dim) {
	int i, j, k;

	for (i = 0; i < nrows; i++)
		for (j = 0; j < ncols; j++) {
			mres[i][j] = 0.0;
			for (k = 0; k < dim; k++)
				mres[i][j] += m1[i][k] * m2[k][j];
		}

}

void matprint(double** m, int nrows, int ncols) {
	int i, j;
	for (i = 0; i < nrows; i++) {
		for (j = 0; j < ncols; j++)
			printf("%3.2f ", m[i][j]);
		putchar('\n');
	}
}


double **matalloc(int nrows, int ncols) {
	double **m;
	int i;

	m = (double **) calloc(nrows, sizeof(double *));

	for (i = 0; i < nrows; i++)
		m[i] = (double *) calloc(ncols, sizeof(double));

	return m;
}

double **matrand(int nrows, int ncols) {
	double **m;
	int i, j;

	m = (double **) calloc(nrows, sizeof(double *));

	for (i = 0; i < nrows; i++) {
		m[i] = (double *) calloc(ncols, sizeof(double));
		for (j = 0; j < ncols; j++)
			m[i][j] = ((double) rand()) / RAND_MAX;
	}

	return m;
}


char **mymatalloc(int nrows, int ncols, int typesize) {
	int i;
	char **m;
	m = (char**) calloc( nrows, sizeof(char *));
	for(i=0; i < nrows; i++)
		m[i] = (char *) calloc(ncols, typesize);
    return m;
}



#if 0
int main() {
	int nr=3, nc=4, dim =5;
	double **m1, **m2, **res;
	srand(0*time(NULL));
	m1 = matrand(nr, dim);
	m2 = matrand(dim, nc);
	//res = matalloc(nr, nc);

	res = (double**) mymatalloc(nr,nc,sizeof(double));

	matXmat(m1, m2, res, nr, nc, dim);
	matprint(res, nr, nc);
}
#endif
