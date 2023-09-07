
// Materia: Programación I, Paralelo 1

// Autor: Judith Marisol Romero Cori

// Fecha creación: 6/09/2023

// Fecha modificación: 6/09/2023

// Número de ejericio: 9

// Problema planteado:Traspones una matriz de N x M
#include <iostream>

int main()
{
    int N, M;

    // Tamaño de la matriz original NxM
    cout << "Ingrese el valor de N (filas): ";
    cin >> N;

    cout << "Ingrese el valor de M (columnas): ";
    cin >> M;

    // Declarar la matriz original
    int matrizOriginal[N][M];

    // Llenar la matriz original
    cout << "Ingrese los valores de la matriz original (" << N << "x" << M << "):\n";
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> matrizOriginal[i][j];
        }
    }

    // Declarar la matriz transpuesta MxN
    int matrizTranspuesta[M][N];

    // Calcular la matriz transpuesta
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            matrizTranspuesta[i][j] = matrizOriginal[j][i];
        }
    }

    cout << "Matriz transpuesta (" << M << "x" << N << "):\n";
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << matrizTranspuesta[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
