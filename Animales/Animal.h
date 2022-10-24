#ifndef Animal_h
#define Animal_h
#include <iostream>
using namespace std;

// La clase Animal deberá ser una clase Abstracta
class Animal
{
public:
    Animal(string, int);
    int calculaEdad();
    string getNombre() const;
    int getAnioNacim() const;
    void setNombre(string);
    void setAnioNacim(int);

    virtual void habla() = 0;     // 1. Agrega lo necesario para sea un método virtual puro
    virtual void muestra() = 0;   // 2. Agrega lo necesario para sea un método virtual puro
private:
    string nombre;
    int anioNacim;
};

Animal::Animal(string nom, int aNac){
    nombre = nom;
    anioNacim = aNac;
}

string Animal::getNombre() const{
    return nombre;
}

int Animal::getAnioNacim() const{
    return anioNacim;
}

void Animal::setNombre(string n){
    nombre = n;
}

void Animal::setAnioNacim(int a){
    anioNacim = a;
}

int Animal::calculaEdad(){
    return 2021 - anioNacim;
}

#endif //Animal_h