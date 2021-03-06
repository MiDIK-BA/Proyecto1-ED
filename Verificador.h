#include <iostream>
#include "Aleatorio.h"
#include "lista_ortogonal.h"

using std::cin;
using std::cout;
using std::endl;

class Verificador {
private:
    int tamanio_arreglo;
    int *valores_iniciales;
    int *valores_ordenados;
    int contador_puntos = 0;

    void iniciarValoresTabla();

    void swap(int *xp, int *yp);

    void bubbleSort(int arr[], int n);

public:
    Verificador(int tamanio);

    int *getValoresIniciales() const;

    void ingresar_valores(bool automatico);

    void ordenar_valores();

    bool verificar_ordenado(Nodo *);

    Nodo *reiniciar(Nodo *);

    int get_contador_puntos();

    ~Verificador();
};