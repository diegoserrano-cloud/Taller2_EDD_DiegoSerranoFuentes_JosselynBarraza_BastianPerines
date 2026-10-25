#include "AVL.hpp"

AVL::AVL(){
    raiz = nullptr;
}

int AVL::obtenerAltura(const NodoAVL* nodo) const{
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

int AVL::factorBalance(const NodoAVL* nodo) const{
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
    y->setIzquierdo(t2);

    actualizarAltura(y);
    actualizarAltura(x);

    return x;
}

NodoAVL* AVL::rotarIzquierda(NodoAVL* x) {
    NodoAVL* y = x->getDerecho();
    NodoAVL* t2 = y->getIzquierdo();

    y->setIzquierdo(x);
    x->setDerecho(t2);

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

    if (balance > 1 && paciente.getId() < nodo->getIzquierdo()->getPaciente().getId()) {
        return rotarDerecha(nodo);
    }

    if (balance < -1 && paciente.getId() > nodo->getDerecho()->getPaciente().getId()) {
        return rotarIzquierda(nodo);
    }

    if (balance > 1 && paciente.getId() > nodo->getIzquierdo()->getPaciente().getId()) {
        nodo->setIzquierdo(rotarIzquierda(nodo->getIzquierdo()));
        return rotarDerecha(nodo);
    }

    if (balance < -1 && paciente.getId() < nodo->getDerecho()->getPaciente().getId()) {
        nodo->setDerecho(rotarDerecha(nodo->getDerecho()));
        return rotarIzquierda(nodo);
    }

    return nodo;
}

NodoAVL* AVL::nodoMinimo(NodoAVL* nodo) const{
    NodoAVL* actual = nodo;
    while(actual != nullptr && actual->getIzquierdo() != nullptr){
        actual = actual->getIzquierdo();
    }
    return actual;
}

NodoAVL* AVL::eliminar(NodoAVL* nodo, const string& id, bool& eliminado){
    if(nodo == nullptr){
        return nullptr;
    }

    if(id < nodo->getPaciente().getId()){
        nodo->setIzquierdo(eliminar(nodo->getIzquierdo(), id, eliminado));
    }else if(id > nodo->getPaciente().getId()){
        nodo->setDerecho(eliminar(nodo->getDerecho(), id, eliminado));
    }else{
        eliminado = true;
        if(nodo->getIzquierdo() == nullptr || nodo->getDerecho() == nullptr){
            NodoAVL* hijo;
            if (nodo->getIzquierdo() != nullptr) {
                hijo = nodo->getIzquierdo();
            } else {
                hijo = nodo->getDerecho();   
            }
            delete nodo;
            return hijo;
        }

        NodoAVL* sucesor = nodoMinimo(nodo->getDerecho());
        nodo->getPaciente() = sucesor->getPaciente();
        nodo->setDerecho(eliminar(nodo->getDerecho(), sucesor->getPaciente().getId(), eliminado));
    }

    actualizarAltura(nodo);
    int balance = factorBalance(nodo);

    if(balance > 1 && factorBalance(nodo->getIzquierdo()) >= 0){
        return rotarDerecha(nodo);
    }
    if(balance > 1 && factorBalance(nodo->getIzquierdo()) < 0){
        nodo->setIzquierdo(rotarIzquierda(nodo->getIzquierdo()));
        return rotarDerecha(nodo);
    }
    if(balance < -1 && factorBalance(nodo->getDerecho()) <= 0){
        return rotarIzquierda(nodo);
    }
    if(balance < -1 && factorBalance(nodo->getDerecho()) > 0){
        nodo->setDerecho(rotarDerecha(nodo->getDerecho()));
        return rotarIzquierda(nodo);
    }

    return nodo;
}

void AVL::insertarPaciente(Paciente paciente){
    this->raiz = insertar(raiz, paciente);
}

bool AVL::eliminarPaciente(const string& id){
    bool eliminado = false;
    raiz = eliminar(raiz, id, eliminado);
    return eliminado;
}

NodoAVL* AVL::buscarPorId(NodoAVL* nodo, const string& id) {
    if (nodo == nullptr || nodo->getPaciente().getId() == id) {
        return nodo;
    }

    if (id < nodo->getPaciente().getId()) {
        return buscarPorId(nodo->getIzquierdo(), id);
    } else {
        return buscarPorId(nodo->getDerecho(),id);
    }
}

const NodoAVL* AVL::buscarPorId(const NodoAVL* nodo, const string& id) const {
    if (nodo == nullptr || nodo->getPaciente().getId() == id) {
        return nodo;
    }

    if (id < nodo->getPaciente().getId()) {
        return buscarPorId(nodo->getIzquierdo(), id);
    }
    return buscarPorId(nodo->getDerecho(), id);
}

Paciente* AVL::buscarPaciente(const string& id) {
    NodoAVL* resultado = buscarPorId(this->raiz,id);
    if (resultado != nullptr) {
        return &(resultado->getPaciente());
    }
    return nullptr;
}

const Paciente* AVL::buscarPaciente(const string& id) const {
    const NodoAVL* resultado = buscarPorId(this->raiz, id);
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

    preorden(this->raiz);
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

int AVL::getAlturaRuta() const {
    return obtenerAltura(this->raiz);
}

int AVL::getFactorBalanceRaiz() const {
    return factorBalance(this->raiz);
}

int AVL::contarNodos(const NodoAVL* nodo) const {
    if (nodo == nullptr) return 0;
    return 1 + contarNodos(nodo->getIzquierdo()) + contarNodos(nodo->getDerecho());
}

int AVL::contarPacientes() const {
    return contarNodos(raiz);
}

void AVL::destruirRecursivo(NodoAVL* nodo) {
    if (nodo == nullptr) return;
    destruirRecursivo(nodo->getIzquierdo());
    destruirRecursivo(nodo->getDerecho());
    delete nodo;
}

void AVL::buscarPorNombre(NodoAVL* nodo, const string& nombre, int& encontrados){
    if(nodo == nullptr){
        return;
    }

    buscarPorNombre(nodo->getIzquierdo(), nombre, encontrados);

    if(nodo->getPaciente().getNombre() == nombre){
        nodo->getPaciente().mostrarInfo();
        encontrados++;
    }

    buscarPorNombre(nodo->getDerecho(), nombre, encontrados);
}

int AVL::buscarPacientesPorNombre(const string& nombre){
    int encontrados = 0;

    buscarPorNombre(raiz, nombre, encontrados);

    return encontrados;
}

NodoAVL* AVL::buscarPorIdConRuta(NodoAVL* nodo, const string& id, string& ruta) {
    if (nodo == nullptr) {
        return nullptr;
    }

    if (nodo->getPaciente().getId() == id) {
        return nodo;
    }

    if (id < nodo->getPaciente().getId() ) {
        ruta += "0";
        return buscarPorIdConRuta(nodo->getIzquierdo(), id, ruta);
    } else {
        ruta += "1";
        return buscarPorIdConRuta(nodo->getDerecho(), id, ruta);
    }
}

Paciente* AVL::buscarPacienteConRuta(const string& id, string& ruta) {
    ruta = "";
    NodoAVL* resultado = buscarPorIdConRuta(this->raiz, id, ruta);

    if (resultado != nullptr) {
        return &(resultado->getPaciente());
    }
    return nullptr;
}

AVL::~AVL(){
    destruirRecursivo(this->raiz);
    raiz = nullptr;
}