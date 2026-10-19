#pragma once
#include "../dominio/Paciente.hpp"
#include "NodoPaciente.hpp"

class Cola{
    private:
        NodoPaciente* primero;
        NodoPaciente* ultimo;
    public:
        Cola();

        void AgregarPaciente(Paciente paciente);
        Paciente eliminarPaciente();
        bool isEmpty();
        void mostrar();
        bool existeId(string id) const;

        ~Cola();

};
