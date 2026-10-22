#include "Paciente.hpp"
#include <iostream>
using namespace std;

// Convierte un bool en "Si" o "No" para mostrarlo por consola
static string textoSiNo(bool valor){
    string texto = "No";
    if(valor){
        texto = "Si";
    }
    return texto;
}
 
Paciente::Paciente(string id, string nombre, int edad, double temperatura, int presionArterial,
                   int dolor, string tipoDolor, bool trauma, bool sintomasNeurologicos,
                   bool requiereCirugia, int diasHospitalizacion): Persona(id, nombre, edad),
                   
  temperatura(temperatura),
  presionArterial(presionArterial),
  dolor(dolor),
  tipoDolor(tipoDolor),
  trauma(trauma),
  sintomasNeurologicos(sintomasNeurologicos),
  requiereCirugia(requiereCirugia),
  diasHospitalizacion(diasHospitalizacion),
  servicio(""){}
 
double Paciente::getTemperatura() const{ return temperatura; }
int Paciente::getPresionArterial() const{ return presionArterial; }
int Paciente::getDolor() const{ return dolor; }
string Paciente::getTipoDolor() const{ return tipoDolor; }
bool Paciente::getTrauma() const{ return trauma; }
bool Paciente::getSintomasNeurologicos() const{ return sintomasNeurologicos; }
bool Paciente::getRequiereCirugia() const{ return requiereCirugia; }
int Paciente::getDiasHospitalizacion() const{ return diasHospitalizacion; }
 
string Paciente::getServicio() const{
    return servicio;
}
 
void Paciente::setServicio(string nuevoServicio){
    servicio = nuevoServicio;
}
 
void Paciente::mostrarInfo() const{
    string textoTrauma = textoSiNo(trauma);
    string textoNeurologicos = textoSiNo(sintomasNeurologicos);
    string textoCirugia = textoSiNo(requiereCirugia);
 
    string textoServicio = servicio;
    if(servicio.empty()){
        textoServicio = "Sin asignar";
    }
 
    cout << "ID: " << id << " - Nombre: " << nombre << " - Edad: " << edad
         << " - Temperatura: " << temperatura << " - Presion Arterial: " << presionArterial
         << " - Dolor: " << dolor << " - Tipo de Dolor: " << tipoDolor
         << " - Trauma: " << textoTrauma
         << " - Sintomas Neurologicos: " << textoNeurologicos
         << " - Requiere Cirugia: " << textoCirugia
         << " - Dias de Hospitalizacion: " << diasHospitalizacion
         << " - Servicio: " << textoServicio
         << endl;
}