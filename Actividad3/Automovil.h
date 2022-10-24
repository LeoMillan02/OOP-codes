#ifndef AUTOMOVIL_H
#define AUTOMOVIL_H

#include "Vehiculo.h"

class Automovil: public Vehiculo{

  public:
    Automovil();
    Automovil(string, string, string, double, string, int, int);
    ~Automovil();
    //accesores
    string getTransmision()const;
    int getNumeroPuertas() const;
    int getTipoCombustible() const;
    // modificadores
    void setTransmision(string);
    void setNumeroPuertas(int);
    void setTipoCombustible(int);
    //otros métodos 
    void aplicaDescuento(); 
    void imprimeVehiculo(); //Polimorfismo dinámico
    
  private:
    string transmision; // automatica o estandar
    int numeroPuertas; //2,4,5
    int tipoCombustible; // 1= gasolina 2=Hibrido 3=electrico
  
};

Automovil::Automovil(){
  transmision = "estandar"; 
  numeroPuertas = 4;
  tipoCombustible = 1;
}
 
//1. IMPLEMENTA el constructor con parámetros
Automovil::Automovil(string marca_, string color_, string modelo_,double precio_, string trans, int numPuer, int tipCombu ):Vehiculo(marca_, color_, modelo_, precio_){
  transmision = trans;
  numeroPuertas = numPuer;
  tipoCombustible = tipCombu;
}


//Destructor
Automovil::~Automovil() {}

//Métodos de acceso
string Automovil::getTransmision()const {return transmision;}
int Automovil::getNumeroPuertas() const{return numeroPuertas;}
int Automovil::getTipoCombustible() const {return tipoCombustible;}

//Métodos modificadores
void Automovil::setTransmision(string transmision_) { transmision = transmision_;}
void Automovil::setNumeroPuertas(int numeroPuertas_) { numeroPuertas = numeroPuertas_;}
void Automovil::setTipoCombustible(int tipoCombustible_) { tipoCombustible = tipoCombustible_;}

//Método para aplicar descuento, se modifica el precio de acuerdo al descuento
void Automovil::aplicaDescuento(){
  // Los automoviles hibridos tienen 5% de descuento del precio y los electricos 10%, sobre el precio
  double descuento = 0;
  if (tipoCombustible == 2){
    //2. AGREGA lo que falta, debe calcular el descuento y modificar el precio del vehículo
    descuento = .05;
    descuento = getPrecio() * descuento; 
    setPrecio(getPrecio()-descuento);
    cout << "APLICA DESCUENTO!! $" << descuento << endl;

  }
  else if (tipoCombustible == 3){
    //3. AGREGA lo que falta, debe calcular el descuento y modificar el precio del vehículo
    descuento = .10;
    descuento = getPrecio() * descuento;
    setPrecio(getPrecio()-descuento);
    cout << "APLICA DESCUENTO!! $" << descuento << endl;
  }
}

//Agrega lo que se te pide pero NO modifiques nada más, observa lo que hace
void Automovil::imprimeVehiculo(){
  string comb;
  if (tipoCombustible == 1)
    comb = "GASOLINA";
  else if (tipoCombustible == 2)
    comb = "HIBRIDO";
  else
    comb = "ELECTRICO";
  cout << "AUTOMOVIL " << comb << endl;
  aplicaDescuento();
  // 4. AGREGA la impresión base de Vehiculo
  Vehiculo::imprimeVehiculo();  
  cout << "PUERTAS: " << numeroPuertas << " TRANSMISION: " << transmision << endl;
  
}

#endif //AUTOMOVIL_H