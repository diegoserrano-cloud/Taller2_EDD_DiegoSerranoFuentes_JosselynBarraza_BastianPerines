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

NodoAVL* AVL::rotarDerecha(NodoAVL* y) {
    NodoAVL* x = y->getIzquierdo();
    NodoAVL* t2 = x->getDerecho();

    x->setDerecho(y);
    y-> setIzquierdo(T2);

    actualizarAltura(y);
    actualizarAltura(x);

    return x;
}

NodoAVL* AVL::rotarIzquierda(NodoAVL* x) {
    NodoAVL* y = x->getIzquierdo();
    NodoAVL* t2 = y->getDerecho();

    y->setDerecho(x);
    x-> setIzquierdo(T2);

    actualizarAltura(x);
    actualizarAltura(y);

    return y;
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

    int balance = factorBalance(nodo);

    if (balance > 1 && paciente.getId() < nodo->getIzquierdo()->getPaciente()->getId()) {
        return rotarDerecha(nodo);
    }

    if (balance < -1 && paciente.getId() > nodo->getIzquierdo()->getPaciente()->getId()) {
        return rotarIzquierda(nodo);
    }

    if (balance > 1 && paciente.getId() > nodo->getIzquierdo()->getPaciente()->getId()) {
        nodo->setIzquierdo(rotarIzquierda(nodo->getIzquierdo()));
        return rotarDerecha(nodo);
    }

    if (balance < -1 && paciente.getId() < nodo->getIzquierdo()->getPaciente()->getId()) {
        nodo->setDerecho(rotarDerecha(nodo->getDerecho()));
        return rotarIzquierda(nodo);
    }

    return nodo;
}

void AVL::insertarPaciente(Paciente paciente){
    this->raiz = insertar(raiz, paciente);
}

NodoAVL* AVL::buscarPorId(NodoAVL* nodo, string id) {
    if (nodo == nullptr || nodo->getPaciente().getId() == id) {
        return nodo;
    }

    if (id < nodo->getPaciente().getId()) {
        return buscarPorId(nodo->getIzquierdo(), id);
    } else {
        return buscarPorId(nodo->getDerecho(),id);
    }
}

Paciente* AVL::buscarPaciente(string id) {
    NodoAVL* resultado = buscarPorId(this->raiz,id);
    if (resultado != nullptr) {
        return &(resultado->getPaciente());
    }
    return nullptr;
}

void AVL::preorden(NodoAVL* nodo) {
    if (nodo == nullptr) return;
    cout << "ID: " << nodo->getPaciente().getId() 
    << " | Nombre: " << nodo->getPaciente().getNombre()
    << " | Edad: " << nodo->getPaciente().getEdad() << endl;
    preorden(nodo->getIzquierdo());
    preorden(nodo->getDerecho());
}

void AVL::inorden(NodoAVL* nodo) {
    if (nodo == nullptr) return;
    inorden(nodo->getIzquierdo());
    cout << "ID: " << nodo->getPaciente().getId() 
         << " | Nombre: " << nodo->getPaciente().getNombre()
         << " | Edad: " << nodo->getPaciente().getEdad() << endl;
    inorden(nodo->getDerecho());
}

void AVL::postorden(NodoAVL* nodo) {
    if (nodo == nullptr) return;
    postorden(nodo->getIzquierdo());
    postorden(nodo->getDerecho());
    cout << "ID: " << nodo->getPaciente().getId() 
         << " | Nombre: " << nodo->getPaciente().getNombre()
         << " | Edad: " << nodo->getPaciente().getEdad() << endl;
}

void AVL::mostrarPreorden() {
    if (this->raiz == nullptr) {
        cout << "Sin pacientes registrados en este servicio." << endl;
        return;
    }

    preoorden(this->raiz);
}

void AVL::mostrarInorden() {
    if (this->raiz == nullptr) {
        cout << "Sin pacientes registrados en este servicio." << endl;
        return;
    }

    inorden(this->raiz);
}

void AVL::mostrarPostorden() {
    if (this->raiz == nullptr) {
        cout << "Sin pacientes registrados en este servicio." << endl;
        return;
    }

    postorden(this->raiz);
}

int AVL::getAltura() {
    return obtenerAltura(this->raiz);
}

int AVL::getFactorBalanceRaiz() {
    return factorBalance(this->raiz);
}

void AVL::destruirRecursivo(NodoAVL* nodo) {
    if (nodo == nullptr) return;
    destruirRecursivo(nodo->getIzquierdo());
    destruirRecursivo(nodo->getDerecho());
    delete nodo;
}

AVL::~AVL(){
    destruirRecursivo(this->raiz);
}

AVL::~AVL(){
    
}