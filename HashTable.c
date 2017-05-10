#include <stdio.h>
#include <stdlib.h>
#include "HashTable.h"
#include "sort.h"

int hash_function(int key) {
    return key % N; // position
}

void init_table(HashTable* table) {
    int i;
    for (i = 0; i < N; i++) {
        table->list[i].start = 0;
    }
}

void clear_table(HashTable* table) {
    int i, key;

    for (i = 0; i < N; i++) {
        if (table->list[i].start != NULL) {
            Node* current = table->list[i].start;
            clear_list(current);
        } else {
            printf("En la posicion %d esta vacio\n", i);
        }
    }
}

Node* find_citizen_by_id(HashTable* table, int id) {
    Node* current;
    int key = hash_function(id);
    
    if (table->list[key].start != NULL) {
        current = table->list[key].start;
        while (current != 0) {
            if (current->ciudadanos.documento == id) {
                return current;
            }
            current = table->list[key].start;
        }
    }
    else{
        current;
    }
}

bool exists_citizen_with_id(HashTable* table, int id) 
{
    Node* Ciudadano = find_citizen_by_id(table, id);
    if(Ciudadano){
        printf("Existe el ciudadano\n");
        return true;
    }
    else{
        printf("No existe el ciudadano\n");
        return false;
    }
}

bool insert_citizen(HashTable* table, Citizen c) {
    int key = hash_function(c.documento);
    Node* aux = (Node *) malloc(sizeof (Node));
    aux->ciudadanos = c;
    if (aux == NULL) {
        printf("No hay memoria disponible");
    } else {
        if (table->list[key].start == 0) {
            table->list[key].start = aux;
            return 1;

        } else {
            Node* current = table->list[key].start;
            while (current != 0) {
                current = current->next;
            }
            current->next = aux;
            return 0;
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
    printf("Estoy en la funcion update\n");
    
    Node* s = find_citizen_by_id(table, new_info.documento); //position
    printf("El documento es %d y el nombre es %s\n", s->ciudadanos.documento, s->ciudadanos.nombre);
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

void print_sorted_citizens(HashTable* table) 
{
    int i,j,aux;   
    int DNIs[N];
    
    for(i = 0; i < N; i++){
        //while(table->list[i] != 0){        
            Node *current = table->list[i].start;        
            while(current != 0){              
                DNIs[i] = current->ciudadanos.documento;//guarda el DNI            
                current = current->next;        
            }
        //}
    }
    for(i = 1;i < N; i++){
        aux = DNIs[i];
        j = i;
        //mientras j sea mayor que 0 y el DNI del siguiente sea menor que el primero
        while(j >= 0 && DNIs[j] < DNIs[j-1]){            
            
            DNIs[j] = DNIs[j-1];
            DNIs[j-1] = aux;
            j--;
        }
    
    
    for(i = 0;i < N; i++){
        printf("%i",DNIs[i]);
    }
    
}
}
