#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item{
    public:
        Item();
        Item(string, string, int, int);
        void MuestraInfo();

        void setNombre(string);
        string getNombre() const;

        void setDescripcion(string);
        string getDescripcion() const;

        void setDefensaChange(int);
        int getDefensaChange() const;

        void setAtaqueChange(int);
        int getAtaqueChange() const;

    private:
        string nombre;
        string descripcion;
        int defensaChange; //Cuanta defensa le aumentara/disminuira al personaje que lo porte
        int ataqueChange; //lo mismo que en defensaChange
};

Item::Item(){
    nombre = "";
    descripcion = "";
    defensaChange = 0;
    ataqueChange = 0;
}
Item::Item(string nom, string desc, int def, int at){
    nombre = nom;
    descripcion = desc;
    defensaChange = def;
    ataqueChange = at;
}

void Item::MuestraInfo(){
    cout << nombre << endl;
    cout << descripcion << endl;
    if(defensaChange >= 0){
        cout << "Defensa: +" << defensaChange << endl;
    }else{
        cout << "Defensa: -" << defensaChange << endl;
    }
    if(ataqueChange >= 0){
        cout << "Ataque: +" << ataqueChange << endl;
    }else{
        cout << "Ataque: -" << ataqueChange << endl;
    }
}

void Item::setNombre(string n){
    nombre = n;
}
string Item::getNombre() const{
    return nombre;
}

void Item::setDescripcion(string d){
    descripcion = d;
}
string Item::getDescripcion() const{
    return descripcion;
}

void Item::setDefensaChange(int d){
    defensaChange = d;
}
int Item::getDefensaChange() const{
    return defensaChange;
}

void Item::setAtaqueChange(int a){
    ataqueChange = a;
}
int Item::getAtaqueChange() const{
    return ataqueChange;
}

#endif