#ifndef COMIDA_H
#define COMIDA_H
using namespace std;
#include <iostream>

/* La clase comida crea objetos que representan una de las opciones en un restaurante
   Tiene un nombre y un precio
   Comida es la clase base de las clases Hamburguesa y Pizza*/

class Comida
{
    public:
        Comida();
        Comida(string, double);
        ~Comida();
        string getNombre() const;
        void setNombre(string);
        double getPrecio() const;
        void setPrecio(double);
        void muestra();

    private:
        string nombre;
        double precio;
};

// Constructores
Comida::Comida(){
    nombre = "";
    precio=0;
}

Comida::Comida(string nombre_, double precio_) {
    nombre = nombre_;
    precio=precio_;
}

//Destructor
Comida:: ~Comida() {}

//Accesores
string Comida::getNombre()const {
    return nombre;
}

double Comida::getPrecio()const {
    return precio;
}

//Modificadores
void Comida::setNombre(string nombre_){
    nombre = nombre_;
}

void Comida::setPrecio(double precio_){
    precio=precio_;
}

//Método muestra
void Comida::muestra(){
    cout<<nombre<<" $"<<precio<<endl;
}

#endif // COMIDA_H