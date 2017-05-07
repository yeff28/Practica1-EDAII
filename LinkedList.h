#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Citizen.h"

typedef struct nodeElem{
    int value;
    struct nodeElem *next;
} Node;

typedef struct{
    Node *start;
} LinkedList;

/**
	TO DO
**/

#endif
