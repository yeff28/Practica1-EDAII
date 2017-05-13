#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Citizen.h"

#define N 1000          // number of slots in the hash table

typedef struct nodeElem{
    Citizen ciudadanos;
    struct nodeElem *next;
} Node;

typedef struct{
    Node *start;
} LinkedList;

void clear_list(Node* current);
void init_list(LinkedList lista[]);
Node* last_citizen(LinkedList* lista);
void insert_into_list(LinkedList* lista, Citizen c);

#endif
