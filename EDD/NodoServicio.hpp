#pragma once
#include <string>
#include "AVL.hpp"
using namespace std;

class NodoServicio{
    private:
        NodoServicio* next;
        AVL pacientes;
        string nombre;
    public:
        NodoServicio(string nombre);

        string getServicio() const;
        NodoServicio* getNextServicio() const;
        AVL& getArbolPacientes();
        const AVL& getArbolPacientes() const;

        void setNextServicio(NodoServicio* nuevo);
};