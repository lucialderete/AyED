#include <iostream>
using namespace std;

typedef char item;
const item indefinido = '@';

struct nodo{
    item dato;
    nodo *siguiente;
};
struct pila{
    nodo *fondo; //fondo de la pila, primer item en ingresar
    nodo *tope; //ultimo nodo en ingresar a la pila
    int altura; //altura de la pila
};

//inicializa la pila
//PILA : -> PILA
void pilaVacia(pila &p){
    p.fondo=nullptr;
    p.tope=nullptr;
    p.altura=0;
}

//devuelve si es vacia o no
//ESPILAVACIA: PILA -> BOOL
bool esPilaVacia(pila p){
    return p.tope==nullptr;
}

//retorna la altura
int altura(pila p){
    return p.altura;
}

//retorna el ultimo item agregado a la pila
item top(pila p){
    if(esPilaVacia(p)){
        return indefinido;
    }
    return p.tope->dato;
}

//retorna el primer item agregado a la pila
item fondo(pila p){
    if(esPilaVacia(p)){
        return indefinido;
    }
    return p.fondo->dato;
}

//PUSH: PILA x ITEM -> PILA
//agrega un item a la pila
void push(pila &p, item i){
    nodo *nuevo = new nodo;
    nuevo->dato=i;
    nuevo->siguiente=p.tope;
    p.tope=nuevo;
    if(p.fondo==nullptr){
        p.fondo=nuevo;
    }
    p.altura++;
}

//POP: PILA -> PILA
// elimina el ultimo item de la pila
void pop(pila &p){
    if(esPilaVacia(p)){
        return;
    }
    nodo *borrar = p.tope; 
    p.tope = p.tope->siguiente;
    delete borrar;
    if(p.tope==nullptr){
        p.fondo=nullptr;
    }
    p.altura--;
}

//POPF: PILA -> PIlA
// elimina el primer elemento agregado a la pila
void popf(pila &p){
    if(esPilaVacia(p)){
        return;
    }
    if(p.tope == p.fondo){
        delete p.tope;
        p.fondo=nullptr;
        p.tope=nullptr;
        p.altura=0;
        return;
    }
    nodo *actual = p.tope;
    while(actual->siguiente!=p.fondo){
        actual=actual->siguiente;
    }
    delete p.fondo;
    p.fondo = actual;
    p.fondo->siguiente=nullptr;
    p.altura--;
}
// pertenece dentro de la especificacion algebraica
bool pertenece(pila &p, item i){
    pila aux;
    pilaVacia(aux);
    bool encontrado = false;
    while(!esPilaVacia(p) && !encontrado){
        item TOP = top(p);
        if(TOP== i){
            encontrado=true;
        }
        push(aux, TOP);
        pop(p);
    }
    while(!esPilaVacia(aux)){
        push(p, top(aux));
        pop(aux);
    }
    return encontrado;
}
//reemplazar un item por otro
void reemp(pila &p, item original, item reemplazo){
    pila aux;
    pilaVacia(aux);
    item TOP;
    while(!esPilaVacia(p)){
        TOP = top(p);
        pop(p);
        if(TOP==original){
            push(aux, reemplazo);
        }else{
            push(aux, TOP);}
        
    }
    while(!esPilaVacia(aux)){
        push(p, top(aux));
        pop(aux);
    }
}
// como usuario funcion recursiva altura
int alturaPila(pila &p){
    if(esPilaVacia(p)){
        return 0;
    }
    item aux = top(p);
    pop(p);
    int resto = alturaPila(p);
    push(p, aux);
    return 1+resto;
}

//como usuario funcion iterativa altura
int alturaP(pila p){
    int h = 0;
    pila aux;
    pilaVacia(aux);
    while(!esPilaVacia(p)){
        push(aux, top(p));
        h +=1;
        pop(p);
    }
    while(!esPilaVacia(aux)){
        push(p, top(aux));
        pop(aux);
    }
    return h;
}

//igualdad de pilas como usuario funcion recursiva
bool igualPila(pila &p1, pila &p2){
    if(esPilaVacia(p1) && esPilaVacia(p2)){
        return true;
    }
    if(esPilaVacia(p1) || esPilaVacia(p2)){
        return false;
    }

    item i1 = top(p1);
    item i2=  top(p2);
    if(i1 == i2){
        return true;
    }
    pop(p1);
    pop(p2);
    bool resultado = igualPila(p1, p2);
    push(p1, i1);
    push(p2, i2);
    return resultado;
}

//igual pila funcion como usuario iterativa
bool igualP(pila &p1, pila &p2){
    if(esPilaVacia(p1) || esPilaVacia(p2)){
        return false;
    }
    pila auxA, auxB;
    pilaVacia(auxA);
    pilaVacia(auxB);
    bool iguales = true;
    while(!esPilaVacia(p1) && !esPilaVacia(p2) && iguales){
        item i1 = top(p1);
        item i2 = top(p2);
        if(i1 != i2){
            iguales = false;
        }
        push(auxA, i1);
        push(auxB, i2);
        pop(p1);
        pop(p2);
    }
    while(!esPilaVacia(auxA)){
        push(p1, top(auxA));
        pop(auxA);
    }
    while(!esPilaVacia(auxB)){
        push(p2, top(auxB));
        pop(auxB);
    }

    return iguales;
}
//apilar pilas funcion recursiva como usuario
void apilarP(pila &origen, pila &destino){
    if(esPilaVacia(origen)){
        return;
    }
    item org = top(origen);
    pop(origen);
    apilarP(origen, destino);
    push(destino, org);
}

//apilar pilas funcion iterativa como usuario
void apilarPilas(pila &orig, pila &dest){
    pila aux;
    pilaVacia(aux);
    while(!esPilaVacia(orig)){
        push(aux, top(orig));
        pop(orig);
    }
    while(!esPilaVacia(aux)){
        push(dest, top(aux));
        pop(aux);
    }
}

void linea(){
    cout << "-----------------------------"<<endl;
}
