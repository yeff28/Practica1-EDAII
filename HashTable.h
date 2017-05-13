#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "LinkedList.h"
#include "util.h"



typedef struct{
    LinkedList list[N];
    int num_ciudadanos;
} HashTable;

void init_table(HashTable* table);
void clear_table(HashTable* table);
bool insert_citizen(HashTable* table, Citizen c);
bool exists_citizen_with_id(HashTable* table, int id);
Node* find_citizen_by_id(HashTable* table, int id);
bool delete_citizen_by_id(HashTable* table, int id);
bool insert_citizen_list(HashTable* table, LinkedList* lista);
bool update_citizen_info(HashTable* table, Citizen new_info);
void print_sorted_citizens(HashTable* table);

#endif
