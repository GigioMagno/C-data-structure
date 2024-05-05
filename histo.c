#include <stdio.h>
char *vowels = "aeiou";

#define boolean char

void gethisto(char *s, int histo[]) {
   char ch;
      

   while (ch = *s++)
     histo[ch]++;

  
}

void vowelsCount(char *s, int histo[]) {
  char ch;
     while (ch = *s++) 
          switch(ch) {
              case('a'): ;
              case('A'): histo[0]++;
             break;
              case('e'): histo[1]++;
             break;
              case('i'): histo[2]++;
             break;
              case('o'): histo[3]++;
             break;
              case('u'): histo[4]++;
             break;
             default: histo[5]++;
     }
}


int getIndex(boolean a, boolean b, boolean c, boolean d)  {
   int res=0;
   res |= a << 0;
   res |= b << 1;
   res |= c << 2;
   res |= d << 3;
}

int main() {
     int histo[6] = {0,0,0,0,0, 0};
     char *str="hallo world, aaa, ssns bb su iiii, iiioooaaaauu";
     int i;
     vowelsCount(str, histo);
     printf("vowels of string: %s\n", str);
     for(i=0; i < 5; i++)
        printf("%c => %d\n", vowels[i], histo[i]);


     int *andp={0, 0, 0, 1};


}
