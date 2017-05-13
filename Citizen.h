#ifndef CITIZEN_H
#define CITIZEN_H

#include "util.h"

#define MAX_NOM 20
#define MAX_APE 40

typedef struct{
        int dia;
        int mes;
        int any;
}sfecha;
    
typedef struct{
    int documento;
    char nombre[MAX_NOM];
    char apellido[MAX_APE];
    char sexo;
    sfecha fecha_nacimiento;
} Citizen;

Citizen read_citizen();
void print_citizen(Citizen c);

#endif
