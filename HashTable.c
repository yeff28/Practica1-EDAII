#include <stdio.h>
#include <stdlib.h>
#include "HashTable.h"
#include "sort.h"

int hash_function(int key) 
{ 
    return key % N;  // position
}

void init_table(HashTable* table) 
{
    int i;
    for(i=0; i<N; i++){
        table->list[i].start=0; 
    }
}

void clear_table(HashTable* table) 
{
    int i, key ;

    for(i=0; i<N; i++){
        if(table->list[i].start != NULL){
            Node* current = table->list[i].start;
            while(current != 0){
                table->list[i].start = current->next;
                free(current);
                current=table->list[i].start;
            }
        }
        else{
            printf("En la posicion %d esta vacio\n", i);
        }
    }   
}

Node* find_citizen_by_id(HashTable* table, int id) 
{
    int key = hash_function(id);
    if(table->list[key].start != NULL){
        Node* current = table->list[key].start;
        while(current != 0){
            if(current->ciudadanos.documento == id){
                return current;
            }
            current=table->list[key].start;
        }
    }
}

bool exists_citizen_with_id(HashTable* table, int id) 
{
    /**
        Checks if a citizen with ID id exists in the hashTable. Task 2.
    **/
}

bool insert_citizen(HashTable* table, Citizen c) 
{
    int key = hash_function(c.documento);
    Node* aux = (Node *) malloc (sizeof(Node));
    aux->ciudadanos = c;
    if(aux==NULL){
        printf("No hay memoria disponible");
    }else{       
        if(table->list[key].start == 0){
        table->list[key].start = aux;
        return 1;
    
        }else{
        Node* current = table->list[key].start;
        while(current != 0){
            current = current->next;
        } 
        current->next = aux;
        return 0;
        }
    }
}

bool delete_citizen_by_id(HashTable* table, int id) 
{
    int key = hash_function(id);
    if(table->list[id].start != NULL){
        Node* current = table->list[key].start;
        
        while(current != 0){
            if(current->ciudadanos.documento == id){
                free(current);
                return 1;
            }
            current=table->list[id].start;
        }
    }
    else{
        return 0;
    }
}

bool insert_citizen_list(HashTable* table, LinkedList* list) 
{
    /**
        Inserts a citizen list to the hash table. Task 3
    **/
}

bool update_citizen_info(HashTable* table, Citizen new_info) 
{
   int b;
   b = hash_function(new_info.documento );
   Node* s = find_citizen_by_id(table, b); //position
   if(s){
       s->ciudadanos.documento = new_info.documento;
       printf(" %d ", s->ciudadanos.documento);
   }
   else{
       return 0;
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
