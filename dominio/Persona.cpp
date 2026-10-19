#include "Persona.hpp"
#include <iostream>
using namespace std;

Persona::Persona(string id, string nombre, int edad) {
    this->id = id;
    this->nombre = nombre;
    this->edad = edad;
}

string Persona::getId() const {
    return id;
}

string Persona::getNombre() const {
    return nombre;
}

int Persona::getEdad() const {
    return edad;
}

void Persona::mostrarInfo() const {
    cout << "ID: " << id << " - Nombre: " << nombre << " - Edad: " << edad << endl;
}

Persona::~Persona() {
}