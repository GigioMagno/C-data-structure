#include <stdio.h>
#include <stdlib.h>
#define BUFSIZE 512
main(int argc, char *argv[])

{
 FILE *fr,*fw;
 char buff[BUFSIZE];
 int num;

 if (argc < 3) {
    fprintf(stderr,"Usage : %s file1 file2\n",argv[0]);
    exit(-1);
    }

 if ((fr = fopen(argv[1],"rb")) == NULL) {
    perror(argv[1]);
    exit(-1);
    }

 if ((fw = fopen(argv[2],"wb")) == NULL) {
    perror(argv[2]);
    exit(-1);
    }

    while ((num = fread(buff,1,BUFSIZE,fr)) == BUFSIZE) {
	printf("%d\n",num);
	fwrite(buff,1,num,fw);
	}

 fwrite(buff,1,num,fw);
 fclose(fr);
 fclose(fw);
}
