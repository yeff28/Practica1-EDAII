#include <stdlib.h>
#include "LinkedList.h"

void clear_list(Node* current) {
    Node* aux;
    while (current != 0) {
        aux = current->next;
        free(current);
        current = aux;
    }
}
