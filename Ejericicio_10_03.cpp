
// Materia: Programación I, Paralelo 1

// Autor: Judith Marisol Romero Cori

// Fecha creación: 6/09/2023

// Fecha modificación: 6/09/2023

// Número de ejericio: 10

// Problema planteado:Queremos realizar una encuesta a 10 personas, en esta encuesta indicaremos el sexo (1=masculino, 2=femenino), si trabaja (1=si trabaja, 2= no trabaja) y su sueldo (si tiene un trabajo, sino sera un cero) estará entre 600 y 2000 (valor entero). Los valores pueden ser generados aleatoriamente. Calcula y muestra lo siguiente:
//• Porcentaje de hombres (tengan o no trabajo).
//• Porcentaje de mujeres (tengan o no trabajo).
//• Porcentaje de hombres que trabajan.
//• Porcentaje de mujeres que trabajan.
//• El sueldo promedio de las hombres que trabajan.
//• EL sueldo promedio de las mujeres que trabajan.

#include <iostream>
#include <cstdlib> // Para generar números aleatorios
#include <ctime>   // Para inicializar la semilla del generador de números aleatorios

int main()
{
    // Inicializar la semilla del generador de números aleatorios
    srand(static_cast<unsigned int>(time(nullptr)));

    int personas = 10;
    int hombres = 0;
    int mujeres = 0;
    int hombresTrabajan = 0;
    int mujeresTrabajan = 0;
    int sueldoTotalHombres = 0;
    int sueldoTotalMujeres = 0;

    for (int i = 0; i < personas; ++i) {
        int sexo = rand() % 2 + 1; // Generar aleatoriamente 1 o 2 para el sexo
        int trabaja = rand() % 2 + 1; // Generar aleatoriamente 1 o 2 para si trabaja
        int sueldo = 0;

        if (trabaja == 1) {
            sueldo = rand() % 1401 + 600; // Generar un sueldo aleatorio entre 600 y 2000
        }

        if (sexo == 1) {
            hombres++;
            if (trabaja == 1) {
                hombresTrabajan++;
                sueldoTotalHombres += sueldo;
            }
        } else {
            mujeres++;
            if (trabaja == 1) {
                mujeresTrabajan++;
                sueldoTotalMujeres += sueldo;
            }
        }
    }

    // Calcular los porcentajes
    double porcentajeHombres = (static_cast<double>(hombres) / personas) * 100.0;
    double porcentajeMujeres = (static_cast<double>(mujeres) / personas) * 100.0;
    double porcentajeHombresTrabajan = (static_cast<double>(hombresTrabajan) / hombres) * 100.0;
    double porcentajeMujeresTrabajan = (static_cast<double>(mujeresTrabajan) / mujeres) * 100.0;
    double sueldoPromedioHombres = (hombresTrabajan > 0) ? (static_cast<double>(sueldoTotalHombres) / hombresTrabajan) : 0;
    double sueldoPromedioMujeres = (mujeresTrabajan > 0) ? (static_cast<double>(sueldoTotalMujeres) / mujeresTrabajan) : 0;


    cout << "Porcentaje de hombres: " << porcentajeHombres << "%" << endl;
    cout << "Porcentaje de mujeres: " << porcentajeMujeres << "%" << endl;
    cout << "Porcentaje de hombres que trabajan: " << porcentajeHombresTrabajan << "%" << endl;
    cout << "Porcentaje de mujeres que trabajan: " << porcentajeMujeresTrabajan << "%" << endl;
    cout << "Sueldo promedio de hombres que trabajan: " << sueldoPromedioHombres << endl;
    cout << "Sueldo promedio de mujeres que trabajan: " << sueldoPromedioMujeres << endl;

    return 0;
}
