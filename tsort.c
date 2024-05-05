#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int val;
	struct node *left;
	struct node *right;
} Nodo;

typedef Nodo* Link;


#define max(a,b)      ((a)  > (b) ? (a) : (b))

Link tsort(Link root, int num) {
	if (root == NULL) {
		root = (Link) malloc(sizeof(Nodo));
		root->val = num;
		root->left = NULL;
		root->right = NULL;
	} else {
		if (num > root->val)
			root->right = tsort(root->right, num);
		else
			root->left = tsort(root->left, num);
	}
	return (root);
}

void showTree(Link root)  {
	if (root != NULL) {
		showTree(root->left);
		printf("%d\n", root->val);
		showTree(root->right);
	}
}

int deepTree(Link root) {
   if (root==NULL)
        return 0;
   return (1 + max(deepTree(root->left), deepTree(root->right))); 
}

int main() {
	Link first = NULL;
	int i;

	for (i = 0; i < 30; i++)
		first = tsort(first, rand() % 1000);

	//showTree(first);
	return 0;
}
