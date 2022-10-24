#ifndef VEHICULO_H
#define VEHICULO_H
using namespace std;

// Constantes para definir el impuesto que se agrega al precio segun el precio base
const double IMPUESTO1 = 0.16, IMPUESTO2 = 0.20, IMPUESTO3 = 0.25;

class Vehiculo{
  public:
  // constructores
    Vehiculo();
    Vehiculo(string, string, string, double);
    // destructor
    ~Vehiculo();
    // accesores
    string getMarca()const;
    string getColor()const;
    string getModelo()const;
    double getPrecio()const;
    // modificadores
    void setMarca(string);
    void setColor(string);
    void setModelo(string);
    void setPrecio(double);
    // otros metodos
    double calculaImpuestos();
    //1. COMPLETA la definición siguiente para que esta función se comporte diferente para cada clase derivada
    /*ESCRIBE*/ virtual void imprimeVehiculo(); //En este método se implementará polimorfismo dinámico
    
  private:
    string marca, color, modelo;  
    double precio;
  
};

Vehiculo::Vehiculo(){
  marca = "S/M";
  color = "acero";
  modelo = "2021";
  precio = 100000;
}

double Vehiculo::calculaImpuestos(){
  // calcula los impuestos correspondientes a este vehículo y lo devuelve
  // el impuesto se determina en funcion del precio
  // 1 - 300000 --> 16%
  // 300001 - 1000000 --> 20%
  // > 1000000 --> 25%
  double impuesto;
  // 2. COMPLETA lo que hace falta
  if(precio >= 1 && precio <= 300000){
    impuesto = .16 * precio;

  }
  else if(precio >= 300001 && precio <= 1000000){
    impuesto = .20 * precio;

  } 
  else if(precio > 1000000){
    impuesto = .25 * precio;

  }
  return impuesto;
}

Vehiculo::Vehiculo(string marca_, string color_, string modelo_, double precio_){
  marca = marca_;
  color = color_;
  modelo = modelo_;
  precio = precio_;
}

Vehiculo::~Vehiculo(){}

string Vehiculo::getMarca()const { return marca;}
string Vehiculo::getColor()const { return color;}
string Vehiculo::getModelo()const { return modelo;}
double Vehiculo::getPrecio()const {return precio;}

void Vehiculo::setMarca(string marca_){marca = marca_;}
void Vehiculo::setColor(string color_){color = color_;}
void Vehiculo::setModelo(string modelo_){modelo = modelo_;}
void Vehiculo::setPrecio(double precio_){precio = precio_;}

//NO modifiques este método, sólo observa qué está haciendo
void Vehiculo::imprimeVehiculo(){
  cout << "Caracteristicas " << endl;
  cout << "MARCA: " << marca << " COLOR: " << color << " MODELO: " << modelo << " PRECIO SIN IMPUESTOS: $" << precio << endl;
  cout << "PRECIO CON IMPUESTOS: $" << precio + calculaImpuestos() << endl;
}

#endif