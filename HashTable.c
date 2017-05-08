#include <stdio.h>
#include <stdlib.h>
#include "HashTable.h"
#include "sort.h"

int hash_function(int key) 
{ 
    return key % N; 
}

void init_table(HashTable* table) 
{
    /**
        Initializes an empty hashTable. Task 2.
    **/
}

void clear_table(HashTable* table) 
{
    /**
        Clears a hashTable. Task 2.
    **/
}

Node* find_citizen_by_id(HashTable* table, int id) 
{
    /**
        Given an ID, return the Node of the citizen. Task 2.
    **/
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
    /**
        Deletes an existing user that has ID id. Task 2
    **/
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
       s->value.documento = new_info.documento;
   }
   else{
       return 0;
   }
    
}


void print_sorted_citizens(HashTable* table) 
{
    
    /**
        Prints the Citizens info sorted by ID. Task 5
    **/
}
