#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define PATH_MAX 512
int main() {

	FILE *fp;
	int status;
	char path[PATH_MAX];

	fp = fopen("namedfifo", "r");
	if (fp == NULL) {
		perror("popen failure");
		exit(-1);
	}

	do {
	while (fgets(path, PATH_MAX, fp) != NULL)
		printf("%s", path);
	 sleep(1);
	} while(1);
	fclose(fp);

}
