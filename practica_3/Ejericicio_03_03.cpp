// Materia: Programación I, Paralelo 1

// Autor: Judith Marisol Romero Cori

// Fecha creación: 5/09/2023

// Fecha modificación: 6/09/2023

// Número de ejericio: 3

// Problema planteado:Generar una matriz de N x N con números al azar entre A y B, y determinar:
//• La suma de la última columna
//• El producto total de la última fila
//• Obtener el mayor valor y su posición
//• Obtener la desviación estándar de todos los elementos de la matriz


#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
using namespace std;

int main()
{
    int n, A, B;

    // Solicitar al usuario el tamaño de la matriz (n x n) y los valores A y B
    cout << "Ingrese el tamaño de la matriz (n x n): ";
    cin >> n;
    cout << "Ingrese el valor de A: ";
    cin >> A;
    cout << "Ingrese el valor de B: ";
    cin >> B;

    // Inicializar la semilla para generar números aleatorios
    srand(time(0));

    // Crear una matriz de n x n e inicializarla con números aleatorios entre A y B
    int matriz[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matriz[i][j] = rand() % (B - A + 1) + A;
        }
    }

    // Calcular la suma de la última columna
    int sumaUltimaColumna = 0;
    for (int i = 0; i < n; i++) {
        sumaUltimaColumna += matriz[i][n - 1];
    }

    // Calcular el producto total de la última fila
    int productoUltimaFila = 1;
    for (int j = 0; j < n; j++) {
        productoUltimaFila *= matriz[n - 1][j];
    }

    // Encontrar el mayor valor y su posición
    int mayorValor = matriz[0][0];
    int filaMayor, columnaMayor;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matriz[i][j] > mayorValor) {
                mayorValor = matriz[i][j];
                filaMayor = i;
                columnaMayor = j;
            }
        }
    }

    // Calcular la media de los elementos de la matriz
    double sumaElementos = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            sumaElementos += matriz[i][j];
        }
    }
    double media = sumaElementos / (n * n);

    // Calcular la desviación estándar
    double sumaDiferenciasCuadradas = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            sumaDiferenciasCuadradas += pow(matriz[i][j] - media, 2);
        }
    }
    double desviacionEstandar = sqrt(sumaDiferenciasCuadradas / (n * n));

    // Imprimir los resultados
    cout << "Suma de la última columna: " << sumaUltimaColumna << endl;
    cout << "Producto total de la última fila: " << productoUltimaFila << endl;
    cout << "Mayor valor: " << mayorValor << " en la posición (" << filaMayor << ", " << columnaMayor << ")" << endl;
    cout << "Desviación estándar de los elementos de la matriz: " << desviacionEstandar << endl;

    return 0;
}
