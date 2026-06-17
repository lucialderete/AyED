#include "baul.h"

int main()
{
    cout << "Programa de prueba de BAUL " << endl;

    Baul A;
    A = baulVacio(5);

    if (estaVacio(A))
    {
        cout << "he creado un baul vacio llamado A" << endl;
    }
    else
    {
        cout << "este mensaje no se deberia estar mostrando por pantalla  :0" << endl;
    }

    linea();

    // agrego objetos al baul

    A = agregar(A, 'a');
    A = agregar(A, 'b');
    A = agregar(A, 'c');
    A = agregar(A, 'd');

    cout << "despues de agregar los objetos a, b, c, d al baul" << endl;
    if (!estaVacio(A))
    {
        cout << "Capacidad de A: " << capacidad(A) << endl;
        cout << "Primero de A: " << primero(A) << endl;
        cout << "Ultimo de A: " << ultimo(A) << endl;
        cout << "Cantidad ocupada de A: " << ocupado(A) << endl;
        cout << "Cantidad disponible de A: " << disponible(A) << endl;
    }
    else
    {
        cout << "no se deberia mostrar esto en pantalla " << endl;
    }

    linea();

    A = quitarUltimo(A);
    cout << "despues de quitar el ultimo elemento de A" << endl;
    cout << "Capacidad de A: " << capacidad(A) << endl;
    cout << "Primero de A: " << primero(A) << endl;
    cout << "Ultimo de A: " << ultimo(A) << endl;
    cout << "Cantidad ocupada de A: " << ocupado(A) << endl;
    cout << "Cantidad disponible de A: " << disponible(A) << endl;

    linea();

    // creo un nuevo baul

    Baul B;
    B = baulVacio(5);
    B = agregar(B, 'e');
    B = agregar(B, 'f');
    B = agregar(B, 'g');
    cout << "despues de agregar los objetos e, f, g al baul B" << endl;
    if (!estaVacio(B))
    {
        cout << "Capacidad de B : " << capacidad(B) << endl;
        cout << "Primero de B: " << primero(B) << endl;
        cout << "Ultimo de B: " << ultimo(B) << endl;
        cout << "Cantidad ocupada de B: " << ocupado(B) << endl;
        cout << "Cantidad disponible de B: " << disponible(B) << endl;
    }
    else
    {
        cout << "no se deberia mostrar esto en pantalla " << endl;
    }

    linea();

    int objetosTransf = 0;
    objetosTransf = moverObjetos(A, B);
    cout << "La cantidad de objetos que se movieron del baul A al baul B son: " << objetosTransf << endl;

    linea();
    if (!estaVacio(A))
    {
        cout << "Capacidad de A: " << capacidad(A) << endl;
        cout << "Primero de A: " << primero(A) << endl;
        cout << "Ultimo de A: " << ultimo(A) << endl;
        cout << "Cantidad ocupada de A: " << ocupado(A) << endl;
        cout << "Cantidad disponible de A: " << disponible(A) << endl;
    }
    else
    {
        cout << "el baul A esta vacio" << endl;
    }

    linea();

    if (!estaVacio(B))
    {
        cout << "Capacidad de B : " << capacidad(B) << endl;
        cout << "Primero de B: " << primero(B) << endl;
        cout << "Ultimo de B: " << ultimo(B) << endl;
        cout << "Cantidad ocupada de B: " << ocupado(B) << endl;
        cout << "Cantidad disponible de B: " << disponible(B) << endl;
    }
    else
    {
        cout << "el baul B esta vacio " << endl;
    }

    linea();

    B = vaciar(B);
    if (estaVacio(B))
    {
        cout << "El baul B ahora esta vacio" << endl;
    }

    return 0;
}