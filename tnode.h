

#ifndef TNODE_H_
#define TNODE_H_
#include <stdlib.h>


typedef struct tn {
	double w;
	int id;
	int degree;
    struct tnL *lowerNodes;
} Tnode;


typedef struct tnL {
  Tnode *tn;
  struct tnL *next;
} TnodeL;

Tnode *pushPH(Tnode *root, double w, int id);
Tnode *popPH(Tnode *root, double *pw, int *pid);
Tnode *peekPH(Tnode *root, double *pw, int *pid);
Tnode *mergePH(Tnode *root, Tnode *n);
int findPH(Tnode *root, double wx, int *pid);

#define drand (((double) rand())/RAND_MAX)
#endif /* TNODE_H_ */
