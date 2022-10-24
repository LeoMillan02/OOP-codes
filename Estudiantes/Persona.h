//
//  Persona.h
//  PolimPersonaMaestroEstudiante
//
//  Created by Yolanda Martinez on 17/05/20.
//  Copyright © 2020 com.itesm. All rights reserved.
//

#ifndef Persona_h
#define Persona_h
using namespace std;

class Persona {
    public:
        Persona();
        Persona(string, int);
        string getNombre() const;
        void setNombre(string);
        int getEdad()const;
        void setEdad(int);
        // 1. Agrega lo necesario para que el método muestraDatos() actúe polimorficamente con un manejador de la clase base
        virtual void muestraDatos(); 

    private:
        string nombre;
        int edad;
};

Persona::Persona() {
    nombre = "N/A";
    edad = 0;
}

Persona::Persona(string nom, int ed) {
    nombre = nom;
    edad = ed;
}

string Persona::getNombre()const{
    return nombre;
}

void Persona::setNombre(string nom){
    nombre = nom;
}

int Persona::getEdad() const {
    return edad;
}

void Persona::setEdad(int ed) {
    edad = ed;
}

void Persona::muestraDatos() {
    cout << "Nombre: " << nombre << " Edad: " << edad << endl;
}

#endif /* Persona_h */