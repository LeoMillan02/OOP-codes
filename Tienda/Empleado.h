//
//  Empleado.h
//  empleadosVendedores
//
//  Created by Yolanda Martinez on 09/05/20.
//  Copyright © 2020 com.itesm. All rights reserved.
//

#ifndef Empleado_h
#define Empleado_h
using namespace std;

class Empleado {
    
public:
    Empleado();
    Empleado(int, double);
    
    void setIdent(int);
    void setSueldo(double);
    
    int getIdent() const;
    double getSueldo() const;
    
    double calculaPago();
    void muestra();
    
private:
    int ident;
    double sueldo;
};

Empleado :: Empleado() {
    ident = 0;
    sueldo = 0;
}

Empleado :: Empleado(int ide, double suel) {
    ident = ide;
    sueldo = suel;
}

void Empleado::setIdent(int id){
    ident=id;
}

void Empleado::setSueldo(double pago){
    sueldo = pago;
}
    
int Empleado::getIdent() const{
    return ident;
}

double Empleado::getSueldo() const{
    return sueldo;
}

// el pago de un empleado es igual que su sueldo
double Empleado :: calculaPago() {
    return sueldo;
}

void Empleado::muestra() {
    cout << "Id de empleado " << ident;
    cout << " sueldo $" << sueldo << endl;
}

#endif //Empleado_h
