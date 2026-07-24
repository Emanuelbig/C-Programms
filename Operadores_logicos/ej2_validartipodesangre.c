/* Programacion 1 - Emanuel Morano Sole*/
#include <stdio.h>

int main()
{
    int grupoSanguineo;
    printf("\tPor favor indique su grupo sanguineo:\n");
    printf("1. A\n");
    printf("2. B\n");
    printf("3. AB+\n");
    printf("4. AB-\n");
    printf("5. O+\n");
    printf("6. O-\n");
    scanf("%d", &grupoSanguineo);
    switch (grupoSanguineo)
    {
    case 1:
        printf("\tPuede donar a A+ y AB+, y puede recibir de A+, A-, O+ y O-.\n");
        break;
    case 2:
        printf("\tPuede donar a A+ y AB+, y puede recibir de A+, A-, O+ y O-.\n");
        break;
    case 3:
        printf("\tPuede recibir de cualquier tipo de sangre (donante universal)\n");
        break;
    case 4:
        printf("\t Puede donar a AB+ y AB- y puede recibir de A-, B- y AB-\n");
        break;
    case 5:
        printf("\tPuede donar a A+, B+, AB+, O+ y Recibe de O+ y O-.  \n");
        break;
    case 6:
        printf("\tPuede donar a cualquier grupo sanguíneo (A+, A-, B+, B-, AB+, AB-, O+, O-). y recibe solo de O-\n");
        break;

    default:
    printf("Ingreso mal el numero de su grupo sanguineo");
        break;
    }
}