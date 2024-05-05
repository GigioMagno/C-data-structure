#include <stdio.h>
#include <stdlib.h>
//SEEK_SET, SEEK_CUR, SEEK_END
main() {
 FILE *fp;
 double v[5] = { 1,0.3,0.01,0.31416, 2.2};
 double w[5];
 int i, numel;
 double val;

 if ((fp=fopen("mydata.dat","wb+"))==NULL) {
    perror("mydata.dat");
    exit(-1);
 }
 numel=fwrite(v, sizeof(double), 5, fp);
 printf("%d values written on file %s\n", numel,"mydata.dat");
 //lettura del terzo valore scritto
 fseek(fp, sizeof(double)*2L, SEEK_SET);
 fread(&val, sizeof(double), 1, fp);
 printf("the third value written is %lf\n", val);
 fclose(fp);
 
 if ((fp=fopen("mydata.dat","rb"))==NULL) {
    perror("mydata.dat");
    exit(-1);
 }
  
 numel=fread(w, sizeof(double), 5, fp);
 printf("%d values loaded from file %s\n", numel, "mydata.dat");
 fclose(fp);
 for(i=0; i < 5; i++)
    printf("%lf %lf\n", v[i], w[i]);
}






