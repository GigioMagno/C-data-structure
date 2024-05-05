
#include <stdio.h>
#include <stdlib.h>
#include "pqueue.h"
#define TEST 0

PQNode *pushPQ(PQNode *root, int id, double w) {
	if (root == NULL) {
		root = (PQNode *) malloc(sizeof(PQNode));
		root->id = id;
		root->w = w;
		root->left = root->right = NULL;
		return root;
	}

	if (w > root->w)
		root->right = pushPQ(root->right, id, w);
	else
		root->left = pushPQ(root->left, id, w);

	return root;
}

PQNode *popPQ(PQNode *root, int *pid, double *pw) {
	PQNode *rightp;
	if (root == NULL)
		return NULL;
	if (root->left) {
		root->left = popPQ(root->left, pid, pw);
		return root;
	}
	*pid = root->id;
	*pw = root->w;
	rightp = root->right;
	free(root);
	return rightp;
}

void printPQ(PQNode *root) {
	if (root != NULL) {
		printPQ(root->left);
		printf("%d %lf\n", root->id, root->w);
		printPQ(root->right);
	}
}

GPQNode *pushGPQ(GPQNode *root, void *data, double w) {

	if (root == NULL) {
		root = (GPQNode *) malloc(sizeof(GPQNode));
		root->data = data;
		root->w = w;
		root->left = NULL;
		root->right = NULL;
		return root;
	}

	if (w > root->w)
		root->right = pushGPQ(root->right, data, w);
	else
		root->left = pushGPQ(root->left, data, w);

	return root;
}

GPQNode *popGPQ(GPQNode *root, void **pdata, double *pw) {
	GPQNode *rightp;

	if (root == NULL) {
		*pdata = NULL;
		return NULL;

	}

	if (root->left) {
		root->left = popGPQ(root->left, pdata, pw);
		return root;
	}

	*pdata = root->data;
	*pw = root->w;
	rightp = root->right;
	free(root);

	return rightp;
}

#if TEST
#define DIM 10
int main() {
	GPQNode *root = NULL;
	double v[DIM];
	int n = DIM;
	double w, *res;


	for (n=0; n < DIM; n++) {
		v[n] = ((double) (rand() % 1000))/1000.0;
		root = pushGPQ(root, (void *) (v+n), v[n]);
	}

    printf("full pqueue\n");fflush(stdout);

	while (root) {
		root = popGPQ(root,(void **) &res, &w);
		printf("%lf\n",  w);
		fflush(stdout);
	}
}
#endif
