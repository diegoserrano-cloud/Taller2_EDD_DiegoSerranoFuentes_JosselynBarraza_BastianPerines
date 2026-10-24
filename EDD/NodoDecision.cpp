#include "NodoDecision.hpp"

NodoDecision::NodoDecision(Criterio crit) {
    this->esHoja = false;
    this->servicio = "";
    this->criterio = crit;
    this->hijoNo = nullptr;
    this->hijoSi = nullptr;
}

NodoDecision::NodoDecision(string servicio) {
    this->esHoja = true;
    this->servicio = servicio;
    this->criterio = NINGUNO;
    this->hijoNo = nullptr;
    this->hijoSi = nullptr;
}  

bool NodoDecision::evaluar(Paciente* p) {
    if (p == nullptr || esHoja) return false;

    switch(this->criterio) {
        case ES_PEDIATRIA:
            return p->getEdad() < 14;
        case TIENE_TRAUMA:
            return p->getTrauma() == 1;
        case REQUIERE_CIRUGIA:
            return p->getRequiereCirugia() == 1;
        case SINTOMAS_NEUROLOGICOS:
            return p->getSintomasNeurologicos() == 1;
        case TIPO_DOLOR_PECHO:
            return p->getTipoDolor() == "pecho";
        case URGENCIAS_CRITICA:
            return p->getTemperatura() >= 38.5 || p->getDolor() >= 8;
        case HOSPITALIZACION_LARGA:
            return p->getDiasHospitalizacion() >= 2;
        default:
            return false;
    }

    bool NodoDecision::getEsHoja() { 
        return this->esHoja; 
    }

    string NodoDecision::getServicio() {
        return this->servicio;
    }

    Criterio NodoDecision::getCriterio() {
        return this->criterio;
    }

    NodoDecision* NodoDecision::getHijoNo() {
        return this->hijoNo;
    }

    NodoDecision* NodoDecision::getHijoSi() {
        return this->hijoSi;
    }

    void NodoDecision::setHijoSi(NodoDecision* si) {
        this->hijoSi = si;
    }

    void NodoDecision::setHijoNo(NodoDecision* no) {
        this->hijoNo = no;
    }

    NodoDecision::~NodoDecision() {
        //la eliminacion de los nodos decision se gestiona en ArbolDecision.cpp
    }
}
