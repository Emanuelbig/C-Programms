#include "palabras.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void pedir_texto(const char *msj, char *buff, int tam) {
  printf("%s", msj);
  if (fgets(buff, tam, stdin) != NULL) {
    int len = strlen(buff);
    buff[len - 1] = '\0';
  }
}

int pedir_entero(const char *msj) {
  int n;
  char buff[50];
  char *endp;
  do {
    pedir_texto(msj, buff, 50);
    n = strtol(buff, &endp, 10);
  } while (n == 0.0 && buff == endp);
  return n;
}

int pedir_entero_entre(const char *msj, int vmin, int vmax) {
  int n = pedir_entero(msj);
  while (n < vmin || n > vmax) {
    printf("Fuera de rango, el número debe estar entre %d y %d.\n", vmin, vmax);
    n = pedir_entero(msj);
  }
  return n;
}

#define MAX_JUGADORES 25
#define MAX_JUGADAS TOTAL_PALABRAS
#define LONG_PALABRA 5
#define MAX_INTENTOS 6

#define NOT_FOUND (-1)

typedef struct {
  int indice_palabra;
  int intentos; // 1 -6: adivinada , 0: no adivinada
} jugada_t;

typedef struct {
  char nombre[50];
  int palabras_jugadas;
  float promedio_adivinacion;
  jugada_t jugadas[MAX_JUGADAS];
} jugador_t;

void init_jugadores(jugador_t jrs[], size_t tam);
int registrar_jugador(const char *nom, jugador_t jrs[], size_t tam);
int buscar_jugador(const char *nom, jugador_t jrs[], size_t tam);
int buscar_palabra(jugada_t jugadas[], int cant_palabras_jugadas);
void cargar_jugada(jugada_t jugadas[], int id_palabra, int intentos, int pos);
int contiene(char c, const char *str);
void jugar(jugador_t jugadores[], size_t tam);
int menu();
void mostrar_jugador(jugador_t *j);
void ripplesort_jugadores(jugador_t jrs[], int tam);
int jugadores_activos(jugador_t jdrs[], int tam);
void mostrar_top(jugador_t jdrs[], int tam);
void feedback_palabra(const char *buff, const char *palabra, char resultado[]);

int main() {
  srand(time(NULL));
  jugador_t jugadores[MAX_JUGADORES];
  bool en_ejecucuion = true;
  while (en_ejecucuion) {
    switch (menu()) {
    case 1: // jugar
      jugar(jugadores, MAX_JUGADORES);
      break;
    case 2: // top 10
      puts("Top 10");
      ripplesort_jugadores(jugadores,
                           jugadores_activos(jugadores, MAX_JUGADORES));
      mostrar_top(jugadores, MAX_JUGADORES);
      break;
    case 0: // salir
      puts("Adiós");
      en_ejecucuion = false;
      break;
    }
  }
}

void mostrar_top(jugador_t jdrs[], int tam) {
  for (int i = 0; i < 10 && i < tam && jdrs[i].palabras_jugadas != 0; ++i) {
    printf("%2d.", i + 1);
    mostrar_jugador(&jdrs[i]);
  }
}

int jugadores_activos(jugador_t jdrs[], int tam) {
  int cont = 0;
  while (cont < tam && jdrs[cont].palabras_jugadas != 0)
    cont++;
  return cont;
}

int menu() {
  puts("1. Jugar\n"
       "2. Top 10\n"
       "0. Salir\n");
  return pedir_entero_entre("Ingrese opción: ", 0, 2);
}

void init_jugadores(jugador_t jrs[], size_t tam) {
  for (size_t i = 0; i < tam; ++i) {
    jrs[i].palabras_jugadas = 0;
  }
}

int registrar_jugador(const char *nom, jugador_t jrs[], size_t tam) {
  for (size_t i = 0; i < tam; i++) {
    if (jrs[i].palabras_jugadas == 0) {
      strcpy(jrs[i].nombre, nom);
      jrs[i].promedio_adivinacion = 0.f;
      return i;
    }
  }
  return -1;
}

int buscar_jugador(const char *nom, jugador_t jrs[], size_t tam) {
  for (size_t i = 0; i < tam && jrs[i].palabras_jugadas != 0; ++i) {
    if (!strcmp(jrs[i].nombre, nom)) {
      return i;
    }
  }
  return NOT_FOUND;
}

int buscar_palabra(jugada_t jugadas[], int cant_palabras_jugadas) {
  int ind_plb = rand() % TOTAL_PALABRAS; // 0~99
  int i = 0;
  while (i < cant_palabras_jugadas) {
    if (jugadas[i].indice_palabra == ind_plb) {
      ind_plb = rand() % TOTAL_PALABRAS;
      i = 0;
    } else {
      i++;
    }
  }
  return ind_plb;
}

void cargar_jugada(jugada_t jugadas[], int id_palabra, int intentos, int pos) {
  jugadas[pos].indice_palabra = id_palabra;
  jugadas[pos].intentos = intentos;
}

int contiene(char c, const char *str) {
  int ubicacion = NOT_FOUND;
  for (int i = 0; i < LONG_PALABRA && ubicacion == NOT_FOUND; ++i) {
    if (str[i] == c) {
      ubicacion = i;
    }
  }
  return ubicacion;
}

void jugar(jugador_t jugadores[], size_t tam) {
  char buff[50];
  pedir_texto("Ingrese su nombre: ", buff, 50);
  int ind_jdr = buscar_jugador(buff, jugadores, tam);
  if (ind_jdr == NOT_FOUND) {
    ind_jdr = registrar_jugador(buff, jugadores, tam);
    if (ind_jdr == -1) {
      puts("No hay espacio para más jugadores...");
      return;
    }
  }
  int ind_plb = buscar_palabra(jugadores[ind_jdr].jugadas,
                               jugadores[ind_jdr].palabras_jugadas);
  int intentos = 1;
  bool adivinada = false;
  printf("Palabra: %s\n", palabras[ind_plb]);
  while (intentos <= MAX_INTENTOS && !adivinada) {
    do {
      printf("\nIntento %d:\n", intentos);
      pedir_texto("", buff, 50);
    } while (strlen(buff) != 5);

    char resultado[] = "XXXXX";
    feedback_palabra(buff, palabras[ind_plb], resultado);
    printf("%s\n", resultado);
    if (!strcmp(resultado, "OOOOO")) {
      adivinada = true;
    } else {
      intentos++;
    }
  }
  if (intentos > MAX_INTENTOS)
    intentos = 0;
  cargar_jugada(jugadores[ind_jdr].jugadas, ind_plb, intentos,
                jugadores[ind_jdr].palabras_jugadas);
  jugadores[ind_jdr].palabras_jugadas++;
  int acum = 0;
  for (int i = 0; i < jugadores[ind_jdr].palabras_jugadas; ++i) {
    acum += jugadores[ind_jdr].jugadas[i].intentos;
  }
  jugadores[ind_jdr].promedio_adivinacion =
      acum / (float)jugadores[ind_jdr].palabras_jugadas;
  mostrar_jugador(&jugadores[ind_jdr]);
}

void feedback_palabra(const char *buff, const char *palabra, char resultado[]) {
  for (int i = 0; i < LONG_PALABRA; i++) {
    if (palabra[i] == buff[i]) {
      resultado[i] = 'O';
    }
  }
  for (int i = 0; i < LONG_PALABRA; i++) {
    if (resultado[i] != 'O') {
      for (int j = 0; j < LONG_PALABRA; ++j) {
        if (resultado[j] == 'X' && buff[i] == palabra[j]) {
          resultado[i] = '^';
        }
      }
    }
  }
}


void mostrar_jugador(jugador_t *j) {
  printf("%s - Promedio: %.1f - Palabras: %d\n", //
         j->nombre, j->promedio_adivinacion, j->palabras_jugadas);
}

void ripplesort_jugadores(jugador_t jrs[], int tam) {
  for (int p = 0; p < tam - 1; p++) {
    for (int i = p + 1; i < tam; i++) {
      bool hay_swap = false;
      float comp = jrs[p].promedio_adivinacion - jrs[i].promedio_adivinacion;
      hay_swap = (0 == comp) ? jrs[i].palabras_jugadas > jrs[p].palabras_jugadas
                             : comp > 0;
      if (hay_swap) {
        jugador_t aux = jrs[p];
        jrs[p] = jrs[i];
        jrs[i] = aux;
      }
    }
  }
}
