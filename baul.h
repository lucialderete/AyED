#include <iostream>
using namespace std;

// baul LIFO last in first out

typedef char objeto;
const objeto indefinido = '@';

struct nodo
{
    objeto dato;
    nodo *siguiente;
};

struct Baul
{
    nodo *fondo; //primero ingresado
    nodo *tope; //ultimo ingresado
    int capacidad;
    int ocupado;
    int disponible;
};

//

// creo el baul O(1)
Baul baulVacio(int m)
{
    Baul b;
    b.tope = nullptr; 
    b.fondo = nullptr; 
    b.capacidad = m;
    b.ocupado = 0;
    b.disponible = b.capacidad;
    return b;
}

// baul vacio O(1)
bool estaVacio(Baul b)
{
    return b.tope == nullptr;
}

// ultimo - retorna el ultimo objeto ingresado en el baul O(1)

objeto ultimo(Baul b)
{
    if (!estaVacio(b))
    {
        objeto u = b.tope->dato;
        return u;
    }
    else
    {
        return indefinido;
    }
}
// primero - retorna el primer objeto ingresado en el baulO(1)
objeto primero(Baul b)
{
    if (!estaVacio(b))
    {
        objeto u = b.fondo->dato;
        return u;
    }
    else
    {
        return indefinido;
    }
}
// retorna la capacidad total del baul O(1)
int capacidad(Baul b)
{
    return b.capacidad;
}
// retorna la cantidad ocupada O(1)
int ocupado(Baul b)
{
    return b.ocupado;
}

// retorna la cantidad disponible del baul O(1)
int disponible(Baul b)
{
    return (capacidad(b) - ocupado(b));
}

// guardar - guarda objetos al baul es decir crea un nuevo tope O(1)
Baul guardar(Baul b, objeto u)
{
    nodo *nuevo = new nodo;
    nuevo->dato = u;
    nuevo->siguiente=b.tope;
    b.tope=nuevo;
    if (b.fondo==nullptr)
    {
        b.fondo = nuevo;
    }
    
    b.ocupado++;
    return b;
}

// agregar - retorna el baul agregando un item O(1)
Baul agregar(Baul b, objeto u)
{
    if (disponible(b) > 0)
    {
        b = guardar(b, u);
    }
    return b;
}

// quitar ultimo elimina el ultimo ingresado (tope) O(1)
Baul quitarUltimo(Baul b)
{
    if(estaVacio(b)){
        return b;
    }
    nodo *borrar = b.tope;
    b.tope = b.tope->siguiente;
    delete borrar;
    b.ocupado--;
    if(b.tope==nullptr){ //si quedo vacio
        b.fondo=nullptr;
    }
    return b;
}

// vaciar - elimina todo los objetos del baul O(n)
Baul vaciar(Baul b)
{
    while (!estaVacio(b))
    {
        b = quitarUltimo(b);
    }
    return b;
}

//contiene O(n)
bool contiene(Baul b, objeto u)
{
    if (!estaVacio(b))
    {
        nodo *aux = b.tope;
        while (aux != nullptr)
        {
            if (aux->dato == u)
            {
                return true;
            }
            aux = aux->siguiente;
        }
        return false;
    }
    else
    {
        return false;
    }
}

int moverObjetos(Baul &origen, Baul &destino)
{
    int objetosTransferidos = 0;
    while (!estaVacio(origen) && disponible(destino) > 0)
    {
        destino = agregar(destino, ultimo(origen));
        origen = quitarUltimo(origen);
        objetosTransferidos++;
    }
    return objetosTransferidos;
}

void linea()
{
    cout << "--------------------------------------" << endl;
}