#include <iostream>
using namespace std;

// implementacion PILA
// LIFO: last in, first out

typedef char item;
const item indefinido = '@';
item infija[100];
item postfija[100];

struct nodo
{
    item dato;
    nodo *siguiente;
};
struct pila
{
    nodo *fondo; // primer item ingresado a la pila
    nodo *top;   // ultimo nodo agregado a la pila
    int altura;  // altura de la pila
};

// PILA: -> PILA
// inicializo la pila
void pilaVacia(pila &p)
{
    p.fondo = nullptr;
    p.top = nullptr;
    p.altura = 0;
}

// ESPILAVACIA: PILA -> BOOL
// retorna verdadero si la pila esta vacia, falso si tiene al menos un item
bool esPilaVacia(pila &p)
{
    return p.fondo == nullptr;
}

// TOP: PILA -> ITEM u {indefinido}
//  retorna el ultimo elemento agregado a la pila
item top(pila &p)
{
    if (esPilaVacia(p))
    {
        return indefinido;
    }
    else
    {
        return p.top->dato;
    }
}
// FONDO: PILA -> ITEM u {indefinido}
// retorna el elemento que se encuentra al final de la pila
item fondo(pila &p)
{
    if (esPilaVacia(p))
    {
        return indefinido;
    }
    else
    {
        return p.fondo->dato;
    }
}

// PUSH: PILA x ITEM -> PILA
// agrega un item al final de la pila
void push(pila &p, item i)
{
    nodo *nuevo = new nodo;
    nuevo->dato = i;
    nuevo->siguiente = p.top;
    p.top = nuevo;
    if (p.fondo == nullptr)
    {
        p.fondo = nuevo;
    }
    p.altura++;
}

// POP: PILA -> PILA
// elimina el ultimo elemento ingresado a la pila
void pop(pila &p)
{
    if (esPilaVacia(p))
    {
        return;
    }
    nodo *borrar = p.top;
    p.top = p.top->siguiente;
    delete borrar;
    if (p.top == nullptr)
    {
        p.fondo = nullptr;
    }
    p.altura--;
}

// POPF: PILA -> PILA
// elimina el elemento que se encuentra al fondo de la pila
void popf(pila &p)
{
    if (esPilaVacia(p))
    {
        return;
    }
    if (p.top->siguiente==nullptr)
    {
        delete p.top;
        p.top = nullptr;
        p.altura --;
        return;
    }
    nodo *actual = p.top;
    while (actual->siguiente != p.fondo)
    {
        actual = actual->siguiente;
    }
    delete actual;
    actual->siguiente=nullptr;
    p.altura--;
}

// REEMP: PILA x ITEM x ITEM -> PILA
// reemplaza todas las ocurrencias de un item por otro
void reemp(pila &p, item original, item reemplazo)
{
    item aux;
    pila pilaAux;
    pilaVacia(pilaAux);
    while (!esPilaVacia(p))
    {
        aux = top(p);
        if (aux == original)
        {
            push(pilaAux, reemplazo);
        }
        else
        {
            push(pilaAux, aux);
        }
        pop(p);
    }
    while (!esPilaVacia(pilaAux))
    {
        push(p, top(pilaAux));
        pop(pilaAux);
    }
}

// PERTENECE: PILA x ITEM -> BOOL
// retorna verdadero si el item pertenece a la pila
bool pertenece(pila &p, item i)
{
    if (esPilaVacia(p))
    {
        return false;
    }
    pila aux;
    pilaVacia(aux);
    bool encontrado = false;
    while (!esPilaVacia(p))
    {
        item x = top(p);
        pop(p);
        if (x == i)
        {
            encontrado = true;
        }
        push(aux, x);
    }
    while (!esPilaVacia(aux))
    {
        push(p, top(aux));
        pop(aux);
    }
    return encontrado;
}

// funciones como usuario

// compara si dos pilas son iguales, funcion recursiva
bool igualP(pila &p1, pila &p2)
{
    if (esPilaVacia(p1) && esPilaVacia(p2))
    {
        return true;
    }
    if (esPilaVacia(p1) || esPilaVacia(p2))
    {
        return false;
    }
    item a = top(p1);
    item b = top(p2);
    pop(p1);
    pop(p2);
    bool iguales = (a == b) && igualP(p1, p2);
    push(p1, a);
    push(p2, b);
    return iguales;
}
// compara si dos pilas son iguales, funcion iterativa
bool igualPila(pila &p1, pila &p2)
{
    if (esPilaVacia(p1) && esPilaVacia(p2))
    {
        return true;
    }
    if (esPilaVacia(p1) || esPilaVacia(p2))
    {
        return false;
    }
    pila aux1, aux2;
    pilaVacia(aux1);
    pilaVacia(aux2);
    bool igual = true;
    while (!esPilaVacia(p1) && !esPilaVacia(p2))
    {
        item a = top(p1);
        item b = top(p2);
        if (a != b)
        {
            igual = false;
        }
        pop(p1);
        pop(p2);
        push(aux1, a);
        push(aux2, b);
    }
    while (!esPilaVacia(aux1))
    {
        push(p1, top(aux1));
        pop(aux1);
    }
    while (!esPilaVacia(aux2))
    {
        push(p2, top(aux2));
        pop(aux2);
    }
    return igual;
}

// invertir pila funcion recursiva
// insertar elemento AL fondo de la pila
void insertarFondo(pila &p, item x)
{
    if (esPilaVacia(p))
    {
        push(p, x);
        return;
    }
    item aux = top(p);
    pop(p);
    insertarFondo(p, x);
    push(p, aux);
}

void invertir(pila &p)
{
    if (esPilaVacia(p))
    {
        return;
    }
    item x = top(p);
    pop(p);
    invertir(p);
    insertarFondo(p, x);
}

// invertir funcion iterativa
void invertirPila(pila &p, pila &pInv)
{
    if (esPilaVacia(p))
    {
        return;
    }
    while (!esPilaVacia(p))
    {
        item x = top(p);
        pop(p);
        push(pInv, x);
    }
}

// convertir de infija  a postfija
int prioridad(item operando)
{
    switch (operando)
    {
    case '+':
    case '-':
        return 1;
        break;
    case '*':
    case '/':
        return 2;
        break;
    case '^':
        return 3;
        break;
    default:
        return 0;
        break;
    }
}

bool esOperador(item c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
    {
        return true;
    }
    else
    {
        return false;
    }
}

void infijaAPostfija(string infija, string &postfija)
{
    pila p;
    pilaVacia(p);
    postfija = "";
    for (int i = 0; i < infija.length(); i++)
    {
        char c = infija[i];
        if (c >= 'A' && c <= 'Z')
        {
            postfija += c;
        }
        else if (c == '(')
        {
            push(p, c);
        }
        else if (c == ')')
        {
            while (top(p) != '(')
            {
                postfija += top(p);
                pop(p);
            }
            pop(p);
        }
        else if (esOperador(c))
        {
            while (!esPilaVacia(p) && prioridad(top(p)) >= prioridad(c))
            {
                postfija += top(p);
                pop(p);
            }
            push(p, c);
        }
    }
    while (!esPilaVacia(p))
    {
        postfija += top(p);
        pop(p);
    }
}