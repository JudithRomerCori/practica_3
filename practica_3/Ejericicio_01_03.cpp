// Materia: Programación I, Paralelo 1

// Autor: Judith Marisol Romero Cori

// Fecha creación: 5/09/2023

// Fecha modificación: 6/09/2023

// Número de ejericio: 1

// Problema planteado: Elabore un programa que lea una matriz de orden n x n y la cambie la fila 1 por la fina n.

#include <iostream>

using namespace std;

int main() {
    int n;

    // Solicitar al usuario el tamaño de la matriz
    cout << "Ingrese el orden de la matriz (n x n): ";
    cin >> n;

    // Declarar una matriz de n x n
    int matriz[n][n];

    // Leer la matriz desde el usuario
    cout << "Ingrese los elementos de la matriz:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matriz[i][j];
        }
    }

    // Intercambiar la fila 1 con la fila n
    for (int j = 0; j < n; j++) {
        int temp = matriz[0][j];
        matriz[0][j] = matriz[n - 1][j];
        matriz[n - 1][j] = temp;
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

