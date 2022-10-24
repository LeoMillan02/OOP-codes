#ifndef Personaje_h
#define Personaje_h

/*
Clase personaje. Es una clase base. Maneja atributos de salud, defensa, ataque, nombre, faccion. Tiene
como métodos, tirar dado, atacar, mostrar stats. Entre estos métodos, mostrar stats, funciona polimorfica-
mente
*/

/*To-do:
    tirarDado
*/

class Personaje{
    public:
        Personaje();
        Personaje(string, int, int, int, int);
        ~Personaje();

        void setNombre(string);
        string getNombre();

        void setSalud(int&);
        int getSalud() const;

        void setDefensa(int);
        int getDefensa() const;

        void setAtaque(int);
        int getAtaque() const;

        void setFaccion(int);
        int getFaccion() const;

        virtual bool operator>(Personaje* );

        virtual void muestraStats() = 0;
    private:
        string nombre;
        int salud; //0-100
        int defensa; //0-20
        int ataque; //0-20
        int faccion; //1=bueno, 2=malo
};

Personaje::Personaje(){
    nombre = "JJ";
    salud = 100;
    defensa = 0;
    ataque = 0;
    faccion = 2;
}


Personaje::Personaje(string nom, int hp, int def, int at, int allegiance){
    nombre = nom;
    salud = hp;
    defensa = def;
    ataque = at;
    faccion = allegiance;
}

Personaje::~Personaje(){}

void Personaje::setNombre(string nom){
    nombre = nom;
}
string Personaje::getNombre(){
    return nombre;
}

void Personaje::setSalud(int &hp){
    salud = hp;
}
int Personaje::getSalud() const{
    return salud;
}

void Personaje::setDefensa(int def){
    defensa = def;
}
int Personaje::getDefensa() const{
    return defensa;
}

void Personaje::setAtaque(int a){
    ataque = a;
}
int Personaje::getAtaque() const{
    return ataque;
}

void Personaje::setFaccion(int f){
    faccion = f;
}
int Personaje::getFaccion() const{
    return faccion;
}

bool Personaje::operator>(Personaje* otro){
    if(this->getAtaque() > otro->getAtaque()){
        return true;
    }else{
        return false;
    }
}



#endif
