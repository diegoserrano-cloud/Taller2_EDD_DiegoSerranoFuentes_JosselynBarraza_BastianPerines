#pragma once
#include "NodoAVL.hpp"

class AVL{
    private:
        NodoAVL* raiz;
        int obtenerAltura(NodoAVL* nodo);
        void actualizarAltura(NodoAVL* nodo);
        int factorBalance(NodoAVL* nodo);
    
    public:
        AVL();
        ~AVL();
};