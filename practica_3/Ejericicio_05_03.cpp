// Materia: Programación I, Paralelo 1

// Autor: Judith Marisol Romero Cori

// Fecha creación: 5/09/2023

// Fecha modificación: 6/09/2023

// Número de ejericio: 5

// Problema planteado:Generar la matriz para un orden NxN

#include <iostream>
using namespace std;

int main()
{
    int n;

    // Solicitar al usuario el tamaño de la matriz (n x n)
    cout << "Ingrese el valor de n: ";
    cin >> n;

    // Declarar una matriz de n x n
    int matriz[n][n];

    // Inicializar la matriz con números consecutivos
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
