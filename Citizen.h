#ifndef CITIZEN_H
#define CITIZEN_H

#include "util.h"

#define MAX_NOM 20
#define MAX_APE 40
#define N 10

typedef struct{
        int dia;
        int mes;
        int any;
}sfecha;
    
typedef struct SOMETHING4{
    int documento;
    char nombre[MAX_NOM];
    char apellido[MAX_APE];
    char sexo;
    sfecha fecha_nacimiento;  
    int next;
} Citizen;

Citizen read_citizen();
void print_citizen(Citizen c);

#endif
