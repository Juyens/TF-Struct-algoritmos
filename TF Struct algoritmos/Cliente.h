#pragma once

#include <string>

using namespace std;

class Cliente
{
private:
    string nombre;
public:
    void setnombre(string nombre)
    {
        this->nombre = nombre;
    }
    string getnombre()
    {
        return nombre;
    }
};
