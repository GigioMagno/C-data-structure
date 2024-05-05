#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
	double *s;

	int sindex, qindex, size;
} QueueStack;

QueueStack stack;

int cindex2(int i, int size) {
	int ci;

	return (i >=0 ? i % size :  (size + (i % size)) % size);
}

int cindex(int i) {

	return cindex2(i, stack.size);
}

double pop() {
	int ci;
	if (stack.sindex > (stack.qindex+1) ) {
		--stack.sindex;
		ci = cindex(stack.sindex);
		return stack.s[ci];
	}
	else {
		fprintf(stderr, "stack underflow!\n");
		return 0;
	}
}

void push(double val) {
	int ci;
	if ((stack.sindex - stack.qindex) <= stack.size) {
		ci = cindex(stack.sindex);
		stack.s[ci] = val;
		stack.sindex++;
	} else
		fprintf(stderr, "stack overflow!\n");
}


double popback() {
	int ci;
	if (stack.sindex > (stack.qindex+1) ) {
		++stack.qindex;
		ci = cindex(stack.qindex);
		return stack.s[ci];
	}
	else {
		fprintf(stderr, "stack underflow!\n");
		return 0;
	}
}

void pushback(double val) {
	int ci;
	if ((stack.sindex - stack.qindex) <= stack.size) {
		ci = cindex(stack.qindex);
		stack.s[ci] = val;
		--stack.qindex;
	} else
		fprintf(stderr, "stack overflow!\n");
}





void init(int size) {
	stack.size = size;
	stack.s = (double *) calloc(stack.size, sizeof(double));
	stack.sindex = (size/2)+1;
	stack.qindex = size/2;
}





int test(){
	int i, count = 30;
	init(10);


	printf("%d %d\n", stack.sindex, stack.qindex);
	while(count--) {
	for(i=0;i < 10; i++)
		push(i+1);
	for(i=0;i < 10; i++)
		printf("%lf\n", popback());

	printf("%d %d\n", stack.sindex, stack.qindex);
	}
	count = 30;
	while(count--) {
	for(i=0;i < 10; i++)
		pushback(i+1);

	for(i=0; i < 10; i++)
		printf("%lf\n", pop());


	printf("%d %d\n", stack.sindex, stack.qindex);
	}
	return 0;
}


int main() {
	test();
	return 0;
}

