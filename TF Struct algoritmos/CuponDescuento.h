#pragma once

#include <string>

using namespace std;

class CuponDescuento
{
private:
    string codigo;
    double descuento;
public:
    void setcodigo(string codigo)
    {
        this->codigo = codigo;
    }
    string getcodigo()
    {
        return codigo;
    }
};
