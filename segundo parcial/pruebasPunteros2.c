#include <stdio.h>

void modifica(int *y);

int main(){
    int x;
    int *ptr; //creo el puntero
    ptr=&x; // le asignamos la dire de memoria d ela variable
    puts("Escribe un numero para X:\n");
    scanf("%i",&x);
    printf("El numero de X antes de pasar por la funcion es = %i\n",x);
    modifica(ptr); //lo usamos
    printf("Despues de pasar por la funcion luego x = %i\n",x);
    return 0;
}

void modifica(int *y){
    *y = 5;
}