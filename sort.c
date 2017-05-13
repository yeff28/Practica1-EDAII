#include <stdlib.h>

bubble_sort(int DNIS[], int tam){
    int i, aux;
    for (i = 0; i < tam; i++) {
        if(i != tam-1){
            if(DNIS[i] > DNIS[i+1]){
                    aux = DNIS[i];
                    DNIS[i] = DNIS[i+1];
                    DNIS[i+1] = aux;
            }
        }
    }
}