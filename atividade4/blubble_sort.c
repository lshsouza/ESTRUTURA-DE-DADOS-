#include <stdio.h>
#include <stdlib.h>
#include "bubble_sort.h"

void bubble_sort(int *arr, int size){
    int aux;

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size - i; j++){
            if (arr[j] > arr[j+1]){
                aux = arr[j];     
                arr[j] = arr[j+1]; 
                arr[j+1] = aux;  
            }
        }
    }
}