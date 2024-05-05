#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "uniter.h"
#define MAX(a,b) ((a)>(b) ? a : b)


int getNextWord(FILE *fp, char *word);

typedef struct node {
	char parola[50];
	int val;
	struct node *left;
	struct node *right;
} Tnode;

typedef Tnode *Link;

void TSort(Link *root, char *string) {
	int cmp;

	if (*root == NULL) {
		*root = (Link) malloc(sizeof(Tnode));
		(*root)->val = 1;
		strncpy((*root)->parola, string, 40);
		(*root)->left = NULL;
		(*root)->right = NULL;
	} else {
		if (cmp = strcmp((*root)->parola, string))
			if (cmp > 0)
				TSort(&(*root)->right, string);
			else
				TSort(&(*root)->left, string);
		else
			(*root)->val++;

	}
}

void ShowTree(Link root) {
	if (root != NULL) {
		ShowTree(root->left);
		printf("%s %d\n", root->parola, root->val);
		ShowTree(root->right);
	}
}

int DeepTree(Link root) {
	if (root == NULL) {
		return 0;
	} else {
		return MAX(DeepTree(root->left), DeepTree(root->right) + 1);
	}
}

void main(int argc, char **argv) {
	FILE *fp;
	Link first = NULL;
	char str[100];
	int i, prof = 0;


#if 1
	fp = stdin;
#else
	if (argc < 2) {
		fprintf(stderr,"Usage %s filename\n",argv[0]);
		exit(-1);
	}

	if ((fp=fopen(argv[1],"r"))==NULL) {
		perror(argv[1]);
		exit(-1);
	}
#endif

	while (!getNextWord(fp, str))
		TSort(&first, str);
	fclose(fp);
	printf(CLR);
	ShowTree(first);

	printf("L'albero e' profondo: %d\n", DeepTree(first));
}
