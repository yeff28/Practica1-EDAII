#include <stdlib.h>

void bubble_sort(int DNIS[], int tam) {
    int i, aux, j;
    for (i = 0; i < tam; i++) {
        for (j = 0; j < tam; j++) {
            if (j != tam - 1) {
                if (DNIS[j] > DNIS[j + 1]) {          //Si el dni de la posicion actual es más grande que el de la siguiente posicion, hacemos el cambio
                    aux = DNIS[j];                    //Guardamos el valor de dni actual en una var auxiliar
                    DNIS[j] = DNIS[j + 1];            //Sobreescribimos el dni actual por el de la siguiente posicion
                    DNIS[j + 1] = aux;                //Sobreescribimos el dni de la siguiente posicion, por el DNI de la anterior posicion
                }
            }
        }
    }
}
