/*
 * fsmsim.c
 */

#include <stdio.h>
#include <stdlib.h>
typedef unsigned char BYTE;

typedef struct {
	int status;
	int nstates, ninputsv;
	int **nextstatus;
	int **outputs;

} FSM;

int **matalloc(int nrows, int ncols);

int fsminit(FSM *rss, char *fname) {
	int chk, i, j;
	FILE *fp;
	fp = fopen(fname, "r");
	if (fp == NULL) {
		perror(fname);
		return -1;
	}
	chk = fscanf(fp, "%d %d", &rss->ninputsv, &rss->nstates);
	if (chk != 2) {
		perror(fname);
		return -1;
	} else {
		fprintf(stderr,"numero possibili inputs = %d\n",rss->ninputsv );
		fprintf(stderr,"numero possibili stati = %d\n",rss->nstates );
	}

	rss->nextstatus = matalloc(rss->ninputsv, rss->nstates);
	rss->outputs = matalloc(rss->ninputsv, rss->nstates);
	for (i = 0; i < rss->ninputsv; i++)
		for (j = 0; j < rss->nstates; j++)
			fscanf(fp,"%d", &rss->nextstatus[i][j]);
	for (i = 0; i < rss->ninputsv; i++)
		for (j = 0; j < rss->nstates; j++)
			fscanf(fp, "%d", &rss->outputs[i][j]);
	fclose(fp);
	return 0;
}

int fsmsim(FSM rss, int *inputs, int ninp) {
	int i, as, ns;
	for (i = 0; i < ninp; i++) {
		as = rss.status;
		ns = rss.nextstatus[inputs[i]][as];
                rss.status = ns;
		//rss.status = as ^ rss.nextstatus[inputs[i]][as]; toggle FF
		printf("%d  input=%x as=%x ns=%x output=%x\n", i, inputs[i], as,
				ns, rss.outputs[inputs[i]][as]);
	}

	return 0;
}  

int **matalloc(int nrows, int ncols) {
	int **m;
	int i;

	m = (int **) calloc(nrows, sizeof(int *));

	for (i = 0; i < nrows; i++)
		m[i] = (int *) calloc(ncols, sizeof(int));

	return m;
}
int main() {

	int inputvalues[10] = { 1, 0, 1, 1, 0, 1, 1, 0, 1, 0 };
	FSM f;

	f.status = 0;
    if (fsminit(&f, "fsm.txt")==0) {
    	fprintf(stderr, "fsm init ok\n");
    }

	fsmsim(f, inputvalues, 10);
    return 0;
}

