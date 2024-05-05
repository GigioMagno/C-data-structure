#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "uniter.h"
#define BSIZE 513
#define FNAME   "maze.txt"

struct lab {
	char **mat;
	int nrows, ncols;
} maze;

int numlines(char *fname, int *maxlen) {
	int numlines = 0, len;
	char buff[512];
	FILE *fp;
	*maxlen = 0;

	if ((fp = fopen(fname, "r")) == NULL) {
		perror(fname);
		exit(-1);
	}

	while (fgets(buff, BSIZE, fp)) {
		numlines++;
		len = strlen(buff);
		if (len > *maxlen)
			*maxlen = len;
	}

	fclose(fp);

	return numlines;
}

void read_maze(struct lab *pmaze, char *fname) {
	int i, j;
	char buff[BSIZE];
	FILE *fp;

    pmaze->nrows = numlines(fname, &pmaze->ncols);
    pmaze->mat = (char **) calloc(pmaze->nrows, sizeof(char *));

	if ((fp = fopen(fname, "r")) == NULL) {
		perror(fname);
		exit(-1);
	}

	for (i = 0; i < pmaze->nrows; i++) {
		fgets(buff, BSIZE, fp);
		buff[pmaze->ncols-1] = '\0';
		pmaze->mat[i] = (char *) calloc(pmaze->ncols,sizeof(char));
		strcpy(pmaze->mat[i], buff);
	}
	fclose(fp);
}

int safe(struct lab *pmaze, int i, int j) {
	if ((i >= pmaze->nrows) || (i < 0) || (j >= pmaze->ncols) || (j < 0))
		return 0;
	if ((pmaze->mat[i][j] != ' ') && (pmaze->mat[i][j] != '@'))
		return 0;
	return 1;
}

void view_maze(struct lab *pmaze) {
	int i, j;

	for (i = 0; i < pmaze->nrows; i++)
		for (j = 0; j < pmaze->ncols; j++) {
			cursor(i, j);
			putchar(pmaze->mat[i][j]);
		}
	putchar ('\n');
}

void maze_sol(struct lab *pmaze, int i, int j) {
	if (safe(pmaze, i, j))
		if (pmaze->mat[i][j] == '@') {
			cursor(i, j);
			putchar('$');
			putchar('\7');
			sleep(3);
		} else {
			pmaze->mat[i][j] = '+';
			cursor(i, j);
			pcolor(RED, "+");
			fflush(stdout);
			usleep(60000);
			maze_sol(pmaze, i + 1, j);
			maze_sol(pmaze, i - 1, j);
			maze_sol(pmaze, i, j + 1);
			maze_sol(pmaze, i, j - 1);
			pmaze->mat[i][j] = ' ';
			cursor(i, j);
			putchar(' ');
		}
}

void main(int argc, char *argv[]) {
	char *fname;

	if (argc < 2)
		fname = FNAME;
	else
		fname = argv[1];
	printf(HOME);
	printf(CLR);
	read_maze(&maze, fname);
	view_maze(&maze);
	maze_sol(&maze, 0, 0);
}

