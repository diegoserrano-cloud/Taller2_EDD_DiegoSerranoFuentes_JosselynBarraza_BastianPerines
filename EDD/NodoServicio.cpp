#include "NodoServicio.hpp"

NodoServicio::NodoServicio(string nombre) : next(nullptr), nombre(nombre) {}

string NodoServicio::getServicio() const{return nombre;}
NodoServicio* NodoServicio::getNextServicio() const{return next;}
AVL& NodoServicio::getArbolPacientes(){return this->pacientes;}
const AVL& NodoServicio::getArbolPacientes() const{return pacientes;}

void NodoServicio::setNextServicio(NodoServicio* nuevo){ this->next = nuevo;}
