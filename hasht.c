#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 64
#define NUMLISTE 1024

typedef struct node {
	char key[MAXLEN], val[MAXLEN];
	struct node *next;
} Nodo;

typedef struct {
	  Nodo **table;
	  int dim;
} HashTable;

/**************************/
Nodo *lput(char *key, char *val, Nodo *lista) {
		Nodo *first;
		first = (Nodo *) malloc(sizeof(Nodo));
		strcpy(first->key, key);
		strcpy(first->val, val);
		first->next = lista;
		return first;
	}

char *lget(char *key, Nodo *lista) {
	if (lista == NULL)
		return NULL;
	if (strcmp(key, lista->key)==0)
		return lista->val;
	return lget(key, lista->next);
}


/********************************/

HashTable htinit(int dim) {
	int i;
	HashTable ht;
	ht.dim = dim;
	ht.table = (Nodo **) calloc(dim, sizeof(Nodo *));

	for(i=0; i < dim; i++)
		ht.table[i] = NULL;
	return ht;
}



unsigned hashv(char *str) {
	int i;
	unsigned hval=0;
	srand(0);

	for(i=0; str[i]; i++) {
		hval += str[i] ^ rand();
	}

	return hval;
}

void put(char *key, char *val, HashTable ht) {
	unsigned index;
	index = hashv(key) % ht.dim;
	//printf("%s %s => %d\n", key, val, index);
	ht.table[index] = lput(key, val, ht.table[index]);
}

char * get(char *key, HashTable ht) {
	unsigned index;
	index = hashv(key) % ht.dim;
    return lget(key, ht.table[index]);
}


main() {
 HashTable ht;
 char *val, *key="book";
 ht = htinit(1024);

 put("book", "libro", ht);

 put("window", "finestra", ht);
 put("red", "rosso", ht);


 if ((val = get(key, ht))==NULL)
	 printf("non trovato\n");
 else
	 printf("%s => %s\n", key, val);

}
