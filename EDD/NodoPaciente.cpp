#include "NodoPaciente.hpp"

NodoPaciente::NodoPaciente(Paciente paciente) : paciente(paciente), next(nullptr) {}
Paciente NodoPaciente::getPaciente() const{return paciente;}
NodoPaciente* NodoPaciente::getNext() const{return next;}
void NodoPaciente::setNext(NodoPaciente* nuevoNext){next= nuevoNext;}