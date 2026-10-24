#pragma once
#include "NodoAVL.hpp"

class AVL{
    private:
        NodoAVL* raiz;
        int obtenerAltura(NodoAVL* nodo);
        void actualizarAltura(NodoAVL* nodo);
        int factorBalance(NodoAVL* nodo);
        NodoAVL* insertar(NodoAVL* nodo, Paciente paciente);//busca donde colocar el paciente.

    
    public:
        AVL();
        void insertarPaciente(Paciente paciente);

        ~AVL();
};