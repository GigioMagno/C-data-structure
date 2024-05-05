#include <stdio.h>
#include <stdlib.h>
#define NUM 8

int posiz[NUM];

int TestPos(int tpos, int qr) {
	int issafe = 1, qi;

	for (qi = 0; (qi < qr) && issafe; qi++)
			if ((tpos == posiz[qi]) || (abs(qr - qi) == abs(posiz[qi] - tpos)))
				issafe = 0;

	return (issafe);
}

void PrintSolution() {
	int i, j;

	for (i = 0; i < NUM; i++) {
		for (j = 1; j < posiz[i]; j++)
			printf(" .");
		printf(" Q");
		for (j = posiz[i]+1; j <= NUM; j++)
			printf(" .");
		putchar('\n');
	}
	putchar('\n');
}

void PutRegina(int r) {
	int i;

	if (r >= NUM)
		PrintSolution();
	else
		for (i = 1; i < NUM + 1; i++)
			if (TestPos(i, r)) {
				posiz[r] = i;
				PutRegina(r + 1);
			}
	posiz[r] = 0;
}

void main() {
	int i;

	for (i = 0; i < NUM; i++)
		posiz[i] = 0;

	PutRegina(0);
}
