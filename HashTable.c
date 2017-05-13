#include <stdio.h>
#include <stdlib.h>
#include "HashTable.h"
#include "sort.h"

int hash_function(int key) {
    return key % N; // Nos devuelve la posicion del hash
}

void init_table(HashTable* table) {
    int i;
    for (i = 0; i < N; i++) {               //Nos movemos por nuestra tabla hash
        table->list[i].start = NULL;     //Indicamos que no tenemos ningun elemento en nuestra LinkedList 
    }
    table->num_ciudadanos = 0;
}

void clear_table(HashTable* table) {
    int i, key;

    for (i = 0; i < N; i++) {               //Nos movemos por nuestra TableHash
        if (table->list[i].start != NULL) { //Si nuestra LinkedList contiene algo procedemos a borrar los elementos
            Node* current = table->list[i].start;   //Nos situamos en el primer elemento de nuestra LinkedList
            clear_list(current);                    //Borramos todos los elementos de la LinkedList
        } else {    //Nuestra LinkedList no contiene nada
            printf("En la posicion %d esta vacio\n", i);    
        }
    }
}

Node* find_citizen_by_id(HashTable* table, int id) {
    Node* current;
    int key = hash_function(id);                //Averiguamos la posicion en nuestra TableHash
    if (table->list[key].start != NULL) {       //Si la posicion que hemos obtenido existe algun elemento
        current = table->list[key].start;       //Seleccionamos el primer elemento    
        while (current != NULL) {               //Mientras haya un elemento en nuestra LinkedList
            if (current->ciudadanos.documento == id) {  //Si numero de documento es igual al que buscamos
                return current;                         //Devolvemos el Nodo actual
            }
            current = current->next;                     //Vamos al siguiente elemento             
        }
    }
    else{                                               //No hay ningun elemento en la posicion obtenida, por lo tanto no existe el ciudadano
        current;
    }
}

bool exists_citizen_with_id(HashTable* table, int id) 
{
    Node* Ciudadano = find_citizen_by_id(table, id);    //Nos devuelve si a encontrado el ciudadano
    if(Ciudadano){                                      //Si la variable contiene algo, existe el ciudadano
        printf("Existe el ciudadano\n");
        return true;
    }
    else{                                               //De lo contrario el ciudadano no existe
        printf("No existe el ciudadano\n");
        return false;
    }
}

bool insert_citizen(HashTable* table, Citizen c) {
    int key = hash_function(c.documento);               //Averiguamos la posicion en nuestra TableHash
    int existe = exists_citizen_with_id(table, c.documento);
    if (existe == true){
        printf("El ciudadano ya existe\n");
        return false;
    }
    Node* aux = (Node**) malloc(sizeof (Node));         //Reservamos memoria
    if (aux == NULL) {                                  //No hay memoria disponible
        printf("No hay memoria disponible");
    } else {                                            //Si hay memoria disponible
        aux->ciudadanos = c;                            //Introducimos los dados del ciudadano nuevo
        aux->next = NULL;                               //El next del nuevo elemento es NULL
        table->num_ciudadanos++;
        if (table->list[key].start == NULL) {           //Se trata del primer elemento de nuestra LinkedList
            table->list[key].start = aux;               //Indicamos que tenemos un nuevo elemento
            return true;
        } else {                                         //No se trata del primer elemento
            Node* current = table->list[key].start;     //Selecionamos el primer elemento
            while (current->next != NULL){              //Mientras haya un next diferente a NULL
                current = current->next;                //Selecionamos el siguiente elemento
            }
            current->next = aux;                        //Ya no hay siguiente elemento, por lo tanto le indicamos que el siguiente elemento sera el que hemos creado
            return true;
        }
    }
}

bool delete_citizen_by_id(HashTable* table, int id) {
    printf("Estoy en la funcion delete_citizen\n");
    int key = hash_function(id);
    if (table->list[key].start != NULL) {
        printf("Procedo a borrar el ciudadano\n");
        Node* current = table->list[key].start;
        if(current->next == 0 && current->ciudadanos.documento == id){
            printf("Es el primer elemento\n");
            free(current);
            table->list[key].start = NULL;
            return true;
        }
        else{
            Node* previous = current;
            current = current->next;
            while (current != 0) {
                if (current->ciudadanos.documento == id) {
                    printf("He entrado dentro del if\n");
                    previous->next=current->next;
                    free(current);
                    return true;
                }
                previous = current;
                current = current->next;
            }
        }
    } else {
        printf("No puedo borrarlo\n");
        return false;
    }
}

bool insert_citizen_list(HashTable* table, int list_size) 
{
    Citizen c;
    while (list_size-- > 0){
        c = read_citizen();
        int insertado = insert_citizen(table, c);
        if(insertado){
            printf("Se ha introducido correctamente el ciudadano\n");
        }
        else{
            printf("El usuario con el dni %d ya se ha introducido \n", c.documento);
        }  
    }
}

bool update_citizen_info(HashTable* table, Citizen new_info) {
    
    Node* s = find_citizen_by_id(table, new_info.documento); //position
    if(s){
        printf("Existe\n");
        s->ciudadanos = new_info;
        printf(" %d ", s->ciudadanos.documento);
        return true;
    } else {
        printf("No Existe\n");
        return false;
    }
}

void print_sorted_citizens(HashTable* table) {
    int tam = table->num_ciudadanos;
    int i, j = 0;
    int DNIS[tam];
    Node* current;
    
    
    for (i = 0; i < N; i++){
            current = table->list[i].start;
            while (current != NULL) {
               
                DNIS[j] = current->ciudadanos.documento;
                j++;
                current = current->next;
            }
    }
    bubble_sort(DNIS, tam);
    for (i = 0; i < tam; i++) {
        current = find_citizen_by_id(table, DNIS[i]);
        printf("mi dni %d tiene el nombre de %s\n", current->ciudadanos.documento, current->ciudadanos.nombre);
    }
}

