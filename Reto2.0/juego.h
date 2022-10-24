#ifndef JUEGO_H
#define JUEGO_H

#include "Enemigo.h"
#include "Protagonista.h"
#include "Item.h"
#include "Habitacion.h"
#include "time.h"

/*To-Do
    robar y hacer una sobrecarga basada en el ataque. Hacer esto en Personaje
*/

class Juego{
    public:
        //aciones de sistema
        void input();
        void accion();
        void load();
        //comandos
        void atacar(string);
        void robar(string);
        void ver();
        void mover(string);
        void ayuda();
    private:
        string comandos[5] = {"atacar", "robar", "ver", "mover", "ayuda"}; 
        int NUM_COMANDS = 5;
        Habitacion* cuartos[4];
        Habitacion* room;
        Protagonista* Prota;
};

void Juego::ayuda(){
    cout << "Los dioses te apoyan..." << endl;
    cout << "No olvides las cosas que puedes hacer..." << endl;
    cout << "\tmover" << endl;
    cout << "\tver todo" << endl;
    cout << "\trobar " << endl;
    cout << "\tatacar " << endl;
    cout << "\trobar " << endl;
    cout << "\tayuda xel " << endl;
}


void Juego::atacar(string nom){
    //comprobar que el enemigo se encuentre en el cuarto
    if(room->getEnemy()->getNombre() != nom){
        cout << "No hay nadie asi para atacar..." << endl;
    }else{ //defensa == probabilidad de bloquear daño
        cout << "Comenzando el ataque" << endl;
        //Ciclio de ataque pseudoaleatorio
        do{
            int dado = rand() % 100; //simula tirar un dado de 100 caras
            if(room->getEnemy()->getDefensa() < dado){
                int dano = Prota->getAtaque();
                cout << room->getEnemy()->getSalud() << endl;
                int nuevaHP = room->getEnemy()->getSalud() - dano;
                room->getEnemy()->setSalud(nuevaHP); 
                cout << "Heriste a " << room->getEnemy()->getNombre() << " por " << dano << " de vida" << endl << endl;
                room->getEnemy()->muestraStats();
                cout << endl;
            }else{
                int dano = room->getEnemy()->getAtaque();
                int nuevaHP = Prota->getSalud() - dano;
                Prota->setSalud(nuevaHP);
                cout << "Te hirierion por " << dano << " de vida" << endl;
            }
        }while(room->getEnemy()->getSalud() > 0 == Prota->getSalud() > 0);

        //Revisa quien sobrevive para saber si el juego sique o no
        //Se otorga la recompensa y se modifican los stats
        if(Prota->getSalud() > 0){
            cout << "Genial derrotaste a " << room->getEnemy()->getNombre() << endl;
            cout << "Recibiste: " << endl;
            room->getEnemy()->getRecompensa()->MuestraInfo();
            cout << endl;
            Prota->add2Inventario(room->getEnemy()->getRecompensa());
            Prota->setAtaque(Prota->getAtaque() + room->getEnemy()->getRecompensa()->getAtaqueChange());
            Prota->setDefensa(Prota->getDefensa() + room->getEnemy()->getRecompensa()->getDefensaChange());
            Prota->muestraStats();
        }else{
            cout << "Has muerto" << endl;
        }
    }
}


void Juego::robar(string nom){
    if(nom != room->getEnemy()->getRecompensa()->getNombre()){
        cout << "Ese item no esta en esta habitacion..." << endl;
    }else{ 
        Personaje *e = room->getEnemy(); //downcast para que funcione la comparacion

        if (Prota->operator>(e)){ //compara los ataques 
            cout << "Robo exitoso" << endl;
            Prota->add2Inventario(room->getEnemy()->getRecompensa());
        }else{
            cout << "Robo fallido" << endl;
        }
    }
}


void Juego::ver(){
    cout << "Estas en " << room->getNombre() << endl;
    if(room->getEnemy() != nullptr){
        cout << "En la habitacion se encuentra:" << endl;
        room->getEnemy()->muestraStats();
    }
    room->mostrarPuertas();
    cout << "Que haras con lo que ahora sabes?" << endl;;
}


void Juego::mover(string dir){
    string direcciones[4] = {"norte", "sur", "este", "oeste"};
    bool check = 0;

    for(int i=0; i<4; i++){
        //Revisar que la direccion dada sea real
        if(dir == direcciones[i]){
            //Revisar que haya una puerta y que se pueda abrir en ese lugar
            if(room->revisarPuerta(i)) {
                //Si se pueden ambas cosas, se cambia de habitacion
                if(room->getNombre() == "Recibidor"){
                    if(i == 1){
                        room = cuartos[3];
                    }else if(i == 2){
                        room = cuartos[2];
                    }else if(i == 3){
                        room = cuartos[1];
                    }
                }else{
                    room = cuartos[0];
                }
                cout << "Cambiaste de cuarto, ahora estas en " << room->getNombre() << endl;
            }
            check = 1;
        }
    }
    if(check == 0){
        cout << "Escribe una direccion real..." << endl;
    }
}


void Juego::input(){
    string accion, especifico;
    int caso = -1;
    while(true){
        cout << "<<<< ";
        cin >> accion >> especifico;
        //cout << accion << " " << comandos[4] << " plop" << endl; 
        for(int i=0; i<NUM_COMANDS; i++){
            if(comandos[i] == accion){
                caso = i;
            }
        }
        if(caso == -1){
            cout << "Ese comando no es valido...\n";
        }else{
            break;
        }
    }
    switch (caso){
    case 0:
        if(especifico == ""){
            cout << "Que hay que atacar?" << endl;
            break;
        }else{
            cout << "Vamos a atacar" << endl;
            atacar(especifico);
            break;
        }
    case 1:
        if(especifico == ""){
            cout << "Que hay que robar?" << endl;
            break;
        }else{
            robar(especifico);
            break;
        }
    case 2:
        ver();
        break;
    case 3:
        if(especifico == ""){
            cout << "A donde me debo mover?" << endl;
            break;
        }else{
            mover(especifico);
            break;
        }
    case 4:
        ayuda();
        break;

    default:
        break;
    }
}


void Juego::load(){
    //El usuario pone su nombre
    srand(time(NULL));
    string nombre;
    cout << "Escoge un nombre para tu personaje: ";
    cin >> nombre;

    //Se genera al protagonista
    Prota = new Protagonista(nombre, 100, 15, 26, 0, 5);

    //Se cargan las recompensas en memoria
    Item* recompensas[3];
    recompensas[0] = new Item("Estrien", "Escudo usado por el guardian Draax. Se dice que aguanta incluso el fuego de dragon", 10, 0);
    recompensas[1] = new Item("Polos", "Legendaria espada blandida por Seris la cazadora de dioses", 0, 15);
    recompensas[2] = new Item("Grial Maldito", "Un artefacto capaz de destruir cualquier cosa, incluso entidades cosmica", 0, 100);

    //Se cargan los enemigos en memoria, para este nivel, se requieren 3 enemigos
    Enemigo* Enemigos[3];
    Enemigos[0] = new Enemigo("Draax", 50, 30, 10, 2, recompensas[0]);
    Enemigos[1] = new Enemigo("Seris", 50, 20, 20, 2, recompensas[1]);
    Enemigos[2] = new Enemigo("Zurduth", 80, 30, 30, 2, recompensas[2]);

    //Se cargan las salas, este nivel, utiliza 4 salas
    bool puertasPrin[4] = {0,1,1,1};
    bool candPrinc[4] = {0,0,1,1};

    bool puertasDer[4] = {0,0,1,0};
    bool candDer[4] = {0,0,1,0};

    bool puertasIzq[4] = {0,0,0,1};
    bool candIzq[4] = {0,0,0,1};

    bool puertasBoss[4] = {1,0,0,0};
    bool candBoss[4] = {0,0,0,0};

    cout << "Check" << endl;

    cuartos[0] = new Habitacion("Recibidor", 1, puertasPrin, candPrinc, nullptr);
    cuartos[1] = new Habitacion("Mazmorras", 1, puertasDer, candDer, Enemigos[0]);
    cuartos[2] = new Habitacion("Comedor", 1, puertasIzq, candIzq, Enemigos[1]);
    cuartos[3] = new Habitacion("Trono", 1, puertasBoss, candBoss, Enemigos[2]);


    //El juego empieza en el recibidor
    room = cuartos[0];

    cout << "Tu mision te ha llevado finalmente al castillo de Zurduth" << endl;
    cout << "No sabes lo que te espera dentro, pero aun asi abres la sospechosa puerta y te adentras a lo desconocido" << endl;

    do{
        input();
        if(Enemigos[0]->getSalud() <= 0 && Enemigos[1]->getSalud() <= 0){
            cout << "Un hechizo se activa ante tus pies..." << endl;
            cout << "Estas en otra habitacion" << endl;
            room = cuartos[3];
            cuartos[0]->desbloquearPuerta(1);
            break;
        }
    }while(Enemigos[2]->getSalud() > 0 == Prota->getSalud() > 0);

    do{
        input();
    }while(Enemigos[2]->getSalud() > 0 == Prota->getSalud() > 0);

    if(Enemigos[2]->getSalud() <= 0)
        cout << "Lo lograste! Has derrotado a Zurduth" << endl;
        cout << "Ahora el mundo podra vivir en paz" << endl;
}


#endif