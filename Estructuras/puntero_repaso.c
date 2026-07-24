#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void cambiarValor(char *letter){
    *letter = 'b';
    
}

int main(){
    /*
    int valor =10;
    int *puntero = &valor;
    int **puntero_doble = &puntero;

    printf("La direccion de memoria del puntero : %p\n",puntero);
    */
    char l;

    l = 'a';
    cambiarValor(&l);
    printf("El valor de l es: %c\n",l);

    return 0;
}

/*
malloc es memory allocator algo usado en punteros
malloc(sizeof(char))
para esto se usa include<stdlib.h>
free() libera la memoria que se asigno con malloc

https://www.youtube.com/watch?v=y3K3jb3wv2I
me quede en el 14:32
*/