#pragma once

#include <string>
#include <queue>
#include <iostream>
#include "Textos.h"

using namespace std;

class Direccion
{
private:
    string direccion;
public:
    Direccion(const string& d = "") : direccion(d) {}

    string getDireccion() const { return direccion; }
    void setDireccion(const string& d) { direccion = d; }
    void mostrar() const { cout << "- " << direccion << endl; }
};

auto direccionesStandard = [] (queue<Direccion>& direcciones)-> void 
    {
    direcciones.push(Direccion("Manzana A, urbanizacion B, Los Jaminez"));
    direcciones.push(Direccion("Canteras, Lima, Provincia de Lima"));
    };

auto agregarDireccion = [] (queue<Direccion>& direcciones)-> void
    {
    cin.ignore();
    string nueva;
    cout << "Ingrese nueva direccion: ";
    getline(cin, nueva);
    direcciones.push(Direccion(nueva));
    cout << "Direccion agregada" << endl;
    pauseConsole();
    };

auto mostrarDirecciones = [] (queue<Direccion> direcciones)-> void 
    {
    if (direcciones.empty()) {
        cout << "No hay direcciones registradas" << endl;
    }
    else {
        cout << endl << "   * . ' *  Direcciones Guardadas * . ' *" << endl;
        while (!direcciones.empty()) {
            direcciones.front().mostrar();
            direcciones.pop();
        }
    }
    pauseConsole();
    };

void mostrarDireccionesRecursivo(queue<Direccion> direcciones)
{
    if (direcciones.empty()) return;

    direcciones.front().mostrar();
    direcciones.pop();
    mostrarDireccionesRecursivo(direcciones);
    pauseConsole();
}