#include <iostream>
#include "ArbolDecision.hpp"
using namespace std;

ArbolDecision::ArbolDecision() {
    construirArbol();
}

void ArbolDecision::construirArbol() {
    this->raiz = new NodoDecision(ES_PEDIATRIA);
    this->raiz->setHijoSi(new NodoDecision("Pediatria"));

    NodoDecision* nTrauma = new NodoDecision(TIENE_TRAUMA);
    this->raiz->setHijoNo(nTrauma);

    NodoDecision* nCirugia = new NodoDecision(REQUIERE_CIRUGIA);
    nTrauma->setHijoSi(nCirugia);
    nCirugia->setHijoSi(new NodoDecision("Cirugia"));
    nCirugia->setHijoNo(new NodoDecision("Traumatologia"));

    NodoDesicion* nNeuro = new NodoDecision(SINTOMAS_NEUROLOGICOS);
    nTrauma->setHijoNo(nNeuro);
    nNeuro->sethijoSi(new NodoDecision("Neurologia"));

    NodoDecision* nPecho = new NodoDecision(TIPO_DOLOR_PECHO);
    nNeuro->setHijoNo(nPecho);
    nPecho->setHijoSi(new NodoDecision("Cardiologia"));

    NodoDecision* nUrgencia = new NodoDecision(URGENCIAS_CRITICA);
    nPecho->setHijoNo(nUrgencia);
    nUrgencia->setHijoSi(new NodoDecision("Urgencias"));

    NodoDecision* nHosp = new NodoDecision(HOSPITALIZACION_LARGA);
    nUrgencia->setHijoNo(nHosp);
    nHosp->setHijoSi(new NodoDecision("Hospitalizacion"));
    nHosp->setHijoNo(new NodoDecision("Medicina General"));
}

string ArbolDesicion::ClasificarRecursivo(NodoDecision* nodo, Paciente* p, string& ruta) {
    if (nodo == nullptr) return "Medicina General"; 

    if (nodo->getEsHoja()) {
        return nodo->getServicio();
    }

    if (nodo->evaluar(p)) {
        ruta += " -> SI";
        return clasificarRecursivo(nodo->getHijoSi(), p, ruta);
    } else {
        ruta += " -> NO";
        return clasificarRecursivo(nodo->getHijoNo(), p, ruta);
    }
}

string ArbolDesicion::clasificarPaciente(Paciente* p, string& rutaDetallada) {
    rutaDetallada = "Raiz(inicio)";
    return clasificarRecursivo(this->raiz, p, rutaDetallada);
}

void ArbolDesicion::preordenRecursivo(NodoDecision* nodo) {
    if (nodo == nullptr) return;

    if (nodo->getEsHoja()) {
        cout << "[hoja: " << nodo->getServicio() << "] ";
    } else {
        cout << "[Nodo Decision] ";
    }

    preordenRecursivo(Nodo->getHijoSi());
    preordenRecursivo(Nodo->getHijoNo());
}

void ArbolDecision::mostrarPreorden() {
    preordenRecursivo(this->raiz);
    cout << endl;
}

void ArbolDecision::destruirRecursivo(NodoDecision* nodo) {
    if (nodo == nullptr) return;
    destruirRecursivo(nodo->getHijoSi());
    destruirRecursivo(nodo->getHijoNo());
    delete nodo;
}

ArbolDecision::~ArbolDecision() {
    destruirRecursivo(this->raiz);
}