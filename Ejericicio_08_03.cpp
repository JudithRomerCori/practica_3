
// Materia: Programación I, Paralelo 1

// Autor: Judith Marisol Romero Cori

// Fecha creación: 6/09/2023

// Fecha modificación: 6/09/2023

// Número de ejericio: 8

// Problema planteado:Multiplique dos matrices una de N x M y la otra de M x N

#include <iostream>

int main()
{
    int N, M;

    // Tamaño de la primera matriz NxM
    cout << "Ingrese el valor de N (filas): ";
    cin >> N;

    cout << "Ingrese el valor de M (columnas): ";
    cin >> M;

    // Declarar las matrices
    int matriz1[N][M];
    int matriz2[M][N];
    int resultado[N][N];

    // Llenar la primera matriz
    cout << "Ingrese los valores de la primera matriz (" << N << "x" << M << "):\n";
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> matriz1[i][j];
        }
    }

    // Llenar la segunda matriz
    cout << "Ingrese los valores de la segunda matriz (" << M << "x" << N << "):\n";
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> matriz2[i][j];
        }
    }

    // Inicializar la matriz resultado con ceros
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            resultado[i][j] = 0;
        }
    }

    // Realizar la multiplicación de matrices
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < M; ++k) {
                resultado[i][j] += matriz1[i][k] * matriz2[k][j];
            }
        }
    }


    cout << "Matriz resultado (" << N << "x" << N << "):\n";
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << resultado[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
