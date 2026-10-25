#pragma once

#include "../dominio/Hospital.hpp"
#include "../EDD/Cola.hpp"
#include "../EDD/Stack.hpp"
#include "../EDD/ArbolDecision.hpp"

class Sistema{
    private:
        Cola* pendientes = new Cola();
        Stack* atendidos = new Stack();
        Hospital* hospital = new Hospital();
        ArbolDecision* arbolDecision = new ArbolDecision();
    public:
         void mostrarPacientesEspera();
         bool CargarArchivo(string arch);
         void mostrarPacientesAtendidos();
         void revisarHistorial();
         void verDepartamento();
         void atenderPaciente(int cantidad);
         void buscaPaciente();
         
        ~Sistema();