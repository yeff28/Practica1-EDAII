#include <stdio.h>
#include <string.h>
#include "Citizen.h"
#include "util.h"

Citizen read_citizen() 
{
    char date[LINE_LENGTH];
    Citizen c;

    

    return c;
}

void print_citizen(Citizen c) 
{
    printf("DNI:%i\n",c.documento);
    printf("Nombre:%s\n",c.nombre);
    printf("Apellido:%s\n",c.apellido);
    printf("Sexo:%c\n",c.sexo);
    printf("Dia nacimiento:%i\n",c.fecha_nacimiento.dia);
    printf("Mes nacimiento:%i\n",c.fecha_nacimiento.mes);
    printf("Año nacimiento:%i\n",c.fecha_nacimiento.any);
}