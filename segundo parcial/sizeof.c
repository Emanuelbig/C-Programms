#include <stdio.h>
//uso de size of para saber el tamaño en bytes 
size_t getsize(float *ptr);
int main() {
    float array[20];
    printf("numero de bytes en el arreglo es : %lu\n",sizeof(array));
    printf("El numero de bytes devueltos por getsize es : %lu\n",getsize(array));
    return 0;
    
}

size_t getsize(float *ptr)
{
    return sizeof(ptr);
}
