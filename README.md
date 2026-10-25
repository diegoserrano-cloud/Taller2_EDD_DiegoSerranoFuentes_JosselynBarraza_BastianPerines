# Taller 1 - Estructura de Datos: Sistema de Gestión de Pacientes "Hospital Marmaja"

## Integrantes

- **Nombre Completo:** Diego Nikolas Serrano Fuentes
  - **RUT:** 22.105.561-6
  - **GitHub:** diegoserrano-cloud
  - **Carrera:** Ing. Civil en Computación e Informática

- **Nombre Completo:** Josselyn Alejandra Barraza Yáñez
  - **RUT:** 22.246.539-7
  - **GitHub:** josselynbarraza-sys
  - **Carrera:** Ing. Civil en Computación e Informática

- **Nombre Completo:** Bastián Felipe Perines Flores
  - **RUT:** 22.386.968-5
  - **GitHub:** Thkr34
  - **Carrera:** Ing. Civil en Computación e Informática
  - 
### 🌲 Árbol de Decisión (Clasificación Automática de Pacientes)

El sistema utiliza un Árbol de Decisión Binario jerárquico para clasificar
automáticamente a cada paciente en uno de los 8 servicios médicos del
hospital evaluando sus signos vitales y síntomas de manera secuencial:

1. Pediatría: Evalúa si la edad del paciente es menor a 14 años (Edad < 14).
2. Cirugía / Traumatología: Si presenta un trauma (Trauma == true), se verifica si requiere intervención quirúrgica (RequiereCirugia == true) para derivar a Cirugía; de lo contrario, se asigna a Traumatología.
3. Neurología: Detecta la presencia de síntomas neurológicos (SintomasNeurologicos == true).
4. Cardiología: Identifica si el cuadro clínico corresponde a un dolor de pecho (TipoDolor == "pecho").
5. Urgencias: Evalúa criterios de gravedad o urgencia crítica (Temperatura >= 38.5 o Dolor >= 8).
6. Hospitalización / Medicina General: Analiza la duración de la estancia prevista (DiasHospitalizacion >= 2) para derivar a Hospitalización; si no cumple ninguna condición anterior, el paciente es asignado a Medicina General.

Nota: Cada evaluación en el árbol imprime en consola la ruta recorrida (ej. Raiz(inicio) -> NO -> SI...) garantizando la trazabilidad de la decisión médica. Tambien esta la imagen ArbolDecisiones.PNG que es una recreacion visual del mismo árbol de decisiones hecha en draw.io

 
## Instrucciones

### Requisitos previos
- Compilador de C++ (g++) instalado, por ejemplo a través de MinGW-w64.
- (Opcional) Visual Studio Code con la extensión de C++, para editar y compilar desde la terminal integrada.

### Instrucciones de compilación y ejecución
1. Abrir una terminal (PowerShell/CMD) **en la carpeta raíz del proyecto** (donde está este README y el archivo `pacientes.txt`).
2. Compilar todos los archivos fuente con:
  ```powershell
    g++ -Wall -Wextra -g3 logica\App.cpp logica\Sistema.cpp dominio\Hospital.cpp dominio\Paciente.cpp dominio\Persona.cpp EDD\AVL.cpp EDD\NodoAVL.cpp EDD\ArbolDecision.cpp EDD\NodoDecision.cpp EDD\Cola.cpp EDD\Stack.cpp EDD\NodoPaciente.cpp EDD\NodoServicio.cpp -o menu.exe
  ```
3. Ejecutar con `.\menu.exe` desde la terminal integrada de VS Code (Ctrl + Ñ / Ctrl + `).
4. El programa carga automáticamente `pacientes.txt` (debe estar en la misma carpeta raíz) y muestra el menú principal.
5. Disfrutar del sistema :D

### Funcionalidades
- La opción **Buscar paciente** imprime la información del paciente y luego lo elimina de su departamento y rebalancea el árbol AVL correspondiente.
