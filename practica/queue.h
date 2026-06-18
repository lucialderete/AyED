#include <iostream>
using namespace std;

typedef char item;
const item indefinido = '@';

struct nodo{
    item dato;
    nodo *siguiente;
};

struct cola{
    nodo *frente;
    nodo *final;
};

// COLAVACIA: -> COLA
void colavacia(cola &c){
    c.frente=nullptr;
    c.final=nullptr;
}

//ESCOLAVACIA: COLA -> BOOL
bool escolavacia(cola c){
    return c.frente==nullptr;
}

// ENCOLAR: COLA x ITEM -> COLA
void encolar(cola &c, item i){
    nodo *nuevo = new nodo;
    nuevo->dato=i;
    nuevo->siguiente=nullptr;
    c.final=nuevo;
    if(c.frente==nullptr){
        c.frente=nuevo;
    }
    c.final->siguiente=nuevo;
    c.final=nuevo;

}

// DESENCOLAR: COLA -> COLA
void desencolar(cola &c){
    if(escolavacia(c)){
        return;
    }
    if(c.final==c.frente){
        delete c.frente;
        c.frente=nullptr;
        c.final=nullptr;
        return;
    }
    nodo *borrar = c.frente;
    c.frente = c.frente->siguiente;
    delete borrar;
}

// FRENTE: COLA -> ITEM u {indefinido}
item frente(cola &c){
    if(escolavacia(c)){
        return indefinido;
    }else{
        return c.frente->dato;
    }
}

// funciones como usuario
// pertenece: determina si el elemento x pertenece a la cola
bool pertenece(cola &c, item x){
    if(escolavacia(c)){
        return false;
    }
    bool encontrado = false;
    cola aux;
    colavacia(aux);
    while(!escolavacia(c)){
        item frenteC=frente(c);
        desencolar(c);
        if(frenteC == x){
            encontrado = true;
        }
        encolar(aux, frenteC);
    }

    while(!escolavacia(aux)){
        encolar(c, frente(aux));
        desencolar(aux);
    }
    return encontrado;
}

int cant(cola &c){
    if(escolavacia(c)){
        return 0;
    }
    cola aux;
    colavacia(aux);
    int total=0;
    while(!escolavacia(c)){
        encolar(aux, frente(c));
        desencolar(c);
        total++;
    }
    while(!escolavacia(aux)){
        encolar(c, frente(aux));
        desencolar(aux);
    }
    return total;
}

bool iguales(cola &c1, cola &c2){
    if(escolavacia(c1) && escolavacia(c2)){
        return true;
    }
    item a = frente(c1);
    item b = frente(c2);
    desencolar(c1);
    desencolar(c2);
    bool sonIguales = (a == b) && iguales(c1, c2);
    encolar(c1, a);
    encolar(c2, b);
    return sonIguales;
}