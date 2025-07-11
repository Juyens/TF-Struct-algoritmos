#pragma once

#include <string>
#include <vector>
#include <iostream>

using namespace std;

struct Productos
{
    string nombre;
    double precio;
};

void mostrarProductos(vector<Productos> Productos, string funcion) 
{
    cout << endl << "lista de productos de " << funcion;
    for (int i = 0; i < Productos.size(); i++)
    {
        cout << Productos[i].nombre << "  - S/." << Productos[i].precio << endl;
    }
}

void mostrarProductosRecursivo(vector<Productos>& productos, int i = 0) {
    if (i >= productos.size()) return;

    cout << productos[i].nombre << " - S/." << productos[i].precio << endl;
    mostrarProductosRecursivo(productos, i + 1);
}

//-------------------------------------------------------- PRODUCTOS -------------------------------------------------------------

vector<Productos> ProductosEnsalada =
{
    {"Ensalada simple" , 4.50},
    {"Ensalada compuesta", 5.00 },
    {"Ensalada rusa", 3.00 },
    {"Tabulete", 4.00},
    {"Ensalada al estilo griego", 9.00 },
    {"Ensalada de pollo", 7.00 },
    {"Ensalada nivel de los dioses", 99.90 }
};

vector<Productos> ProductosRestaurante =
{
    {"Pollo al horno" , 14.25},
    {"Ceviche", 12.00 },
    {"Tallarin salteado", 15.00 },
    {"Arroz chaufa", 14.00},
    {"Pachamanca", 14.00 },
    {"Juane", 10.00},
    {"Tacacho", 7.00},
};

vector<Productos> ProductosFruta =
{
    {"Manzana" , 4.00},
    {"Platano", 0.30 },
    {"Mandarina", 0.20 },
    {"Coco", 3.00},
    {"Guayaba", 1.20 },
    {"Pera", 0.30},
    {"Fruta gomu gomu", 9.99}
};

vector<Productos> ProductosPostres =
{
    {"Tiramisu" , 32.00},
    {"Waffles de la upc", 12.50 },
    {"Arroz con leche", 2.50 },
    {"Helado cookies n cream de un Litro", 15.00},
    {"Chocolate cancun", 1.50 },
    {"Helado de vainilla legendario (extra manjar blanco, extra chocolate, extras grajeas de chocolate y pinguinos)", 100.0},
    {"Rosquitas de ajonjoli", 9.99}
};