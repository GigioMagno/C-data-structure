#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define BUFSIZE 512

void usage(char *argv[]) {
	fprintf(stderr, "Usage : %s -i file1 -o file2 -s chiave\n", argv[0]);
	exit(-1);
}

main(int argc, char **argv)

{
	FILE *fr, *fw;
	char buff[BUFSIZE];
	int i, num, seed;
    int ch;
    char f1[64], f2[64];

    while ((ch=getopt(argc, argv, "i:o:s:h"))!= -1) {
    	switch(ch) {
    	case 'i': strcpy(f1, optarg);
    	break;
    	case 'o': strcpy(f2, optarg);
        break;
    	case 's': seed= atoi(optarg);
    	break;
    	case 'h': usage(argv);
    	break;
    	default:
    	 fprintf(stderr, "unknown option: %c\n", ch);
    	}
    }

        srand(seed);

	if ((fr = fopen(f1, "rb")) == NULL) {
		perror(f1);
		exit(-1);
	}

	if ((fw = fopen(f2, "wb")) == NULL) {
		perror(f2);
		exit(-1);
	}

	while ((num = fread(buff, 1, BUFSIZE, fr)) > 0) {
	
		for(i=0; i < num; i++)
			buff[i] ^= rand();
		fwrite(buff, 1, num, fw);
	}


	fclose(fr);
	fclose(fw);
}
