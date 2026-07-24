#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define p printf
#define s scanf
#define _LONG 3


typedef struct
{
    int dia;
    int mes;
    int anio;
}Fecha;

typedef struct
{
    int cod;
    char nombre[30];
    float sueldo;
    Fecha nac;
}Empleado;

//PROTOTIPOS:
void cargarEmpleado(Empleado[]);
void mostrarEmpleados(Empleado[]);

int main(void)
{
    Empleado empleados[_LONG];
    cargarEmpleado(empleados);
    mostrarEmpleados(empleados);

    return 0;
}

void cargarEmpleado(Empleado emp[])
{
    for(int i=0;i<_LONG; i++)
    {
        emp[i].cod = i+1;
        p("Ingrese nombre del empleado con codigo %d: ", emp[i].cod);
        s("%[^\n]",emp[i].nombre);
        //gets(emp[i].nombre);
        p("Ingrese sueldo del empleado con codigo %d: $", emp[i].cod);
        s("%f", &emp[i].sueldo);
        p("Ingrese dia de nacimiento del empleado con codigo %d: ", emp[i].cod);
        s("%d", &emp[i].nac.dia);
        p("Ingrese mes de nacimiento del empleado con codigo %d: ", emp[i].cod);
        s("%d", &emp[i].nac.mes);
        p("Ingrese anio de nacimiento del empleado con codigo %d: ", emp[i].cod);
        s("%d", &emp[i].nac.anio);
        getchar();
    }
}

void mostrarEmpleados(Empleado emp[])
{
    for(int i=0;i<_LONG; i++)
    {
        p("\nCodigo del empleado: %d \n", emp[i].cod);
        p("Nombre del empleado: %s\n", emp[i].nombre);
        p("Sueldo del empleado: $%.2f\n", emp[i].sueldo);
        p("Fecha de nacimiento del empleado: %d/%d/%d\n", emp[i].nac.dia, emp[i].nac.mes, emp[i].nac.anio);
    }
}