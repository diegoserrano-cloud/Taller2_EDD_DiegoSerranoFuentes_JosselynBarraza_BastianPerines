#pragma once
#include "NodoDecision.hpp"

class ArbolDecision {
    private:
        NodoDesicion* raiz;

        void construirArbol();
        string clasificarRecursivo(NodoDesicion* nodo, Paciente* p, string& ruta);
        void preordenRecursivo(NodoDecision* nodo);
        void destruirRecursivo(NodoDecision* nodo);

    public:
        ArbolDecision();
        string clasificarPaciente(Paciente* p, string& rutaDetallada);
        void mostrarPreorden();
        ~ArbolDecision();
};