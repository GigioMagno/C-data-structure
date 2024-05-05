#include <stdio.h>
#include <malloc.h>
#include <math.h>
#include "matrix.h"

void writePGM(unsigned char **mat, int nrows, int ncols) {
	int i, j, val;

	printf("P2\n");
	printf("%d %d\n%d\n", nrows, ncols, 255);

	for (i = 0; i < nrows; i++) {
		for (j = 0; j < ncols; j++) {

			printf("%3d ", mat[i][j]);
		}
		putchar('\n');
	}

}





void writePPM(unsigned char **mat[3], int nrows, int ncols) {
	int i, j, k, val;

	printf("P3\n");
	printf("%d %d\n%d\n", nrows, ncols, 255);

	for (i = 0; i < nrows; i++) {
		for (j = 0; j < ncols; j++) {
                   for (k = 0; k < 3; k++) 
			printf("%3d ", mat[k][i][j]);
		}
		putchar('\n');
	}

}

