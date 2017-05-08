#include <stdio.h>
#include <string.h>
#include "Citizen.h"
#include "util.h"

Citizen read_citizen() 
{
    //char date[LINE_LENGTH];
    Citizen c;
        printf("Introduzca el numero de documento: \n");
        scanf("%d", &c.documento);
        printf("Introduzca su nombre:\n");
        scanf("%s", c.nombre);
        printf("Introduzca su apellido:\n");
        scanf("%s", c.apellido);
        printf("Introduzca su fecha de nacimiento(dd/mm/yyyy):\n");
        scanf("%d%*c%d%*c%d", &c.fecha_nacimiento.dia, &c.fecha_nacimiento.mes, &c.fecha_nacimiento.any);
        printf("Introduzca su sexo(M/F):\n");
        scanf(" %c", &c.sexo);
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
