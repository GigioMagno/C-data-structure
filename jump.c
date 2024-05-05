#include <stdio.h>
#include <setjmp.h>
#include <signal.h>

jmp_buf ambiente;


se_interrupt()
{
 signal(SIGINT,se_interrupt);
 fprintf(stderr,"\nInterrupt\n");
 clearerr(stdin);
 longjmp(ambiente,1);
}




main()
{
 int variabile=0;
 char buf[80];
 int se_interrupt();

 if(setjmp(ambiente)==0)
 {
   puts("Sto salvando l'ambiente: prima esecuzione");
   printf("La variabile vale %d\n", variabile);
 }
 else
 {
   puts("Setjmp ritorna nonzero: dev'esserci stato un segnale!");
   printf("La variabile vale %d\n",variabile);
   exit(0);
 }
 signal(SIGINT,se_interrupt);

 variabile=1;
 printf("Valore della variabile %d\n",variabile);
 while(1)
 {
   gets(buf);
   puts(buf);
 }
}

