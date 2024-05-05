
#include <stdio.h>
#include <string.h>
#define MAXL 100
int levmat[MAXL][MAXL];

int min3(int a, int b, int c) {
	if (a < b)
		return (a < c ? a : c);
	else
		return (b < c ? b : c);

}


