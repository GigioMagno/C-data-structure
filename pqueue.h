
#ifndef PQUEUE_H_
#define PQUEUE_H_

typedef struct node {
	int id;
	double w;
	struct node *left, *right;

} PQNode;
PQNode *pushPQ(PQNode *root, int id, double w);
PQNode *popPQ(PQNode *root, int *pid, double *pw);


typedef struct gnode {
	void *data; /*priority queue generica*/
	double w;
	struct gnode *left, *right;

} GPQNode;

GPQNode *pushGPQ(GPQNode *root, void *data, double w);
GPQNode *popGPQ(GPQNode *root, void **pdata, double *pw);


#endif /* PQUEUE_H_ */
