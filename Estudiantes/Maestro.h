//
//  Maestro.h
//  PolimPersonaMaestroEstudiante
//
//  Created by Yolanda Martinez on 17/05/20.
//  Copyright © 2020 com.itesm. All rights reserved.
//


#ifndef Maestro_h
#define Maestro_h

#include "Persona.h"

class Maestro : public Persona {
    public:
        Maestro();
        Maestro(string, int, string);
        string getDepto()const;
        void setDepto(string);
        void muestraDatos();

    private:
        string depto;
};

Maestro::Maestro() : Persona() {
    depto = "N/A";
}

Maestro::Maestro(string nom, int ed, string ca) : Persona(nom, ed) {
    depto = ca;
}

string Maestro::getDepto() const {
    return depto; 
}    

void Maestro::setDepto(string de) {
    depto = de; 
}

void Maestro::muestraDatos() {
    cout << "Nombre: " << getNombre() << " Edad: " << getEdad() << " Depto: " << depto << endl;
}

#endif /* Maestro_h */