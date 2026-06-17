#include <iostream>

using namespace std;

typedef char item;
const item indefinido='@';

struct nodo{
    nodo *derecho;
    nodo *izquierdo;
    item dato;
};

struct AB{
    nodo *raiz;
};

//ABVACIO : ->AB
AB abvacio(){
    AB ab;
    ab.raiz=nullptr;
    return ab;
}

//ESABVACIO: AB -> BOOL
bool esABVacio(AB ab){
    return ab.raiz==nullptr;
}

//ARMARAB : AB x item xAB ->
AB armarab(AB izq, item x, AB der){
    AB arbol;
    nodo *nuevo = new nodo;
    nuevo->dato=x;
    nuevo->izquierdo= izq.raiz;
    nuevo->derecho=der.raiz;
    arbol.raiz=nuevo;
    return arbol;

}

//RAIZ: AB -> item U {indefinido}
item raiz(AB ab){
    if(esABVacio(ab)){
        return indefinido;
    }
    return ab.raiz->dato;
}

//IZQUIERDO : AB -> AB
AB izquierdo(AB ab){
    if(esABVacio(ab)){
        return abvacio();
    }
    AB subarbol;
    subarbol.raiz=ab.raiz->izquierdo;
    return subarbol;
}

//DERECHO : AB -> AB
AB derecho(AB ab){
    if(esABVacio(ab)){
        return abvacio();
    }
    AB subarbol;
    subarbol.raiz = ab.raiz->derecho;
    return subarbol;
}

//PERTENECE: ABxITEM -> BOOL
bool pertenece(AB ab, item x){
    if(esABVacio(ab)){
        return false;
    }
    if(raiz(ab)==x){
        return true;
    }
    return pertenece(izquierdo(ab), x) || pertenece(derecho(ab), x);
}

//orden simetrico - raiz en el medio, empieza por el hijo izquierdo 
void ordenSimetrico(AB ab){
    if(!esABVacio(ab)){
        ordenSimetrico(izquierdo(ab));
        cout << raiz(ab)<<" ";
        ordenSimetrico(derecho(ab));
    }
}

//preorden empieza por la raiz
void preOrden(AB ab){
    if(!esABVacio(ab)){
        cout<<raiz(ab)<<" ";
        preOrden(izquierdo(ab));
        preOrden(derecho(ab));
    }
}

//postOrden raiz al final
void postOrden(AB ab){
    if(!esABVacio(ab)){
        preOrden(izquierdo(ab));
        preOrden(derecho(ab));
        cout <<raiz(ab)<<" ";
    }
}


//esArbolHoja: AB ->BOOL

bool esABhoja(AB ab){
    if(esABVacio(ab)){
        return false;
    }
    return esABVacio(izquierdo(ab)) && esABVacio(derecho(ab));
}

//numeroHojas : AB -> entero>=0
int numeroHojas(AB ab){
    if(esABVacio(ab)){
        return 0;
    }
    if(esABhoja(ab)){
        return 1;
    }else{
        return numeroHojas(izquierdo(ab))+numeroHojas(derecho(ab));
    }
}

//cuenta: T x X: -> entero>=0
int cuenta(AB ab, item x){
    if(esABVacio(ab)){
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
    return a;
}
//altura: AB -> entero>=0

int altura(AB ab){
    if(esABVacio(ab) || esABhoja(ab)){
        return 0;
    }
    return 1+maximo(altura(izquierdo(ab)), altura(derecho(ab)));
}
//creo la fila adaptada para ab
struct nodoFila{
    AB dato;
    nodoFila *siguiente;
};
struct Fila{
    nodoFila *frente;
    nodoFila *final;
    int longitud;
};
Fila filaVaciaAB(){
    Fila filaAB;
    filaAB.frente=nullptr;
    filaAB.final=nullptr;
    filaAB.longitud=0;
    return filaAB;
}

Fila enfilaAB(Fila f, AB arbol){
    nodoFila *nuevo = new nodoFila;
    nuevo->dato=arbol;
    nuevo->siguiente=nullptr;
    if(f.frente==nullptr){
        f.frente=nuevo;
        f.final=nuevo;
    }else{
        f.final->siguiente=nuevo;
        f.final=nuevo;
    }
    f.longitud++;
    return f;

}

AB frenteb(Fila f){
    return f.frente->dato;
}
bool esfilaVacia(Fila f){
    return f.frente==nullptr;
}
Fila defila(Fila f){
    if(esfilaVacia(f)){
        return f;
    }
    nodoFila *borrar = f.frente;
    f.frente=f.frente->siguiente;
    delete borrar;
    f.longitud--;
    if(f.frente==nullptr){
        f.final=nullptr;
    }
    return f;
}

//niveles
void niveles(AB ab){
    if(!esABVacio(ab)){
        Fila f = filaVaciaAB();
        f = enfilaAB(f, ab);
        while(!esfilaVacia(f)){
            AB actual;
            actual = frenteb(f);
            f=defila(f);
            cout << raiz(actual)<<" ";
            if(!esABVacio(izquierdo(actual))){
                f = enfilaAB(f, izquierdo(actual));
            }
            if(!esABVacio(derecho(actual))){
                f = enfilaAB(f, derecho(actual));
            }
        }
    }
}

// Función auxiliar para mostrar el árbol de forma visual (opcional)
void mostrarArbol(AB arbol, int espacio = 0, int nivel = 0)
{
    if (esABVacio(arbol))
    {
        return;
    }
    
    espacio += 5;
    
    mostrarArbol(derecho(arbol), espacio, nivel + 1);
    
    cout << endl;
    for (int i = 5; i < espacio; i++)
    {
        cout << " ";
    }
    cout << raiz(arbol) << endl;
    
    mostrarArbol(izquierdo(arbol), espacio, nivel + 1);
}

void linea()
{
    cout << "--------------------------------------" << endl;
}