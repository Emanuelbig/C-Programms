/*
Ejercicio 01 – Gestión y control de stock diario en un minimercado
Un minimercado desea implementar un sistema que le permita controlar el stock de 10
productos distintos y realizar un análisis al finalizar cada jornada de ventas.

Cada producto posee:
• Un stock inicial, generado aleatoriamente entre 10 y 100 unidades.

• Un punto de pedido, que representa el nivel mínimo de stock aceptable antes de
necesitar reponer. 

Se calcula automáticamente como el 20% del stock inicial.

• Un tope de reposición, que indica el máximo nivel de stock permitido para evitar
sobrecarga. 

Se define automáticamente como un 20% más que el stock inicial.

Durante la jornada, se registran las ventas diarias, generadas también de forma aleatoria
o las pueden generar Uds. en forma manual, eso queda abierto a decisión de Uds., para
cada producto.

Las ventas no pueden superar el stock disponible.

Objetivos del sistema:
1. Cargar el stock inicial de los productos.
2. Calcular automáticamente el punto de pedido y el tope de reposición de cada
producto.
3. Generar las ventas del día (simuladas aleatoria o manualmente), de acuerdo con
las consignas indicadas anteriormente.
4. Actualizar el stock restante por cada venta realizada.
5. Informar:
o Cuáles productos quedaron por debajo del punto de pedido y requieren
reposición urgente mostrando los productos y cuanto hace falta reponer.
o Cuál o cuáles fueron los productos más vendidos del día (en cantidad de
unidades).
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

#define productos 10

int numAle();
void cargarStockinicial(int v[]);
void reposicion(int v[], int repo[], int tope[]);
void ventasdelDia(int v[], int ventas[]);
void mostrarInforme(int v[],int repo[],int tope[], int ventas[]);

int main()
{
    srand(time(NULL));
    int stock[productos];
    int puntodeRepo[productos], topedeRepo[productos];
    cargarStockinicial(stock);
    reposicion(stock,puntodeRepo,topedeRepo);
    int ventas[productos];
    ventasdelDia(stock, ventas);
    mostrarInforme(stock,puntodeRepo,topedeRepo,ventas);
}

int numAle()
{
    return (rand() % 91) + 1;
}

void cargarStockinicial(int v[])
{
    for (int i = 0; i < productos; i++)
    {
        v[i]=numAle();
    }
    
}

void reposicion(int v[], int repo[], int tope[])
{
    for (int i = 0; i < productos; i++)
    {
        repo[i]= v[i] *0.2;
        tope[i]= v[i] *1.2;
    }
    
}

void ventasdelDia(int v[], int ventas[])
{
    for (int i = 0; i < productos; i++)
    {
        ventas[i]= rand() % (v[i] + 1);
        v[i] -= ventas[i];
    }
    
}

void mostrarInforme(int v[],int repo[],int tope[], int ventas[])
{
    printf("Productos que necesitan reposicion urgente:\n");
    for (int i = 0; i < productos; i++)
    {
        if (v[i] < repo[i])
        {
            int faltante = tope[i] - v[i];
            printf("Producto %d, tiene stock actual %d, su punto de pedido %d, faltante %d\n",i+1,v[i],repo[i],faltante);
        }
        
    }

    //max de venta

    int maxventa = ventas[0];
    for (int i = 0; i < productos; i++)
    {
        if (ventas[i]>maxventa)
        {
            maxventa = ventas[i];
        }
        
    }

    printf("Producto mas vendido del dia:\n");

    for (int i = 0; i < productos; i++)
    {
        if (ventas[i]==maxventa)
        {
            printf("Producto %d con unidades vendidas: %d\n",i+1,maxventa);
        }
        
    }
        
}