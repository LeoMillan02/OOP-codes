#ifndef PROTAGONISTA_H
#define PROTAGONISTA_H

#include "Personaje.h"
#include "Item.h"

/*To do:
    Cuando add2inventario se aplica, modificar stats
*/

class Protagonista: public Personaje{
    public:
        Protagonista();
        Protagonista(string, int, int, int, int, int);
        ~Protagonista();

        void add2Inventario(string, string, int, int);
        void add2Inventario(Item*);

        void setSizeInventario(int);
        int getSizeInventario() const;

        void muestraStats();

    private:
        int SizeInventario;
        Item* inventario[];

};

Protagonista::Protagonista(): Personaje(){
    SizeInventario = 1;
    for(int i=0; i<SizeInventario; i++){
        inventario[i]=nullptr;
    }
}

Protagonista::Protagonista(string n, int hp, int d, int a, int f, int s): Personaje(n, hp, d, a, 0){
    SizeInventario = s;
    for(int i=0; i<SizeInventario; i++){
        inventario[i]=nullptr;
    }
}
Protagonista::~Protagonista(){}

void Protagonista::add2Inventario(string n, string d, int def, int at){ //revisar esto, alta probabilidad de fallo
    int i = 0;
    while(true){
        if(inventario[i] == nullptr){ 
            inventario[i] = new Item(n,d,def,at);
            break;
        }else{
            i = i + 1;
        }
    }  
}

void Protagonista::add2Inventario(Item *cosa){
    int i = 0;
    while(true){
        if(inventario[i] == nullptr){ 
            inventario[i] = cosa;
            break;
        }else{
            i = i + 1;
        }
    }  
}

void Protagonista::setSizeInventario(int s){
    SizeInventario = s;
}
int Protagonista::getSizeInventario() const{
    return SizeInventario;
}

void Protagonista::muestraStats(){
    cout << getNombre() << endl;
    cout << "Salud: " << getSalud() << endl;
    cout << "Inventario: " << endl;
    for(int i=0; i<SizeInventario; i++){
        if(inventario[i] != nullptr)
            cout << "\t" << i+1 <<") " << inventario[i]->getNombre() << endl;
    }
}

#endif