#include <stdio.h>
#include <string.h>
#include "funciones.h"

int main() {
    char archivo[] = "Diccionario.txt";
    char entrada[100];
    int encontrar;

    while (1) {
        printf("Ingrese una palabra: ");
        scanf("%s", entrada);

        encontrar = comparar(entrada, archivo);

        if (encontrar) {
            printf("La palabra coincide con el diccionario: %s\n", entrada);
        } else {
            printf("La palabra no existe en el diccionario. ¿Desea agregarla? (s/n): ");
            char elec;
            scanf(" %c", &elec);
            if (elec == 's' || elec == 'S') {
                agregar(entrada, archivo);
                printf("Palabra agregada al diccionario: %s\n", entrada);
            } else {
                sugerir(entrada, archivo);
            }
        }

        printf("¿Desea ingresar otra palabra? (s/n): ");
        char repetir;
        scanf(" %c", &repetir);
        if (repetir != 's' && repetir != 'S') {
            break;
        }
    }

    leer(archivo);

    return 0;
}
