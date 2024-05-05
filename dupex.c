#include <stdio.h>
#include <fcntl.h>

main()
{
FILE *fp;
int fd;

if ((fp=fopen("prova.out","w"))==NULL) {
    perror("prova.out");
    exit(-1);
    }

fd = fileno(fp);

if(close(1) == -1){
   perror("close");
   exit(-1);
   }


 if(dup(fd) != 1 ){
   perror("dup");
   exit(-1);
   }

 if((fp=fdopen(fd,"w"))==NULL){
    perror("fdopen");
    exit(-1);
    }

  puts("!");

  close(fd);
}

