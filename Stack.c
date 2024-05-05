#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
	double *s;
	int sindex, size;
} Stack;

Stack stack;

double pop() {
	if (stack.sindex > 0)
		return stack.s[--stack.sindex];
	else {
		fprintf(stderr, "stack underflow!\n");
		return 0;
	}
}

double peek() {

	if (stack.sindex > 0)
		return stack.s[stack.sindex - 1];
	else {
		fprintf(stderr, "stack underflow!\n");
		return 0;
	}
}

void push(double val) {
	if (stack.sindex < stack.size) {
		stack.s[stack.sindex] = val;
		stack.sindex++;
	} else
		fprintf(stderr, "stack overflow!\n");
}

void init(int size) {
	stack.size = size;
	stack.s = (double *) calloc(size, sizeof(double));
	stack.sindex = 0;
}


void print() {
  printf("%lf\n", peek());
}

void dup() {
	push(peek());
}

void swap() {
	double a, b;
	a = pop();
	b = pop();
	push(a);
	push(b);
}

int parse(char *inp) {
	char x;
	double val;

	if ((inp == NULL) || (strlen(inp) < 1)) {
	    print();
		return 0;
	}

	x = inp[0]; 

	switch (x) {
	case ('+'):
		push(pop() + pop());
		print();
		break;
	case ('-'):
		swap();
		push(pop() - pop());
		print();
		break;
	case ('*'):
		push(pop() * pop());
		print();
		break;
	case ('/'):
		swap();
		push(pop() / pop());
		print();
		break;
	case ('^') :
		push(pow(pop(), pop()));
	    print();
	    break;
	case ('s') :
		push(sin(pop()));
	    print();
		break;
	case (' ') :
		print();
		break;
	case ('q') :
		 return -1;
	default:
		val = atof(inp);
		push(val);
	}


	return 0;
}

void rpn() {
	char line[512];
	int chk;

	do {
		putchar('>');
		fflush(stdout);
		gets(line);
		chk=parse(line);
	} while (chk == 0);
}

int main() {
	int stacksize=8;
	init(stacksize);
	rpn();
	return 0;
}

