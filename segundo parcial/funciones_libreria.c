/*

--------------------------------------Librerias-----------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>

---------------------------------------------------------------------------------------------------------------
--------------------------------------Como se declara el vector---------------------------------------------------------

#define MAX 10 , max es el nombre del espacio que tiene el vector v[MAX]

const int CANTIDAD = 15; de esta manera tambien se declara el tamanio de un vector

---------------------------------------------------------------------------------------------------------------------
--------------------------------------Numero Aleatorio-----------------------------------------------------------------
int numAleatorio();

int numAleatorio()
{
    return (rand() % 200 )+ 1 ;
}

---------------------------------------------------------------------------------------------------------------
-------------------------Funcion hecha por el profesor del preparcial------------------------------------------

int ExisteValor(int num, int v[MAX], int m);

int ExisteValor(int num, int v[CAP_MAX], int TamActual) // Funcion para verificar si el numero ya existe en el vector
{
    // aclaro el Tamaño Actual del vector puede ser menor a CAP_MAX en este instante
    // evito recorrer de mas el vector, ya que puede estar incompleto hasta ese momento
    // por lo tanto se debe pasar como parametro el tamaño actual del vector
    if (TamActual==0)
    {
        return -1; // Si el vector está vacío, retornar -1
    }
    else
    {
        for (int i = 0; i < TamActual; i++)
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
---------------------------------------------------------------------------------------------------------------
-------------------------Funcion hecha por mi para comprobar si se repite un numero ------------------------------------------
int ExisteValor(int num, int v[], int tam);

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
---------------------------------------------------------------------------------------------------------------
-------------------------Funcion para cargar vectores sin que se repitan------------------------------------------

void CargarSinRepetirNumeros(int v[], int tam);

void CargarSinRepetirNumeros(int v[], int tam)
{
    int num, i= 0;

    while (i<tam)
    {
        num = numAleatorio();
        ExisteValor(num, v, i);

        if (ExisteValor(num, v, i)==-1)
        {
            v[i]=num;
            i++;
    
        }
               
    }

    for (int i = 0; i < tam; i++)
    {
        printf("Numero ID atleta: %d\n", v[i]);
    }
    
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
----------------------------------------------------------------------------------------------------------------
-------------------------Funcion para cargar vectores de forma basica------------------------------------------

void MostrarVector(int v[], int tam);

void MostrarVector(int v[], int tam)
{
    for (int i = 0; i < tam; i++)
    {
        printf("vector1[%d] con valor %d\n",i+1,v[i]);
    }
    
}
----------------------------------------------------------------------------------------------------------------
------------------------------------------Parcial del bingo resuelto--------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int CANT_NUM = 7;
const int MIN_NUM = 1;
const int MAX_NUM = 18;
const int PREMIO_MAX = 1400000;
const int PRECIO_BOLETO = 5;

int generar_aleatorio_entre(int vmin, int vmax);
void generar_aletorios_sr(int vec[], int tam, int vmin, int vmax);
int buscar_coincidencias(int vec1[], int vec2[], int tam);
void mostrar_premios(int coincidencias, int max_coincidencias);
void mostrar_vector(int vec[], int tam, const char msj[]);

int main() {
  srand(time(NULL));
  int boleto[CANT_NUM], sorteo[CANT_NUM];
  generar_aletorios_sr(boleto, CANT_NUM, MIN_NUM, MAX_NUM);
  generar_aletorios_sr(sorteo, CANT_NUM, MIN_NUM, MAX_NUM);
  mostrar_vector(boleto, CANT_NUM, "Boleto generado: ");
  mostrar_vector(sorteo, CANT_NUM, "Números sorteados: ");
  int coincidencias = buscar_coincidencias(boleto, sorteo, CANT_NUM);
  mostrar_premios(coincidencias, CANT_NUM);
}

void mostrar_vector(int vec[], int tam, const char msj[]) {
  printf(msj);
  for (int i = 0; i < tam; ++i) {
    printf("%d ", vec[i]);
  }
  puts("");
}

int generar_aleatorio_entre(int vmin, int vmax) {
  return rand() % (vmax - vmin + 1) + vmin;
}

void generar_aletorios_sr(int vec[], int tam, int vmin, int vmax) {
  for (int i = 0; i < tam; ++i) {
    int n = generar_aleatorio_entre(vmin, vmax);
    int c = 0;
    while (c < i) {
      if (vec[c] == n) {
        c = 0;
        n = generar_aleatorio_entre(vmin, vmax);
      } else {
        c++;
      }
    }
    vec[i] = n;
  }
}

int buscar_coincidencias(int vec1[], int vec2[], int tam) {
  int coincidencias = 0;
  for (int i = 0; i < tam; ++i) {
    for (int j = 0; j < tam; ++j) {
      if (vec1[i] == vec2[j])
        coincidencias++;
    }
  }
  return coincidencias;
}

void mostrar_premios(int coincidencias, int max_coincidencias) {
  printf("Cantidad de coincidencias: %d\n", coincidencias);
  if (coincidencias == max_coincidencias) {
    printf("¡Felicitaciones! Premio: $%d\n", PREMIO_MAX);
  } else if (coincidencias == (max_coincidencias - 1)) {
    printf("¡Felicitaciones! Premio: $%d\n", (int)(PREMIO_MAX * .2));
  } else if (coincidencias == (max_coincidencias - 2)) {
    printf("¡Felicitaciones! Premio: $%d\n", (int)(PREMIO_MAX * .03));
  } else if (coincidencias == (max_coincidencias - 3)) {
    printf("¡Felicitaciones! Premio: $%d\n", PRECIO_BOLETO);
  } else {
    puts("Sin premio.");
  }
----------------------------------------------------------------------------------------------------------------
-------------------------------------------UN TP---------------------------------------------------------------
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
-----------------------------------------------------------------------------------------------------------------
*/