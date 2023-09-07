// Materia: Programaci�n I, Paralelo 1

// Autor: Judith Marisol Romero Cori

// Fecha creaci�n: 6/09/2023

// Fecha modificaci�n: 6/09/2023

// N�mero de ejericio: 11

// Problema planteado:. Realizar el t�pico juego del 3 en raya, donde habr� dos jugadores que tengan que hacer el 3 en raya, los signos ser�n el X y el O, cuando haya una posici�n vac�a habr� un � El tablero de juego, ser� una matriz de 3�3 de char. El juego termina cuando uno de los jugadores hace 3 en raya o si no hay m�s posiciones que poner.
//El juego debe pedir las posiciones donde el jugador actual quiera poner su marca, esta debe ser validada y por supuesto que no haya una marca ya puesta. Por �ltimo mostrar la matriz del juego y muestra al ganador.

#include <iostream>
using namespace std;

// Funci�n para imprimir el tablero
void imprimirTablero(char tablero[3][3])
{
    cout << "Tablero de juego:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << tablero[i][j] << " ";
        }
        cout << endl;
    }
}

// Funci�n para verificar si un jugador ha ganado
bool verificarGanador(char tablero[3][3], char jugador)
{
    // Verificar filas y columnas
    for (int i = 0; i < 3; i++) {
        if (tablero[i][0] == jugador && tablero[i][1] == jugador && tablero[i][2] == jugador)
            return true;
        if (tablero[0][i] == jugador && tablero[1][i] == jugador && tablero[2][i] == jugador)
            return true;
    }
    // Verificar diagonales
    if (tablero[0][0] == jugador && tablero[1][1] == jugador && tablero[2][2] == jugador)
        return true;
    if (tablero[0][2] == jugador && tablero[1][1] == jugador && tablero[2][0] == jugador)
        return true;
    return false;
}

int main() {
    char tablero[3][3] = {{'-', '-', '-'},
                         {'-', '-', '-'},
                         {'-', '-', '-'}};

    char jugadorActual = 'X';
    int fila, columna;
    int movimientos = 0;

    while (true) {
        imprimirTablero(tablero);
        cout << "Es el turno del jugador " << jugadorActual << endl;

        // Solicitar posici�n al jugador
        cout << "Ingresa la fila (0, 1, o 2) y la columna (0, 1, o 2) separadas por un espacio: ";
        cin >> fila >> columna;

        // Verificar si la posici�n es v�lida
        if (fila < 0 || fila > 2 || columna < 0 || columna > 2 || tablero[fila][columna] != '-') {
            cout << "Posici�n inv�lida. Int�ntalo de nuevo." << endl;
            continue;
        }

        // Colocar la ficha del jugador en la posici�n elegida
        tablero[fila][columna] = jugadorActual;
        movimientos++;

        // Verificar si alguien ha ganado
        if (verificarGanador(tablero, jugadorActual)) {
            imprimirTablero(tablero);
            cout << "�El jugador " << jugadorActual << " ha ganado!" << endl;
            break;
        }

        // Verificar si no quedan movimientos disponibles (empate)
        if (movimientos == 9) {
            imprimirTablero(tablero);
            cout << "�Es un empate!" << endl;
            break;
        }

        // Cambiar al siguiente jugador
        jugadorActual = (jugadorActual == 'X') ? 'O' : 'X';
    }

    return 0;
}
