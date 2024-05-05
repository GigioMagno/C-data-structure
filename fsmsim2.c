/*
 * fsmsim.c
 */

#include <stdio.h>
#define NINPUTS 1
#define NFF 2
#define NINPUTSV 2
#define NSTATES  4
typedef unsigned char BYTE;

typedef struct {
	int status;
	int (*nextstatus)[NSTATES];
	int (*outputs)[NSTATES];
	//int outputs[NSTATES];
} FSM;


int fsmsim(FSM rss, int *inputs, int ninp) {
    int i, as;
    for(i=0; i < ninp; i++) {
    	as = rss.status;
    	rss.status = rss.nextstatus[inputs[i]][as];
    	printf("%d  input=%x as=%x ns=%x output=%x\n",
    			i, inputs[i], as, rss.status,
    			rss.outputs[inputs[i]][as]);
    }

	return 0;
}

int main() {
    int rc[NINPUTSV][NSTATES] = {
			{ 0, 0, 3, 0 }, //input=0
			{ 1, 2, 2, 1 }, //input=1
	};

    int outputs[NINPUTSV][NSTATES] = {
    		{ 0, 0, 0, 0 },
    		{ 0, 0, 0, 1 },
    };

    int inputvalues[10] = { 1, 0, 1, 1, 0, 1, 1, 0, 1, 0 };

	FSM f;
	f.nextstatus = rc;
	f.outputs = outputs;
	f.status = 0;


    fsmsim(f, inputvalues, 10);




}

