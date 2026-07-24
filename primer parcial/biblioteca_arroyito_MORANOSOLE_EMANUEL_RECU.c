/*
Organización de la Biblioteca Escolar de Ayacucho

En este desafío de programación, deberás crear un programa que asista a la bibliotecaria de la Escuela de Ayacucho 
en la organización de los 25 estantes disponibles en la biblioteca, 
donde por cada estante, solo cabe un libro. Recientemente, 
ha llegado 10 libros que deben ser acomodados siguiendo un patrón específico.

Reglas para la Asignación de Libros:

Identificación del Libro: Cada libro que llega se identifica por su código de ISBN, que, 
para nuestro ingreso, no utilizaremos el total del número, sino los últimos 4 dígitos, 
es un número entero aleatorio generado entre 1000 y 9999 (inclusive).

    Regla de Ubicación de los libros:

        Si el código ISBN es par, el libro se colocará en un estante par.
        Si el código ISBN es impar, el libro se colocará en un estante impar.

    Numeración de Estantes:
        Los 25 estantes están numerados del 0 al 24. Por lo tanto:

        Los estantes pares son: 0, 2, 4, ..., 24.
        Los estantes impares son: 1, 3, 5, ..., 23.

    localización de Estantes vacíos:
        Si el estante inicial asignado según sea par o no, ya está ocupado, es decir, 
        ya contiene al menos un libro, tu programa debe buscar el siguiente estante disponible 
        que cumpla on la regla de Ubicación de los libros.

Alumno: Emanuel Morano Solé
fecha: 15-07-2025
Recuperatorio 1er Parcial

*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h> // Para usar el tipo bool

#define CAP_TOTAL_ESTANTES 25 // Cantidad de CAP_TOTAL_ESTANTES disponibles
#define LIBROS 10          // Cantidad de libros a cargar
void utf8();
void LimpiarPantalla();
//void CargarLibros(int vec[]); // Prototipo de la función para cargar los libros
void Mostrar_libros_en_ESTANTES(int vec[]); // Prototipo de la función para mostrar los libros en los CAP_TOTAL_ESTANTES

/*
--------------------------mi parte-------------------------------
número entero aleatorio generado entre 1000 y 9999 (inclusive)*/
int numAleatorio();
int ExisteValor(int num, int v[], int tam);
void CargarLibros(int v[], int tam);

/*-------------------------------------------------------------*/
int main()
{

    int vec[CAP_TOTAL_ESTANTES]={0}; // Vector Estante, donde se almacenaran los libros
    srand(time(NULL)); // Inicializar la semilla para números aleatorios
    utf8(); // Configurar la consola para UTF-8
    LimpiarPantalla(); // Limpiar la pantalla para una mejor visualización
    CargarLibros(vec,LIBROS); // Llamar a la función para cargar los libros en los CAP_TOTAL_ESTANTES

    Mostrar_libros_en_ESTANTES(vec); // Llamar a la función para mostrar los libros en los estantes ocupados y vacios
    
}

void Mostrar_libros_en_ESTANTES(int vec[])
{
    printf("\nLibros en los Estantes:\n");
    for (int i = 0; i < CAP_TOTAL_ESTANTES; i++)
    {
        if (vec[i] != 0) // Si el compartimiento tiene un libro es porque es diferente de cero
        {
            printf("Estante: %2d: Libro ISBN %4d\n", i, vec[i]);
        }
        else // Si el compartimiento está vacío
        {
            printf("Estante: %2d: ---- Vacío ----\n", i);
        }
    }
}

 /*void CargarLibros(int vec[])
 {
    // desarrollar el codigo, si necesita crear funciones adicionales a esta, puede hacerlo
 }
*/
void utf8()
{
#ifdef _WIN32
	system("chcp 65001");
#endif
}

void LimpiarPantalla() // limpa la consola para los dos sistemas operativos
{
#ifdef _WIN32
    system("cls");
#endif
#ifdef __linux__
    system("clear");
#endif
}

/*-------------------mi parte-----------------------------------------------------*/

int numAleatorio()
{
    return (rand() % 8999 )+ 1000 ;
}

int ExisteValor(int num, int v[], int tam) // Funcion para verificar si el numero ya existe en el vector
{
    // aclaro el Tamaño Actual del vector puede ser menor a CAP_MAX en este instante
    // evito recorrer de mas el vector, ya que puede estar incompleto hasta ese momento
    // por lo tanto se debe pasar como parametro el tamaño actual del vector
    if (tam==0)
    {
        return -1; // Si el vector está vacío, retornar -1
    }
    else
    {
        for (int i = 0; i < tam; i++)
        {
            if (v[i] == num) // Verificar si el número ya existe en el vector
            {
                return i;
                // Si existe, retornar la posicion donde se encuentra para despues incrementar
                // el contador en esa posicion en el vector contador
            }
        }
        return -1; // Si no existe, retornar -1 y como es un valor fuera de rango no se incrementa el contador
    }
}

void CargarLibros(int v[], int tam)
{
    int num, i= 0;

    while (i<tam)
    {
        num = numAleatorio();
        ExisteValor(num, v, i);
        
        if (ExisteValor(num, v, i)==-1 )
        {

            if (num % 2 ==0 && v[i] % 2 ==0)
            {
                v[i]=num;
                i+=2;
            } 

            
            //else if(v[LIBROS] % 2 != 0)
            //{
            //    v[i]=num;
            //    i+=1;
            //}
            
            
            
            //v[i]=num;
            //i++;
    
        }
               
    }


}

