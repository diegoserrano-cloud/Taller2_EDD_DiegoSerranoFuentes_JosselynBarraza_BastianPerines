#include "Cola.hpp"
#include <iostream>
#include <stdexcept> //permite manejar errores mediante excepciones (la uso en la linea 23 para que revisen)

using namespace std;

Cola::Cola() : primero(nullptr), ultimo(nullptr){}

void Cola::AgregarPaciente(Paciente paciente){
    NodoPaciente* nuevo = new NodoPaciente(paciente); //creamos el nuevo nodo
    if(isEmpty()){
        primero = nuevo;
        ultimo = nuevo;
    }else{
        ultimo->setNext(nuevo);
        ultimo = nuevo;
    }
}

Paciente Cola::eliminarPaciente(){
    NodoPaciente* temporal = primero;
    if(isEmpty()){
        throw runtime_error("La cola esta vacia");
    }

    Paciente p = temporal->getPaciente();
    primero = primero->getNext();

    if(primero == nullptr){
        ultimo= nullptr;
    }
    delete temporal;
    return p;
}

bool Cola::isEmpty(){
    return primero == nullptr;
}

void Cola::mostrar(){
    NodoPaciente* cursor = primero;
    while(cursor!= nullptr){
        cursor->getPaciente().mostrarInfo();
        cursor = cursor->getNext();
    }
}

bool Cola::existeId(string id) const {
    NodoPaciente* cursor = primero;
    while (cursor != nullptr) {
        if (cursor->getPaciente().getId() == id) {
            return true; // Se encontró el ID
        }
        cursor = cursor->getNext();
    }
    return false; // No se encontró el ID
}   

Cola::~Cola(){
    while(!isEmpty()){
        eliminarPaciente();
    }
}