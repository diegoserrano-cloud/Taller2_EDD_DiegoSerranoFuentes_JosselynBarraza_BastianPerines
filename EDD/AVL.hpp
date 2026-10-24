#pragma once
#include "NodoAVL.hpp"
#include <iostream>
#include <string>

using namespace std;

class AVL{
    private:
        NodoAVL* raiz;

        int obtenerAltura(NodoAVL* nodo);
        void actualizarAltura(NodoAVL* nodo);
        int factorBalance(NodoAVL* nodo);
        NodoAVL* rotarDerecha(NodoAVL* y);
        NodoAVL* rotarIzquierda(NodoAVL* x);
        NodoAVL* insertar(NodoAVL* nodo, Paciente paciente);//busca donde colocar el paciente.
        NodoAVL* buscarPorId(NodoAVL* nodo, string id);
        void preorden(NodoAVL* nodo);
        void inorden(NodoAVL* nodo);
        void postorden(NodoAVL* nodo);
        void destruirRecursivo(NodoAVL* nodo);
    
    public:
        AVL();
        void insertarPaciente(Paciente paciente);
        Paciente* buscarPaciente(string id);

        void mostrarPreorden();
        void mostrarInorden();
        void mostrarPostorden();

        int getAlturaRuta();
        int getFactorBalanceRaiz();

        ~AVL();
};