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
        nodoServicio->getArbolPacientes().insertarPaciente(p);
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
        cursor->getArbolPacientes().mostrarInorden();
        cursor = cursor->getNextServicio();
    }
}

void Hospital::mostrarServicio(string nombre) {
    NodoServicio* nodoServicio = buscarServicio(nombre);
    if (nodoServicio != nullptr) {
        cout << "Pacientes en el servicio " << nombre << ":" << endl;
        nodoServicio->getArbolPacientes().mostrarInorden();
    } else {
        cout << "No existe el servicio: " << nombre << endl;
    }
}

int Hospital::contarPacientes(string nombre){
    NodoServicio* nodoServicio = buscarServicio(nombre);
    if (nodoServicio != nullptr) {
        return nodoServicio->getArbolPacientes().contarPacientes();
    }
    return 0;
}

Paciente* Hospital::buscarPaciente(string id){
    NodoServicio* cursor = primerServicio;

    while(cursor!= nullptr){
        Paciente* encontrado = cursor->getArbolPacientes().buscarPaciente(id);

        if(encontrado != nullptr){
            return encontrado;
        }

        cursor = cursor->getNextServicio();

    }

    return nullptr;
}

Paciente* Hospital::buscarPacienteConRuta(string id, string& ruta) {
    NodoServicio* cursor = primerServicio;

    while(cursor!=nullptr) {
        ruta = "";
        Paciente* encontrado = cursor->getArbolPacientes().buscarPacienteConRuta(id,ruta);
        if (encontrado != nullptr) {
            return encontrado;
        }

        cursor = cursor->getNextServicio();
    }
    ruta = "";
    return nullptr;
}

bool Hospital::eliminarPaciente(string id){
    NodoServicio* cursor = primerServicio;
    while(cursor != nullptr){
        if(cursor->getArbolPacientes().eliminarPaciente(id)){
            return true;
        }
        cursor = cursor->getNextServicio();
    }
    return false;
}

int Hospital::buscarPacientesPorNombre(string nombre){
    NodoServicio* cursor = primerServicio;
    int encontrados = 0;

    while(cursor != nullptr){
        encontrados += cursor->getArbolPacientes().buscarPacientesPorNombre(nombre);

        cursor = cursor->getNextServicio();
    }

    return encontrados;
}

Hospital::~Hospital() {
    NodoServicio* cursor = primerServicio;

    while(cursor != nullptr) {
        NodoServicio* temporal = cursor;
        cursor = cursor->getNextServicio();
        delete temporal;
    }
}