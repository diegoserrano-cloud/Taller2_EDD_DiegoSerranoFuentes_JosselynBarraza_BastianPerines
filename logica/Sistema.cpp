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
bool separarLinea(const string& linea, string partes[11]) {
    const char* inicio = linea.c_str(); // Convierte la línea en un puntero a char para poder recorrerla con aritmética de punteros
    const char* cursor = inicio; // Puntero que se moverá a través de la línea
    int campoActual = 0;

    while (*cursor != '\0' && campoActual < 11) {
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

    return campoActual == 11; }


bool convertirEntero(const string& texto, int& resultado) {
    try {
        size_t posicion = 0; //Size_t es un tipo de dato sin signo que representa el tamaño de un objeto en bytes. Se utiliza para evitar problemas de desbordamiento y garantizar que la variable pueda almacenar cualquier tamaño posible.
        int valor = stoi(texto, &posicion);
        if (posicion != texto.size()) {
            return false; // Quedaron caracteres sin convertir
        }
        resultado = valor;
        return true;
    } catch (const exception&) {
        return false; // stoi lanza excepción si el texto no es un número o es demasiado grande
    }
}

bool convertirDouble(const string& texto, double& resultado) {
    try {
        size_t posicion = 0; 
        double valor = stod(texto, &posicion);
        if (posicion != texto.size()) {
            return false; // Quedaron caracteres sin convertir
        }
        resultado = valor;
        return true;
    } catch (const exception&) {
        return false; // stod lanza excepción si el texto no es un número o es demasiado grande
    }
}

bool convertirBool(const string& texto, bool& resultado) {
    int numero = 0;
    bool esNumero = convertirEntero(texto, numero);
    if (!esNumero) {
        return false;
    }
 
    if (numero == 0) {
        resultado = false;
        return true;
    }
    if (numero == 1) {
        resultado = true;
        return true;
    }
    return false; // Si el número no es 0 ni 1, no es un valor booleano válido
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

        string partes[11];

        bool formatoValido = separarLinea(linea, partes);
        if(!formatoValido){
            cout << "Error: formato de línea inválido en la línea " << cantLineas << ". Paciente no agregado." << endl;
            continue; // Saltar a la siguiente línea
        }


        string id = partes[0];
        string nombre = partes[1];
        string tipoDolor = partes[6];
        int edad;
        double temperatura;
        int presionArterial;
        int dolor;
        bool trauma;
        bool sintomasNeurologicos;
        bool requiereCirugia;
        int diasHospitalizacion;

        bool datosValidos = true;
        if(!convertirEntero(partes[2], edad)){ datosValidos = false; }
        if(!convertirDouble(partes[3], temperatura)){ datosValidos = false; }
        if(!convertirEntero(partes[4], presionArterial)){ datosValidos = false; }
        if(!convertirEntero(partes[5], dolor)){ datosValidos = false; }
        if(!convertirBool(partes[7], trauma)){ datosValidos = false; }
        if(!convertirBool(partes[8], sintomasNeurologicos)){ datosValidos = false; }
        if(!convertirBool(partes[9], requiereCirugia)){ datosValidos = false; }
        if(!convertirEntero(partes[10], diasHospitalizacion)){ datosValidos = false; }

        if(!datosValidos){
            cout << "Error: datos inválidos en la línea " << cantLineas << ". Paciente no agregado." << endl;
            continue; 
        }

        //Dado que el servicio no se encuentra en el archivo, se otorgara uno en el arbol AVL, segun el tipo de dolor y la gravedad del paciente.
        Paciente p(id, nombre, edad, temperatura, presionArterial,
                   dolor, tipoDolor, trauma, sintomasNeurologicos,
                   requiereCirugia, diasHospitalizacion);
       

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
    const string servicios[] = {
        "Urgencias", "Medicina General", "Cardiologia", "Neurologia",
        "Traumatologia", "Cirugia", "Pediatria", "Hospitalizacion"
    };
    const int cantidadServicios = sizeof(servicios) / sizeof(servicios[0]);

    for(int i = 0; i < cantidadServicios; i++){
        cout << i + 1 << ". " << servicios[i] << endl;
    }

    int opcion;
    cout << "Seleccione un departamento: ";
    if(!(cin >> opcion) || opcion < 1 || opcion > cantidadServicios){
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Opcion fuera de rango." << endl;
        return;
    }

    const string& servicio = servicios[opcion - 1];
    int cantidadPacientes = hospital->contarPacientes(servicio);
    cout << "==== ESTADO " << servicio << " ====" << endl;
    if(cantidadPacientes == 0){
        cout << "No hay pacientes en el departamento de " << servicio << endl;
        return;
    }

    cout << "Pacientes en el departamento de " << servicio << ": "
         << cantidadPacientes << endl;
    hospital->mostrarServicio(servicio);
    cout << endl;
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
            string rutaDecision = "";
            string servicioAsignado = arbolDecision->clasificarPaciente(&p, rutaDecision);

            p.setServicio(servicioAsignado);

            cout<<"=== Atendiendo Pacientes ==="<<endl;
            cout<<"ID: "<< p.getId() <<endl;
            cout<<"Nombre: "<<p.getNombre() <<endl;
            cout<<"Edad: "<<p.getEdad() << endl;
            cout << "Ruta de Decision: " << rutaDecision << endl;
            cout<<" "<<endl;
            cout<<"Paciente enviado a "<<p.getServicio()<<endl;
            cout<<" "<<endl;
            hospital->derivarPaciente(p);
            atendidos->push(p);
        }
    }
    arbolDecision->mostrarPreorden();
    arbolDecision->mostrarInorden();
    arbolDecision->mostrarPostorden();
}

void Sistema::buscaPaciente(){
    int opcion;

    cout << "=== BUSCAR PACIENTE ===" << endl;
    cout << "1. Buscar por ID" << endl;
    cout << "2. Buscar por nombre" << endl;
    cout << "Seleccione una opcion: ";
    cin >> opcion;

    if(opcion == 1){
        string id;

        cout << "Ingrese el ID del paciente: ";
        cin >> id;

        Paciente* encontrado = hospital->buscarPaciente(id);

        if(encontrado != nullptr){
            cout << "=== PACIENTE ENCONTRADO ===" << endl;
            encontrado->mostrarInfo();
        }else{
            cout << "No se encontro un paciente con ID: " << id << endl;
        }
    }
    else if(opcion == 2){
        string nombre;

        cout << "Ingrese el nombre completo del paciente: ";
        getline(cin >> ws, nombre); //lee nombre con espacios "Juan Perez"

        int encontrados = hospital->buscarPacientesPorNombre(nombre);

        if(encontrados == 0){
            cout << "No se encontraron pacientes con nombre: " << nombre << endl;
        }
    }
    else{
        cout << "Opcion invalida." << endl;
    }
}

void Sistema::eliminarPacientePorId(){
    string id;
    cout << "Ingrese el ID del paciente que desea buscar: ";
    cin >> id;
    Paciente* paciente = hospital->buscarPaciente(id);
    if(paciente != nullptr){

        cout << paciente->mostrarInfo() << endl;
        bool eliminado = hospital->eliminarPaciente(id);

    }else{
        cout << "No se encontro un paciente con ID: " << id << endl;
    }
}

Sistema::~Sistema(){
    delete pendientes;
    delete atendidos;
    delete hospital;
    delete arbolDecision;
}
