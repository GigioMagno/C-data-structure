#include <stdio.h>
int graytable[256];

int bintogray(int bin) {
   return (bin ^ (bin >> 1));
}

void filltable() {
  int i;
  for(i=0; i < 256; i++)
       graytable[bintogray(i)] = i;
 }


int graytobin(int val) {
   return graytable[val];
 }

main() {
  int i;
  for(i=0; i < 16; i++)
     printf("%x %x\n", i, bintogray(i));

}
