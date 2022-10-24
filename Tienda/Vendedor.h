// Escribe aquí la clase Vendedor

// usa estos cout para COMPLETAR el despliegue de los datos de un vendedor
// recuerda que un vendedor es también un Empleado
//    cout << " %comision " << porcentajeComision;
//    cout << " ventas " << ventas << endl;


#ifndef Vendedor_h
#define Vendedor_h
#include "Empleado.h"

//Escribe tu clase Vendedor
class Vendedor:public Empleado{
    public:
        Vendedor();
        Vendedor(int, double, double, double);
        double getPorcentajeComision() const;
        double getVentas() const;
        double calculaPago()const;
        void setPorcentajeComision(double);
        void setVentas(double);
        void muestra();
        
    private:
        double ventas, porcentajeComision;
};

Vendedor::Vendedor(){
    ventas = 0;
    porcentajeComision = 0;

}

Vendedor::Vendedor(int ide, double suel, double comi, double ven):Empleado(ide, suel){
    porcentajeComision = comi;
    ventas = ven;
}

double Vendedor::getPorcentajeComision() const{
    return porcentajeComision;

}

double Vendedor::getVentas() const{
    return ventas;
}

void Vendedor::setPorcentajeComision(double comi){
    porcentajeComision =  comi;
}

double Vendedor::calculaPago() const{
    double comi = getVentas() *porcentajeComision;
    double pago = comi + getSueldo();
    return pago;
}

void Vendedor::setVentas(double ven){
    ventas = ven;

}

void Vendedor::muestra(){
    cout << "Id de empleado " << getIdent();
    cout << " sueldo $" << getSueldo() << endl;
    cout << "%comision "<< porcentajeComision ;
    cout << " ventas " << ventas <<endl;
}

#endif //Vendedor_h