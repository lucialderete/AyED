#include <iostream>
using namespace std;

typedef int item;
const item indefinido = '-999999';

// implementacion del adt FILA
// FIFO: first in, first out
// frente: A -> B-> C-> final

struct nodo{
    item dato;
    nodo *siguiente;
};

struct fila{
    nodo *frente;
    nodo *final;
    int longitud;
};

// FILAVACIA: -> FILA
// inicializo la fila
void filaVacia(fila &f){
    f.frente=nullptr;
    f.final=nullptr;
    f.longitud= 0;
}

//ESFILAVACIA: FILA -> BOOL
// retorna true o false dependiendo si la fila esta vacia o no
bool esFilaVacia(fila &f){
    return f.frente==nullptr;
}

//FRENTE: FILA -> ITEM u {indefinido}
//retorna el frente de la fila (primer item ingresado)
item frente(fila &f){
    if(esFilaVacia(f)){
        return indefinido;
    }else{
        return f.frente->dato;
    }
}

// FONDO: FILA -> ITEM u {indefinido}
// retorna el fondo de la fila (ultimo item en ingresar)
item fondo (fila &f){
    if(esFilaVacia(f)){
        return indefinido;
    }else{
        return f.final->dato;
    }
}

// LONGITUD: FILA -> ENTERO>=0
int longitud(fila &f){
    return f.longitud;
}

// ENFILA: FILA x ITEM -> FILA
// agrega un item al final de la fila
void enFila(fila &f, item i){
    nodo *nuevo = new nodo;
    nuevo->dato=i;
    nuevo->siguiente=nullptr;
    if(esFilaVacia(f)){
        f.frente=nuevo;
        f.final=nuevo;
    }else{
        f.final->siguiente=nuevo;
        f.final=nuevo;
    }
    f.longitud++;
}

// DEFILA: FILA -> FILA
// elimina el primer item de la fila
void defila(fila &f){
    if(esFilaVacia(f)){
        return;
    }
    nodo *borrar = f.frente;
    f.frente = f.frente->siguiente;
    //si la fila tenia 1 elemento
    if(f.frente==nullptr){
        f.final=nullptr;
    }
    delete borrar;
    f.longitud--;
}

// DEFILARN: FILA x ENTERO -> FILA
// elimina los primeros n elementos de la fila
void defilarN(fila &f, int n){
    if(n<0 || n>longitud(f)){
        return;
    }
    nodo *borrar = f.frente;
    int aux=0;
    while(aux != n){
        defila(f);
        aux++;
    }
}

// SINGULAR: FILA -> FILA
// elimina los items repetidos de la fila
void singular(fila &f){
    nodo *actual = f.frente;
    while(actual != nullptr){
        nodo *anterior = actual;
        nodo *aux = actual->siguiente;
        while(aux != nullptr){
            if(aux->dato==actual->dato){
                anterior->siguiente=aux->siguiente;
                if(aux==f.final){
                    f.final=anterior;
                }
                nodo *borrar = aux;
                aux = anterior->siguiente;
                delete borrar;
                f.longitud--;
            }else{
                anterior = aux;
                aux = aux->siguiente;
            }
        }
        actual = actual->siguiente;
    }

}

// FUNCIONES COMO USUARIO
// LONGITUD de fila - funcion recursiva
int longitudFila(fila &f){
    if(esFilaVacia(f)){
        return 0;
    }else{
        item x = frente(f);
        defila(f);
        int l  = longitudFila(f);
        enFila(f, x);
        return l + 1;
    }
}

// longitud de fila - funcion iterativa
int longitudF(fila &f){
    int l = 0;
    fila filaAux;
    filaVacia(filaAux);
    while(!esFilaVacia(f)){
        item i=frente(f);
        defila(f);
        enFila(filaAux, i);
        l++;
    }
    while(!esFilaVacia(filaAux)){
        enFila(f, frente(filaAux));
        defila(filaAux);
    }
    return l;
}

// pertenece - funcion recursiva
bool pertenece(fila &f, item i){
    if(esFilaVacia(f)){
        return false;
    }
    item frenteF = frente(f);
    defila(f);
    bool p = (frenteF == i) || pertenece(f, i);
    enFila(f, frenteF);
    return p;
}
// pertenece - funcion iterativa
bool perteneceF(fila &f, item i){
    bool encontrado = false;
    fila filaAux;
    filaVacia(filaAux);
    while(!esFilaVacia(f)){
        item x =  frente(f);
        if(x == i){
            encontrado = true;
        }
        defila(f);
        enFila(filaAux, x);
    }
    while(!esFilaVacia(filaAux)){
        enFila(f, frente(filaAux));
        defila(filaAux);
    }
    return encontrado;
}

//igualFilas - funcion recursiva
bool igual(fila &f1, fila &f2){
    if(esFilaVacia(f1) && esFilaVacia(f2)){
        return true;
    }
    if(esFilaVacia(f1) || esFilaVacia(f2)){
        return false;
    }

    int aux1 = frente(f1);
    int aux2 = frente(f2);
    defila(f1);
    defila(f2);
    bool i = (aux1 == aux2) && igual(f1, f2);
    enFila(f1, aux1);
    enFila(f2, aux2);
    return i;
}

// igual filas, funcion iterativa
bool igualesF(fila &f1, fila &f2){
    fila aux1, aux2;
    filaVacia(aux1);
    filaVacia(aux2);
    bool i = true;
    while(!esFilaVacia(f1) && !esFilaVacia(f2)){
        item frente1 = frente(f1);
        item frente2 = frente(f2);
        if(frente1 != frente2){
            i = false;
        }
        defila(f1);
        enFila(aux1, frente1);
        defila(f2);
        enFila(aux2, frente2);
    }
    if(!esFilaVacia(f1) || !esFilaVacia(f2)){
        i = false;
    }
    while(!esFilaVacia(aux1)){
        enFila(f1, frente(aux1));
        defila(aux1);
    }
    while(!esFilaVacia(aux2)){
        enFila(f2, frente(aux2));
        defila(aux2);
    }

    return i;
}

// concatenar filas, funcion recursiva
void concat(fila &f1, fila &f2){
    if(esFilaVacia(f1)){
        return;
    }
    enFila(f2, frente(f1));
    defila(f1);
    return(concat(f1, f2));
}

// concatenar filas, funcion iterativa
void concatenarF(fila &f1, fila &f2){
    while(!esFilaVacia(f1)){
        enFila(f2, frente(f1));
        defila(f1);
    }
}

// invertir fila, funcion recursiva
void invertir(fila &f, fila &finv){
    if(!esFilaVacia(f)){
        item x = fondo(f);
        enFila(finv, x);
        invertir(f, finv);
        enFila(finv, x);
    }
}

// invertir fila, funcion iterativa
void invertirF(fila &f){
    int LF = longitud(f) - 1;
    int n=0;
    while(n!=(LF)){
        item aux = frente(f);
        defila(f);
        enFila(f, aux);
    }
}

// contar pares, funcion recursiva
int contPares(fila &f){
    if(esFilaVacia(f)){
        return 0;
    }
    item aux = frente(f);
    defila(f);
    int pares = contPares(f);
    enFila(f, aux);
    if(aux % 2 == 0){
        return pares +1 ;
    }else{
        return pares;
    }
}

// contar pares, funcion iterativa
int contarPares(fila &f){
    fila aux;
    filaVacia(aux);
    int par = 0;
    while(!esFilaVacia(f)){
        item x = frente(f);
        defila(f);
        if(x % 2 == 0){
            par++;
        }
        enFila(aux, x);
    }
    while(!esFilaVacia(aux)){
        enFila(f, frente(aux));
        defila(aux);
    }
    return par;
}

// cuenta los numeros impares de la fila, funcion recursiva
int contImp(fila &f){
    if(esFilaVacia(f)){
        return 0;
    }
    item x = frente(f);
    defila(f);
    int impares = contImp(f);
    enFila(f, x);
    if(x % 2 != 0){
        return impares + 1;
    }else{
        return impares;
    }
}

// cuenta los numeros impares, funcion iterativa
int contarImpares(fila &f){
    int impar = 0;
    fila aux;
    filaVacia(aux);
    while(!esFilaVacia(f)){
        item x = frente(f);
        defila(f);
        if(x % 2!=0){
            impar++;
        }
        enFila(aux, x);
    }
    while(!esFilaVacia(aux)){
        enFila(f, frente(aux));
        defila(aux);
    }
    return impar;
}

// suma todos los elementos de la fila funcion  recursiva

int sumarE(fila &f){
    if(esFilaVacia(f)){
        return 0;
    }
    item s = frente(f);
    defila(f);
    int suma = sumarE(f);
    enFila(f, s);
    return suma + s;
}

// suma todos los elementos funcion iterativa
int sumarElementos(fila &f){
    int sumar =0;
    fila aux;
    filaVacia(aux);
    while(!esFilaVacia(f)){
        item x = frente(f);
        defila(f);
        sumar += x;
        enFila(aux, x);
        
    }
    while(!esFilaVacia(aux)){
        enFila(f, frente(aux));
        defila(aux);
    }
    return sumar;
}

int mayorE(fila &f){
    if(esFilaVacia(f)){
        return indefinido;
    }
    item x = frente(f);
    defila(f);
    int esMayor = mayorE(f);
    if(x > esMayor){
        return x;
    }
    return esMayor;
}

// funcion iterativa
int mayorElemen(fila &f){
    if(esFilaVacia(f)){
        return indefinido;
    }
    int mayorn=frente(f);
    fila filaux;
    filaVacia(filaux);
    while(!esFilaVacia(f)){
        item x = frente(f);
        defila(f);
        if(x > mayorn){
            mayorn = x;
        }
        enFila(filaux, x);
    }
    while(!esFilaVacia(filaux)){
        enFila(f, frente(filaux));
        defila(filaux);
    }
    return mayorn;
}

void linea(){
    cout << "---------------------"<<endl;
}