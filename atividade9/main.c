#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lista.h"

int main(int argc, char* argv[]){
    //Atividade 8 com alterações de char para float 
    // Cria alguns nós para testar a lista
    No* n0 = no(1.0, NULL);
    No* n1 = no(2.0, NULL);
    No* n2 = no(3.0, no(4.0, no(5.0, no(6.0, no(7.0, NULL)))));
    No* n3 = no(8.0, NULL);
    // Inserir nós na lista
    lista_inserir_no(n0, n2);
    lista_inserir_no(n0, n1);
    lista_inserir_no(n0, n3);
    lista_imprimir(n0);
    printf("\nqtd nos: %d", lista_quantidade_nos(n0));
    No* n_copia = lista_copiar(n0);
    printf("\n");
    lista_imprimir(n_copia); 
    lista_concatenar(n0, n_copia);
    printf("\n");
    lista_imprimir(n0);

    // Chamadas novas
    printf("\nVerificar existencia: %d", lista_verificar_existencia(n0, 1.0));
    printf("\nVerificar ocorrencias: %d", lista_verificar_ocorrencias(n0, 1.0));
    printf("\nImprimir inversa: ");
    lista_imprimir_inversa(n0);
    printf("\nInserir no i: ");
    lista_inserir_no_i(n0, 2, 9.0);
    printf("\n");
    lista_imprimir(n0);
    printf("\nRemover no i: ");
    lista_remover_no_i(n0, 2);
    printf("\n");
    lista_imprimir(n0);
    printf("\nRemover no: ");
    lista_remover_no(n0, 1.0);
    printf("\n");
    lista_imprimir(n0);

    //Atividade 9
    // Criar listas para teste de desempenho
    No* lista_nao_ordenada = NULL;
    No* lista_ordenada = NULL;

    FILE* file = fopen("1kk_rand_float.csv", "r");
    if (file == NULL) {
        printf("Não foi possível abrir o arquivo.\n");
        return 1;
    }

    float num;
    while (fscanf(file, "%f", &num) != EOF) {
        No* novo_no = no(num, NULL);
        lista_inserir_no(lista_nao_ordenada, novo_no);
        novo_no = no(num, NULL);
        lista_inserir_no_ordenado(lista_ordenada, novo_no);
    }

    fclose(file);

    // Medir tempo médio de inserção na lista não ordenada
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    printf("\n\nTempo de inicio: %f\n", ((double)start) / CLOCKS_PER_SEC);
    for (int i = 100000; i >= 1; i--) {
        No* novo_no = no(i * 1.0, NULL);
        lista_inserir_no_ordenado(lista_ordenada, novo_no);
    }
    end = clock();
    printf("Tempo de fim: %f\n", ((double)end) / CLOCKS_PER_SEC);
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Tempo medio de insercao na lista ordenada: %f segundos\n", cpu_time_used);


    // Medir tempo médio de inserção na lista ordenada
    start = clock();
    for (int i = 100000; i >= 1; i--) {
        No* novo_no = no(i * 1.0, NULL);
        lista_inserir_no_ordenado(lista_ordenada, novo_no);
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Tempo medio de insercao na lista ordenada: %f segundos\n", cpu_time_used);

    // Liberar memória alocada para as listas
    lista_liberar(lista_nao_ordenada);
    lista_nao_ordenada = NULL;
    lista_liberar(lista_ordenada);
    lista_ordenada = NULL;

    exit(0);
}