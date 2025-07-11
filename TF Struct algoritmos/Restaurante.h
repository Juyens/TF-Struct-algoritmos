#pragma once

#include <string>

using namespace std;

class Restaurante 
{
private:
    string nombre1 = "Ensaladas el 'Zapallo enojado'";
    string nombre2 = "Fruteria Bananini Peladini";
    string nombre3 = "Restaurante el Factan";
    string nombre4 = "Postres maxi";

public:
    string getNombre1() const { return nombre1; }
    string getNombre2() const { return nombre2; }
    string getNombre3() const { return nombre3; }
    string getNombre4() const { return nombre4; }
};