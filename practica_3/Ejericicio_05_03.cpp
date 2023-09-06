// Materia: Programaci�n I, Paralelo 1

// Autor: Judith Marisol Romero Cori

// Fecha creaci�n: 5/09/2023

// Fecha modificaci�n: 6/09/2023

// N�mero de ejericio: 5

// Problema planteado:Generar la matriz para un orden NxN

#include <iostream>
using namespace std;

int main()
{
    int n;

    // Solicitar al usuario el tama�o de la matriz (n x n)
    cout << "Ingrese el valor de n: ";
    cin >> n;

    // Declarar una matriz de n x n
    int matriz[n][n];

    // Inicializar la matriz con n�meros consecutivos
    int numero = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matriz[i][j] = numero++;
        }
    }

    // Imprimir la matriz resultante
    cout << "Matriz resultante:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
