/*
Ejercicio 03 – Control de consumo eléctrico
Una empresa de energía registra el consumo mensual (en kWh) de 12 hogares en Buenos
Aires. Se sabe que:
• El consumo mensual habitual de un hogar varía entre 150 y 300 kWh.
• La tarifa residencial promedio es de 104 ARS/kWh.
Se desea un programa que:
1. Identifique el hogar con mayor y menor consumo.
2. Calcule el promedio de consumo mensual (kWh).
3. Detecte hogares con consumo excesivo (> 500 kWh).
4. Estime el costo mensual para cada hogar usando la tarifa de 104 ARS/kWh.
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

#define hogares 12

int numAle();
void cargaConsumoHogares(int consumo[]);
void mayorymenor(int consumo[],int mayor, int menor,int hmayor, int hmenor);
void consumoPromediomensual(int consumo[], int suma);
void consumoExcesivo(int consumo[], int hogarexcesivo);
void costoMensual(int consumo[], int preciomensual[]);


int main ()
{
    srand(time(NULL));
    int consumo[hogares];
    cargaConsumoHogares(consumo);
    int mayor = consumo[0];
    int menor = consumo[0];
    int hogarmenor=1, hogarmayor=1;
    mayorymenor(consumo,mayor,menor,hogarmayor,hogarmenor);
    int suma=0;
    consumoPromediomensual(consumo,suma);
    int hogarexcesivo=0;
    consumoExcesivo(consumo,hogarexcesivo);
    int preciomensual[hogares];
    costoMensual(consumo,preciomensual);
}

int numAle()
{
    return (rand() % 151) + 350; 
}

void cargaConsumoHogares(int consumo[])
{
    for (int i = 0; i < hogares; i++)
    {
        consumo[i]=numAle();
    }
    
}

void mayorymenor(int consumo[],int mayor, int menor,int hmayor, int hmenor)
{
    for (int i = 0; i < hogares; i++)
    {
        if (consumo[i]>mayor)
        {
            mayor=consumo[i];
            hmayor=i+1;
        }
        else if (consumo[i]<menor)
        {
            menor=consumo[i];
            hmenor=i+1;
        }
        
    }
    
    printf("El hogar %d tiene mayor consumo con %d kWh\n",hmayor,mayor);
    printf("El hogar %d tiene menor consumo con %d kWh\n",hmenor,menor);
    
}

void consumoPromediomensual(int consumo[], int suma)
{
    for (int i = 0; i < hogares; i++)
    {
        suma += consumo[i];
    }

    float promedio = suma / hogares;
    printf("El promedio de consumo de los 12 hogares es de %.2f kWh\n",promedio);
    
}

void consumoExcesivo(int consumo[], int hogarexcesivo)
{
    for (int i = 0; i < hogares; i++)
    {
        if (consumo[i]>450)
        {
            printf("Hogar %d tiene un consumo excesivo de: %d kWh\n", i + 1, consumo[i]);
            hogarexcesivo ++;
        }     
        
    }

    if (hogarexcesivo==0)
    {
        printf("No hubo hogares con un consumo excesivo\n");
    } 
    
}

void costoMensual(int consumo[], int preciomensual[])
{
    for (int i = 0; i < hogares; i++)
    {
        preciomensual[i]= consumo[i] *104;
    }

    printf("Precio mensual de cada hogar\n");

    for (int i = 0; i < hogares; i++)
    {
        printf("hogar %d tiene que pagar %d ARS/kWh este mes\n",i+1,preciomensual[i]);
    }
    
}