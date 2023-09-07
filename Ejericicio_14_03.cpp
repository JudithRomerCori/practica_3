// Materia: Programación I, Paralelo 1

// Autor: Judith Marisol Romero Cori

// Fecha creación: 6/09/2023

// Fecha modificación: 6/09/2023

// Número de ejericio: 14

// Problema planteado:
#include <iostream>
#include <vector>
#include <algorithm>

struct Candidato
{
    int id;
    string nombre;
    int votos;
};

bool compararPorVotos(const Candidato& a, const Candidato& b) {
    return a.votos > b.votos;
}

int main() {
    int departamentos, candidatos;

    // Solicitar la cantidad de departamentos y candidatos al usuario
    cout << "Ingrese la cantidad de departamentos: ";
    cin >> departamentos;
    cout << "Ingrese la cantidad de candidatos: ";
    cin >> candidatos;

    vector<vector<int>> votos(departamentos, vector<int>(candidatos, 0));
    vector<Candidato> listaCandidatos(candidatos);

    // Ingresar los nombres de los candidatos
    for (int i = 0; i < candidatos; ++i) {
        listaCandidatos[i].id = i + 1;
        cout << "Ingrese el nombre del candidato " << i + 1 << ": ";
        cin >> listaCandidatos[i].nombre;
    }

    // Ingresar los votos por departamento y candidato
    for (int i = 0; i < departamentos; ++i) {
        cout << "Ingrese los votos para el departamento " << i + 1 << ":" << endl;
        for (int j = 0; j < candidatos; ++j) {
            cout << "Votos para " << listaCandidatos[j].nombre << ": ";
            cin >> votos[i][j];
        }
    }

    // Calcular el total de votos por candidato
    for (int j = 0; j < candidatos; ++j) {
        int totalVotos = 0;
        for (int i = 0; i < departamentos; ++i) {
            totalVotos += votos[i][j];
        }
        listaCandidatos[j].votos = totalVotos;
    }

    // Ordenar los candidatos por cantidad de votos (de mayor a menor)
    sort(listaCandidatos.begin(), listaCandidatos.end(), compararPorVotos);

    // Verificar si hay un ganador absoluto
    int totalVotosValidos = 0;
    for (int i = 0; i < departamentos; ++i) {
        totalVotosValidos += votos[i][0]; // Suponemos que el candidato 1 es el ganador
    }

    if (listaCandidatos[0].votos > totalVotosValidos / 2) {
        cout << "El candidato ganador absoluto es: " << listaCandidatos[0].nombre << endl;
    } else {
        cout << "Se requiere una segunda vuelta entre los dos candidatos más votados:" << endl;
        cout << "1. " << listaCandidatos[0].nombre << endl;
        cout << "2. " << listaCandidatos[1].nombre << endl;
    }

    return 0;
}
