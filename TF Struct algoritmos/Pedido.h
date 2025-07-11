#pragma once

#include "Restaurante.h"
#include "Direccion.h"
#include "Ordenamientos.h"
#include "List.h"

extern List<double> BoletaPrecio;
extern List<string> BoletaProducto;

class Pedido {
private:
    Restaurante r;
    Direccion direccionActual;
    bool direccionCreada = false;

public:
    void CrearDireccion(queue<Direccion>& direcciones) {
        cin.ignore();
        string nueva;
        cout << "Ingrese una nueva direccion: ";
        getline(cin, nueva);
        direccionActual.setDireccion(nueva);
        direccionCreada = true;
        direcciones.push(direccionActual);
        cout << "Direccion creada y guardada." << endl;
        system("pause>0");
    }

    void RealizarPedido() {
        int res = 0;
        int seleccion = 0;
        double total = 0;
        bool ciclo = true;
        string restauranteSeleccionado = "";
        do {
            cout << endl << "Restaurantes disponibles:" << endl;
            cout << "1. " << r.getNombre1() << endl;
            cout << "2. " << r.getNombre2() << endl;
            cout << "3. " << r.getNombre3() << endl;
            cout << "4. " << r.getNombre4() << endl;
            cout << "Seleccione Restaurante (0 para cancelar): ";
            cin >> res;

            if (res == 0) return;

            switch (res) {
            case 1:
                mostrarProductosRecursivo(ProductosEnsalada);
                restauranteSeleccionado = r.getNombre1();
                do
                {
                    seleccion = 0;
                    cout << endl << "Seleccione su pedido (0 para finalizar)"; cin >> seleccion;
                    if (seleccion > 0 && seleccion < 8) {
                        total += ProductosEnsalada[seleccion - 1].precio;
                        cout << endl << "Producto agregado: " << ProductosEnsalada[seleccion - 1].nombre << " - S/." << ProductosEnsalada[seleccion - 1].precio << endl;
                    }

                    if (seleccion == 8)
                    {
                        OrdenarPorBurbuja<int>(ProductosEnsalada);
                        for (int i = 0; i < ProductosEnsalada.size(); i++)
                        {
                            cout << ProductosEnsalada[i].nombre << " - S/ " << ProductosEnsalada[i].precio << endl;
                        }
                    }

                    else if (!(seleccion > 0 && seleccion < 8)) {
                        cout << endl << "La cantidad total es: " << total;
                        BoletaPrecio.push_back(total);
                        system("pause>0");
                        ciclo = false;
                        return;
                    }
                }
                while (ciclo);
                break;

            case 2:
                mostrarProductosRecursivo(ProductosFruta);
                restauranteSeleccionado = r.getNombre2();

                do {
                    seleccion = 0;
                    cout << endl << "Seleccione su pedido (0 para finalizar)"; cin >> seleccion;
                    if (seleccion > 0 && seleccion < 8) {
                        total += ProductosFruta[seleccion - 1].precio;
                        cout << "Producto agregado: " << ProductosFruta[seleccion - 1].nombre << " - S/." << ProductosFruta[seleccion - 1].precio << endl;
                        BoletaProducto.push_back(ProductosFruta[seleccion - 1].nombre);

                    }

                    if (seleccion == 8)
                    {
                        OrdenamientoInsersion<int>(ProductosFruta);
                        for (int i = 0; i < ProductosFruta.size(); i++)
                        {
                            cout << ProductosFruta[i].nombre << " - S/ " << ProductosFruta[i].precio << endl;
                        }
                    }

                    else if (!(seleccion > 0 && seleccion < 8)) {
                        cout << endl << "La cantidad total es: " << total;
                        BoletaPrecio.push_back(total);
                        system("pause>0");
                        ciclo = false;
                        return;
                    }
                }
                while (ciclo);
                break;
            case 3:
                mostrarProductos(ProductosRestaurante, r.getNombre3());
                restauranteSeleccionado = r.getNombre3();
                do {
                    seleccion = 0;
                    cout << endl << "Seleccione su pedido (0 para finalizar)"; cin >> seleccion;
                    if (seleccion > 0 && seleccion < 8) {
                        total += ProductosRestaurante[seleccion - 1].precio;
                        cout << "Producto agregado: " << ProductosRestaurante[seleccion - 1].nombre << " - S/." << ProductosRestaurante[seleccion - 1].precio << endl;
                        BoletaProducto.push_back(ProductosRestaurante[seleccion - 1].nombre);

                    }

                    if (seleccion == 8)
                    {
                        Ordenamientointercambio<int>(ProductosRestaurante);
                        for (int i = 0; i < ProductosRestaurante.size(); i++)
                        {
                            cout << ProductosRestaurante[i].nombre << " - S/ " << ProductosRestaurante[i].precio << endl;
                        }
                    }

                    else if (!(seleccion > 0 && seleccion < 8)) {
                        cout << endl << "La cantidad total es: " << total;
                        BoletaPrecio.push_back(total);
                        system("pause>0");
                        ciclo = false;
                        return;
                    }
                }
                while (ciclo);
                break;
            case 4:
                mostrarProductos(ProductosPostres, r.getNombre4());
                restauranteSeleccionado = r.getNombre4();
                do {
                    seleccion = 0;
                    cout << endl << "Seleccione su pedido (0 para finalizar)"; cin >> seleccion;
                    if (seleccion > 0 && seleccion < 8) {
                        total += ProductosPostres[seleccion - 1].precio;
                        cout << "Producto agregado: " << ProductosPostres[seleccion - 1].nombre << " - S/." << ProductosPostres[seleccion - 1].precio << endl;
                        BoletaProducto.push_back(ProductosPostres[seleccion - 1].nombre);

                    }

                    if (seleccion == 8)
                    {
                        OrdenamientoSleccion<int>(ProductosPostres);
                        for (int i = 0; i < ProductosPostres.size(); i++)
                        {
                            cout << ProductosPostres[i].nombre << " - S/ " << ProductosPostres[i].precio << endl;
                        }
                    }

                    else if (!(seleccion > 0 && seleccion < 8)) {
                        cout << endl << "La cantidad total es: " << total;
                        BoletaPrecio.push_back(total);
                        system("pause>0");
                        ciclo = false;
                        return;
                    }
                }
                while (ciclo);
                break;
            case 0:
                return;
            }

            cout << endl << "Pedido realizado desde " << restauranteSeleccionado
                << " a la direccion " << direccionActual.getDireccion() << endl;
            system("pause>0");
        }
        while (res != 0);
    }
};
