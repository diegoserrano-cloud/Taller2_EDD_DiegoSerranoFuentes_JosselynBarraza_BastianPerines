#pragma once
#include "NodoAVL.hpp"
#include <iostream>
#include <string>

using namespace std;

class AVL{
    private:
        NodoAVL* raiz;

        int obtenerAltura(const NodoAVL* nodo) const;
        void actualizarAltura(NodoAVL* nodo);
        int factorBalance(const NodoAVL* nodo) const;
        NodoAVL* rotarDerecha(NodoAVL* y);
        NodoAVL* rotarIzquierda(NodoAVL* x);
        NodoAVL* insertar(NodoAVL* nodo, Paciente paciente);//busca donde colocar el paciente.
        NodoAVL* eliminar(NodoAVL* nodo, const string& id, bool& eliminado);
        NodoAVL* nodoMinimo(NodoAVL* nodo) const;
        NodoAVL* buscarPorId(NodoAVL* nodo, const string& id);
        const NodoAVL* buscarPorId(const NodoAVL* nodo, const string& id) const;
        void preorden(NodoAVL* nodo);
        void inorden(NodoAVL* nodo);
        void postorden(NodoAVL* nodo);
        void destruirRecursivo(NodoAVL* nodo);
        int contarNodos(const NodoAVL* nodo) const;
        void buscarPorNombre(NodoAVL* nodo, const string& nombre, int& encontrados);
        NodoAVL* buscarPorIdConRuta(NodoAVL* nodo, const string& id, string& ruta);
    
    public:
        AVL();
        AVL(const AVL&) = delete;
        AVL& operator=(const AVL&) = delete;

        void insertarPaciente(Paciente paciente);
        bool eliminarPaciente(const string& id);
        Paciente* buscarPaciente(const string& id);
        const Paciente* buscarPaciente(const string& id) const;

        void mostrarPreorden();
        void mostrarInorden();
        void mostrarPostorden();

        int getAlturaRuta() const;
        int getFactorBalanceRaiz() const;
        int contarPacientes() const;
        int buscarPacientesPorNombre(const string& nombre);

        Paciente* buscarPacienteConRuta(const string& id, string& ruta);
        ~AVL();
};