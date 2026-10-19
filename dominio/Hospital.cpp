#include "Hospital.hpp"
#include <iostream>
using namespace std;

Hospital::Hospital(){
    string servicios[8] = {"Urgencias", "Medicina General", "Cardiologia", "Neurologia", 
                            "Traumatologia", "Cirugia", "Pediatria", "Hospitalizacion"};
    
    NodoServicio* anterior = nullptr;
    primerServicio = nullptr;

    for(int i= 0; i< 8; i++){
        NodoServicio* nuevo = new NodoServicio(servicios[i]);

        if(primerServicio==nullptr){
            primerServicio = nuevo;

        }else{
            anterior->setNextServicio(nuevo);
        }anterior = nuevo;
    }
}

NodoServicio* Hospital::buscarServicio(string nombre) const{
    NodoServicio* cursor = primerServicio;
    while(cursor != nullptr){
        if(cursor->getServicio() == nombre){ 
            return cursor;
        }
        cursor = cursor->getNextServicio();

    }
    return nullptr; // no se encontro el servicio
}

void Hospital::derivarPaciente(Paciente p) {
    string servicio = p.getServicio();
    NodoServicio* nodoServicio = buscarServicio(servicio);
    if(nodoServicio != nullptr){
        NodoPaciente* nuevo = new NodoPaciente(p);
        
        NodoPaciente* primeroDelServicio = nodoServicio->getPacienteLista();

        if (primeroDelServicio == nullptr) {
            nodoServicio->setPrimerPaciente(nuevo);
        } else {
            NodoPaciente* cursor = primeroDelServicio;
            while (cursor->getNext() != nullptr) {
                cursor = cursor->getNext();
            }
            cursor->setNext(nuevo);
        }
    }else{
        cout << "No se encontro el servicio indicado: " << servicio << endl;
    }
    
}

void Hospital::atenderPaciente(Paciente p) {
    derivarPaciente(p);
}

void Hospital::mostrarEstado(){
    NodoServicio* cursor = primerServicio;
    while(cursor!=nullptr){
        cout<<cursor->getServicio()<< ": " << endl;
        NodoPaciente* paciente = cursor->getPacienteLista();
 
        while(paciente!=nullptr){
            cout<<"- "<<paciente->getPaciente().getNombre()<<endl;
            paciente = paciente->getNext();
        }
        cursor = cursor->getNextServicio();
    }
}

void Hospital::mostrarServicio(string nombre) {
    NodoServicio* nodoServicio = buscarServicio(nombre);
    if (nodoServicio != nullptr) {
        cout << "Pacientes en el servicio " << nombre << ":" << endl;
        NodoPaciente* paciente = nodoServicio->getPacienteLista();
        while (paciente != nullptr) {
            cout <<paciente->getPaciente().getNombre() << " ("<<paciente->getPaciente().getEdad()<<")"<<endl;
            paciente = paciente->getNext();
        }
    } else {
        cout << "No existe el servicio: " << nombre << endl;
    }
}

int Hospital::contarPacientes(string nombre){
    NodoServicio* nodoServicio = buscarServicio(nombre);
    int cant = 0;
    if (nodoServicio != nullptr) {
        NodoPaciente* paciente = nodoServicio->getPacienteLista();
        while (paciente != nullptr) {
            cant++;
            paciente = paciente->getNext();
        }
    }return cant;
}

Hospital::~Hospital() {
    NodoServicio* cursor = primerServicio;

    while(cursor != nullptr) {
        NodoPaciente* paciente = cursor->getPacienteLista();
        NodoServicio* temporal = cursor;

        while(paciente != nullptr) {
            NodoPaciente* temp = paciente;
            paciente = paciente->getNext();
            delete temp;
        }
        cursor = cursor->getNextServicio();
        delete temporal;
    }
}