#ifndef ENEMIGO_H
#define ENEMIGO_H

#include "Personaje.h"
#include "Item.h"

/*To do:
*/
class Enemigo: public Personaje{
    public:
        Enemigo();
        Enemigo(string, int, int, int, int, Item*);
        ~Enemigo();
        void muestraStats();

        Item* getRecompensa();
        
    private:
        Item *recompensa;
};

Enemigo::Enemigo(){
    recompensa = new Item();
}

Enemigo::Enemigo(string n, int hp, int d, int a, int f, Item* i): Personaje(n, hp, d, a, f){
    recompensa = i;
}

Enemigo::~Enemigo(){}

void Enemigo::muestraStats(){
    cout << getNombre() << endl;
    cout << "Salud: " << getSalud() << endl;
}

Item* Enemigo::getRecompensa(){
    return recompensa;
}
#endif