#include <iostream>
#include <string>
#include <queue>
#include <fstream>

#include "conio.h"

using namespace std;

class Usuario 
{
private:
    string nombre;
    int edad;
    string genero;
    string contrasenia;

public:
    Usuario(string n = "", int e = 0, string g = "", string c = "") :
        nombre(n), edad(e), genero(g), contrasenia(c) {
    }

    void setNombre(const string& n) { nombre = n; }
    string getNombre() const { return nombre; }
    int getEdad() const { return edad; }
    string getGenero() const { return genero; }

    void mostrarUsuario() const {
        cout << "Nombre: " << nombre << ", Edad: " << edad
            << ", Género: " << genero << endl;
    }
};