#pragma once
#include <string>
using namespace std;

// Clase base para representar a una persona, en este caso tanto pacientes como médicos los cuales pueden heredar esta clase
class Persona{
    protected:
        string id;
        string nombre;
        int edad;
        
    public:
        Persona(string id, string nombre, int edad);
        string getId() const;
        string getNombre() const;
        int getEdad() const;
        virtual void mostrarInfo() const = 0; // Método virtual puro para mostrar información de la persona

        virtual ~Persona(); 

};