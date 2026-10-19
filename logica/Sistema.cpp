#include "Sistema.hpp"
#include <fstream> // Para leer archivos
#include <iostream>
#include "../EDD/Stack.hpp"
#include "../EDD/Cola.hpp"
#include "../dominio/Hospital.hpp"

using namespace std;



void Sistema::mostrarPacientesEspera(){
    pendientes->mostrar();
}

void Sistema::mostrarPacientesAtendidos(){
    atendidos->mostrar();
}

/*
* Esta función separa una línea en partes utilizando el delimitador ';' y almacena las partes en un arreglo de strings.
* Lo hace utilizando una aritmetica de punteros para recorrer la cadena de caracteres.
* Devuelve true si se separaron exactamente 4 partes, de lo contrario devuelve false.
* El "\0" al final de la línea indica el final de la cadena, por lo tanto el bucle se detiene cuando se alcanza ese carácter.
*/
bool separarLinea(const string& linea, string partes[4]) {
    const char* inicio = linea.c_str(); // Convierte la línea en un puntero a char para poder recorrerla con aritmética de punteros
    const char* cursor = inicio; // Puntero que se moverá a través de la línea
    int campoActual = 0;

    while (*cursor != '\0' && campoActual < 4) {
        const char* inicioCampo = cursor; // Guardamos el inicio del campo actual

        while (*cursor != ';' && *cursor != '\0') { // Avanzamos el cursor hasta encontrar un ';' o el final de la línea
            cursor++;
        }

        // Calculamos la longitud del campo y lo copiamos en el arreglo de partes 
        long largoCampo = cursor - inicioCampo;
        partes[campoActual] = string(inicioCampo, largoCampo);
        campoActual++;

        if (*cursor == ';') {
            cursor++;
        }
    }

    return campoActual == 4;
}

bool Sistema::CargarArchivo(string arch){
    ifstream archivo(arch);
    if(!archivo.is_open()){
        cout<< "Error: no se pudo abrir el archivo " << arch << endl;
        return false;
    }
    string linea;
    int cantLineas = 0;
    while(getline(archivo, linea)){
        cantLineas++;
        if(linea.empty()) continue; // Ignorar líneas vacías o en blanco

        string partes[4];

        bool formatoValido = separarLinea(linea, partes);
        if(!formatoValido){
            cout << "Error: formato de línea inválido en la línea " << cantLineas << ". Paciente no agregado." << endl;
            continue; // Saltar a la siguiente línea
        }


        string id = partes[0];
        string nombre = partes[1];
        int edad = stoi(partes[2]);
        string servicio = partes[3];
        
        Paciente p(id, nombre, edad, servicio);

        if(hospital->buscarServicio(servicio) == nullptr){
            cout << "Error: el servicio " << servicio << " no existe. Paciente " << nombre << " no agregado." << endl;
            continue; 
        }

        if(pendientes->existeId(id)){
            cout << "Error: el paciente con ID " << id << " ya existe en la cola de espera. Paciente " << nombre << " no agregado." << endl;
            continue; 
        }

        pendientes->AgregarPaciente(p);

    }
    return true;
}


void Sistema::verDepartamento(){
    cout<<" "<< endl;
    cout << "=== DEPARTAMENTOS/SERVICIOS ===" << endl;
    cout<<" "<< endl;
    
    cout<<"1. Urgencias \n"<<
          "2. Medicina General \n"<<
          "3. Cardiología \n"<<
          "4. Neurología \n"<<
          "5. Traumatología \n"<<
          "6. Cirugía \n"<<
          "7. Pediatria \n"<<
          "8. Hospitalizacion "<<endl;
    cout<<" "<< endl;
    int op;
    cin>>op;
    if(op >= 1 && op <= 8){


        if(op == 1){
            cout<<"==== ESTADO URGENCIA ==="<<endl;
            if(hospital->contarPacientes("Urgencias") == 0){
                cout<<"No hay pacientes en el departamento de Urgencias"<<endl;
                return;
            }
            cout<<"Pacientes en el departamente de Urgencias: "<<hospital->contarPacientes("Urgencias")<<endl;
            hospital->mostrarServicio("Urgencias");

        }else if(op == 2){
            cout<<"==== ESTADO MEDICINA GENERAL ==="<<endl;
            if(hospital->contarPacientes("Medicina General") == 0){
                cout<<"No hay pacientes en el departamento de Medicina General"<<endl;
                return;
            }
            cout<<"Pacientes en el departamente de Medicina General: "<<hospital->contarPacientes("Medicina General")<<endl;
            hospital->mostrarServicio("Medicina General");

        }else if(op == 3){
            cout<<"==== ESTADO CARDIOLOGIA ==="<<endl;
            if(hospital->contarPacientes("Cardiologia") == 0){
                cout<<"No hay pacientes en el departamento de Cardiologia"<<endl;
                return;
            }
            cout<<"Pacientes en el departamente de Cardiologia: "<<hospital->contarPacientes("Cardiologia")<<endl;
            hospital->mostrarServicio("Cardiologia");

        }else if(op == 4){
            cout<<"==== ESTADO NEUROLOGIA ==="<<endl;
            if(hospital->contarPacientes("Neurologia") == 0){
                cout<<"No hay pacientes en el departamento de Neurologia"<<endl;
                return;
            }
            cout<<"Pacientes en el departamente de Neurologia: "<<hospital->contarPacientes("Neurologia")<<endl;
            hospital->mostrarServicio("Neurologia");

        }else if(op == 5){
            cout<<"==== ESTADO TRAUMATOLOGIA ==="<<endl;
            if(hospital->contarPacientes("Traumatologia") == 0){
                cout<<"No hay pacientes en el departamento de Traumatologia"<<endl;
                return;
            }
            cout<<"Pacientes en el departamente de Traumatologia: "<<hospital->contarPacientes("Traumatologia")<<endl;
            hospital->mostrarServicio("Traumatologia");

        }else if(op == 6){
            cout<<"==== ESTADO CIRUGIA ==="<<endl;
            if(hospital->contarPacientes("Cirugia") == 0){
                cout<<"No hay pacientes en el departamento de Cirugia"<<endl;
                return;
            }
            cout<<"Pacientes en el departamente de Cirugia: "<<hospital->contarPacientes("Cirugia")<<endl;
            hospital->mostrarServicio("Cirugia");

        }else if(op == 7){
            cout<<"==== ESTADO PEDIATRIA ==="<<endl;
            if(hospital->contarPacientes("Pediatria") == 0){
                cout<<"No hay pacientes en el departamento de Pediatria"<<endl;
                return;
            }
            cout<<"Pacientes en el departamente de Pediatria: "<<hospital->contarPacientes("Pediatria")<<endl;
            hospital->mostrarServicio("Pediatria");

        }else if(op == 8){
            cout<<"==== ESTADO HOSPITALIZACION ==="<<endl;
            if(hospital->contarPacientes("Hospitalizacion") == 0){
                cout<<"No hay pacientes en el departamento de Hospitalizacion"<<endl;
                return;
            }
            cout<<"Pacientes en el departamente de Hospitalizacion: "<<hospital->contarPacientes("Hospitalizacion")<<endl;
            hospital->mostrarServicio("Hospitalizacion");
        }cout<<" "<<endl;
    }else{
        cout<<"Fuera del rango, SALIENDO.."<<endl;
        return;
    }
}

void Sistema::revisarHistorial(){
    cout<<" "<< endl;
    cout << "=== HISTORIAL DE ATENCION ===" << endl;
    atendidos->mostrar();
}

void Sistema::atenderPaciente(int cantidad){
    for(int i = 0; i< cantidad; i++){
        if(pendientes->isEmpty()){
            cout<<"Sin pacientes que atender, saliendo..."<<endl;
            return;
        }else{
            Paciente p = pendientes->eliminarPaciente();
            cout<<"=== Atendiendo Pacientes ==="<<endl;
            cout<<"ID: "<< p.getId() <<endl;
            cout<<"Nombre: "<<p.getNombre() <<endl;
            cout<<"Edad: "<<p.getEdad() << endl;
            cout<<"Servicio: "<<p.getServicio()<<endl;
            cout<<" "<<endl;
            cout<<"Paciente enviado a "<<p.getServicio()<<endl;
            cout<<" "<<endl;
            hospital->derivarPaciente(p);
            atendidos->push(p);
        }
    }
}


Sistema::~Sistema(){
    delete pendientes;
    delete atendidos;
    delete hospital;
}

