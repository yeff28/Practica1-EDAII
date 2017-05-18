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
        table->list[i].start = NULL;        //Indicamos que no tenemos ningun elemento en nuestra LinkedList 
    }
    table->num_ciudadanos = 0;              //Inicializamos el numero de ciudadanos
}

void clear_table(HashTable* table) {
    int i, key;

    for (i = 0; i < N; i++) {                           //Nos movemos por nuestra TableHash
        if (table->list[i].start != NULL) {         //Si nuestra LinkedList contiene algo procedemos a borrar los elementos
            Node* current = table->list[i].start;   //Nos situamos en el primer elemento de nuestra LinkedList
            clear_list(current);                    //Borramos todos los elementos de la LinkedList
            table->list[i].start = NULL; 
        } 
    }
    table->num_ciudadanos=0;
}

Node* find_citizen_by_id(HashTable* table, int id) {
    Node* current;
    int key = hash_function(id);                        //Averiguamos la posicion en nuestra TableHash
    if (table->list[key].start != NULL) {               //Si la posicion que hemos obtenido existe algun elemento
        current = table->list[key].start;               //Seleccionamos el primer elemento    
        while (current != NULL) {                       //Mientras haya un elemento en nuestra LinkedList
            if (current->ciudadanos.documento == id) {  //Si numero de documento es igual al que buscamos
                return current;                         //Devolvemos el Nodo actual
            }
            current = current->next;                     //Vamos al siguiente elemento             
        }
    }
    else{                                               //No hay ningun elemento en la posicion obtenida, por lo tanto no existe el ciudadano
        return NULL;
    }
}

bool exists_citizen_with_id(HashTable* table, int id) 
{
    Node* Ciudadano = find_citizen_by_id(table, id);    //Nos devuelve si a encontrado el ciudadano
    if(Ciudadano){                                      //Si la variable contiene algo, existe el ciudadano
        return true;
    }
    else{                                               //De lo contrario el ciudadano no existe
        return false;
    }
}

bool insert_citizen(HashTable* table, Citizen c) {
    int key = hash_function(c.documento);                   //Averiguamos la posicion en nuestra TableHash
    int existe = exists_citizen_with_id(table, c.documento);
    if (existe == true){                                    //Si existe, no lo introducimos el nuevo ciudadano
        return false;
    }
    insert_into_list(&table->list[key], c);                 //Introducimos el usuario a la lista
    table->num_ciudadanos++;                                //Sumamos un ciudadano mas
    return true;
}

bool delete_citizen_by_id(HashTable* table, int id) {
    int key = hash_function(id);                            //Averiguamos la posicion en nuestra TableHash
    
    if (table->list[key].start != NULL) {                   //Hay elementos en la posicion de la TableHash
        Node* current = table->list[key].start;             //Nos ubicamos en el primer elemento
        if(current->next == NULL && current->ciudadanos.documento == id){   //Estamos en el primer elemento
            free(current);                                                  //Hacemos free del elemento
            table->list[key].start = NULL;                                  //Inicializamos el primer elemento  
            table->num_ciudadanos--;                                        //disminuimos en 1 el numero de ciudadanos
            return true;
        }
        else{                                               //No estamos en primer elemento
            Node* previous = current;                       //Creamos un node auxiliar que contiene el node actual
            current = current->next;                        //Current apunta ahora al siguiente elemento
            while (current != NULL) {                       //Mientras no estemos en el ultimo elemento                         
                if (current->ciudadanos.documento == id) {  //Si el documento del nodo actual es igual al que buscamos  
                    previous->next=current->next;           //El anterior elemento apunta ahora al siguiente del que vamos borrar
                    free(current);                          //Borramos el elemento 
                    table->num_ciudadanos--;                //Disminuimos en un el numero de ciudadanos
                    return true;
                }
                previous = current;                         
                current = current->next;
            }
        }
    } else {                                                //No hay nada de esta posicion
        return false;
    }
}

bool insert_citizen_list(HashTable* table, LinkedList* lista) 
{
    int i;
    for (i = 0; i < N; i++) {                                           //Nos movemos por nuestra TableHash
        if (table->list[i].start != NULL && lista[i].start != NULL) {   //Si nuestra LinkedList contiene algo procedemos a borrar los elementos
            Node* current = last_citizen(&table->list[i]);              //Vamos al ultimo elemento          
            current->next=lista[i].start;                               //Indicamos que el next de ultimo elemento es star de la lista
        } else {                                                        //Nuestra LinkedList no contiene nada
            if(lista[i].start != NULL){                                 //Tenemos elementos en la lista, asi que los tenemos que introducir
                table->list[i].start = lista[i].start;                  //El start apuntar al star de la lista
            }
        }
    }
}

bool update_citizen_info(HashTable* table, Citizen new_info) {
    
    Node* s = find_citizen_by_id(table, new_info.documento); //Buscamos el elemento
    if(s){                                                   //Existe el node que queremos modificar
        s->ciudadanos = new_info;                            //Sobreescribimos los valores
        return true;    
    } else {                                                 //No existe el node que queremos modificar
        return false;
    }
}

void print_sorted_citizens(HashTable* table) {
    int tam = table->num_ciudadanos;
    int i, j = 0;
    int DNIS[tam];
    Node* current;
    for (i = 0; i < N; i++){                                //Nos movemos por toda la HashTable
            current = table->list[i].start;             
            while (current != NULL) {                       //Recorremos la LinkedList hasta que no hayan más ciudadanos
                DNIS[j] = current->ciudadanos.documento;    //Introducimos el documento en el array
                j++;
                current = current->next;
            }
    }
    bubble_sort(DNIS, tam);                                 //Ordenamos los DNIS
    
    for (i = 0; i < tam; i++) {                             //Recorremos el array
        current = find_citizen_by_id(table, DNIS[i]);       //Encontramos el elemento con el dni en el que estamos
        print_citizen(current->ciudadanos);                 //Mostramos por pantalla el ciudadano
    }
}

