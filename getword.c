#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#define FLAGEOF 1
int getNextWord(FILE *fp, char *word) {
 char c;
 int flageof=0;

 while ((!(flageof=feof(fp))) && (!isalpha(c=fgetc(fp))))
    ;
 ungetc(c,fp);
 while((!(flageof=feof(fp))) && isalpha(c=fgetc(fp))) {
   *word = c;
   word++;
   }
 *word = '\0';
 return(flageof);
}

#if 0
int main(int argc, char *argv[]) {
 FILE *fp;
 char *fname;
 char word[256];
 
 if (argc < 2) {
   fprintf(stderr,"usage: %s <filename>\n",argv[0]);
   exit(-1);
 }
 fname = argv[1];
 if ((fp=fopen(fname, "r"))==NULL) {
     perror(fname);
     exit(-1); 
     }
 
 while(getNextWord(fp, word)==0) {
   printf("%s\n", word);
 }
 
 fclose(fp);
 return 0;
}

#endif
