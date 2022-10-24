#ifndef ARTICULO_H
#define ARTICULO_H
#include <iostream>
using namespace std;

// Asegúrate que esta clase sea abstracta, ¿Qué tienes que hacer para que sea abstracta?

class Articulo {
    public:
        Articulo();
        Articulo(string, double);
        void setDescrip(string);
        void setPrecio(double);
        string getDescrip() const;
        double getPrecio() const;
        virtual double precioAPagar() = 0; 
        virtual void muestra() = 0;
            
    private:
        string descrip;
        double precio;
};

Articulo::Articulo() { 
    descrip = " "; 
    precio = 0; 
}

Articulo::Articulo(string d, double p) {
    descrip = d; 
    precio = p; 
}

void Articulo::setDescrip(string d) {
    descrip = d;
}

void Articulo::setPrecio(double p) {
    precio = p;
}

string Articulo::getDescrip() const {
    return descrip;
}

double Articulo::getPrecio() const {
    return precio;
}

#endif //ARTICULO_H