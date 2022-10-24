#ifndef HABITACION_H
#define HABITACION_H

#include "Protagonista.h"
#include "Enemigo.h"


class Habitacion{

    public:
        Habitacion();
        Habitacion(string, int, bool[], bool[], Enemigo*); 

        Enemigo* getEnemy();

        string getNombre() const;
        void mostrarPuertas();

        bool revisarPuerta(int);
        void desbloquearPuerta(int);

    private:
        string nombre;
        int tipo; // 1=sala, 2=pasillo
        bool puertas[4]; // [arriba, abajo, izq, der]
        bool candado[4];// [arriba, abajo, izq, der]
        Enemigo* enemy;

};

Habitacion::Habitacion(){
    nombre = "";
    tipo = 1;
    for(int i=0; i<4; i++){
        puertas[i] = 0;
        candado[i] = 0;
    }
    enemy = nullptr;

}

Habitacion::Habitacion(string nom, int tip, bool prts[4], bool cands[4], Enemigo *enem){
    nombre = nom;
    tipo = tip;
    for(int i=0; i<4; i++){
        puertas[i] = prts[i];
        candado[i] = cands[i];
    }
    enemy = enem;

}

Enemigo* Habitacion::getEnemy(){
    return enemy;
}

string Habitacion::getNombre() const{
    return nombre;
}

void Habitacion::mostrarPuertas(){
    for(int i=0; i<4; i++){
        if(puertas[i] == 1){
            switch (i)
            {
            case 0:
                cout << "Hay una puerta al norte" << endl;
                break;
            case 1:
                cout << "Hay una puerta al sur" << endl;
                break;
            case 2:
                cout << "Hay una puerta al este" << endl;
                break;
            case 3:
                cout << "Hay una puerta al oeste" << endl;
                break;
            default:
                break;
            }
        }
    }
}

bool Habitacion::revisarPuerta(int prt){
    if(puertas[prt] == 1){
        cout << "Intenta abrirla..." << endl;
        if(candado[prt] == 1){
            cout << "Se ha abierto!" << endl;
            return 1;
        }else{
            cout << "Esta puerta esta bloqueada por algun tipo de magia" << endl;
            return 0;
        }
    }
    cout << "Ahi no hay una puerta..." << endl;
    return 0;
}

void Habitacion::desbloquearPuerta(int prt){
    candado[prt] == 1;
}
#endif