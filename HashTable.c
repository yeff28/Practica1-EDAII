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
        while (current != 0) {                  //Mientras haya un elemento en nuestra LinkedList
            if (current->ciudadanos.documento == id) {  //Si numero de documento es igual al que buscamos
                return current;                         //Devolvemos el Nodo actual
            }
            current = table->list[key].start;           //Vamos al siguiente elemento
        }
    }
    else{                                       //No hay ningun elemento en la posicion obtenida, por lo tanto no existe el ciudadano
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
    Node* aux = (Node *) malloc(sizeof (Node));         //Reservamos memoria
    if (aux == NULL) {                                  //No hay memoria disponible
        printf("No hay memoria disponible");            
        return false;
    } else {                                            //Si hay memoria disponible
        aux->ciudadanos = c;                            //Introducimos los dados del ciudadano nuevo
        if (table->list[key].start == 0) {              //Se trata del primer elemento de nuestra LinkedList
            table->list[key].start = aux;               //Indicamos que tenemos un nuevo elemento
            return true;
        } else {                                        //No se trata del primer elemento
            Node* current = table->list[key].start;     //Selecionamos el primer elemento
            while (current != 0) {                      //Mientras haya un elemento en nuestra LinkedList
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
    printf("Estoy en la funcion update\n");
    
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
