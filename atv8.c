#include <stdio.h>
#include <string.h>

#define NUM_PESSOAS 6

typedef struct {
    char nome[50];
    int dia;
    int mes;
    int ano;
} Pessoa;

int comparaDatas(Pessoa p1, Pessoa p2) {
    if (p1.ano != p2.ano) {
        return p1.ano - p2.ano;  
    } else if (p1.mes != p2.mes) {
        return p1.mes - p2.mes; 
    } else {
        return p1.dia - p2.dia; 
    }
}

int main() {
    Pessoa pessoas[NUM_PESSOAS];
    Pessoa *maisVelha;
    Pessoa *maisNova;

    for (int i = 0; i < NUM_PESSOAS; i++) {
        printf("Digite os dados da pessoa %d:\n", i + 1);
        
        printf("Nome: ");
        scanf(" %[^\n]", pessoas[i].nome);
        
        printf("Dia de nascimento: ");
        scanf("%d", &pessoas[i].dia);
        
        printf("Mês de nascimento: ");
        scanf("%d", &pessoas[i].mes);
        
        printf("Ano de nascimento: ");
        scanf("%d", &pessoas[i].ano);
    }

    maisVelha = &pessoas[0];
    maisNova = &pessoas[0];

    for (int i = 1; i < NUM_PESSOAS; i++) {
        if (comparaDatas(pessoas[i], *maisVelha) < 0) {
            maisVelha = &pessoas[i];
        }
        if (comparaDatas(pessoas[i], *maisNova) > 0) {
            maisNova = &pessoas[i];
        }
    }

    printf("\nPessoa mais velha:\n");
    printf("Nome: %s\n", maisVelha->nome);
    printf("Data de nascimento: %02d/%02d/%d\n", maisVelha->dia, maisVelha->mes, maisVelha->ano);
    
    printf("\nPessoa mais nova:\n");
    printf("Nome: %s\n", maisNova->nome);
    printf("Data de nascimento: %02d/%02d/%d\n", maisNova->dia, maisNova->mes, maisNova->ano);

    return 0;
}
