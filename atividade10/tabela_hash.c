#include <stdlib.h>
#include <string.h>
#include "tabela_hash.h"

#define TAMANHO_TABELA 1000

char* tabela[TAMANHO_TABELA];


int hash(char* chave) {
   int hash = 0;
   for (int i = 0; chave[i]; i++) {
       hash += chave[i];
   }
   return hash % TAMANHO_TABELA;
}

char* hash_table_get(char* chave) {
   int indice = hash(chave);
   return tabela[indice];
}

void hash_table_put(char* chave, char* dado) {
   int indice = hash(chave);
   tabela[indice] = dado;
}

int hash_table_contains(char* chave) {
   int indice = hash(chave);
   return tabela[indice] != NULL;
}

void hash_table_remove(char* chave) {
   int indice = hash(chave);
   tabela[indice] = NULL;
}