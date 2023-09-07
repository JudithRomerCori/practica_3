// Materia: Programación I, Paralelo 1

// Autor: Judith Marisol Romero Cori

// Fecha creación: 6/09/2023

// Fecha modificación: 6/09/2023

// Número de ejericio: 12

// Problema planteado:Ingresa una matriz de NxN y a continuación:
//a. Elimine una fila ingresada por el usuario.
//b. Elimine una columna ingresada por el usuario.
//c. Inserte una fila por un valor determinado por el usuario.
//d. Inserte una columna por un valor determinado por el usuario.

#include <iostream>
#include <vector>

int main()
{
    int N;

    // Solicitar el tamaño de la matriz NxN al usuario
    cout << "Ingrese el tamaño de la matriz (N x N): ";
    cin >> N;

    // Crear la matriz NxN
    vector<vector<int>> matriz(N, vector<int>(N));

    // Ingresar valores en la matriz
    cout << "Ingrese los valores de la matriz:" << endl;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> matriz[i][j];
        }
    }

    // Mostrar la matriz original
    cout << "Matriz original:" << endl;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
        cout << matriz[i][j] << " ";
        }
        cout << endl;
    }

    int filaEliminar, columnaEliminar, filaInsertar, columnaInsertar, valorInsertar;

    // Eliminar una fila ingresada por el usuario
    cout << "Ingrese la fila que desea eliminar: ";
    cin >> filaEliminar;

    if (filaEliminar >= 0 && filaEliminar < N) {
        matriz.erase(matriz.begin() + filaEliminar);
        --N;
    } else {
        cout << "Fila no válida." << endl;
    }

    // Eliminar una columna ingresada por el usuario
    cout << "Ingrese la columna que desea eliminar: ";
    cin >> columnaEliminar;

    if (columnaEliminar >= 0 && columnaEliminar < N) {
        for (int i = 0; i < N; ++i) {
            matriz[i].erase(matriz[i].begin() + columnaEliminar);
        }
    } else {
        std::cout << "Columna no válida." << std::endl;
    }

    // Insertar una fila por un valor determinado por el usuario
    std::cout << "Ingrese la fila donde desea insertar: ";
    std::cin >> filaInsertar;
    std::cout << "Ingrese el valor que desea insertar en la fila: ";
    std::cin >> valorInsertar;

    if (filaInsertar >= 0 && filaInsertar <= N) {
        vector<int> nuevaFila(N, valorInsertar);
        matriz.insert(matriz.begin() + filaInsertar, nuevaFila);
        ++N;
    } else {
        cout << "Fila no válida." << endl;
    }

    // Insertar una columna por un valor determinado por el usuario
    cout << "Ingrese la columna donde desea insertar: ";
    cin >> columnaInsertar;
    cout << "Ingrese el valor que desea insertar en la columna: ";
    cin >> valorInsertar;

    if (columnaInsertar >= 0 && columnaInsertar <= N) {
        for (int i = 0; i < N; ++i) {
            matriz[i].insert(matriz[i].begin() + columnaInsertar, valorInsertar);
        }
        ++N;
    } else {
        cout << "Columna no válida." << endl;
    }

    // Mostrar la matriz resultante
    cout << "Matriz resultante:" << endl;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
