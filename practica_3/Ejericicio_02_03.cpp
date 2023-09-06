// Materia: Programación I, Paralelo 1

// Autor: Judith Marisol Romero Cori

// Fecha creación: 5/09/2023

// Fecha modificación: 6/09/2023

// Número de ejericio: 2

// Problema planteado:Generar la matriz espiral para un orden n.

#include <iostream>
using namespace std;

int main()
{
    int n;

    // Solicitar al usuario el valor de n
    cout << "Ingrese el valor de n: ";
    cin >> n;

    int matriz[n][n] = {{0}};

    int valor = 1;
    int fila_inicio = 0, fila_fin = n - 1;
    int columna_inicio = 0, columna_fin = n - 1;

    while (valor <= n * n) {
        // Llenar la fila superior
        for (int i = columna_inicio; i <= columna_fin; i++) {
            matriz[fila_inicio][i] = valor++;
        }
        fila_inicio++;

        // Llenar la columna derecha
        for (int i = fila_inicio; i <= fila_fin; i++)
        {
            matriz[i][columna_fin] = valor++;
        }
        columna_fin--;

        // Llenar la fila inferior
        for (int i = columna_fin; i >= columna_inicio; i--)
        {
            matriz[fila_fin][i] = valor++;
        }
        fila_fin--;

        // Llenar la columna izquierda
        for (int i = fila_fin; i >= fila_inicio; i--)
        {
            matriz[i][columna_inicio] = valor++;
        }
        columna_inicio++;
    }

    cout << "Matriz en forma de espiral:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}
