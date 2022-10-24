// Declara e implementa aquí la clase ArticuloPorPieza
#ifndef ArticuloPorPieza_h
#define ArticuloPorPieza_h
#include "Articulo.h"

class ArticuloPorPieza:public Articulo{
    public:
        ArticuloPorPieza(string d, double p, int Cp);
        void muestra();
        double precioAPagar();
        int getCantPie();
        void setCantPie(int);
    private:
        int piezas;
};

ArticuloPorPieza::ArticuloPorPieza(string d, double p, int Cp):Articulo(d,p){
    piezas = Cp;
}

int ArticuloPorPieza::getCantPie(){
    return piezas;
}
void ArticuloPorPieza::setCantPie(int Cp){
    piezas = Cp;
}

double ArticuloPorPieza::precioAPagar(){
    double pago = getPrecio()*getCantPie();
    return pago;
}
void ArticuloPorPieza::muestra(){
    cout<< getCantPie()<<" " <<getDescrip()<< " " <<precioAPagar() <<endl;
}



#endif