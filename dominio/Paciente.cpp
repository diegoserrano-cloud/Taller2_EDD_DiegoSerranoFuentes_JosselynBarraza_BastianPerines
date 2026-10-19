#include "Paciente.hpp"
#include <iostream>
using namespace std;

Paciente::Paciente(string id, string nombre, int edad, string servicio) 
: Persona(id, nombre, edad), servicio(servicio){}

string Paciente::getServicio() const{
    return servicio;
}

void Paciente::setServicio(string nuevoServicio){
    servicio = nuevoServicio;
}

void Paciente::mostrarInfo() const{
    cout << "ID: " << getId() << "| Nombre: " << getNombre()
         << "| Edad: " << getEdad() << "| Departamento: " << servicio << endl;

}