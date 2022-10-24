#ifndef Perro_h
#define Perro_h
#include "Animal.h"

class Perro:public Animal{
public:
    Perro(string, int);
    void muestra();
    void habla();
private:
    

};

Perro::Perro(string s, int i):Animal(s, i){

}

void Perro::muestra(){
    cout<<"Soy el perro " << getNombre()<< " tengo "<< calculaEdad() << " años."<<endl;
}
void Perro::habla(){
    cout<< "GUAU"<<endl;
}




#endif