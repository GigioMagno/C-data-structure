 
#include <stdio.h>
#include <stdlib.h>

int main() {
	FILE *fp;
	char line[256], nome[256];
	int numero;
	char *fname = "testo.txt";
	fp = fopen(fname, "a+");
	if (fp == NULL) {
		perror(fname);
		exit(-1);
	}
	fprintf(fp, "matite 5\n");
	fprintf(fp, "quaderni 7\n");
	fprintf(fp, "libri 9\n");

	/********************************/
#if 1
	fclose(fp);
	fp = fopen(fname, "r");
	if (fp == NULL) {
		perror(fname);
		exit(-1);
	}
#else
	rewind(fp);
#endif

    while (fscanf(fp, "%s %d", nome, &numero) == 2)
    	printf("%s %d\n", nome, numero);

	fclose(fp);

}

