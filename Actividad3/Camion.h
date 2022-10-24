#ifndef CAMION_H
#define CAMION_H

class Camion:public Vehiculo /*1. COMPLETA para que herede de la clase Vehiculo*/{
  public:

    Camion();
    Camion(string, string, string, double, double, double, double);
    ~Camion();

    double getLargo();
    double getAncho();
    double getAlto();
    
    void setLargo(double);
    void setAncho(double);
    void setAlto(double);

    double calculaVolumenCarga();
    void imprimeVehiculo();

  private:
    double largo, ancho, alto;
};

//2. IMPLEMENTA el constructor por default, todos los valores a inicializar deberán ser 1
Camion::Camion(){
 largo = 1;
 ancho = 1;
 alto = 1;
}


//3. IMPLEMENTA el constructor con parámetros de la clase.
Camion::Camion(string marca_, string color_, string modelo_,double precio_, double lar, double anch, double alt):Vehiculo(marca_, color_, modelo_,precio_){
  largo = lar;
  ancho = anch;
  alto = alt;
}

Camion::~Camion(){}

double Camion::getLargo(){ return largo;}
double Camion::getAncho(){return ancho;}
double Camion::getAlto(){return alto;}

void Camion::setLargo(double largo_) {largo = largo_;}
void Camion::setAncho(double ancho_) {ancho = ancho_;}
void Camion::setAlto(double alto_) {alto = alto_;}

double Camion::calculaVolumenCarga(){
    //4. CALCULA el volumen de carga y asignala a la variable volumenCarga
    double volumenCarga;
    volumenCarga = getLargo()*getAncho()*getAlto();
    /*5. COMPLETA: Si el volumen de la carga supera los 50 m3, 
      se incrementa (modifica el precio) en 15 %*/
    if(volumenCarga > 50){
      double porc = getPrecio() * .15;
      setPrecio(getPrecio()+porc);
    }
    return volumenCarga;
}

//No modifiques este método
void Camion::imprimeVehiculo(){
  cout << "CAMION DE CARGA " << endl;
  cout << "VOLUMEN DE CARGA: " << calculaVolumenCarga() << " m^3" << endl;
  Vehiculo::imprimeVehiculo(); 
}

#endif