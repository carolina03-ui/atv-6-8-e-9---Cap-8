#include <stdio.h>

#define NUM_ALUNOS 5

typedef struct {
    int matricula;
    char nome[50];
    float notas[3];
} Aluno;

float calcularMedia(Aluno aluno) {
    return (aluno.notas[0] + aluno.notas[1] + aluno.notas[2]) / 3;
}

int main() {
    Aluno alunos[NUM_ALUNOS];
    Aluno *melhorAluno;
    float maiorMedia = 0.0;
    
    for (int i = 0; i < NUM_ALUNOS; i++) {
        printf("Digite os dados do aluno %d:\n", i + 1);
        
        printf("Número de matrícula: ");
        scanf("%d", &alunos[i].matricula);
        
        printf("Nome: ");
        scanf(" %[^\n]", alunos[i].nome);
        
        printf("Nota 1: ");
        scanf("%f", &alunos[i].notas[0]);
        
        printf("Nota 2: ");
        scanf("%f", &alunos[i].notas[1]);
        
        printf("Nota 3: ");
        scanf("%f", &alunos[i].notas[2]);
        
        float media = calcularMedia(alunos[i]);
        if (media > maiorMedia) {
            maiorMedia = media;
            melhorAluno = &alunos[i];
        }
    }
    
    printf("\nAluno com a maior média:\n");
    printf("Nome: %s\n", melhorAluno->nome);
    printf("Notas: %.2f, %.2f, %.2f\n", melhorAluno->notas[0], melhorAluno->notas[1], melhorAluno->notas[2]);
    printf("Média: %.2f\n", maiorMedia);
    
    return 0;
}
