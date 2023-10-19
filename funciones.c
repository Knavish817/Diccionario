#include <stdio.h>
#include <string.h>
#include "funciones.h"

void leer(char *Diccionario) {                         //Esta función llamada leer intenta abrir un archivo especificado por la variable Diccionario y leer su contenido palabra por palabra. 
    FILE *file = fopen(Diccionario, "r");              // El archivo se abre en modo lectura ("r") utilizando un bucle while con fscanf para leer cada palabra del archivo hasta que se alcanza el final del archivo (EOF).
    char palabra[100];
    while (fscanf(file, "%s", palabra) != EOF) {
        printf("%s\n", palabra);
    }
    fclose(file);
}

int comparar(char *entrada, char *Diccionario) {      //Esta función llamada comparar intenta abrir un archivo especificado por la variable Diccionario y 
    FILE *file = fopen(Diccionario, "r");             //luego compara cada palabra en el archivo con la cadena de caracteres entrada Si encuentra una coincidencia exacta entre entrada  
    char palabra[100];                                // y alguna de las palabras en el archivo, la función devuelve 1. De lo contrario, si se recorre todo el archivo y no se encuentra ninguna coincidencia, la función devuelve 0
    while (fscanf(file, "%s", palabra) != EOF) {                                                                                 
        if (strcmp(entrada, palabra) == 0) {
            fclose(file);
            return 1;
        }
    }
    fclose(file);
    return 0;
}

void sugerir(char *entrada, char *Diccionario) {    //Esta función llamada sugerir intenta abrir un archivo especificado por la variable Diccionario y busca palabras que contengan la cadena de caracteres entrada. 
    FILE *file = fopen(Diccionario, "r");           //Luego imprime las palabras encontradas como sugerencias.La función utiliza un bucle while con fscanf para leer cada palabra del archivo hasta que se alcanza 
    char palabra[100];                              //el final del archivo (EOF). Luego, utiliza la función strstr para comprobar si la cadena de caracteres entrada está presente en la cadena palabra
    printf("Sugerencias:\n");
    while (fscanf(file, "%s", palabra) != EOF) {
        if (strstr(palabra, entrada) != NULL) {
            printf("%s\n", palabra);
        }
    }
    fclose(file);
}

void agregar(char *entrada, char *Diccionario) {   //La función abre el archivo especificado por Diccionario en modo de anexar ("a"), lo que significa que cualquier escritura en el archivo se agrega al final del mismo 
    FILE *file = fopen(Diccionario, "a");          // sin eliminar el contenido existente Luego utiliza fprintf para escribir la cadena entrada en el archivo seguido de un carácter de nueva línea "\n" .
    fprintf(file, "%s\n", entrada);               //lo que asegura que la próxima entrada se agregue en una nueva línea.
    fclose(file);
}
