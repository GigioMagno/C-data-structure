
#include <stdio.h>
#include <stdlib.h>
#define DRAND (((double) rand())/RAND_MAX)

typedef struct node {
	double val;
	struct node *next;
} Nodo;

Nodo *push(double val, Nodo *lista) {
	Nodo *first;
	first = (Nodo *) malloc(sizeof(Nodo));
	first->val = val;
	first->next = lista;
	return first;
}

Nodo* pop(Nodo *lista, double *val) {
    Nodo *tmp;
	if (lista == NULL) {
		fprintf(stderr, "stack empty\n");
		return NULL;
	}
	*val = lista->val;
    tmp = lista->next;
    free(lista);
	return tmp;
}

double peek(Nodo *lista) {

	return lista->val;
}

void printall(Nodo *lista) {

	if (lista == NULL)
		return;
	printf("%lf\n", lista->val);
	printall(lista->next);
}

void printallR(Nodo *lista) {

	if (lista != NULL) {
	
	printallR(lista->next);
	printf("%lf\n", lista->val);
    }
}

int size(Nodo *lista) {
	if (lista == NULL)
		return 0;
	return 1 + size(lista->next);
}

void tovett(Nodo *lista, double *vett) {
	int i = 0;

	while (lista != NULL) {
		vett[i] = lista->val;
		lista = lista->next;
		i++;
	}

}

int main() {
	Nodo *listastack = NULL;
	int i;
	double val, vett[32];
	printf("elementi della lista:\n");
	for (i = 0; i < 6; i++)
		listastack = push(DRAND, listastack);

	printallR(listastack);
	printf("numero elementi: %d\n", size(listastack));
	/////////////////////////


	tovett(listastack, vett);
	printf("elementi del vettore:\n");
	for (i = 0; i < size(listastack); i++)
		printf("%lf\n", vett[i]);
	//////////////////////////////
	printf("elementi della lista letti dalla funzione pop:\n");
	while (listastack != NULL) {
		listastack = pop(listastack, &val);
		printf("%lf\n", val);
	}
	printf("numero elementi: %d\n", size(listastack));
	///////////////////////////////

}

