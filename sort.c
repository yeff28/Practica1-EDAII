#include <stdlib.h>

void bubble_sort(int DNIS[], int tam) {
    int i, aux, j;
    for (i = 0; i < tam; i++) {
        for (j = 0; j < tam; j++) {
            if (j != tam - 1) {
                if (DNIS[j] > DNIS[j + 1]) {
                    aux = DNIS[j];
                    DNIS[j] = DNIS[j + 1];
                    DNIS[j + 1] = aux;
                }
            }
        }
    }
}
