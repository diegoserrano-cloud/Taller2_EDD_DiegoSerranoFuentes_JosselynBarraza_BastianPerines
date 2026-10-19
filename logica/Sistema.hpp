#pragma once

#include "../dominio/Hospital.hpp"
#include "../EDD/Cola.hpp"
#include "../EDD/Stack.hpp"

class Sistema{
    private:
        Cola* pendientes = new Cola();
        Stack* atendidos = new Stack();
        Hospital* hospital = new Hospital();
    public:
         void mostrarPacientesEspera();
         bool CargarArchivo(string arch);
         void mostrarPacientesAtendidos();
         void revisarHistorial();
         void verDepartamento();
         void atenderPaciente(int cantidad);
         
        ~Sistema();
};