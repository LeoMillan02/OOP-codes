#ifndef AEREOPUERTO_H
#define AEREOPUERTO_H
 
class Pasajero{

    private:

        string nombre, ubicacion;
        int cantidadMaxAviones, avionesActuales;

    public:

        Pasajero();
        Pasajero(std::string nombre, string ubicacion, int cantidadMaxAviones, int avionesActuales);
        void setNombre(string nombre);
        void setUbicacion(string ubicacion);
        void setCantidadMaxAviones(int cantidadMaxAviones);
        void setAvionesActuales(int avionesActuales);
        string getNombre();
        string getUbicacion();
        int getCantidadMaxAviones();
        int getAvionesActuales();
        bool aterizAvion();

};

Pasajero::Pasajero(){

}
Pasajero::Pasajero(string nombre, string ubicacion, int cantidadMaxAviones, int avionesActuales){
    this->nombre=nombre;
    this->ubicacion=ubicacion;
    this->cantidadMaxAviones=cantidadMaxAviones;
    this->avionesActuales=avionesActuales;
}
void Pasajero::setNombre(string nombre){
    this->nombre=nombre;
}
void Pasajero::setUbicacion(string ubicacion){
    this->ubicacion=ubicacion;
}
void Pasajero::setCantidadMaxAviones(int cantidadMaxAviones){
    this->cantidadMaxAviones=cantidadMaxAviones;
}
void Pasajero::setAvionesActuales(int avionesActuales){
    this->avionesActuales=avionesActuales;
}
string Pasajero::getNombre(){
    return nombre;
}
string Pasajero::getUbicacion(){
    return ubicacion;
}
int Pasajero::getCantidadMaxAviones(){
    return cantidadMaxAviones;
}
int Pasajero::getAvionesActuales(){
    return avionesActuales;
}
bool Pasajero::aterizAvion(){
    
}

#endif