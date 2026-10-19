#include "Cola.hpp"
#include <iostream>
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
        cout<<cursor->getPaciente().getId()<< " - " << cursor->getPaciente().getNombre() << endl;
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