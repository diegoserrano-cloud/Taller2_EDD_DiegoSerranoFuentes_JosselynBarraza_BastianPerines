#pragma once
#include "../dominio/Paciente.hpp"
#include "NodoPaciente.hpp"    

class Stack{
    private:
        NodoPaciente* top; 
    public:
        Stack(); // Constructor
        void push(Paciente paciente); // Agrega un paciente al historial
        Paciente pop(); // Elimina y devuelve el paciente en la parte superior de la pila
        bool isEmpty() const; // Verifica si la pila está vacía
        void mostrar() const; // Muestra los pacientes en el historial
        ~Stack();
};