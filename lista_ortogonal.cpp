#include <iostream>
#include "lista_ortogonal.h"
#include "Aleatorio.h"

using namespace std;

lista_ortogonal::lista_ortogonal() {
}

void lista_ortogonal::crear(int niveles, int n, int m, bool automatico) {
    inicio = new struct Nodo;
    inicio->valor = 0; //----> Eliminar
    Nodo *actual = inicio;
    Nodo *fila = inicio;
    Nodo *aux = inicio;
    Nodo *columna;
    Nodo *abajo = inicio;
    Nodo *nuevo;
    Nodo *nivel=inicio;
    //int contador = 0; //---> Eliminar
    //contador++; //---> Eliminar
    for (int k = 0; k < niveles; ++k) {
        for (int j = 0; j < n; ++j) { //n=3 filas   j=0
            for (int i = 0; i < m - 1; ++i) { //m=3 columnas  i=0
                columna = new struct Nodo;
                //columna->valor = contador; //-->Eliminar
                //contador++; //--->Eliminar
                actual->siguiente = columna;
                columna->anterior = actual;
                if (j > 0) {
                    aux = aux->siguiente;
                    aux->inferior = columna;
                    columna->superior = aux;
                }
                if(k > 0){

                }
                actual = columna;
            }
            if (j != n - 1) {
                aux = fila;
                columna = new struct Nodo;
               // columna->valor = contador; //--->Eliminar
                //contador++; //--->Eliminar
                columna->superior = fila;
                fila->inferior = columna;
                fila = columna;
                actual = columna;
            }
        }
        if (k != niveles - 1) {
            nuevo = new struct Nodo;
            abajo->abajo = nuevo;
            nuevo->arriba = abajo;
            abajo = nuevo;
            actual = nuevo;
        }
    }

}

void lista_ortogonal::desplegar() {
    Nodo *aux1 = inicio;
    Nodo *aux2 = inicio;
    Nodo *aux3;
    char separador = ' ';
    if (inicio != NULL) {
        while (aux2 != NULL) {
            while (aux1 != NULL) {
                printf("%c %-3d", separador, aux1->valor);
                aux1 = aux1->siguiente;
                separador = '|';
            }
            separador = ' ';
            cout << "" << endl;
            aux1 = aux2->inferior;
            aux2 = aux1;
        }
    } else {
        cout << "Lista vacia" << endl;
    }
}