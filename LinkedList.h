#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Citizen.h"

typedef struct nodeElem{
    Citizen ciudadanos;
    struct nodeElem *next;
} Node;

typedef struct{
    Node *start;
} LinkedList;

/**
	TO DO
**/

#endif
