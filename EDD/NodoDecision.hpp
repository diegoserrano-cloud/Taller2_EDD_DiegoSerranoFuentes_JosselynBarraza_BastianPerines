#pragma once
#include <string>
#include "Paciente.hpp"
using namespace std;

enum Criterio {
    ES_PEDIATRIA,
    TIENE_TRAUMA,
    REQUIERE_CIRUGIA,
    SINTOMAS_NEUROLOGICOS,
    TIPO_DOLOR_PECHO,
    URGENCIAS_CRITICA,
    HOSPITALIZACION_LARGA,
    NINGUNO
};

class NodoDecision {
    private:
        bool esHoja;
        string servicio;
        Criterio criterio;
        NodoDecision* hijoSi;
        NodoDecision* hijoNo;
    
    public:
        NodoDecision(Criterio crit);
        NodoDecision(string nombreServicio);

        bool evaluar(Paciente* p);
        bool esHoja();
        string getServicio();
        Criterio getCriterio();
        NodoDecision* getHijoSi();
        NodoDecision* getHijoNo();

        void setHijoSi(NodoDecision* si);
        void setHijoNo(NodoDecision* no);

        ~NodoDecision();
};