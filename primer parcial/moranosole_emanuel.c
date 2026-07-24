/*
bingo.c
Alumno: Emanuel Morano Solé
Legajo:
Fecha: 24/06/2025
Descripción: Genera un boleto de bingo de 7 números,
             realiza un sorteo y calcula el promedio
             segun la cantidad de aciertos.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define NUMEROS 7

int numerosAleatorios();                          // Sacamos los numeros aleatorios
void generarticket(int v[]);                      // Cargamos los vectores boletodeBingo y sorteo
void mostrarBoleto(int v[]);                      // Mostramos
void mostrarSorteo(int v[]);                      // Mostramos
int cantidadAciertos(int boleto[], int sorteo[]); // Contamos aciertos
void premio(int aciertos);                        // Damos premios segun aciertos

int main() // funcion principal que contiene las funciones y variables de mi programa
{
    int boletodeBingo[NUMEROS], sorteo[NUMEROS];
    srand(time(NULL));                               // semilla aleatoria para que funcione bien el rand() y no arroje siempre los mismos numeros
    generarticket(boletodeBingo);                    // funcion que carga el vector boletodeBingo
    mostrarBoleto(boletodeBingo);                    // muestro el boleto del bingo
    generarticket(sorteo);                           // funcion que carga el vector sorteo
    mostrarSorteo(sorteo);                           // muestro los numeros del sorteo
    cantidadAciertos(boletodeBingo, sorteo);         // cantidad de aciertos que hay entre boleto y sorteo
    premio(cantidadAciertos(boletodeBingo, sorteo)); // condicional que nombra los premios

    return 0; // se termina el programa
}

int numerosAleatorios()
{
    return (rand() % 18) + 1;
}

void generarticket(int v[])
{
    for (int i = 0; i < NUMEROS; i++)
    {
        v[i] = numerosAleatorios();
        //creo que deberia inicializar v[0] primero y despues comparar que no se repita el num.
        
        /*if (v[0]==v[i])
        {
            
        }*/
        
    }

    
}

void mostrarBoleto(int v[])
{
    printf("\nBoleto generado: ");//muestro con for los datos
    for (int i = 0; i < NUMEROS; i++)
    {
        printf("%4d", v[i]);
    }
}

void mostrarSorteo(int v[])
{
    printf("\nNumeros sorteados:");//muestro con for los datos
    for (int i = 0; i < NUMEROS; i++)
    {
        printf("%4d", v[i]);
    }
}

int cantidadAciertos(int boleto[], int sorteo[])
{
    int aciertos = 0; //inicializo contador en 0 para que no haya datos basura

    for (int i = 0; i < NUMEROS; i++)
    {
        if (boleto[0] == sorteo[i])
        {
            aciertos++;
        }
        else if (boleto[1] == sorteo[i])
        {
            aciertos++;
        }
        else if (boleto[2] == sorteo[i])
        {
            aciertos++;
        }
        else if (boleto[3] == sorteo[i])
        {
            aciertos++;
        }
        else if (boleto[4] == sorteo[i])
        {
            aciertos++;
        }
        else if (boleto[5] == sorteo[i])
        {
            aciertos++;
        }
        else if (boleto[6] == sorteo[i])
        {
            aciertos++;
        }
    }

    return aciertos;
}

void premio(int aciertos)
{
    printf("\nCantidad de aciertos: %d", aciertos);
    if (aciertos == 7)
    {
        printf("\n¡Felicitaciones! Premio: $1400000");
    }
    else if (aciertos == 6)
    {
        printf("\n¡Felicitaciones! Premio: 20 por ciento del pozo");
    }
    else if (aciertos == 5)
    {
        printf("\n¡Felicitaciones! Premio: 3 por ciento del pozo");
    }
    else if (aciertos == 4)
    {
        printf("\n¡Felicitaciones! Premio: El valor del billete $5");
    }
    else
    {
        printf("\nNo hay premio");
    }
}