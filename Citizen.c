#include <stdio.h>
#include <string.h>
#include "Citizen.h"
#include "util.h"


Citizen read_citizen() {
    //char date[LINE_LENGTH];
    Citizen c;
    int correcto;
    char buffer[200];
    while(1){
       printf("Introduzca el numero de documento: \n");
       if(scanf("%d", &c.documento) != 1){
           printf("Se ha producido un error\n");
            scanf("%s", buffer);
       }
       else{
           if(c.documento > 9999999 && c.documento < 99999999){
                break;
           }
           else{
               printf("El numero de documento debe tener 8 digitos\n");
           }
       }
    }
    printf("Introduzca su nombre:\n");
    scanf("%s", c.nombre);
    printf("Introduzca su apellido:\n");
    scanf("%s", c.apellido);
   do{   
   printf("Introduzca su fecha de nacimiento(dd/mm/yyyy):\n");
   scanf("%d%*c%d%*c%d", &c.fecha_nacimiento.dia,&c.fecha_nacimiento.mes,&c.fecha_nacimiento.any);
   } while ((c.fecha_nacimiento.dia<0 || c.fecha_nacimiento.dia>30),(c.fecha_nacimiento.mes>12 || c.fecha_nacimiento.mes<0), (c.fecha_nacimiento.any>2017||c.fecha_nacimiento.any<1800));
    do{
   printf("Introduzca su sexo(M/F):\n");
    scanf(" %c", &c.sexo);
    }while(c.sexo != 'M' && c.sexo != 'F');
    return c;
}

void print_citizen(Citizen c) 
{
    printf("\n=============================\n");
    printf("DNI: %d\n",c.documento);
    printf("Nombre:%s\n",c.nombre);
    printf("Apellido:%s\n",c.apellido);
    printf("Sexo:%c\n",c.sexo);
    printf("Dia nacimiento:%d\n",c.fecha_nacimiento.dia);
    printf("Mes nacimiento:%d\n",c.fecha_nacimiento.mes);
    printf("Año nacimiento:%d\n",c.fecha_nacimiento.any);
    printf("=============================\n");
}
