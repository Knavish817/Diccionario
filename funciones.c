#include <stdio.h>
#include <string.h>
#include "funciones.h"

void leer(char *Diccionario) {
    FILE *file = fopen(Diccionario, "r");
    char palabra[100];
    while (fscanf(file, "%s", palabra) != EOF) {
        printf("%s\n", palabra);
    }
    fclose(file);
}

int comparar(char *entrada, char *Diccionario) {
    FILE *file = fopen(Diccionario, "r");
    char palabra[100];
    while (fscanf(file, "%s", palabra) != EOF) {
        if (strcmp(entrada, palabra) == 0) {
            fclose(file);
            return 1;
        }
    }
    fclose(file);
    return 0;
}

void sugerir(char *entrada, char *Diccionario) {
    FILE *file = fopen(Diccionario, "r");
    char palabra[100];
    printf("Sugerencias:\n");
    while (fscanf(file, "%s", palabra) != EOF) {
        if (strstr(palabra, entrada) != NULL) {
            printf("%s\n", palabra);
        }
    }
    fclose(file);
}

void agregar(char *entrada, char *Diccionario) {
    FILE *file = fopen(Diccionario, "a");
    fprintf(file, "%s\n", entrada);
    fclose(file);
}
