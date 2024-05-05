 
#include <stdio.h>
unsigned  fattorialei(int n) {
	int i;
	unsigned  res=1;
	if (n < 2)
		return 1;
	for(i=2; i <=n; i++)
		res*=i;
	return res;
}

unsigned fattorialer(int n) {
	if (n < 2)
		return 1;
	return n *fattorialer(n-1);
}

int main() {
	int i;
	for(i=0; i < 20; i++)
	printf("fattoriale(%d) = %u = %u\n", i, fattorialei(i), fattorialer(i));
	return 0;
}
