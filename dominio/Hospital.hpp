#pragma once
#include <string>
#include "../EDD/NodoServicio.hpp"
#include "../EDD/NodoPaciente.hpp"
using namespace std;

class Hospital {
    private:
        NodoServicio* primerServicio;
    public:
        Hospital(); //Crea los 8 servicios 

        NodoServicio* buscarServicio(string nombre) const; //recorre la lista y devuelve el servicio con ese nombre

        void derivarPaciente(Paciente p);//Segun el servicio se inserta el paciente en su lista interna

        void atenderPaciente(Paciente p); //Segun el servicio se elimina el paciente de su lista interna y se agrega a la lista de historial

        void mostrarEstado(); //Recorre todos los servicios y muestra sus pacientes

        void mostrarServicio(string nombre); //Muestra los pacientes del servicio que se necesite

        int contarPacientes(string nombre);

        ~Hospital();

};