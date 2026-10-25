#pragma once
#include "../dominio/Paciente.hpp"

class NodoAVL{
    private:
        Paciente paciente;
        NodoAVL* izquierdo; //pacientes ID menor
        NodoAVL* derecho; //pacientes ID mayor
        int altura;
    public:
        NodoAVL(Paciente p);

        Paciente& getPaciente();
        const Paciente& getPaciente() const;
        NodoAVL* getIzquierdo() const;
        NodoAVL* getDerecho() const;
        int getAltura() const;

        void setIzquierdo(NodoAVL* nuevo);
        void setDerecho(NodoAVL* nuevo);
        void setAltura(int nuevaAltura);

};