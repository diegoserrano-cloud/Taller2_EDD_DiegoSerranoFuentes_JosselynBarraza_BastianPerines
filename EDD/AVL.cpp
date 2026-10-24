#include "AVL.hpp"

AVL::AVL(){
    raiz = nullptr;
}

int AVL::obtenerAltura(NodoAVL* nodo){
    if(nodo == nullptr){
        return 0;
    }
    return nodo->getAltura();
}

void AVL::actualizarAltura(NodoAVL* nodo){
    if(nodo == nullptr){
        return;
    }

    int izquierda = obtenerAltura(nodo->getIzquierdo());
    int derecha = obtenerAltura(nodo->getDerecho());

    if(izquierda > derecha){
        nodo->setAltura(izquierda + 1);
    }

    else{
        nodo->setAltura(derecha + 1);
    }
}

int AVL::factorBalance(NodoAVL* nodo){
    if(nodo==nullptr){
        return 0;
    }

    int izquierda = obtenerAltura(nodo->getIzquierdo());
    int derecha = obtenerAltura(nodo->getDerecho());

    return izquierda - derecha;
}

NodoAVL* AVL::insertar(NodoAVL* nodo, Paciente paciente){ //busca donde colocar el paciente de forma recursiva.
    if(nodo == nullptr){
        return new NodoAVL(paciente);
    }

    if(paciente.getId() < nodo->getPaciente().getId()){
        nodo->setIzquierdo(insertar(nodo->getIzquierdo(), paciente));
    }

    else if(paciente.getId() > nodo->getPaciente().getId()){
        nodo->setDerecho(insertar(nodo->getDerecho(), paciente));
    }

    else{
        return nodo;
    }

    actualizarAltura(nodo);

    return nodo;
}

void AVL::insertarPaciente(Paciente paciente){
    raiz = insertar(raiz, paciente);
}

AVL::~AVL(){
    
}