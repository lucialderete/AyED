#include <iostream>
using namespace std;

typedef char item;
const item indefinido = '@';

struct nodo{
    item dato;
    nodo *izquierdo;
    nodo *derecho;
};

struct ArbolBinario{
    nodo *raiz;
};

// ABVACIO :->AB
// inicializo el arbol
void abvacio(ArbolBinario &ab){
    ab.raiz=nullptr;
}

// ESABVACIO: AB -> BOOL
bool esABvacio(ArbolBinario &ab){
    return ab.raiz==nullptr;
}

// ARMARAB: AB x item x AB -> AB
void armarAB(ArbolBinario &ab, ArbolBinario &izq, item x, ArbolBinario &der){
    nodo *nuevo = new nodo;
    nuevo->dato = x;
    nuevo->izquierdo = izq.raiz;
    nuevo->derecho = der.raiz;
    ab.raiz=nuevo;
}