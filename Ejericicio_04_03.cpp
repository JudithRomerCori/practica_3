// Materia: Programaci�n I, Paralelo 1

// Autor: Judith Marisol Romero Cori

// Fecha creaci�n: 6/09/2023

// Fecha modificaci�n: 6/09/2023

// N�mero de ejericio:4

// Problema planteado:


#include <iostream>
#include <vector>

const int FILAS = 3; // N�mero de filas de la matriz
const int COLUMNAS = 4; // N�mero de columnas de la matriz

// Funci�n para mostrar la matriz
void mostrarMatriz(const vector<vector<char>>& matriz)
{
    for (int i = 0; i < FILAS; ++i) {
        for (int j = 0; j < COLUMNAS; ++j) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

// Funci�n para contar filas y columnas seguras
void contarFilasColumnasSeguras(const vector<vector<char>>& matriz, int& filasSeguras, int& columnasSeguras)
{
    filasSeguras = 0;
    columnasSeguras = 0;

    for (int i = 0; i < FILAS; ++i) {
        bool filaSegura = true;
        for (int j = 0; j < COLUMNAS; ++j) {
            if (matriz[i][j] == 'x') {
                filaSegura = false;
                break;
            }
        }
        if (filaSegura) {
            filasSeguras++;
        }
    }

    for (int j = 0; j < COLUMNAS; ++j) {
        bool columnaSegura = true;
        for (int i = 0; i < FILAS; ++i) {
            if (matriz[i][j] == 'x') {
                columnaSegura = false;
                break;
            }
        }
        if (columnaSegura) {
            columnasSeguras++;
        }
    }
}

// Funci�n para encontrar las coordenadas de los muertos vivientes
void encontrarCoordenadasMuertos(const vector<vector<char>>& matriz, vector<int>& filasMuertos, vector<int>& columnasMuertos)
{
    filasMuertos.clear();
    columnasMuertos.clear();

    for (int i = 0; i < FILAS; ++i) {
        for (int j = 0; j < COLUMNAS; ++j) {
            if (matriz[i][j] == 'x') {
                filasMuertos.push_back(i);
                columnasMuertos.push_back(j);
            }
        }
    }
}

// Funci�n para contar la cantidad de muertos vivientes
int contarMuertosVivientes(const vector<vector<char>>& matriz)
{
    int contador = 0;

    for (int i = 0; i < FILAS; ++i) {
        for (int j = 0; j < COLUMNAS; ++j) {
            if (matriz[i][j] == 'x') {
                contador++;
            }
        }
    }

    return contador;
}

int main() {
    // Inicializar la matriz como se indica en la nota
    vector<vector<char>> matriz = {
        {'x', 'o', 'x', 'o'},
        {'o', 'o', 'o', 'o'},
        {'o', 'o', 'x', 'o'}
    };

    // a. Mostrar la matriz
    cout << "a. Matriz que describe el �rea:" << endl;
    mostrarMatriz(matriz);

    // b. Contar filas y columnas seguras
    int filasSeguras, columnasSeguras;
    contarFilasColumnasSeguras(matriz, filasSeguras, columnasSeguras);
    cout << "\nb. N�mero de filas seguras: " << filasSeguras << endl;
    cout << "   N�mero de columnas seguras: " << columnasSeguras << endl;

    // c. Encontrar las coordenadas de los muertos vivientes
    vector<int> filasMuertos, columnasMuertos;
    encontrarCoordenadasMuertos(matriz, filasMuertos, columnasMuertos);
    cout << "\nc. Coordenadas de los muertos vivientes:" << endl;
    for (size_t i = 0; i < filasMuertos.size(); ++i) {
        cout << "   Muerto viviente en fila " << filasMuertos[i] << ", columna " << columnasMuertos[i] << endl;
    }

    // d. Contar la cantidad de muertos vivientes
    int cantidadMuertos = contarMuertosVivientes(matriz);
    cout << "\nd. Cantidad de muertos vivientes en toda la matriz: " << cantidadMuertos << endl;

    // e. Determinar si dos o m�s muertos vivientes se encuentran en la primera columna
    bool entradaPosible = true;
    for (size_t i = 0; i < filasMuertos.size(); ++i) {
        if (columnasMuertos[i] == 0) {
            entradaPosible = false;
            break;
        }
    }

    if (entradaPosible) {
        cout << "\ne. Es posible entrar al complejo." << endl;
    } else {
        cout << "\ne. No es posible entrar al complejo." << endl;
    }

    return 0;
}
