#include <stdlib.h>
#include "LinkedList.h"

void clear_list(Node* current) {
    Node* aux;
    while (current != NULL) {
        aux = current->next;
        free(current);
        current = aux;
    }
}

void init_list(LinkedList lista[]){
    int i;
    
    for(i=0; i < N; i++){
        lista[i].start = NULL;
    }  
}

Node* last_citizen(LinkedList* lista){
    Node* current = lista->start;
    
    while (current->next != NULL){              //Mientras haya un next diferente a NULL
        current = current->next;                //Selecionamos el siguiente elemento
    }
    return current;
}

void insert_into_list(LinkedList* lista, Citizen c){
    Node* aux = (Node**) malloc(sizeof (Node));
    if (aux == NULL) {                                  //No hay memoria disponible
        printf("No hay memoria disponible");
    } else {
        aux->ciudadanos = c;                            //Introducimos los dados del ciudadano nuevo
        aux->next = NULL;
        if (lista->start == NULL) {           //Se trata del primer elemento de nuestra LinkedList
            lista->start = aux;               //Indicamos que tenemos un nuevo elemento
            return true;
        } else {                            //No se trata del primer elemento
            Node* current = last_citizen(lista);
            current->next = aux;                        //Ya no hay siguiente elemento, por lo tanto le indicamos que el siguiente elemento sera el que hemos creado
            return true;
        }
    }
}


