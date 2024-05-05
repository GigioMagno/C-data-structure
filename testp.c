#include <stdio.h>
#include <stdlib.h>
#define PATH_MAX 512
int main() {

	FILE *fp;
	int status;
	char path[PATH_MAX];

	fp = popen("ls *", "r");
	if (fp == NULL) {
		perror("popen failure");
		exit(-1);
	}

	while (fgets(path, PATH_MAX, fp) != NULL)
		printf("%s", path);

	pclose(fp);

}

