#include <stdio.h>
#include <string.h>

#define MAX_INTENTOS 3
#define ENTRADA_NORMAL 8
#define ENTRADA_VIP 15
#define ENTRADA_3D 12
#define MAX_ASIENTOS_NORMAL 100
#define MAX_ASIENTOS_VIP 20
#define MAX_ASIENTOS_3D 40
#define DESCUENTO_1 0.5
#define DESCUENTO_2 0.10
#define DESCUENTO_3 0.15

int main() {
    char user[10];
    char pass[10];
    int opcion;
    int intentos = 0;
    int entradas_vendidas = 0;
    int ingresos_generados = 0;

    printf("-------Inicio de Sesion--------\n");
    while (intentos < MAX_INTENTOS) {
        printf("Ingrese su usuario: ");
        scanf("%s", user);
        printf("Ingrese su contraseña: ");
        scanf("%s", pass);
        intentos += 1;

        if (strcmp(user, "Roberto") == 0 && strcmp(pass, "1234") == 0) {
            printf("Inicio de sesion exitoso\n");
            break;
        } else if (strcmp(user, "Jose") == 0 && strcmp(pass, "4567") == 0) {
            printf("Inicio de sesion exitoso\n");
            break;
        } else if (strcmp(user, "Pepe") == 0 && strcmp(pass, "7890") == 0) {
            printf("Inicio de sesion exitoso\n");
            break;
        } else {
            printf("Usuario o contraseña incorrectos\n");
            printf("Intente de nuevo\n");
        }

        if (intentos == MAX_INTENTOS) {
            printf("Maximo de intentos permitidos\n");
            return 0;
        }
    }

    int i = 1;
    while (i == 1) {
        printf("\nMenú principal\n");
        printf("1. Venta de Entradas\n");
        printf("2. Estadísticas de Ventas\n");
        printf("3. Salir\n");
        printf("Ingrese una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Venta de entradas\n");
                printf("Escriba (1) o (2) para seleccionar una pelicula\n");
                printf("1. Shrek\n");
                printf("2. Proyect X\n");

                int pelicula;
                printf("Seleccione una pelicula: ");
                scanf("%d", &pelicula);

                char entrada[10];
                float precio_entrada;
                int max_asientos;
                int num_entradas;

                if (pelicula == 1) {
                    printf("Ha seleccionado Shrek\n");
                } else if (pelicula == 2) {
                    printf("Ha seleccionado Proyect X\n");
                } else {
                    printf("Opcion no valida\n");
                    break;
                }

                printf("¿Que tipo de entrada desea?\n");
                printf("1. Normal ($8)\n");
                printf("2. VIP ($15)\n");
                printf("3. 3D ($12)\n");
                scanf("%s", entrada);

                if (strcmp(entrada, "Normal") == 0) {
                    precio_entrada = ENTRADA_NORMAL;
                    max_asientos = MAX_ASIENTOS_NORMAL;
                } else if (strcmp(entrada, "VIP") == 0) {
                    precio_entrada = ENTRADA_VIP;
                    max_asientos = MAX_ASIENTOS_VIP;
                } else if (strcmp(entrada, "3D") == 0) {
                    precio_entrada = ENTRADA_3D;
                    max_asientos = MAX_ASIENTOS_3D;
                } else {
                    printf("Opcion no valida\n");
                    break;
                }

                printf("¿Cuantas entradas desea?\n");
                scanf("%d", &num_entradas);

                if (num_entradas > max_asientos) {
                    printf("No hay asientos disponibles\n");
                    break;
                }

                float costo_total = precio_entrada * num_entradas;

                if (costo_total >= 40 && costo_total < 80) {
                    printf("Tiene un descuento del 5 porciento\n");
                    costo_total -= DESCUENTO_1;
                } else if (costo_total >= 80 && costo_total < 120) {
                    printf("Tiene un descuento del 10 porciento\n");
                    costo_total -= DESCUENTO_2;
                } else if (costo_total > 120) {
                    printf("Tiene un descuento del 15 porciento\n");
                    costo_total -= DESCUENTO_3;
                }

                printf("Costo total de las entradas: %.2f\n", costo_total);

                entradas_vendidas += num_entradas;
                ingresos_generados += costo_total;
                break;

            case 2:
                printf("Estadisticas\n");
                printf("Ingresos generados: %d\n", ingresos_generados);
                printf("Entradas vendidas: %d\n", entradas_vendidas);
                break;

            case 3:
                printf("Fin del programa\n");
                return 0;

            default:
                printf("Opción no válida\n");
                break;
        }
    }

    return 0;
}




