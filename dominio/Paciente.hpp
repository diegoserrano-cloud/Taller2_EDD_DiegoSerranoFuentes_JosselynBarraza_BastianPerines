#pragma once
#include "Persona.hpp"
#include <string>
using namespace std;

class Paciente : public Persona{
    private:

        double temperatura;
        int presionArterial;
        int dolor;
        string tipoDolor; // Tipo de dolor, por ejemplo: "pecho", "cabeza", "abdomen", "extremidad" u otros.
        bool trauma;
        bool sintomasNeurologicos;
        bool requiereCirugia;
        int diasHospitalizacion;
        string servicio; 
        
    public:
        Paciente(string id, string nombre, int edad, double temperatura, int presionArterial,
                 int dolor, string tipoDolor, bool trauma, bool sintomasNeurologicos,
                 bool requiereCirugia, int diasHospitalizacion);

        double getTemperatura() const;
        int getPresionArterial() const; 
        int getDolor() const;
        string getTipoDolor() const;
        bool getTrauma() const;
        bool getSintomasNeurologicos() const;
        bool getRequiereCirugia() const;
        int getDiasHospitalizacion() const;

        string getServicio() const;
        void setServicio(string nuevoServicio);

        void mostrarInfo() const override;

        
};