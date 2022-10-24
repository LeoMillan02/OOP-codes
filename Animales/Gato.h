// Declara e implementa aquí la clase Gato
#ifndef Gato_h
#define Gato_h
#include "Animal.h"



class Gato:public Animal{ 
    public:
        Gato(string, int);
        void muestra();
        void habla();
    private:
      

}; 

Gato::Gato(string s,int i):Animal(s,i){

}

void Gato::muestra(){
    cout<<"Soy el gato" <<getNombre()<<" tengo "<<calculaEdad()<<" años." <<endl;
}

void Gato::habla(){
    cout<<"MIAU"<<endl;
}
#endif
