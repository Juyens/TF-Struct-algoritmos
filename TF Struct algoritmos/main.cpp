#include "Matriz.h"
#include "Textos.h"
#include "Direccion.h"
#include "Pedido.h"
#include "List.h"
#include "HashTable.h"
#include "Graph.h"
#include "Usuario.h"

#include <iostream>
#include <string>
#include <fstream>
#include <queue>
#ifdef _WIN32
#include <conio.h>
#else
#include <termios.h>
#include <unistd.h>
int getch() {
    termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    int ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}
#endif

using namespace std;

List<string> libroReclamos;
List<double> BoletaPrecio;
List<string> BoletaProducto;

HashTable<int, Usuario> users(50);
List<string> pedidosHistorial;
Graph<string, double> rutasEntrega;

int main()
{
    queue<Direccion> direcciones;
    Pedido pedido;
    direccionesStandard(direcciones);

    int const x = 100;
    int const y = 60;
    int proxy;

    for (int f = 0; f < y; f++) {
        for (int c = 0; c < x; c++) {
            if (Inicio[f][c] == 0) Console::ForegroundColor = ConsoleColor::DarkGray;
            if (Inicio[f][c] == 1) Console::ForegroundColor = ConsoleColor::Yellow;
            if (Inicio[f][c] == 2) Console::ForegroundColor = ConsoleColor::White;
            cout << (char)219;
        }
        cout << endl;
    }

    proxy = 0;
    pauseConsole();
    limpiar();

    int opcion;
    int tecla;
    int userIdCounter = 1;

    do {
        tecla = getch();

        switch (tecla) {
        case 53:
        {
            int opcionAvanzada;
            do {
                system("cls");
                imprimiropcion5();
                cout << "1. Gestion de Usuarios (HashTable)\n";
                cout << "2. Historial de Pedidos (List)\n";
                cout << "3. Rutas de Entrega (Graph)\n";
                cout << "0. Volver\n";
                cout << "Ingrese una opcion: ";
                cin >> opcionAvanzada;

                switch (opcionAvanzada) {
                case 1:
                {
                    int sub;
                    do {
                        system("cls");
                        cout << "1. Agregar usuario\n";
                        cout << "2. Buscar usuario por ID\n";
                        cout << "3. Eliminar usuario por ID\n";
                        cout << "4. Mostrar todos los usuarios\n";
                        cout << "0. Volver\n";
                        cout << "Opcion: ";
                        cin >> sub;

                        switch (sub) {
                        case 1:
                        {
                            string nombre, genero, contrasenia;
                            int edad;
                            cout << "Nombre: "; cin.ignore(); getline(cin, nombre);
                            cout << "Edad: "; cin >> edad;
                            cout << "Genero: "; cin.ignore(); getline(cin, genero);
                            cout << "Contrasenia: "; getline(cin, contrasenia);
                            Usuario nuevo(nombre, edad, genero, contrasenia);
                            users.insert(userIdCounter++, nuevo);
                            cout << "Usuario agregado con ID " << userIdCounter - 1 << endl;
                            pauseConsole();
                            break;
                        }
                        case 2:
                        {
                            int id;
                            cout << "Ingrese ID: ";
                            cin >> id;
                            Usuario* u = users.find(id);
                            if (u) u->mostrarUsuario();
                            else cout << "No encontrado.\n";
                            pauseConsole();
                            break;
                        }
                        case 3:
                        {
                            int id;
                            cout << "ID a eliminar: ";
                            cin >> id;
                            users.erase(id);
                            cout << "Intento de eliminacion realizado.\n";
                            pauseConsole();
                            break;
                        }
                        case 4:
                        {
                            cout << "Usuarios registrados:\n";
                            for (unsigned int i = 0; i < users.getCapacity(); ++i) {
                                List<HashEntry<int, Usuario>>& bucket = users.getBucket(i);
                                for (unsigned int j = 0; j < bucket.size(); ++j) {
                                    cout << "ID: " << bucket[j].key << " - ";
                                    bucket[j].value.mostrarUsuario();
                                }
                            }
                            pauseConsole();
                            break;
                        }
                        }
                    }
                    while (sub != 0);
                    break;
                }
                case 2:
                {
                    int sub;
                    do {
                        system("cls");
                        cout << "1. Agregar pedido\n";
                        cout << "2. Ver pedidos\n";
                        cout << "0. Volver\n";
                        cout << "Opcion: ";
                        cin >> sub;

                        switch (sub) {
                        case 1:
                        {
                            string pedido;
                            cin.ignore();
                            cout << "Pedido: ";
                            getline(cin, pedido);
                            pedidosHistorial.push_back(pedido);
                            break;
                        }
                        case 2:
                            cout << "Historial de pedidos:\n";
                            for (uint i = 0; i < pedidosHistorial.size(); ++i)
                                cout << "- " << pedidosHistorial[i] << endl;
                            pauseConsole();
                            break;
                        }
                    }
                    while (sub != 0);
                    break;
                }
                case 3:
                {
                    int sub;
                    do {
                        system("cls");
                        cout << "1. Añadir punto\n";
                        cout << "2. Conectar puntos\n";
                        cout << "3. Mostrar conexiones\n";
                        cout << "0. Volver\n";
                        cout << "Opcion: ";
                        cin >> sub;

                        switch (sub) {
                        case 1:
                        {
                            string nodo;
                            cin.ignore();
                            cout << "Nombre: ";
                            getline(cin, nodo);
                            rutasEntrega.addVertex(nodo);
                            break;
                        }
                        case 2:
                        {
                            string desde, hasta;
                            double dist;
                            cin.ignore();
                            cout << "Desde: "; getline(cin, desde);
                            cout << "Hasta: "; getline(cin, hasta);
                            cout << "Distancia: "; cin >> dist;
                            rutasEntrega.addEdge(desde, hasta, dist);
                            break;
                        }
                        case 3:
                        {
                            rutasEntrega.forEachVertex([] (const string& v) {
                                cout << "Punto: " << v << " conectado a:\n";
                                rutasEntrega.forEachEdge(v, [] (const string& to, double dist) {
                                    cout << "  - " << to << " (distancia: " << dist << ")\n";
                                    });
                                });
                            pauseConsole();
                            break;
                        }
                        }
                    }
                    while (sub != 0);
                    break;
                }
                }
            }
            while (opcionAvanzada != 0);
            break;
        }
        default:
            imprimirTextoConFondo("Opcion invalida", 3, 40, 12, 8);
            pauseConsole();
            break;
        }

    }
    while (opcion != 8);

    return 0;
}