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
bool esABvacio(ArbolBinario ab){
    return ab.raiz==nullptr;
}

// ARMARAB: AB x item x AB -> AB
void armarAB(ArbolBinario &ab, ArbolBinario &izq, item x, ArbolBinario &der){
    nodo *nuevo = new nodo;
    nuevo->dato = x;
    nuevo->izquierdo = izq.raiz;
    nuevo->derecho = der.raiz;
    ab.raiz=nuevo;
    izq.raiz=nullptr;
    der.raiz=nullptr;
}

// RAIZ: AB -> ITEM u {indefinido}
item raiz(ArbolBinario &ab){
    if(esABvacio(ab)){
        return indefinido;
    }else{
        return ab.raiz->dato;
    }
}

// IZQUIERDO: AB -> AB
// retorna el arbol izquierdo
ArbolBinario izquierdo(ArbolBinario &ab){
    ArbolBinario izq;
    if(esABvacio(ab)){
        izq.raiz=nullptr;
    }else{
        izq.raiz=ab.raiz->izquierdo;
    }
    return izq;
}

// DERECHO: AB -> AB
ArbolBinario derecho(ArbolBinario &ab){
    ArbolBinario der;
    if(esABvacio(ab)){
        der.raiz=nullptr;
    }else{
        der.raiz=ab.raiz->derecho;
    }
    return der;
}

// pertenece: ab x item  -> bool
bool pertenece(ArbolBinario &ab, item x){
    if(esABvacio(ab)){
        return false;
    }
    if(raiz(ab)==x){
        return true;
    }
    ArbolBinario izq = izquierdo(ab);
    ArbolBinario der = derecho(ab);

    return pertenece(izq, x) || pertenece(der, x);
}

// altura
int altura(nodo *p){
    if(p==nullptr){
        return 0;
    }
    int hi = altura(p->izquierdo);
    int hd= altura(p->derecho);
    if(hi > hd){
        return hi + 1;
    }else{
        return hd + 1;
    }
}

// cuenta la cantidad de nodos
int cantNodos(nodo *p){
    if(p == nullptr){
        return 0;
    }
    return 1 + cantNodos(p->izquierdo) + cantNodos(p->derecho);
}


void ordenSimetrico(ArbolBinario ab){
    if(!esABvacio(ab)){
        ordenSimetrico(izquierdo(ab));
        cout<<raiz(ab)<<" ";
        ordenSimetrico(derecho(ab));
    }
}

void preOrden(ArbolBinario ab){
    if(!esABvacio(ab)){
        cout<<raiz(ab)<<" ";
        preOrden(izquierdo(ab));
        preOrden(derecho(ab));
    }
}

void postOrden(ArbolBinario ab){
    if(!esABvacio(ab)){
        postOrden(izquierdo(ab));
        postOrden(derecho(ab));
        cout<<raiz(ab)<<" ";
    }
}

//esArbolHoja: AB ->BOOL

bool esABhoja(ArbolBinario ab){
    if(esABvacio(ab)){
        return false;
    }
    ArbolBinario izq = izquierdo(ab);
    ArbolBinario der = derecho(ab);
    return esABvacio(izq) && esABvacio(der);
}

//numeroHojas : AB -> entero>=0
int numeroHojas(ArbolBinario ab){
    if(esABvacio(ab)){
        return 0;
    }
    if(esABhoja(ab)){
        return 1;
    }else{
        return numeroHojas(izquierdo(ab))+numeroHojas(derecho(ab));
    }
}

//cuenta: T x X: -> entero>=0
int cuenta(ArbolBinario ab, item x){
    if(esABvacio(ab)){
        return 0;
    }
    int cont =0;
    if(raiz(ab)==x){
        cont = 1;
    }
    return cont+cuenta(izquierdo(ab), x)+cuenta(derecho(ab), x);
}

//funcion aux maximo
int maximo(item a, item b){
    if(a > b){
        return a;
    }else{
        return b;
    }
}
//altura: AB -> entero>=0

int altura(ArbolBinario ab){
    if(esABvacio(ab) || esABhoja(ab)){
        return 0;
    }
    return 1+maximo(altura(izquierdo(ab)), altura(derecho(ab)));
}