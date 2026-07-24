/*
 *Autor: Emanuel Morano Sole
 *Legajo: 
 *Fecha:04/11/2025
 *Enunciado: gestion de inscripciones para un curso
 *se debe organizar la inscripcion de estudiantes para un curso con cupo limitado.
 *Se registran 50 inscriptos,se genera la lista de matriculados, la lista de espera.
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INSCRIPTOS 50
#define MAX_MATRICULADOS 40

// Estructura del pasajero
typedef struct {
    int codigo;
    char nombre[30];
    char apellido[30];
    int dni;
    char email[30];
    int matricula; // 1(true) = se matricula, 0(false) = pendiente no se matricula
} inscriptos;

// Prototipos de funciones
void cargarInscriptos(inscriptos v[], int n);
void cargarInscriptosManual(inscriptos v[], int n);
void generarListas(inscriptos todos[], inscriptos matriculados[], inscriptos espera[],inscriptos pendientes [], int n, int capacidad, int *cantMatriculados, int *cantEspera, int *canPendiente);
//void generarListas(inscriptos todos[], inscriptos matriculados[], inscriptos espera[], int n, int capacidad, int *cantMatriculados, int *cantEspera);
void mostrarLista(inscriptos v[], int n, char titulo[]);

int main(){
    inscriptos todos[MAX_INSCRIPTOS];
    inscriptos matriculados[MAX_MATRICULADOS];
    inscriptos espera[MAX_INSCRIPTOS];
    inscriptos pendientes[MAX_INSCRIPTOS];
    int capacidad, modo;
    int cantMatriculados = 0, cantEspera = 0, cantPendiente = 0;

    srand(time(NULL)); // Inicializa numeros aleatorios

    printf("=== GESTION DE INSCRIPCIONES PARA UN CURSO ===\n");
    printf("1. Carga manual\n2. Carga aleatoria\nSeleccione modo: ");
    scanf("%d", &modo);

    //Elija el camino que mas le guste
    if (modo == 1) {
        cargarInscriptosManual(todos, MAX_INSCRIPTOS); //Cargamos los incriptos manualmente
    } else {
        cargarInscriptos(todos, MAX_INSCRIPTOS); //Cargamos los inscriptos de manera aleatoria
    }


    do {
        printf("Ingrese la capacidad del curso (20 a 35 estudiantes): ");
        scanf("%d", &capacidad);
        if (capacidad < 20 || capacidad > 35) //no sale del bucle hasta que conteste entre 20 y 35
            printf("Capacidad invalida. Debe ser entre 20 y 35.\n");
    } while (capacidad < 20 || capacidad > 35);

    //generamos 2 listas, los matriculados y los que estan en espera
    generarListas(todos, matriculados, espera, pendientes, MAX_INSCRIPTOS, capacidad, &cantMatriculados, &cantEspera,&cantPendiente);
    //mostramos las listas
    mostrarLista(todos, MAX_INSCRIPTOS, "LISTA COMPLETA DE INSCRIPTOS 2025");
    mostrarLista(matriculados, cantMatriculados, "LISTA DE MATRICULADOS");
    mostrarLista(espera, cantEspera, "LISTA DE ESPERA");
    mostrarLista(pendientes, cantPendiente, "MATRICULADOS QUE NO CUMPLEN REQUERIMIENTOS AUN");
    
    return 0;
}

void cargarInscriptos(inscriptos v[], int n) {
    for (int i = 0; i < n; i++) {
        v[i].codigo = i + 1;
        sprintf(v[i].nombre, "Nombre%d", i + 1);
        sprintf(v[i].apellido, "Apellido%d", i + 1);
        v[i].dni = 30000000 + rand() % 5000000;
        strcpy(v[i].email, "user@gmail.com");
        int ramdon = rand() % 2;
        bool ramdon_bool= (ramdon ==1);
        if (ramdon_bool)
        {
            v[i].matricula = 1;
        } else
        {
            v[i].matricula = 0;
        }
        
    }
    printf("Se cargaron %d inscriptos automaticamente.\n\n", n);
}

//CARGA MANUAL
void cargarInscriptosManual(inscriptos v[], int n) {
    printf("\n=== CARGA MANUAL DE INSCRIPTOS ===\n");

    for (int i = 0; i < n; i++) {
        printf("\nInscripto #%d\n", i + 1);
        v[i].codigo = i + 1;

        printf("Nombre: ");
        getchar();
        fgets(v[i].nombre, 30, stdin);
        v[i].nombre[strcspn(v[i].nombre, "\n")] = 0;

        printf("Apellido: ");
        fgets(v[i].apellido, 30, stdin);
        v[i].apellido[strcspn(v[i].apellido, "\n")] = 0;

        printf("DNI: ");
        scanf("%d", &v[i].dni);

        printf("Email: ");
        getchar();
        fgets(v[i].email, 20, stdin);
        v[i].email[strcspn(v[i].email, "\n")] = 0;

        printf("Matricula (1 = Matriculado, 0 = Faltan documentos): ");
        scanf("%d", &v[i].matricula);

        if (v[i].matricula != 0 && v[i].matricula != 1) {
            printf(" Valor invalido, se establece prioridad regular.\n");
            v[i].matricula = 0;
        }
    }
    printf("\n Se cargaron %d los inscriptos manualmente.\n", n);
}

void generarListas(inscriptos todos[], inscriptos matriculados[], inscriptos espera[],inscriptos pendientes [], int n, int capacidad, int *cantMatriculados, int *cantEspera, int *cantPendiente){
    int i;

    // 1️ Agregar primero los matriculados 1
    for (i = 0; i < n && *cantMatriculados < capacidad; i++) {
        if (todos[i].matricula == 1) {
            matriculados[*cantMatriculados] = todos[i];
            (*cantMatriculados)++;
        }
    }

    // 2️ Luego llenar con los que no cumplen(pendientes)
    for (i = 0; i < n && *cantMatriculados < capacidad; i++) {
        if (todos[i].matricula == 0) {
            matriculados[*cantMatriculados] = todos[i];
            pendientes[*cantPendiente] = todos[i];//
            (*cantMatriculados)++;
            (*cantPendiente)++;//
        }
    }

    // 3️ El resto pasa a lista de espera
    for (i = 0; i < n; i++) {
        int encontrado = 0;
        // verificar si esta inscripto
        for (int j = 0; j < *cantMatriculados; j++) {
            if (todos[i].codigo == matriculados[j].codigo) {
                encontrado = 1;
                break;
            }
        }
        if (!encontrado) {
            espera[*cantEspera] = todos[i];
            (*cantEspera)++;
        }
    }
}

void mostrarLista(inscriptos v[], int n, char titulo[]){
    
    printf("\n==============================\n");
    printf("%s\n", titulo);
    printf("==============================\n");
    for (int i = 0; i < n; i++) {
        printf("%02d | %s %s | DNI: %d | Mail: %s | Estado: %s\n",
               v[i].codigo,
               v[i].nombre,
               v[i].apellido,
               v[i].dni,
               v[i].email,
               v[i].matricula ? "Matriculado" : "Pendiente");
    }
    printf("------------------------------\nTotal: %d Inscriptos\n\n", n);
}
