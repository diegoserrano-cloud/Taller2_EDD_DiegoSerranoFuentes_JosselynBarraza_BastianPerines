#include <iostream>
#include <string>
#include "Sistema.hpp"
using namespace std;


int main() {
    int opcion;
    Sistema* sis = new Sistema();

    if (!sis->CargarArchivo("pacientes.txt")) {
        cout << "Error al cargar el archivo de pacientes." << endl;
        delete sis;
        return 1;
    }
   
    
    do{
    cout<<"Hola taller 2 "<<endl;
      cout<<"=== HOSPITAL MARMAJA =="<<endl;
      cout<<"1. Atender pacientes"<<endl;
      cout<<"2. Ver departamento"<<endl;
      cout<<"3. Revisar historial de atención"<<endl;
      cout<<"4. Salir"<<endl;
      cout<<" "<<endl;
      cout<<"Seleccionar opción (debe estar entre 1 y 4): ";
      cin>>opcion;
      try{
       
        if(cin.fail()){
            cin.clear();
            cin.ignore(1000, '\n');
            cout<<"ERROR: Ingrese un número entre 1 y 4"<<endl;
            throw opcion;
        }   

        if(opcion < 1 || opcion > 4){
            cout<<"ERROR: Ingrese un número entre 1 y 4"<<endl;
            throw opcion;
        }
        switch(opcion){
            case 1:
                cout<<"== PACIENTES EN ESPERA"<<endl;
                sis->mostrarPacientesEspera();
                cout<<" "<< endl;
                cout<<" Indique la cantidad de pacientes a atender: ";
                int cantidad;
                cin>>cantidad;
                sis->atenderPaciente(cantidad);
                break;
            case 2:
                sis->verDepartamento();  
                break;
            case 3:
                sis->revisarHistorial();
                break;
            case 4:
                cout<<"Saliendo....."<<endl;
                break;
        }

      }catch(int e){
        cout<<"ERROR: "<< e << " invalido" << endl;
        opcion= 0;
      }

    }while(opcion != 4);
    delete sis;
    return 0;

}