
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include "./levlib.h"
#define or ||


void Strrev(char *st) {
 int i, j, len;
 
 len = strlen(st);
 i = 0; j = len - 1;
 while (j > i) {
   st[i] ^= st[j]; st[j] ^= st[i]; st[i] ^= st[j];
   i++; j--;
 }
}


int Levenshtein( const char  *strA, const char *strB)
{
  int m1, m2, m3,  LD, min;
  int i, j, dimA, dimB, ntokA=0, ntokB=0;
  int **D;
  char *A, *B;
  static char *tokA[MAXNTOK], *tokB[MAXNTOK];

  A = strdup(strA); B = strdup(strB);
  assert(A != NULL); assert(B != NULL);
  
  ntokA = 0;
  tokA[ntokA] = strtok(A, " \t");
  while(tokA[ntokA]) {      
      if (tokA[ntokA][0]) ntokA++;
      tokA[ntokA] = strtok(NULL, " \t");
      if (ntokA >= MAXNTOK) break;   
  }
 
  ntokB = 0;
  
  tokB[ntokB] = strtok(B, " \t");
  while(tokB[ntokB]) {
      if (tokB[ntokB][0]) ntokB++;
      tokB[ntokB] = strtok(NULL, " \t");
      if (ntokB > MAXNTOK) break;      
  }

  
  /*for(i=0; i < ntokA; i++) printf("%s\n", tokA[i]);
    for(i=0; i < ntokB; i++) printf("%s\n", tokB[i]);*/
  dimA = ntokA; dimB = ntokB;

  D = (int **) calloc(dimA+1, sizeof(int *)); 
  for(i=0; i <= dimA; i++) 
    D[i] = (int *) calloc(dimB+1, sizeof(int));

  /******************************/
  D[0][0] = 0;
  for (i=1; i <= dimA; i++) 
    {D[i][0] = D[i - 1 ][0] + 1;}

  for (j=1; j <= dimB; j++)  
    {D[0][j] = D[0][j-1] + 1;}

 for (i=1; i <= dimA; i++)  {
     for (j=1; j <= dimB; j++)  {
      m1 = D[i-1][j-1] + ((strcmp(tokA[i-1], tokB[j-1])==0) ? 0 : 1);    
      m2 = D[i][j-1] + 1;
      m3 = D[i-1][j] + 1;
      min = m1;
      if (m2 < min) min = m2;
      if (m3 < min) min = m3; 
      D[i][j] = min;
    }
  }

  LD = D[dimA][dimB];   

  /******************************/
  free(A); free(B);  
  for(i=0; i <= dimA; i++) 
   free(D[i]);
  free(D);

 return LD;
}  

int MarkStringDiff(const char  *strA, const char *strB, char *seq)
{
  int m1, m2, m3,  LD, min, eqflag, s;
  int i, j, dimA, dimB, ntokA=0, ntokB=0;
  int **D;
  char *A, *B, **oper, op;
  static char *tokA[MAXNTOK], *tokB[MAXNTOK];

  A = strdup(strA); B = strdup(strB);
  assert(A != NULL); assert(B != NULL);
  
  ntokA = 0;
  tokA[ntokA] = strtok(A, " \t");
  while(tokA[ntokA]) {      
      if (tokA[ntokA][0]) ntokA++;
      tokA[ntokA] = strtok(NULL, " \t");
      if (ntokA >= MAXNTOK) break;   
  }
 
  ntokB = 0;
  
  tokB[ntokB] = strtok(B, " \t");
  while(tokB[ntokB]) {
      if (tokB[ntokB][0]) ntokB++;
      tokB[ntokB] = strtok(NULL, " \t");
      if (ntokB > MAXNTOK) break;      
  }

  dimA = ntokA; dimB = ntokB;
  D = (int **) calloc(dimA+1, sizeof(int *));
  oper = (char **) calloc(dimA+1, sizeof(char *)); 
  for(i=0; i <= dimA; i++) { 
    D[i] = (int *) calloc(dimB+1, sizeof(int));
    oper[i] = (char *) calloc(dimB+1, 1);
   }
  /******************************/
  D[0][0] = 0;
  for (i=1; i <= dimA; i++) 
    {D[i][0] = D[i - 1 ][0] + 1;}

  for (j=1; j <= dimB; j++)  
    {D[0][j] = D[0][j-1] + 1;}

 for (i=1; i <= dimA; i++)  {
     for (j=1; j <= dimB; j++)  {
      eqflag =  ((strcmp(tokA[i-1], tokB[j-1])==0) ? 0 : 1);
      m1 = D[i-1][j-1] + eqflag;    
      m2 = D[i][j-1] + 1;
      m3 = D[i-1][j] + 1;
      min = m1;
      if (m2 < min) min = m2;
      if (m3 < min) min = m3; 
      D[i][j] = min;
      
      if      (min == m2) { op = 'L' ;}
      else if (min == m3) { op = 'T'; }
      else { op = (eqflag == 0) ? 'S' : 'R';}
      oper[i][j] = op; 
    }
  }


  
  oper[0][0] = 'S';

  for (i=1; i <= dimA; i++) { oper[i][0] = 'T'; }
  for (j=1; j <= dimB; j++) { oper[0][j] = 'L'; }
  i = dimA; j = dimB;
  s = 0;
  while (1) {
     op = oper[i][j];
     if ((i>0) or (j>0)) {seq[s] = op; s++;}
     if ((op == 'S') or (op == 'R')) { i--; j--; } 
     else if (op == 'T') { i--; }
     else if (op == 'L') { j--; }
     if ((i < 0) or (j < 0)) { break; } 
  } 
  
  seq[s] = '\0';
  Strrev(seq);
  LD = D[dimA][dimB];   

  /******************************/
  
  free(A); free(B);  
  for(i=0; i <= dimA; i++) { 
   free(D[i]);
   free(oper[i]);
  }

  free(D);
  free(oper);
 return LD;
}  

#if 1
main() {

char *w1 = "My Taylor is almost rich s s s s s ss s s s";
char *w2 = "x x x My Taylor is very rich I suppose";
char *seq;
seq = (char *) calloc(100,1);
MarkStringDiff(w1, w2, seq);
printf("%s\n%s\n%s\n", w1, w2, seq);
 return 0;
}
#endif
