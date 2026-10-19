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

## Instrucciones

### Requisitos previos
- Compilador de C++ (g++) instalado, por ejemplo a través de MinGW-w64.
- (Opcional) Visual Studio Code con la extensión de C++, para editar y compilar desde la terminal integrada.

### Instrucciones de compilación y ejecución
1. Abrir una terminal (PowerShell/CMD) **en la carpeta raíz del proyecto** (donde está este README y el archivo `pacientes.txt`).
2. Compilar todos los archivos fuente con:
  ```powershell
  g++ -Wall -Wextra -g3 logica\App.cpp logica\Sistema.cpp dominio\Hospital.cpp dominio\Paciente.cpp dominio\Persona.cpp EDD\Cola.cpp EDD\Stack.cpp EDD\NodoPaciente.cpp EDD\NodoServicio.cpp -o menu.exe
  ```
3. Ejecutar con `.\menu.exe` desde la terminal integrada de VS Code (Ctrl + Ñ / Ctrl + `).
4. El programa carga automáticamente `pacientes.txt` (debe estar en la misma carpeta raíz) y muestra el menú principal.
5. Disfrutar del sistema :D
