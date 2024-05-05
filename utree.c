
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define max(a,b) ((a) > (b) ? (a) : (b))
#define NEW(t)  (t *) malloc(sizeof(t))

typedef struct node {
	void *val;
	int counter;
	struct node *left;
	struct node *right;
} Nodo;
typedef Nodo* Link;

int compstrings(char *a, char * b) {
	return strcmp(a, b);
}

int compintegers(int *a, int *b) {
	if (*a==*b) return 0;
	if (*a > *b) return 1;
	return -1;
}

Link tsort(Link root, void * dato, int(*compare)()) {
	int compres;
	if (root == NULL) {
		root = (Link) malloc(sizeof(Nodo));
		root->counter = 1;
		root->val = dato;
		root->left = NULL;
		root->right = NULL;
	} else {
		compres = (*compare)(dato, root->val);
		switch (compres) {
		case 0:
			root->counter += 1;
			break;
		case 1:
			root->right = tsort(root->right, dato, compare);
			break;
		case -1:
			root->left = tsort(root->left, dato, compare);
		}
	}
	return (root);
}

void showTreeStrings(Link root) {
	if (root != NULL) {
		showTreeStrings(root->left);
		printf("%s => %d\n", (char *) root->val, root->counter);
		showTreeStrings(root->right);
	}
}

int treeDeep(Link root) {
	if (root==NULL) return 0;
	return 1 + max(treeDeep(root->left), treeDeep(root->right));
}

int main() {
	Link first = NULL;
	char *str;
	int i;
    srand(time(NULL));
	for (i = 0; i < 300; i++) {
		str = (char *) malloc(10);
	    sprintf(str, "%02x", rand() % 20);
		first = tsort(first, str, compstrings);
	}
	showTreeStrings(first);
	printf("massima profondità dell'albero : %d\n", treeDeep(first));

	return 0;
}
