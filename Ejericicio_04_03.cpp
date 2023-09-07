// Materia: Programación I, Paralelo 1

// Autor: Judith Marisol Romero Cori

// Fecha creación: 6/09/2023

// Fecha modificación: 6/09/2023

// Número de ejericio:4

// Problema planteado:En la segunda temporada de The Walking Dead, los personajes llegaron a una cárcel para refugiarse. La cárcel estaba rodeada de vallas por lo que los muertos vivientes no podían entrar en ella. Sin embargo, dentro de las instalaciones aun existían muertos vivientes que amenazaban a los personajes. Por tanto, Rick y otros miembros del grupo decidieron ir a investigar las instalaciones con el fin de determinar cuáles eran los lugares seguros. Para lograr su objetivo construyeron un mapa basado en una matriz que indicaba las zonas seguras. Después de un tiempo, tu grupo llega al mismo complejo y encuentra el mapa hecho por Rick. Para mantener a salvo a tus amigos decides diseñar e implementar un programa que te ayude a determinar las zonas seguras. 


#include <iostream>
#include <vector>

const int FILAS = 3; // Número de filas de la matriz
const int COLUMNAS = 4; // Número de columnas de la matriz

// Función para mostrar la matriz
void mostrarMatriz(const vector<vector<char>>& matriz)
{
    for (int i = 0; i < FILAS; ++i) {
        for (int j = 0; j < COLUMNAS; ++j) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

// Función para contar filas y columnas seguras
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

// Función para encontrar las coordenadas de los muertos vivientes
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

// Función para contar la cantidad de muertos vivientes
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
    cout << "a. Matriz que describe el área:" << endl;
    mostrarMatriz(matriz);

    // b. Contar filas y columnas seguras
    int filasSeguras, columnasSeguras;
    contarFilasColumnasSeguras(matriz, filasSeguras, columnasSeguras);
    cout << "\nb. Número de filas seguras: " << filasSeguras << endl;
    cout << "   Número de columnas seguras: " << columnasSeguras << endl;

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

    // e. Determinar si dos o más muertos vivientes se encuentran en la primera columna
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
