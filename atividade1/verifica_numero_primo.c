#include <stdio.h>
#include <locale.h>

int main(int argc, char* argv[]){
    setlocale(LC_ALL,"");
    int num, i, resultado = 0;

   printf("Digite um numero da sua escolha: ");
   scanf("%d", &num);

   for (i= 2; i <= num / 2; i++){
     if (num % i == 0) {
        resultado ++;
        break;
     }

   }
   if(resultado == 0)
     printf("%d e um numero primo\n", num);
     else
     printf("%d nao e um numero primo\n", num);
     
return 0;
}