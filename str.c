#include <stdio.h>

char asciichars[37];

void fillascii() {
	int i;
	for (i = 0; i < 10; i++) {
		asciichars[i] = '0' + i;
	}

	for (i = 10; i < 36; i++) {
		asciichars[i] = 'A' + (i - 10);
	}

	asciichars[36] = '\0';
}

int strlen(char *s) {
	int len = 0;
	while (*s++)
		len++;
	return len;

}

void strcpy(char *s1, char *s2) {
	int i;
	for (i = 0; s2[i] != '\0'; i++)
		s1[i] = s2[i];
	s1[i] = '\0';
}

int myatoi(char *s, int base) {
	char c;
	int res = 0;
	while (c = *s++) {
		res *= base;
		res += c - '0';
	}
	return res;
}

int numcifre(int val, int base) {
	int count = 0;
	while (val) {
		val /= base;
		count++;
	}
	return count;
}

void myitoa(int val, char *res) {
	int i, n;
	if (val == 0) {
		res[0] = '0';
		return;
	}
	n = numcifre(val, 10);
	//printf("n = %d\n", n);

	for (i = n - 1; val; i--) {
		res[i] = (val % 10) + '0'; //res[i] = asciichars[val % 10];
		val /= 10;
	}

	res[n] = '\0';
}

char *strncpy(char *dest, const char *src, size_t n) {
	size_t i;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[i] = src[i];
	for (; i < n; i++)
		dest[i] = '\0';

	return dest;
}

void main() {
	char str[20];

	int val = 4242555, val2;
	fillascii();
	puts(asciichars);
	myitoa(val, str);
	printf("%d %s\n", val, str);
	val2 = myatoi(str, 8);
	printf("%d %s\n", val2, str);
}

