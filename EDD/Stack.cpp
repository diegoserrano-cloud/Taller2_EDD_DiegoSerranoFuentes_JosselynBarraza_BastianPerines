#include "Stack.hpp"
#include <iostream>
using namespace std;

Stack::Stack() {
    this->top = nullptr;
}

void Stack::push(Paciente paciente) {
    NodoPaciente* nuevo = new NodoPaciente(paciente);
    nuevo->setNext(top);
    top = nuevo;
}

Paciente Stack::pop() {
    if (isEmpty()) {
        throw runtime_error("La pila está vacía");
    }
    NodoPaciente* temporal = top;
    Paciente p = temporal->getPaciente();
    top = top->getNext();
    delete temporal;
    return p;
}

bool Stack::isEmpty() const {
    return top == nullptr;
}

void Stack::mostrar() const {
    NodoPaciente* cursor = top;
    while (cursor != nullptr) {
        cursor->getPaciente().mostrarInfo();
        cursor = cursor->getNext();
    }
    
}

Stack::~Stack() {
    while (!isEmpty()) {
        pop();
    }
}