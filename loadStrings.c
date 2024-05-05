#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **loadStrings(int nwords) {
	char **vstr, buff[512];
	int i;
	vstr = (char **) calloc(nwords, sizeof(char *));
	for(i=0; i < nwords; i++) {
		scanf("%s", buff);
		vstr[i] = (char *) calloc(strlen(buff)+1, sizeof(char));
		strcpy(vstr[i], buff);
	}
	return vstr;
}

void printStrings(char **words, int nwords) {
  int i;

  for(i=0; i < nwords; i++)
	  puts(words[i]);
}

void main() {
  int nwords;
  char **parole;
  puts("quante parole ?");
  scanf("%d", &nwords);
  printf("digita %d parole:\n", nwords);
  parole = loadStrings(nwords);
  printStrings(parole, nwords);

}

