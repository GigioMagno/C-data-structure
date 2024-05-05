#include <stdio.h>
#include <stdlib.h>
    
    int estrazione(int sacchetto[], int last) {
    
    	int indice, estratto;
    	
//    	restituisce un numero casuale  >=0 e < last
    	indice = rand() % last; 
    	
//    	legge il valore presente all'i-esima locazione
    	estratto = sacchetto[indice]; 
    	sacchetto[indice] = sacchetto[last-1];
        //sacchetto[last-1] = estratto;  
    	return estratto;
    }






   void fillSacchetto(int sacchetto[], int dim) {
       int i;
	for(i=0; i < dim; i++)
          sacchetto[i] = i+1;
   }
	
    void main() {
	int i, sacchetto[90], last = 90;
        fillSacchetto(sacchetto, 90);
	for(i=1; i <= 90; i++) {
                  printf("estratto n. %d = %d\n", i, estrazione(sacchetto,last));
                  last--;
                  getchar();
                  }
	}


