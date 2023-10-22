#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definición de la estructura de nodo para la pila
struct Nodo {
    char nombre[50];
    struct Nodo* siguiente;
};

struct Nodo* cima = NULL; // Inicializamos la pila como vacía

// Función para insertar un elemento en la pila
void insertar(char nombre[]) {
    struct Nodo* nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    if (nuevoNodo == NULL) {
        printf("Error: Memoria insuficiente\n");
        exit(1);
    }
    strcpy(nuevoNodo->nombre, nombre);
    nuevoNodo->siguiente = cima;
    cima = nuevoNodo;
    printf("Nombre '%s' agregado a la pila.\n", nombre);
}

// Función para eliminar un elemento de la pila
void eliminar() {
    if (cima == NULL) {
        printf("La pila está vacía.\n");
    } else {
        struct Nodo* temp = cima;
        printf("Nombre '%s' eliminado de la pila.\n", cima->nombre);
        cima = cima->siguiente;
        free(temp);
    }
}

// Función para mostrar todos los nombres en la pila
void mostrar() {
    if (cima == NULL) {
        printf("La pila está vacía.\n");
    } else {
        struct Nodo* actual = cima;
        printf("Nombres en la pila:\n");
        while (actual != NULL) {
            printf("%s\n", actual->nombre);
            actual = actual->siguiente;
        }
    }
}

int main() {
    int eleccion;
    char nombre[50];

    while (1) {
        printf("\n1. Agregar nombre a la pila\n");
        printf("2. Eliminar nombre de la pila\n");
        printf("3. Mostrar nombres en la pila\n");
        printf("4. Salir\n");
        printf("Ingrese su eleccion: ");
        scanf("%d", &eleccion);

        switch (eleccion) {
            case 1:
                printf("Ingrese un nombre: ");
                scanf("%s", nombre);
                insertar(nombre);
                break;
            case 2:
                eliminar();
                break;
            case 3:
                mostrar();
                break;
            case 4:
                printf("Saliendo del programa.\n");
                exit(0);
            default:
                printf("Opción no válida. Intente de nuevo.\n");
        }
    }

    return 0;
}
