#ifndef FRACCION_H
#define FRACCION_H
#include <iostream>
using namespace std;

class Fraccion {    
    public:
        //Constructores
        Fraccion();
        Fraccion(int, int); // primero el numerador y luego el denominador

        //Metodos de acceso
        int getNum() const;
        int getDen() const;

        //Metodos de modificacion
        void setNum(int);
        void setDen(int);

        // Otros métodos
        double valorDecimal();

        // sobrecargas
        // a) suma 2 fracciones
        Fraccion operator+(const Fraccion&);   
        // b) Operador unitario -. Devuelve la Fraccion pero negativa. NOTA que solo debe cambiar el signo al numerador
        Fraccion operator-();
        // c) == igual. Compara el valor en decimal de ambas fracciones
        bool operator==(Fraccion&);
        // d) + suma fraccion + entero. Ejemplo f3 = f1 + 5;
        Fraccion operator + (int);
        // e) ++ incrmenta 1 entero. Ejemplo f3 = ++f1;
        Fraccion operator ++ ();
        // f) += suma. Ejemplo:   f1 += f2;
        void operator += (const Fraccion&);
        // Sobrecarga de operador de flujo de salida <<
        friend ostream& operator<< (ostream &, const Fraccion&);

    
    private:
        // atributos
        int num;
        int den;
};

//Constructores
Fraccion::Fraccion() {
    num = 1;
    den = 1;
}

Fraccion::Fraccion(int n, int d) { // primero el numerador y luego el denominador 
    num = n;
    den = d;
}

//Metodos de acceso
int Fraccion::getNum() const {
    return num; 
}

int Fraccion::getDen() const {
    return den; 
}

//Metodos de modificacion
void Fraccion::setNum(int n) {
    num = n; 
} 

void Fraccion::setDen(int d) { 
    den = d; 
}

//Funcion  para calcular el valor decimal
double Fraccion::valorDecimal() {
    return (double)num / den;
}

// 1. Suma 2 fracciones
Fraccion Fraccion::operator+(const Fraccion& otra){
    int n = num*otra.den + den*otra.num;
    int d = den*otra.den;
    return Fraccion(n,d);
}

// 2. Sobrecarga de operador unitario -. Para hacer negativa la fraccion. NOTA que solo debe cambiar el signo al numerador
Fraccion Fraccion::operator-(){
    int n = num*-1;
    return Fraccion(n, den);
}
// 3. Sobrecarga de operador ==. Compara el valor en decimal de ambas fracciones
bool Fraccion::operator == (Fraccion& otra){
    return valorDecimal() == otra.valorDecimal();
}

// 4. Sobrecarga de operador + para sumar fraccion + entero.
Fraccion Fraccion::operator + (int en){
    int n = (den*en) + num;
    return Fraccion(n, den);
}

// 5. Sobrecarga del operador de flujo de salida 
ostream& operator<< (ostream &os, const Fraccion& otra){
     os<<otra.num<<"/"<<otra.den;
 }

// 6. Sobrecarga de operador ++ incrementa 1 entero. Ejemplo f3 = ++f1  preincremento
Fraccion Fraccion::operator ++ (){
    *this = *this+1;
    return *this;
}

// 7. Sobrecarga de operador += suma. Ejemplo:   f1 += f2;
void Fraccion::operator += (const Fraccion& nueva){
    *this = *this + nueva;
}

#endif //FRACCION_H