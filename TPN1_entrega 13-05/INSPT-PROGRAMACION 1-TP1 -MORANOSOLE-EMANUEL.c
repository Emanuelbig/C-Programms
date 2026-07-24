/*
Programacion 1
TP N 1 - Simulacion de cajero automatico
Profesores: Ing. Alejandro Behringer 
            Matias Avalos            
            Juan Capia
Alumno: Emanuel Morano Sole
*/
#include <stdio.h> //Libreria std para escribir lenguaje C
#include <stdbool.h> //Libreria para incluir booleanos

int main()
{
    int clave = 1234, intentos = 0, ingresar, opcion = 0, confirmarRetiro, confirmarSaldo, claveActual, nuevaClave;
    double ingresoDeseado, cajadeAhorro = 14503550.23, cuentaCorriente = 123244542.99;
    bool esClaveCorrecta = false;

    printf("\tBienvenido a mi Banco!!\n");
    while (intentos < 3 && !esClaveCorrecta) // Bucle que marca 3 intentos para logearse, sino se cierra el programa
    {
        printf("\tIngrese por favor su clave numerica:\n");
        scanf("%d", &ingresar);

        if (ingresar == clave)
        {
            printf("\n\tBienvenido a su Banca Digital!\n");
            esClaveCorrecta = true;
        }
        else
        {
            intentos++;
            printf("\tClave incorrecta. Intento %d de 3\n", intentos);
        }

        if (intentos == 3)
        {
            printf("\tClave incorrecta. Dirijase a su Banco emisor\n");
        }
    }

    if (esClaveCorrecta)
    {
        while (opcion != 5) // Este while englobal el menu y adentro contiene un switch con todas las opciones
        {
            printf("\t1 - Sacar Dinero\n");
            printf("\t2 - Depositar Dinero\n");
            printf("\t3 - Consultar Saldo\n");
            printf("\t4 - Cambiar la Clave\n");
            printf("\t5 - Salir\n\n");
            printf("\tIngrese una opcion:\n ");
            scanf("%d", &opcion);

            switch (opcion) // Para completar cada operacion se usaron if, else, do-while en su mayoria
            {
            case 1:
                do
                {
                    printf("\tSolicitar el ingreso deseado a retirar por favor:\n");
                    scanf("%lf", &ingresoDeseado);
                    printf("\tConfirma que quiere retirar %.2f?\n \t1. Si\n \t2. No\n", ingresoDeseado);
                    scanf("%d", &confirmarRetiro);
                } while (confirmarRetiro != 1);
                printf("\tPerfecto ha retirado %.2f\n\n", ingresoDeseado);

                break;
            case 2:
                do
                {
                    printf("\tSolicitar el importe a depositar en pesos por favor:\n");
                    scanf("%lf", &ingresoDeseado);
                    printf("\tConfirma que quiere depositar %.2f?\n \t1. Si\n \t2. No\n", ingresoDeseado);
                    scanf("%d", &confirmarRetiro);
                } while (confirmarRetiro != 1);
                printf("\tPerfecto ha depositado %.2f\n\n", ingresoDeseado);

                break;
            case 3:
                printf("\tConsultar el saldo de:\n \t1. Caja de Ahorro\n \t2. Cuenta Corriente\n");
                scanf("%d", &confirmarSaldo);
                if (confirmarSaldo == 1)
                {
                    printf("\tSu saldo en su caja de ahorro es de: %.2f\n\n", cajadeAhorro);
                }
                else if (confirmarSaldo == 2)
                {
                    printf("\tSu saldo en su cuenta corriente es de: %.2f\n\n", cuentaCorriente);
                }

                break;
            case 4:
                do
                {
                    printf("\tColoque clave actual por favor:\n");
                    scanf("%d", &claveActual);
                    if (claveActual != clave)
                    {
                        printf("\tClave incorrecta, intente de nuevo:\n\n");
                    }
                } while (claveActual != clave);
                do
                {
                    printf("\tIngrese su nueva clave por favor:\n");
                    scanf("%d", &nuevaClave);
                    if (claveActual == nuevaClave)
                    {
                        printf("\tLa nueva clave no puede ser igual a la anterior\n\n");
                    }
                } while (claveActual == nuevaClave);

                clave = nuevaClave;
                printf("\tLa clave ha sido cambiado de forma exitosa!!\n\n");

                break;
            case 5:
                printf("\t\nUsted ha salido de la banca digital, Hasta luego\n");

                break;
            default:
                printf("\t\nOpcion invalida, Ingrese por favor la opcion que desea ejecutar:\n\n");
                break;
            }
        }
    }
    return 0;
}

/*
GRACIAS POR LEER MI CODIGO, CUALQUIER FEEDBACK VA A SER TOMADO EN CUENTA PARA MEJORAR.
SALUDOS!!

Emanuel Morano Sole 
Programacion 1
*/