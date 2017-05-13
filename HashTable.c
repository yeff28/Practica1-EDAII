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
            table->list[i].start = NULL; 
        } 
    }
    table->num_ciudadanos=0;
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
    int key = hash_function(c.documento);               //Averiguamos la posicion en nuestra TableHash
    int existe = exists_citizen_with_id(table, c.documento);
    if (existe == true){
        return false;
    }
    insert_into_list(&table->list[key], c);
    table->num_ciudadanos++;
    return true;
}

bool delete_citizen_by_id(HashTable* table, int id) {
    int key = hash_function(id);
    
    if (table->list[key].start != NULL) {
        Node* current = table->list[key].start;
        if(current->next == NULL && current->ciudadanos.documento == id){
            free(current);
            table->list[key].start = NULL;
            table->num_ciudadanos--;
            return true;
        }
        else{
            Node* previous = current;
            current = current->next;
            while (current != 0) {
                if (current->ciudadanos.documento == id) {
                    previous->next=current->next;
                    free(current);
                    table->num_ciudadanos--;
                    return true;
                }
                previous = current;
                current = current->next;
            }
        }
    } else {
        return false;
    }
}

bool insert_citizen_list(HashTable* table, LinkedList* lista) 
{
    int i;
    for (i = 0; i < N; i++) {//Nos movemos por nuestra TableHash
        if (table->list[i].start != NULL && lista[i].start != NULL) { //Si nuestra LinkedList contiene algo procedemos a borrar los elementos
            Node* current = last_citizen(&table->list[i]);
            current->next=lista[i].start;
        } else {    //Nuestra LinkedList no contiene nada
            if(lista[i].start != NULL){
                table->list[i].start = lista[i].start;
            }
        }
    }
}

bool update_citizen_info(HashTable* table, Citizen new_info) {
    
    Node* s = find_citizen_by_id(table, new_info.documento); //position
    if(s){
        s->ciudadanos = new_info;
        return true;
    } else {
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
        print_citizen(current->ciudadanos); 
    }
}

