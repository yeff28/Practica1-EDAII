#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "LinkedList.h"
#include "util.h"

#define N 1000          // number of slots in the hash table

typedef struct SOMETHING3 {
    int key;
    Citizen ciudadanos;      
} HashTable;

void init_table(HashTable* table);
void clear_table(HashTable* table);
bool insert_citizen(HashTable* table, Citizen c);
bool exists_citizen_with_id(HashTable* table, int id);
Node* find_citizen_by_id(HashTable* table, int id);
bool delete_citizen_by_id(HashTable* table, int id);
bool insert_citizen_list(HashTable* table, LinkedList* list);
bool update_citizen_info(HashTable* table, Citizen new_info);
void print_sorted_citizens(HashTable* table);

#endif
