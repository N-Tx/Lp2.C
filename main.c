#include <stdio.h>
#include <string.h>
#include "calculo.h" 

#define MAX_ALUNOS 100


typedef struct {
    char nome[100];  
    float notas[3];  
    float media;      
} aluno;

float calcularMedia(float notas[], int numNotas) {
    float soma = 0;
    for (int i = 0; i < numNotas; i++) {
        soma += notas[i];
    }
    return soma / numNotas;
}

int main() {
    aluno turma[MAX_ALUNOS];
    int numAlunos = 0;
    int opcao;

    do {
        printf("Menu:\n");
        printf("1. Adicionar aluno\n");
        printf("2. Exibir alunos\n");
        printf("3. Atualizar notas do aluno\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                if (numAlunos < MAX_ALUNOS) {
                    printf("Digite o nome do aluno: ");
                    fgets(turma[numAlunos].nome, 100, stdin);
                    turma[numAlunos].nome[strcspn(turma[numAlunos].nome, "\n")] = '\0'; 
                    printf("Digite as 3 notas do aluno: \n");
                    for (int i = 0; i < 3; i++) {
                        printf("Nota %d: ", i + 1);
                        scanf("%f", &turma[numAlunos].notas[i]);
                    }
                    turma[numAlunos].media = calcularMedia(turma[numAlunos].notas, 3);
                    numAlunos++;
                } else {
                    printf("Numero maximo de alunos atingido.\n");
                }
                break;

            case 2:
                for (int i = 0; i < numAlunos; i++) {
                    printf("Aluno: %s\n", turma[i].nome);
                    printf("Notas: %.2f, %.2f, %.2f\n", turma[i].notas[0], turma[i].notas[1], turma[i].notas[2]);
                    printf("Media: %.2f\n\n", turma[i].media);
                }
                break;

            case 3:
                if (numAlunos > 0) {
                    int indice;
                    printf("Digite o indice do aluno (0 a %d): ", numAlunos - 1);
                    scanf("%d", &indice);
                    getchar();

                    if (indice >= 0 && indice < numAlunos) {
                        printf("Digite as novas 3 notas para o aluno %s: \n", turma[indice].nome);
                        for (int i = 0; i < 3; i++) {
                            printf("Nota %d: ", i + 1);
                            scanf("%f", &turma[indice].notas[i]);
                        }
                        turma[indice].media = calcularMedia(turma[indice].notas, 3);
                    } else {
                        printf("Indice invalido.\n");
                    }
                } else {
                    printf("Nao ha alunos cadastrados.\n");
                }
                break;

            case 0:
                printf("Saindo...\n");
                break;

            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}

