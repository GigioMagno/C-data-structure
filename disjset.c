 
#include <stdio.h>
#include <stdlib.h>
#include "tnode.h"


Tnode **init(int nnodes) {
	Tnode **sets;
	int i;
	sets = (Tnode**) calloc(nnodes, sizeof(Tnode*));

	for (i = 0; i < nnodes; i++) {
		sets[i] = pushPH(sets[i], i, i);
	}

	return sets;
}

int getSet(int node, int nsets, Tnode **sets) {
	double w;
	int i, id;

	for(i=0; i < nsets; i++) {
		if (node < sets[i]->w) return -1;
		if (findPH(sets[i], node, &id )==1)
			return i;
	}

	return -3;

}

int mergeSets(Tnode **sets, int s1, int s2, int nsets) {
	int i, smin, smax;

	if (s1 == s2) return nsets;
	smin = s1 < s2 ? s1 : s2;
	smax = s1 < s2 ? s2 : s1;

	sets[smin] = mergePH(sets[s1], sets[s2]);
	for (i=smax; i < nsets-1; i++)
		sets[i] = sets[i+1];


	sets[nsets-1] = NULL;
	return nsets -1;
}



#if TEST
int main() {
	Tnode **sets;
	int nnodes=16;
	int nsets;
    int s1, s2, i;

    nsets = nnodes;
    sets = init(nsets);

#if 1
	s1 = getSet(5, nsets, sets);
    s2 = getSet(11, nsets, sets);
    nsets = mergeSets(sets, s1, s2, nsets);

	s1 = getSet(0, nsets, sets);
    s2 = getSet(15, nsets, sets);
    nsets = mergeSets(sets, s1, s2, nsets);
    s2 = getSet(12, nsets, sets);
    nsets = mergeSets(sets, s1, s2, nsets);
#endif

    for(i=0; i < nnodes; i++)
	    printf("node %d -> set %d\n",i, getSet(i, nsets, sets));


}
#endif


