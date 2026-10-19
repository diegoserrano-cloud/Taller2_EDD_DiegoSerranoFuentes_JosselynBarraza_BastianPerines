#pragma once
#include "Persona.hpp"
#include <string>
using namespace std;

class Paciente : public Persona{
    private:
        string servicio;
    public:
        Paciente(string id, string nombre, int edad, string servicio);

        string getServicio() const;
        void setServicio(string nuevoServicio);

        void mostrarInfo() const override;
};