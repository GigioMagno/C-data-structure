
#include <stdio.h>
#include <stdlib.h>

void hanoi(char p1, char p2, char p3, int n) {
	if (n==1)
		printf("sposta da %c a %c\n", p1, p3);
	else {
		hanoi(p1, p3, p2, n-1);
		hanoi(p1, p2, p3, 1);
		hanoi(p2, p1, p3, n-1);
	}
}





int main(int argc, char *argv[]) {
       int n=3;

        if (argc > 1)
            n = atoi(argv[1]);

	hanoi('A', 'B', 'C', n);

	return 0;


	
}
