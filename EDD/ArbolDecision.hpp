#pragma once
#include "NodoDecision.hpp"

class ArbolDecision {
    private:
        NodoDecision* raiz;

        void construirArbol();
        string clasificarRecursivo(NodoDecision* nodo, Paciente* p, string& ruta);
        void preordenRecursivo(NodoDecision* nodo);
        void inordenRecursivo(NodoDecision* nodo);
        void postordenRecursivo(NodoDecision* nodo);
        void destruirRecursivo(NodoDecision* nodo);

    public:
        ArbolDecision();
        string clasificarPaciente(Paciente* p, string& rutaDetallada);
        void mostrarPreorden();
        void mostrarInorden();
        void mostrarPostorden();
        ~ArbolDecision();
};