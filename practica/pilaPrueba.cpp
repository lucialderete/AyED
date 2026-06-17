#include "pila.h"

int main()
{
    cout << "Programa de prueba PILA" << endl;
    pila p1;
    pilaVacia(p1);
    if (esPilaVacia(p1))
    {
        cout << "Inicializo una pila vacia llamada P1" << endl;
    }
    else
    {
        cout << "este mensaje no se deberia mostrar" << endl;
    }

    linea();

    push(p1, 'A');
    push(p1, 'B');
    push(p1, 'C');
    push(p1, 'D');
    push(p1, 'E');
    push(p1, 'F');
    if (!esPilaVacia(p1))
    {
        cout << "Le agrego a la pila P1 los items A, B, C, D, E, F" << endl;
        cout << "El fondo de la pila es: " << fondo(p1) << endl;
        cout << "El tope de la pila es: " << top(p1) << endl;
        cout << "La altura de la pila es: " << altura(p1) << endl;
    }

    linea();

    pop(p1);
    popf(p1);
    if (!esPilaVacia(p1))
    {
        cout << "Despues de eliminar el fondo de la pila y el utlimo item: " << endl;
        cout << "El fondo de la pila es: " << fondo(p1) << endl;
        cout << "El tope de la pila es: " << top(p1) << endl;
        cout << "La altura de la pila es: " << altura(p1) << endl;
    }
    else
    {
        cout << "La pila quedo vacia" << endl;
    }

    linea();

    item itemA = 'A';
    item itemB = 'B';
    if (!pertenece(p1, itemA))
    {
        cout << "El item " << itemA << " no pertenece a la pila P1" << endl;
    }
    else
    {
        cout << "El item " << itemA << " pertenece a la pila P1" << endl;
    }
    if (!pertenece(p1, itemB))
    {
        cout << "El item " << itemB << " no pertenece a la pila P1" << endl;
    }
    else
    {
        cout << "El item " << itemB << " pertenece a la pila P1" << endl;
    }

    linea();

    item original = 'E';
    item reemplaza = 'J';
    reemp(p1, original, reemplaza);
    cout << "despues de reemplazar el item " << original << " por " << reemplaza << endl;
    cout << "El fondo de la pila es: " << fondo(p1) << endl;
    cout << "El tope de la pila es: " << top(p1) << endl;
    cout << "La altura de la pila es: " << altura(p1) << endl;

    linea();
    int altura1 = alturaPila(p1);
    cout << "Altura pila funcion recursiva: " << altura1 << endl;
    int altura2 = alturaP(p1);
    cout << "Altura pila funcion iterativa: " << altura2 << endl;

    linea();

    cout << "agrego otra pila P2 con los items K,L,M" << endl;

    pila p2;
    pilaVacia(p2);
    push(p2, 'K');
    push(p2, 'L');
    push(p2, 'M');

    if (!esPilaVacia(p2))
    {
        cout << "El fondo de la pila2 es: " << fondo(p2) << endl;
        cout << "El tope de la pila 2 es: " << top(p2) << endl;
        cout << "La altura de la pila 2es: " << altura(p2) << endl;
    }

    linea();

    cout << "agrego otra pila P3 con los items K,L,M" << endl;

    pila p3;
    pilaVacia(p3);
    push(p3, 'K');
    push(p3, 'L');
    push(p3, 'M');

    linea();
    cout << "igualdad de pilas funcion recursiva" << endl;
    if (igualPila(p2, p3))
    {
        cout << "Las pilas 2 y 3 son iguales" << endl;
    }
    linea();
    cout << "igualdad de pilas funcion iterativa" << endl;
    if (igualP(p2, p3))
    {
        cout << "Las pilas 2 y 3 son iguales" << endl;
    }
    linea();
    cout << "igualdad de pilas funcion iterativa" << endl;
    if (igualP(p1, p3))
    {
        cout << "Las pilas 1 y 3 son iguales" << endl;
    }
    else
    {
        cout << "Las pilas 1 y 3 no son iguales" << endl;
    }

    linea();
    cout << "apilo la pila 1 y 2 con funcion recursiva" << endl;
    apilarP(p1, p2);
    cout << "El fondo de la pila2 es: " << fondo(p2) << endl;
    cout << "El tope de la pila 2 es: " << top(p2) << endl;
    cout << "La altura de la pila 2es: " << altura(p2) << endl;

    linea();

    cout << "apilo la pila 2 y 3 con funcion iterativa" << endl;
    apilarP(p2, p3);
    cout << "El fondo de la pila final es: " << fondo(p3) << endl;
    cout << "El tope de la pila final es: " << top(p3) << endl;
    cout << "La altura de la pila final es: " << altura(p3) << endl;

    linea();
    cout<<"fin del programa :p"<<endl;
    return 0;
}