#pragma once

#include <string>

using namespace std;

class MetodoPago 
{
private:
    string tipo;
public:
    void setmetododepago(string tipo)
    {
        this->tipo = tipo;
    }
    string getmetododepago()
    {
        return tipo;
    }
};