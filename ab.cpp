#include "ab.h"
int main()
{
    cout << "=== PRUEBA DEL ADT ARBOL BINARIO ===" << endl;
    linea();

    // 1. Crear árbol vacío
    AB arbol = abvacio();
    cout << "1. Arbol vacio creado" << endl;
    cout << "¿Es vacio? " << (esABVacio(arbol) ? "Sí" : "No") << endl;
    cout << "Raiz: " << raiz(arbol) << endl;
    linea();

    // 2. Construir árbol hoja
    AB hojaA = armarab(abvacio(), 'A', abvacio());
    AB hojaB = armarab(abvacio(), 'B', abvacio());
    AB hojaC = armarab(abvacio(), 'C', abvacio());
    AB hojaD = armarab(abvacio(), 'D', abvacio());
    AB hojaE = armarab(abvacio(), 'E', abvacio());

    cout << "2. Hojas creadas: A, B, C, D, E" << endl;
    cout << "¿Hoja A es arbol hoja? " << (esABhoja(hojaA) ? "Sí" : "No") << endl;
    linea();

    // 3. Construir árbol:     D
    //                       /   \
    //                      B     E
    //                     / \
    //                    A   C
    AB subIzq = armarab(hojaA, 'B', hojaC);
    AB subDer = hojaE;
    AB arbol1 = armarab(subIzq, 'D', subDer);

    cout << "3. Arbol construido:" << endl;
    mostrarArbol(arbol1);
    linea();

    // 4. Probar operaciones básicas
    cout << "4. Operaciones basicas:" << endl;
    cout << "Raiz: " << raiz(arbol1) << endl;
    cout << "Raiz izquierdo: " << raiz(izquierdo(arbol1)) << endl;
    cout << "Raiz derecho: " << raiz(derecho(arbol1)) << endl;
    linea();

    // 5. Probar recorridos
    cout << "5. Recorridos:" << endl;
    cout << "Orden Simetrico (In-Orden): ";
    ordenSimetrico(arbol1);
    cout << endl;

    cout << "Pre-Orden: ";
    preOrden(arbol1);
    cout << endl;

    cout << "Post-Orden: ";
    postOrden(arbol1);
    cout << endl;

    cout << "Recorrido por Niveles: ";
    niveles(arbol1);
    cout << endl;
    linea();

    // 6. Probar pertenece
    cout << "6. Pertenencia:" << endl;
    cout << "¿Pertenece 'B'? " << (pertenece(arbol1, 'B') ? "Sí" : "No") << endl;
    cout << "¿Pertenece 'Z'? " << (pertenece(arbol1, 'Z') ? "Sí" : "No") << endl;
    linea();

    // 7. Probar número de hojas
    cout << "7. Número de hojas: " << numeroHojas(arbol1) << endl;
    linea();

    // 8. Probar cuenta
    cout << "8. Conteo de elementos:" << endl;
    cout << "Cuantas 'B' hay? " << cuenta(arbol1, 'B') << endl;
    cout << "Cuantas 'D' hay? " << cuenta(arbol1, 'D') << endl;
    linea();

    // 9. Probar altura
    cout << "9. Altura del arbol: " << altura(arbol1) << endl;
    linea();

    // 10. Construir árbol más grande
    cout << "10. Arbol mas grande:" << endl;
    //         F
    //       /   \
    //      D     G
    //     / \     \
    //    B   E     H
    //   / \
    //  A   C
    AB hojaH = armarab(abvacio(), 'H', abvacio());
    AB subDer2 = armarab(abvacio(), 'G', hojaH);
    AB subIzq2 = armarab(hojaA, 'B', hojaC);
    AB subIzqCompleto = armarab(subIzq2, 'D', hojaE);
    AB arbolGrande = armarab(subIzqCompleto, 'F', subDer2);

    mostrarArbol(arbolGrande);
    cout << "\nRecorridos del arbol grande:" << endl;
    cout << "In-Orden: ";
    ordenSimetrico(arbolGrande);
    cout << endl;
    cout << "Niveles: ";
    niveles(arbolGrande);
    cout << endl;
    cout << "Altura: " << altura(arbolGrande) << endl;
    cout << "Numero de hojas: " << numeroHojas(arbolGrande) << endl;
    linea();

    return 0;
}