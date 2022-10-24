// Declara e implementa aquí la clase ArticuloPorPeso
#ifndef ArticuloPorPeso_h
#define ArticuloPorPeso_h
#include "Articulo.h"

class ArticuloPorPeso:public Articulo{
    public:
        ArticuloPorPeso(string d, double p, double pE);
        double getCantPe();
        void setCantPe(double);
        void muestra();
        double precioAPagar();
    private:
        double peso;
 
};

ArticuloPorPeso::ArticuloPorPeso(string d, double p, double pE):Articulo(d,p){
    peso = pE;
}

double ArticuloPorPeso::getCantPe(){
    return peso;
}
void ArticuloPorPeso::setCantPe(double pE){
   peso = pE;
}
double ArticuloPorPeso::precioAPagar(){
    double pago = getPrecio() * getCantPe();
    return pago;
}

void ArticuloPorPeso::muestra(){
    cout<< getDescrip()<<" "<<getCantPe()<< " Kg "<< precioAPagar() <<endl;
}


#endif