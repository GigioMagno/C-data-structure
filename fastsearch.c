#include <stdio.h>
#define max(a,b)   ((a) > (b) ? a : b)


int intcompare(char *a, char *b) {
    int *da, *db;

    da = (int *) a;
    db = (int *) b;
    if (*da == *db) return 0;
    return ((*da < *db) ? -1 : 1);
    
}


int fastsearch(int v[], int a, int b, int val) {
	int c;
	if (b < a)
		return -1;
	c = (a+b)/2;
	if (v[c]==val) return c;
	if (val > v[c])
		return fastsearch(v, c+1, b, val);
	else
		return fastsearch(v, a, c-1, val);
}

int ufastsearch(char *v,int a,int b,char *pval,int size,int (*compare)()) {
  int c, cmp;
	if (b < a)
		return -1;
	c = (a+b)/2;

        cmp = (*compare)(pval, v + (size*c));


	if (cmp==0) return c;
        if (cmp==1)
		return ufastsearch(v, c+1, b, pval, size, compare);
	else
		return ufastsearch(v, a, c-1 , pval, size, compare);

}

void main() {
        int v[] = { 0, 2, 4, 7, 9 , 100, 121, 200, 201, 1000};
	int val_da_cercare=121, indice;

	if ((indice=fastsearch(v, 0, 9, val_da_cercare)) >= 0)
	   printf("il valore %d si trova in corrispondenza dell'indice %d\n", val_da_cercare, indice);
	else
	   printf("valore non trovato!");
/////////////////////////////////////


       if ((indice=ufastsearch((char *)v, 0, 9, (char *) &val_da_cercare, sizeof(int), intcompare)) >= 0)
	   printf("il valore %d si trova in corrispondenza dell'indice %d\n", val_da_cercare, indice);
	else
	   printf("valore non trovato!");
        
        

}
