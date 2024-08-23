#include <stdio.h>

#define NUM_ATLETAS 5

typedef struct {
    char nome[50];
    char esporte[50];
    int idade;
    float altura;
} Atleta;

int main() {
    Atleta atletas[NUM_ATLETAS];
    Atleta *maisAlto;
    Atleta *maisVelho;

    for (int i = 0; i < NUM_ATLETAS; i++) {
        printf("Digite os dados do atleta %d:\n", i + 1);
        
        printf("Nome: ");
        scanf(" %[^\n]", atletas[i].nome);
        
        printf("Esporte: ");
        scanf(" %[^\n]", atletas[i].esporte);
        
        printf("Idade: ");
        scanf("%d", &atletas[i].idade);
        
        printf("Altura (em metros): ");
        scanf("%f", &atletas[i].altura);
    }

    maisAlto = &atletas[0];
    maisVelho = &atletas[0];

    for (int i = 1; i < NUM_ATLETAS; i++) {
        if (atletas[i].altura > maisAlto->altura) {
            maisAlto = &atletas[i];
        }
        if (atletas[i].idade > maisVelho->idade) {
            maisVelho = &atletas[i];
        }
    }

    printf("\nAtleta mais alto:\n");
    printf("Nome: %s\n", maisAlto->nome);
    printf("Esporte: %s\n", maisAlto->esporte);
    printf("Idade: %d anos\n", maisAlto->idade);
    printf("Altura: %.2f metros\n", maisAlto->altura);

    printf("\nAtleta mais velho:\n");
    printf("Nome: %s\n", maisVelho->nome);
    printf("Esporte: %s\n", maisVelho->esporte);
    printf("Idade: %d anos\n", maisVelho->idade);
    printf("Altura: %.2f metros\n", maisVelho->altura);

    return 0;
}
