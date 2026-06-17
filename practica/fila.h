#include <iostream>
using namespace std;
// implementacion de FILA
// fifo: first in, first out
typedef int item;
const item indefinido = '@';

struct nodo
{
    item dato;
    nodo *siguiente;
};

struct fila
{
    nodo *frente; // primer nodo ingresado a la fila
    nodo *final;  // ultimo nodo ingresado a la fila
    int longitud; // longitud de la fila
};

// FILAVACIA: -> FILA
//  inicializo la fila vacia

void filavacia(fila &f)
{
    f.frente = nullptr;
    f.final = nullptr;
    f.longitud = 0;
}

// ESFILAVACIA: FILA-> BOOL
// retorna verdadero o falso si la fila está vacia
bool esFilaVacia(fila &f)
{
    return f.frente == nullptr;
}

// FRENTE: FILA -> ITEM U {indefinido}
// retorna el primer item ingresado a la fila
item frente(fila &f)
{
    if (esFilaVacia(f))
    {
        return indefinido;
    }
    else
    {
        return f.frente->dato;
    }
}

// FINAL: FILA -> ITEM u {indefinido}
// retorna el utlimo elemento ingresado  a la fila
item final(fila &f)
{
    if (esFilaVacia(f))
    {
        return indefinido;
    }
    else
    {
        return f.final->dato;
    }
}
int longitud(fila &f)
{
    return f.longitud;
}
// ENFILA: FILA x ITEM -> FILA
// agrega un item al final de la fila
void enFila(fila &f, item i)
{
    nodo *nuevo = new nodo;
    nuevo->dato = i;
    nuevo->siguiente = nullptr;
    if (esFilaVacia(f))
    {
        f.frente = nuevo;
        f.final = nuevo;
    }
    else
    {
        f.final->siguiente = nuevo;
        f.final = nuevo;
    }
    f.longitud++;
}

// DEFILA: FILA -> FILA
// elimina el primer item ingresado a la fila
void defila(fila &f)
{
    if (esFilaVacia(f))
    {
        return;
    }
    nodo *borrar = f.frente;
    f.frente = f.frente->siguiente;
    if (f.frente == nullptr)
    {
        f.final = nullptr;
    }
    delete borrar;
    f.longitud--;
}
// DEFILAN: FILA x ENTERO -> FILA
// elimina los primeros n items de la fila
void defilaN(fila &f, int n)
{
    if (n < 0 && n > longitud(f))
    {
        return;
    }
    int aux = 0;
    while (aux != n)
    {
        defila(f);
        aux++;
    }
}

// SIGULAR: FILA -> FILA
// elimina los items repetidos de la fila
void singular(fila &f)
{

    nodo *actual = f.frente;

    while (actual != nullptr)
    {
        nodo *anterior = actual;
        nodo *aux = actual->siguiente;
        while (aux != nullptr)
        {
            if (aux->dato == actual->dato)
            {
                anterior->siguiente = aux->siguiente;
                if (aux == f.final)
                {
                    f.final = anterior;
                }
                nodo *borrar = aux;
                aux = anterior->siguiente;
                delete borrar;
                f.longitud--;
            }
            else
            {
                anterior = aux;
                aux = aux->siguiente;
            }
        }
        actual = actual->siguiente;
    }
}

// longitud de fila, como usuario funcion recursiva
int longitudFila(fila &f)
{
    if (esFilaVacia(f))
    {
        return 0;
    }
    else
    {
        item frenteFila = frente(f);
        defila(f);
        int h = longitudFila(f);
        enFila(f, frenteFila);
        return 1 + h;
    }
}

// longitud de fila, como usuario funcion iterativa
int longitudF(fila &f)
{
    fila aux;
    filavacia(aux);
    int h = 0;
    while (!esFilaVacia(f))
    {
        item x = frente(f);
        defila(f);
        enFila(aux, x);
        h++;
    }
    while (!esFilaVacia(aux))
    {
        enFila(f, frente(aux));
        defila(aux);
    }

    return h;
}

// pertenece funcion como usuario recursiva
bool pertenece(fila &f, item x)
{
    if (esFilaVacia(f))
    {
        return false;
    }
    item it = frente(f);
    defila(f);
    bool encontrado = (it == x) || pertenece(f, x);
    enFila(f, it);
    return encontrado;
}

// pertenece funcion como usuario iterativa
bool perteneceF(fila &f, item x)
{
    bool encontrado = false;
    fila aux;
    filavacia(aux);
    while (!esFilaVacia(f))
    {
        item i = frente(f);
        if (i == x)
        {
            encontrado = true;
        }
        defila(f);
        enFila(aux, i);
    }

    while (!esFilaVacia(aux))
    {
        enFila(f, frente(aux));
        defila(aux);
    }
    return encontrado;
}

// igualdad de filas como usuario funcion recursiva
bool iguales(fila &f1, fila &f2)
{
    if (esFilaVacia(f1) && esFilaVacia(f2))
    {
        return true;
    }
    if (esFilaVacia(f1) || esFilaVacia(f2))
    {
        return false;
    }
    item auxA = frente(f1);
    item auxB = frente(f2);
    defila(f1);
    defila(f2);
    bool r = (auxA == auxB) && iguales(f1, f2);
    enFila(f1, auxA);
    enFila(f2, auxB);
    return r;
}

// funcion iterativa como usuario
bool igualesF(fila &f1, fila &f2)
{
    fila auxA, auxB;
    filavacia(auxA);
    filavacia(auxB);
    bool iguales = true;
    while (!esFilaVacia(f1) && !esFilaVacia(f2))
    {
        item a = frente(f1);
        item b = frente(f2);
        if (a != b)
        {
            iguales = false;
        }
        enFila(auxA, a);
        enFila(auxB, b);
        defila(f1);
        defila(f2);
    }
    if (!esFilaVacia(f1) || !esFilaVacia(f2))
    {
        iguales = false;
    }
    while (!esFilaVacia(auxA))
    {
        enFila(f1, frente(auxA));
        defila(auxA);
    }

    while (!esFilaVacia(auxB))
    {
        enFila(f2, frente(auxB));
        defila(auxB);
    }
    return iguales;
}

// concatenar filas como usuario recursiva
void concat(fila &destino, fila &origen)
{
    if (esFilaVacia(origen))
    {
        return;
    }
    enFila(destino, frente(origen));
    defila(origen);
    return concat(destino, origen);
}

// concatenar filas como usuario funcion iterativa
void concatenar(fila &origen, fila &destino)
{
    while (!esFilaVacia(origen))
    {
        enFila(destino, frente(origen));
        defila(origen);
    }
}

// invertir fila de manera  recursiva como usuario
void invertir(fila &f, fila &finv)
{
    if (!esFilaVacia(f))
    {
        item itaux = frente(f);
        defila(f);
        invertir(f, finv);
        enFila(finv, itaux);
    }
}

// contar pares, devuelve la cantidad de numeros pares que contiene
// funcion recursiva
int contPares(fila &f){
    if(esFilaVacia(f)){
        return 0;
    }
    item frenteF = frente(f);
    defila(f);
    int pares = contPares(f);
    enFila(f, frenteF);
    if(frenteF % 2 == 0){
        return pares + 1;
    }else{
        return pares;
    }
    
}

void linea(){
    cout << "-------------------------"<<endl;
}