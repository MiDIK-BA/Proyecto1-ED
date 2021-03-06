#include "TablaPosiciones.h"
#include <iostream>

using std::cout;
using std::endl;

void TablaPosiciones::agregar(Partida *partida) {
    NodoPartida *aux;
    if (primero == NULL) {
        primero = new struct NodoPartida;
        primero->valor = partida;
    } else {
        aux = primero;
        primero = new struct NodoPartida;
        primero->valor = partida;
        aux->anterior = primero;
        primero->siguiente = aux;
    };
}

void TablaPosiciones::desplegar() {
    NodoPartida *nodo = primero;
    int contador = 1;
    const int MAXIMO = 5;
    cout << "-------------TABLA DE POSICIONES-------------" << endl;
    printf(" %-21s %-9s %-s \n", "Nombre del jugador", "Punteo", "Tiempo de partida (s)");
    if (nodo != NULL ) {
        do {
            char *nombre_jugador = nodo->valor->getNombreJugador();
            int num_puntos = nodo->valor->getNumPuntos();
            int tiempo_partida = nodo->valor->getTiempoPartida();
            printf(" %-21s %-9d %-d \n", nombre_jugador, num_puntos, tiempo_partida);
            contador++;
            nodo = nodo->siguiente;
        } while (nodo != NULL && contador <= MAXIMO);
    } else {
        cout << " Aun no hay registros" << endl;
    }
}

void TablaPosiciones::ordenar() {
    NodoPartida *nodo = primero;
    NodoPartida *nodo_mayor = nodo;
    NodoPartida *nodo_indice = primero;
    Partida *aux;
    while (nodo_indice != NULL) {
        while (nodo != NULL) {
            if (nodo->valor->getNumPuntos() > nodo_mayor->valor->getNumPuntos()) {
                nodo_mayor = nodo;
            }
            nodo = nodo->siguiente;
        }
        aux = nodo_mayor->valor;
        nodo_mayor->valor = nodo_indice->valor;
        nodo_indice->valor = aux;
        nodo_indice = nodo_indice->siguiente;
        nodo = nodo_indice;
        nodo_mayor = nodo_indice;
    }
}

TablaPosiciones::~TablaPosiciones() {
    delete primero;
}

