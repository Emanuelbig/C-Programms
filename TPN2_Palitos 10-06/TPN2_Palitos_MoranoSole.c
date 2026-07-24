/*
 * Este software es una implementacion del juego
 * "El Ultimo Palito Pierde", desarrollado como trabajo practico N 2 de Programacion 1.
 * Permite jugar contra otro jugador o contra la computadora.
 *
 * Materia: Programación 1
 * Comisión:1.605
 * Alumno: Emanuel Morano Solé
 * Profesores: Matías Avalos
 *             Alejandro Behringer
 *             Juan Capia
 **/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Funciones creadas para el juego
void jugar();
void jugarContraJugador();
void jugarContraCPU();
void mostrarPalitos(int cantidad);
int sacarPalitos(char jugador[], int maxSacar, int palitosRestantes);
void cambiarPalitosIniciales();
void cambiarMaximoSacar();
int validarEntrada(int min, int max);

// Variables globales
int palitosIniciales = 30;
int maximoSacar = 3;

int main()
{
    system("chcp 65001 > nul");
    srand(time(NULL));
    int opcion;
    do
    {
        printf("\n***************************************\n");
        printf("*     El Ultimo Palito Pierde         *\n");
        printf("***************************************\n");
        printf("1. Jugar\n");
        printf("2. Cambiar palitos iniciales (%d)\n", palitosIniciales);
        printf("3. Cambiar sacada maxima (%d)\n", maximoSacar);
        printf("0. Salir\n");
        printf("Ingrese opcion: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            jugar();
            break;
        case 2:
            cambiarPalitosIniciales();
            break;
        case 3:
            cambiarMaximoSacar();
            break;
        case 0:
            printf("\n***************************************\n");
            printf("*       Gracias por jugar :)          *\n");
            printf("***************************************\n");
            break;
        default:
            printf("Opcion invalida.\n");
        }
    } while (opcion != 0);
    return 0;
}

void jugar()
{
    int opcion;
    printf("\n¿Que desea?\n");
    printf("1. Contra otro jugador\n");
    printf("2. Contra la computadora\n");
    printf("Opcion 1 o 2: ");
    scanf("%d", &opcion);

    if (opcion == 1)
    {
        jugarContraJugador();
    }
    else if (opcion == 2)
    {
        jugarContraCPU();
    }
    else
    {
        printf("Opcion invalida.\n");
    }
}

void jugarContraJugador()
{
    int palitos = palitosIniciales;
    int turno = 1;
    int cantidad;
    while (palitos > 0)
    {
        mostrarPalitos(palitos);
        if (turno % 2 == 1)
        {
            cantidad = sacarPalitos("Jugador1", maximoSacar, palitos);
        }
        else
        {
            cantidad = sacarPalitos("Jugador2", maximoSacar, palitos);
        }
        palitos -= cantidad;
        if (palitos == 0)
        {
            if (turno % 2 == 1)
            {
                printf("\nPerdio Jugador1, se quedo con el ultimo palito.\n");
            }
            else
            {
                printf("\nPerdio Jugador2, se quedo con el ultimo palito.\n");
            }
            break;
        }
        turno++;
    }
}

void jugarContraCPU()
{
    int palitos = palitosIniciales;
    int turno = 1;
    int cantidad;
    while (palitos > 0)
    {
        mostrarPalitos(palitos);
        if (turno % 2 == 1)
        {
            cantidad = sacarPalitos("Jugador1", maximoSacar, palitos);
        }
        else
        {
            cantidad = (rand() % maximoSacar) + 1;
            if (cantidad > palitos)
                cantidad = palitos;
            printf("CPU saco %d palito(s) de la pila.\n\n", cantidad);
        }
        palitos -= cantidad;
        if (palitos == 0)
        {
            if (turno % 2 == 1)
            {
                printf("\nPerdio Jugador1, se quedo con el ultimo palito.\n");
            }
            else
            {
                printf("\nPerdio CPU, se quedo con el ultimo palito.\n");
            }
            break;
        }
        turno++;
    }
}

void mostrarPalitos(int cantidad)
{
    for (int i = 0; i < cantidad; i++)
    {
        printf("|");
    }
    printf("\n");
}

int sacarPalitos(char jugador[], int maxSacar, int palitosRestantes)
{
    int cantidad;
    int limite = (maxSacar < palitosRestantes) ? maxSacar : palitosRestantes;
    printf("*** Turno de %s ***\n", jugador);
    printf("Ingrese cantidad a sacar (1 - %d): ", limite);
    cantidad = validarEntrada(1, limite);
    printf("%s saco %d palito(s) de la pila.\n", jugador, cantidad);
    return cantidad;
}

void cambiarPalitosIniciales()
{
    int nuevoValor;
    printf("Ingrese nueva cantidad de palitos (entre 20 y 100): ");
    nuevoValor = validarEntrada(20, 100);
    palitosIniciales = nuevoValor;
    printf("Palitos iniciales actualizados a %d.\n", palitosIniciales);
}

void cambiarMaximoSacar()
{
    int nuevoValor;
    int maximo = (palitosIniciales / 10);
    if (maximo < 3)
        maximo = 3;
    printf("Ingrese nuevo maximo a sacar (entre 3 y %d): ", maximo);
    nuevoValor = validarEntrada(3, maximo);
    maximoSacar = nuevoValor;
    printf("Cantidad maxima a sacar actualizada a %d.\n", maximoSacar);
}

int validarEntrada(int min, int max)
{
    int valor;
    do
    {
        scanf("%d", &valor);
        if (valor < min || valor > max)
        {
            printf("Valor fuera de rango. Intente de nuevo (%d - %d): ", min, max);
        }
    } while (valor < min || valor > max);
    return valor;
}

/*
 * Gracias por ver!!
 */