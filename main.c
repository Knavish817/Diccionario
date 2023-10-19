#include <stdio.h>           //Este código es un programa  que interactúa con un archivo de texto llamado "Diccionario.txt". 
#include <string.h>         //El programa solicita al usuario que ingrese palabras y luego verifica si la palabra existe en el diccionario.
#include "funciones.h"     // Si la palabra no existe, le da la opción al usuario de agregarla al diccionario.ademas el programa sugiere palabras similares en el diccionario
                           //  El usuario puede repetir el proceso con una nueva palabra o salir del programa.
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
