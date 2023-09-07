// Materia: Programación I, Paralelo 1

// Autor: Judith Marisol Romero Cori

// Fecha creación: 6/09/2023

// Fecha modificación: 6/09/2023

// Número de ejericio: 13

// Problema planteado:La farmacia FARMACARP tiene N sucursales, leer sus ventas por mes de un año entero de cada sucursal y calcule:
//a. Total, de ventas
//b. Total, de ventas por sucursal.
//c. Sucursal que más ha vendido.
//d. Sucursal que menos ha vendido.

#include <iostream>
#include <vector>

int main()
{
    int N; // Número de sucursales
    int meses = 12; // Número de meses en un año

    // Solicitar el número de sucursales al usuario
    cout << "Ingrese el número de sucursales: ";
    cin >> N;

    // Crear un vector para almacenar las ventas por mes de cada sucursal
    vector<vector<double>> ventas(N, vector<double>(meses, 0.0));

    // Leer las ventas por mes de cada sucursal
    for (int i = 0; i < N; ++i) {
        cout << "Ingrese las ventas de la sucursal " << i + 1 << " por mes:" << endl;
        for (int j = 0; j < meses; ++j) {
            cin >> ventas[i][j];
        }
    }

    // Calcular el total de ventas
    double totalVentas = 0.0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < meses; ++j) {
            totalVentas += ventas[i][j];
        }
    }

    // Calcular el total de ventas por sucursal y encontrar la sucursal que más y menos ha vendido
    double maxVentas = ventas[0][0];
    double minVentas = ventas[0][0];
    int sucursalMaxVentas = 1;
    int sucursalMinVentas = 1;

    for (int i = 0; i < N; ++i) {
        double totalVentasSucursal = 0.0;
        for (int j = 0; j < meses; ++j) {
            totalVentasSucursal += ventas[i][j];
        }

        if (totalVentasSucursal > maxVentas) {
            maxVentas = totalVentasSucursal;
            sucursalMaxVentas = i + 1;
        }

        if (totalVentasSucursal < minVentas) {
            minVentas = totalVentasSucursal;
            sucursalMinVentas = i + 1;
        }

        cout << "Total de ventas de la sucursal " << i + 1 << ": " << totalVentasSucursal << endl;
    }

    // Mostrar resultados
    cout << "a. Total de ventas: " << totalVentas << endl;
    cout << "b. Total de ventas por sucursal." << endl;
    cout << "c. Sucursal que más ha vendido: Sucursal " << sucursalMaxVentas << " (" << maxVentas << " ventas)" << endl;
    cout << "d. Sucursal que menos ha vendido: Sucursal " << sucursalMinVentas << " (" << minVentas << " ventas)" << endl;

    return 0;
}
