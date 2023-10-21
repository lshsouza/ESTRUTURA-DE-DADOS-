#include <stdio.h>
#include <stdlib.h>

struct Ponto {
    int coordenadaX;
    float coordenadaY;
};

int main(int argc, char *argv[]) {
    (void)argc;

    int x = 0;
    float y = 0;
    int quantidade = 0;

    FILE *arquivo;
    arquivo = fopen(argv[1], "r");

    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    
    while (fscanf(arquivo, "%i,%f", &x, &y) != EOF) {
        quantidade++;
    }

   
    x = 0;
    y = 0;

   
    fseek(arquivo, 0, SEEK_SET);

    struct Ponto *pontos = (struct Ponto *)malloc(quantidade * sizeof(struct Ponto));
    if (pontos == NULL) {
        printf("Erro ao alocar memória");
        fclose(arquivo);
        return 1;
    }

    for (int i = 0; i < quantidade; i++) {
        fscanf(arquivo, "%i,%f", &pontos[i].coordenadaX, &pontos[i].coordenadaY);
        while (fgetc(arquivo) != '\n');
    }

    fclose(arquivo);

    int totalX = 0;
    float totalY = 0;
    for (int i = 0; i < quantidade; i++) {
        totalX += pontos[i].coordenadaX;
        totalY += pontos[i].coordenadaY;
    }

    float mediaX = (float)totalX / quantidade;
    float mediaY = totalY / quantidade;

    float somaXY = 0, somaXX = 0;
    for (int i = 0; i < quantidade; i++) {
        somaXY += (pontos[i].coordenadaX - mediaX) * (pontos[i].coordenadaY - mediaY);
        somaXX += (pontos[i].coordenadaX - mediaX) * (pontos[i].coordenadaX - mediaX);
    }

    float inclinacao = somaXY / somaXX;

    float intercepcao = mediaY - inclinacao * mediaX;

    printf("Quantidade de registros = %d\n", quantidade);
    printf("Media X = %.2f, Media Y = %.2f\n", mediaX, mediaY);
    printf("Inclinacao = %.2f\n", inclinacao);
    printf("Intercepcao = %.2f\n", intercepcao);
    printf("Resultado Final: Y = %.2f * X + %.2f\n", inclinacao, intercepcao);

    free(pontos);

    return 0;
    
}