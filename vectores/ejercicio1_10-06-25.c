/*********************************************
 Ejercicio 01
Juego: Adivinar el Número Secreto
Desarrollar un programa que:
1. Genere un número aleatorio entre 1 y 100.
2. Permita al usuario adivinar ese número, con un máximo de 15 intentos.
3. Después de cada intento, el programa debe:
o Informar cuántos intentos le quedan.
o Dar pistas según la distancia (valor absoluto) entre el número ingresado y 
el número secreto:
▪ Si la diferencia es 1, mostrar: "Estás al lado".
▪ Si la diferencia es 2, mostrar: "Estás muy cerca".
▪ Si la diferencia es 5, mostrar: "Estás muy lejano".
▪ Si la diferencia es mayor a 20, mostrar: "Estás demasiado lejos".
4. El juego termina si el usuario adivina el número o si se agotan los intentos.

*********************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int NumeroAleatorio();
int main()
{
    system("chcp 65001 > nul");  // Cambia la consola a UTF-8
    int numUsuario;
    srand(time(NULL));
    int secreto = NumeroAleatorio();
    printf("\tAdivíne el numero secreto entre 1 y 100\n\n");
    
    for (int i = 1; i <= 15; i++)
    {
        printf("Ingrese el intento numero %d de 15:\n",i );
        scanf("%d",&numUsuario);
        //printf("Numero Aleatorio: %d\n",secreto);
        int diferencia = abs(secreto - numUsuario);
        if (numUsuario == secreto)
        {
            printf("\tFelicitaciones ganaste el juego!!!\n");
            return 0;
        } 
        else if (diferencia == 1)
        {
            printf("\tEstás al lado\n");
        }
        else if (diferencia == 2)
        {
            printf("\tEstás muy cerca\n");
        }
        else if (diferencia == 5)
        {
            printf("\tEstás al muy lejano\n");
        } 
        else
        {
            printf("Segui intentando!\n");
        }    
        
    }
    printf ("Te quedaste sin intentos llegaste a 15 de 15");
    return 0;
}
int NumeroAleatorio(){
    int numAle = (rand() % 100) + 1;
    int resultado = numAle;
    return resultado;
}