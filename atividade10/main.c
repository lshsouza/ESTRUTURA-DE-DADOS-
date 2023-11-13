#include "tabela_hash.h"
#include <stdio.h>

int main()
{
    
    hash_table_put("Luis", "UC22102126");
    hash_table_put("Pedro", "UC22101838");
    hash_table_put("Lucas", "UC22101679");

   
    printf("Matricula de Luis: %s\n", hash_table_get("Italo"));
    printf("Matricula de Pedro: %s\n", hash_table_get("Kaua"));
    printf("Matricula de Lucas: %s\n\n", hash_table_get("Mirelle"));

    
    printf("Pedro esta na tabela? %d\n", hash_table_contains("Pedro"));
    printf("Luis esta na tabela? %d\n", hash_table_contains("Luis"));
    printf("Lucas esta na tabela? %d\n", hash_table_contains("Lucas"));
    printf("Camila esta na tabela? %d\n\n", hash_table_contains("Camila"));

    
    printf("Removendo Pedro da tabela...\n");
    hash_table_remove("Pedro");

   
    printf("Pedro esta na tabela? %d\n\n", hash_table_contains("Pedro"));

    
    printf("------------------CALCULANDO INDICE------------------\n");
    int hash1 = hash("Luis"); 
    hash_table_put("Luis", "UC22102126"); 
    printf("Hash de Luis: %d\n", hash1);

    int hash2 = hash("Pedro"); 
    hash_table_put("Pedro", "UC22101838"); 
    printf("Hash de Pedro: %d\n", hash2);

    int hash3 = hash("Lucas");
    hash_table_put("Lucas", "UC22101679");
    printf("Hash de Lucas: %d\n", hash3); 
}