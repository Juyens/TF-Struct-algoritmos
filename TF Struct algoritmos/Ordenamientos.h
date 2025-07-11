#pragma once

#include "Producto.h"
#include "Textos.h"
#include "Matriz.h"

template<typename T>
void OrdenarPorBurbuja(vector<Productos>& productos) {
    T n = productos.size();
    for (T i = 0; i < n - 1; ++i) {
        for (T j = 0; j < n - i - 1; ++j) {
            if (productos[j].precio > productos[j + 1].precio) {
                swap(productos[j], productos[j + 1]);
            }
        }
    }
}

template <typename T>
void Ordenamientointercambio(vector<Productos>& productos) {
    T n = productos.size();
    for (T i = 0; i < n - 1; i++) {
        for (T j = i + 1; j < n; j++) {
            if (productos[i].precio > productos[j].precio) {
                swap(productos[i], productos[j]);
            }
        }
    }
}

template <typename T>
void OrdenamientoSleccion(vector<Productos>& productos) {
    T n = productos.size();
    for (T i = 0; i < n - 1; i++) {
        T minimo = i;
        for (T j = i + 1; j < n; j++) {
            if (productos[j].precio < productos[minimo].precio) {
                minimo = j;
            }
        }
        if (minimo != i) {
            swap(productos[i], productos[minimo]);
        }
    }
}

template <typename T>
void OrdenamientoInsersion(vector<Productos>& productos) {
    T n = productos.size();
    for (T i = 1; i < n; i++) {
        auto actual = productos[i];
        T j = i - 1;
        while (j >= 0 && productos[j].precio > actual.precio) {
            productos[j + 1] = productos[j];
            j--;
        }
        productos[j + 1] = actual;
    }
}

void ordenarProductosPorRestaurante() {
    int opcion;
    do {
        int yxx = 18;

        imprimirTextoConFondo("              (`-') _(`-')   (`-')  _<-. (`-')_ (`-')  _    (`-')  ", 0, yxx++, 15, 8);
        imprimirTextoConFondo("     .->   <-.(OO )( (OO ).->( OO).-/   \\( OO) )(OO ).-/ <-.(OO )  ", 0, yxx++, 15, 8);
        imprimirTextoConFondo("(`-')----. ,------,)<'\\    .'_(,------.,--./ ,--/ / ,---.  ,------,) ", 0, yxx++, 15, 8);
        imprimirTextoConFondo("( OO).-.  '|   /`. ''`'-..__)|  .---'|   \\ |  | | \\ /`.\\ |   /`. ' ", 0, yxx++, 15, 8);
        imprimirTextoConFondo("( _) | |  ||  |_.' ||  |  ' (|  '--. |  . '|  |)'-'|_.' ||  |_.' | ", 0, yxx++, 15, 8);
        imprimirTextoConFondo(" \\|  |)|  ||  .   .'|  |  / :|  .--' |  |\\    |(|  .-.  ||  .   .' ", 0, yxx++, 15, 8);
        imprimirTextoConFondo("  '  '-'  '|  |\\  \\ |  '-'  /|  `---.|  | \\   | |  | |  ||  |\\  \\  ", 0, yxx++, 15, 8);
        imprimirTextoConFondo("   `-----' `--' '--'`------' `------'`--'  `--' `--' `--'`--' '--' ", 0, yxx++, 15, 8);
        imprimirTextoConFondo("               productos por precio (Menor a mayor)", 0, yxx++, 15, 8);
        imprimirTextoConFondo("[1] Ensaladas el 'Zapallo enojado'", 0, yxx++, 15, 8);
        imprimirTextoConFondo("[2] Fruteria Bananini Peladini", 0, yxx++, 15, 8);
        imprimirTextoConFondo("[3] Restaurante el Factan", 0, yxx++, 15, 8);
        imprimirTextoConFondo("[4] Postres Maxi", 0, yxx++, 15, 8);
        imprimirTextoConFondo("[5] Volver", 0, yxx++, 15, 8);
        imprimirTextoConFondo("Seleccione un restaurante: ", 0, yxx++, 15, 8);

        cin >> opcion;

        switch (opcion) {
        case 1:
            OrdenarPorBurbuja<int>(ProductosEnsalada);
            cout << "\nProductos ordenados (Ensaladas):\n";
            for (auto& p : ProductosEnsalada)
                cout << p.nombre << " - S/." << p.precio << endl;
            system("pause>0");
            break;
        case 2:
            OrdenamientoInsersion<int>(ProductosFruta);
            cout << "\nProductos ordenados (Frutas):\n";
            for (auto& p : ProductosFruta)
                cout << p.nombre << " - S/." << p.precio << endl;
            system("pause>0");
            break;
        case 3:
            Ordenamientointercambio<int>(ProductosRestaurante);
            cout << "\nProductos ordenados (Comida):\n";
            for (auto& p : ProductosRestaurante)
                cout << p.nombre << " - S/." << p.precio << endl;
            system("pause>0");
            break;
        case 4:
            OrdenamientoSleccion<int>(ProductosPostres);
            cout << "\nProductos ordenados (Postres):\n";
            for (auto& p : ProductosPostres)
                cout << p.nombre << " - S/." << p.precio << endl;
            system("pause>0");
            break;
        case 5:
            return;
        default:
            cout << "Opcion invalida\n";
            system("pause>0");
            limpiar();
            imprimiropcion4();
        }
    }
    while (opcion != 5);
}
