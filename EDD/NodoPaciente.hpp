#pragma once
#include "../dominio/Paciente.hpp"

class NodoPaciente{
    private:
        Paciente paciente;
        NodoPaciente* next;
    public:
        NodoPaciente(Paciente paciente);
        Paciente getPaciente() const;
        NodoPaciente* getNext() const;

        void setNext(NodoPaciente* nuevoNext);
};