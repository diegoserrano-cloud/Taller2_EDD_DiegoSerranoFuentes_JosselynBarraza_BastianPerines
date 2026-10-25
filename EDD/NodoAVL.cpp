#include "NodoAVL.hpp"

NodoAVL::NodoAVL(Paciente p) : 
    paciente(p), izquierdo(nullptr), 
    derecho(nullptr), altura(1) {}

Paciente& NodoAVL::getPaciente(){
    return this->paciente;
}

const Paciente& NodoAVL::getPaciente() const{
    return this->paciente;
}

NodoAVL* NodoAVL::getIzquierdo() const{
    return izquierdo;
}

NodoAVL* NodoAVL::getDerecho() const{
    return derecho;
}

int NodoAVL::getAltura() const{
    return altura;
}

void NodoAVL::setIzquierdo(NodoAVL* nuevo){
    izquierdo = nuevo;
}

void NodoAVL::setDerecho(NodoAVL* nuevo){
    derecho = nuevo;
}

void NodoAVL::setAltura(int nuevaAltura){
    altura = nuevaAltura;
}
