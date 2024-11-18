#include "calculo.h"

float calcularMedia(float notas[], int numNotas) {
    float soma = 0;
    for (int i = 0; i < numNotas; i++) {
        soma += notas[i];
    }
    return soma / numNotas;
}


