#include "bubble_sort.h"
#include <string.h>
#define MaxTamanhoPalavra 100

void swap(char *PalavraA, char *PalavraB){
    char PalavraTemp[MaxTamanhoPalavra];
    strcpy(PalavraTemp, PalavraA);
    strcpy(PalavraA, PalavraB);
    strcpy(PalavraB, PalavraTemp);
}

void BubbleSort(char palavras[][MaxTamanhoPalavra], int NumElementos){
    int i, j;
    for (i = 0; i < NumElementos - 1; i++){
        for (j = 0; j < NumElementos - i - 1; j++){
            if (strcmp(palavras[j], palavras[j + 1]) > 0){
                swap(palavras[j], palavras[j + 1]);
            }
        }
    }
}