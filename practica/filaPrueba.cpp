#include "fila.h"

int main()
{
    // cout << "Programa de prueba de Fila" << endl;

    // linea();

    // cout << "Creo una fila vacia" << endl;

    // fila f1;
    // filavacia(f1);

    // if (esFilaVacia(f1))
    // {
    //     cout << "la fila 1 es fila vacia" << endl;
    // }
    // else
    // {
    //     cout << "este mensaje no se deberia mostrar por la pantalla" << endl;
    // }

    // linea();

    // cout << "Agrego los items 'A', 'B', 'C', 'D' a la fila 1" << endl;
    // enFila(f1, 'A');
    // enFila(f1, 'B');
    // enFila(f1, 'C');
    // enFila(f1, 'D');
    // if (!esFilaVacia(f1))
    // {
    //     cout << "Frente de fila1: " << frente(f1) << endl;
    //     cout << "Final de fila1: " << final(f1) << endl;
    //     cout << "Longitud de fila1: " << longitud(f1) << endl;
    // }

    // linea();

    // cout << "elimino el item A y agrego un item C" << endl;

    // defila(f1);
    // enFila(f1, 'C');
    // cout << "Frente de fila1: " << frente(f1) << endl;
    // cout << "Final de fila1: " << final(f1) << endl;
    // cout << "Longitud de fila1: " << longitud(f1) << endl;

    // linea();
    // cout << "Elimino los items repetidos de la fila 1" << endl;
    // singular(f1);
    // if (!esFilaVacia(f1))
    // {
    //     cout << "Frente de fila1: " << frente(f1) << endl;
    //     cout << "Final de fila1: " << final(f1) << endl;
    //     cout << "Longitud de fila1: " << longitud(f1) << endl;
    // }
    // else
    // {
    //     cout << "la fila quedo vacia" << endl;
    // }

    // linea();

    // cout << "elimino los primeros 2 elementos de la fila 1" << endl;
    // defilaN(f1, 2);
    // if (!esFilaVacia(f1))
    // {
    //     cout << "Frente de fila1: " << frente(f1) << endl;
    //     cout << "Final de fila1: " << final(f1) << endl;
    //     cout << "Longitud de fila1: " << longitud(f1) << endl;
    // }
    // else
    // {
    //     cout << "la fila quedo vacia" << endl;
    // }

    // linea();

    // item A = 'A';
    // item D = 'D';
    // // funcion recursiva
    // if (pertenece(f1, A))
    // {
    //     cout << "el item " << A << " pertenece a la fila 1" << endl;
    // }
    // else
    // {
    //     cout << "el item " << A << " NO pertenece a la fila 1" << endl;
    // }

    // if (pertenece(f1, D))
    // {
    //     cout << "el item " << D << " pertenece a la fila 1" << endl;
    // }
    // else
    // {
    //     cout << "el item " << D << " NO pertenece a la fila 1" << endl;
    // }

    // // funcion iterativa
    // if (perteneceF(f1, D))
    // {
    //     cout << "el item " << D << " pertenece a la fila 1" << endl;
    // }
    // else
    // {
    //     cout << "el item " << D << " NO pertenece a la fila 1" << endl;
    // }

    // linea();
    // // creo una fila y le agrego los items D, A, F
    // fila f2;
    // filavacia(f2);
    // enFila(f2, 'D');
    // enFila(f2, 'A');
    // enFila(f2, 'F');
    // // a la fila 1 le agrego los items A F
    // enFila(f1, 'A');
    // enFila(f1, 'F');
    // // recursiva
    // if (iguales(f1, f2))
    // {
    //     cout << "la fila 1 y 2 son iguales" << endl;
    // }
    // else
    // {
    //     cout << "la fila no 1 y 2 son iguales" << endl;
    // }
    // // iterativa
    // if (igualesF(f1, f2))
    // {
    //     cout << "la fila 1 y 2 son iguales" << endl;
    // }
    // else
    // {
    //     cout << "la fila no 1 y 2 son iguales" << endl;
    // }

    // linea();

    // concat(f1, f2);
    // cout << "despues de concatenar la fila 1 y 2" << endl;
    // cout << "Frente de fila concatenada: " << frente(f1) << endl;
    // cout << "Final de fila concatenada: " << final(f1) << endl;
    // cout << "Longitud de fila concatenada: " << longitud(f1) << endl;

    // if(esFilaVacia(f2)){
    //     cout<<"la fila 2 quedo vacia"<<endl;
    // }

    // linea();
    // cout << "despues de invertir la fila"<<endl;
    // fila finv;
    // filavacia(finv);
    // invertir(f1, finv);
    // cout << "Frente de fila invertida: " << frente(finv) << endl;
    // cout << "Final de fila invertida: " << final(finv) << endl;
    // cout << "Longitud de fila invertida: " << longitud(finv) << endl;

    // linea();

    // if(esFilaVacia(f1)){
    //     cout<<"la fila 1 esta vacia"<<endl;
    // }
    // if(esFilaVacia(f2)){
    //     cout<<"la fila 2 esta vacia"<<endl;
    // }

    fila F;
    filavacia(F);
    enFila(F, 1);
    enFila(F, 2);
    enFila(F, 4);
    enFila(F, 6);
    enFila(F, 9);
    cout << "Frente de la fila F: " << frente(F) << endl;
    cout << "Final de la fila F: " << final(F) << endl;
    cout << "longitud de la fila F: " << longitud(F) << endl;
    linea();

    int num;
    num = contPares(F);
    cout << "la cantidad de nros pares que tiene la fila F es: " << num << endl;
    linea();

    cout << "Frente de la fila F: " << frente(F) << endl;
    cout << "Final de la fila F: " << final(F) << endl;
    cout << "longitud de la fila F: " << longitud(F) << endl;
    return 0;
}