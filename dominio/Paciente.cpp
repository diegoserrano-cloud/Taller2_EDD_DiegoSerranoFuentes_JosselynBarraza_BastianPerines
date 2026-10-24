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
 
    cout << "ID: " << id << "\n - Nombre: " << nombre << "\n - Edad: " << edad
         << "\n - Temperatura: " << temperatura << "\n - Presion Arterial: " << presionArterial
         << "\n - Dolor: " << dolor << "\n - Tipo de Dolor: " << tipoDolor
         << "\n - Trauma: " << textoTrauma
         << "\n - Sintomas Neurologicos: " << textoNeurologicos
         << "\n - Requiere Cirugia: " << textoCirugia
         << "\n - Dias de Hospitalizacion: " << diasHospitalizacion
         << "\n - Servicio: " << textoServicio
         << endl;
}