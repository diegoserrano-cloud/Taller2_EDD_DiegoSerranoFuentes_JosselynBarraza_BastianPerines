#pragma once
#include <string>
#include "NodoPaciente.hpp"
using namespace std;

class NodoServicio{
    private:
        NodoServicio* next;
        NodoPaciente* primero;
        string nombre;
    public:
        NodoServicio(string nombre);

        string getServicio() const;
        NodoServicio* getNextServicio() const;
        NodoPaciente* getPacienteLista() const;

        void setNextServicio(NodoServicio* nuevo);
        void setPrimerPaciente(NodoPaciente* p);
};