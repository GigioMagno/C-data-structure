#include <stdio.h>
 #define MAXLINE 1000 /* massima lunghezza di una linea di input */


 int mygetline(char line[], int max);

 int mystrindex(char source[], char searchfor[]);


 char pattern[]="ould"; /* stringa da ricercare */
 /* trova tutte le linee contenenti la stringa voluta */
 int main()
 {
 char line[MAXLINE];
 int found=0;

 while (mygetline(line, MAXLINE)>0)
 if (mystrindex(line, pattern)>=0)
 {
 printf("%s", line);
 found++;
 }
 return found;
 }


 /* getline: carica una linea in s, ritorna la lunghezza */
 int mygetline(char s[], int lim)
 {
 int c, i;
 i=0;
 while (--lim>0 && (c=getchar()) != EOF && c!='\n')
 s[i++]=c;
 if (c=='\n')
 s[i++]=c;
 s[i]='\0';
 return i;
 }


 /* strindex: ritorna l’indice di t in s, -1 se t non compare */

 int mystrindex(char s[], char t[])
 {
 int i, j, k;
 for (i=0; s[i]!='\0'; i++)
 {
 for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++) 
  ;
 if (k>0 && t[k]=='\0')
 return i;
 }
 return -1;
 }
