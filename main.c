#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "HashTable.h"

int main() {
    int option = -1, id, list_size;
    Citizen c;
    HashTable table;
    LinkedList lista[N];

    init_table(&table);

    while (option != 7) {
        option = -1;
        printf("\n0. Clear all data.\n");
        printf("1. Find a citizen by ID.\n");
        printf("2. Insert a single citizen.\n");
        printf("3. Insert a list of citizens.\n");
        printf("4. Update data for an existing citizen.\n");
        printf("5. Delete a single citizen.\n");
        printf("6. Display all citizens in order of increasing ID.\n");
        printf("7. Exit\n\n");
        scanf("%d", &option);
        while(getchar() != '\n'){
            printf("Introduce un numero, no una letra\n");
        }
        switch (option) {
            case OPT_CLR:
                clear_table(&table);
                printf("Cleared!\n");
                break;

            case OPT_FIND:
                scan_line("Document number: ", "%i", &id);
                Node* p = find_citizen_by_id(&table, id);
                if (p) {
                    printf("Found!\n");
                    print_citizen(p->ciudadanos);
                }
                else {
                    printf("Not found!\n");
                };
                break;

            case OPT_INSERT_C:
                c = read_citizen();
                printf("Salimos de introducir usuario\n");
                if (insert_citizen(&table, c)) {
                    printf("Succeeded!");
                } 
                else {
                    printf("Error! A citizen with that id already exists.\n");
                };
                break;

            case OPT_INSERT_LIST:
                scan_line("Number of citizens to insert: ", "%i", &list_size);
                init_list(lista);
                printf("el numero de usuarios es %d\n", list_size);
                while (list_size-- > 0) 
                {
                     c = read_citizen();
                     int id = hash_function(c.documento);               //Averiguamos la posicion en nuestra TableHash
                     int existe = exists_citizen_with_id(&table, c.documento);
                     if (existe == true){
                        printf("El ciudadano ya existe\n");
                    }
                    else{
                        table.num_ciudadanos++;
                        insert_into_list(&lista[id], c);
                    }
                }

                insert_citizen_list(&table, &lista);

                break;

            case OPT_UPDT:
                c = read_citizen();
                if (update_citizen_info(&table, c)) {
                    printf("Succeeded!");
                } else {
                    printf("Error! No citizen with that id exists.\n");
                };
                break;

            case OPT_DELETE:
                scan_line("Document number: ", "%i", &id);
                if (exists_citizen_with_id(&table, id)) {
                    delete_citizen_by_id(&table, id);
                    printf("Deleted!\n");
                }
                else {
                    printf("Not found!\n");
                };
                break;

            case OPT_PRINT:
                print_sorted_citizens(&table);
                break;

            case OPT_EXIT:
                printf("Exiting!\n");
                break;

            default:
                printf("Invalid option.\n");
        }
        printf("======\n");
    }
    clear_table(&table);
    // clear_list(&list); 
    return 0;
}
