//
//  Cuadratica.h
//
// COMPLETA LAS SOBRECARGAS DE OPERADORES QUE SE DESCRIBEN EN LAS INSTRUCCIONES
// APARECEN NUMERADAS EN LOS COMENTARIOS, SON 6.
// NO MODIFIQUES NADA EN EL MÉTODO MUESTRA

#ifndef Cuadratica_h
#define Cuadratica_h

class Cuadratica {
    
public:
    Cuadratica();
    Cuadratica(int, int, int);
      // Realiza las sobrecargas de operadores que se incluyen enseguida. 
      // La descripción y un ejemplo de cómo debe funcionar cada una la puedes ver en las instrucciones.
      // 1. suma de dos cuadráticas y regresa una cuadrática
      Cuadratica operator+(const Cuadratica&);   
      // 2. resta de dos cuadráticas y regresa una cuadrática
      Cuadratica operator-(const Cuadratica&); 
      // 3. multiplicar una cuadrática por un número entero y regresa una cuadrática
      Cuadratica operator* (int);
      // 4. incrementa una cuadrática con un valor entero y regresa una cuadrática
      Cuadratica operator++ ();
      // 5. comparar si dos cuadráticas son iguales
      bool operator==(Cuadratica&);
      // 6. comparar si dos cuadráticas son diferentes
      bool operator!=(Cuadratica&);       
    
    void muestra();
private:
    int coefA, coefB, coefC;
    
};

Cuadratica::Cuadratica() {
    coefA = 1;
    coefB = 1;
    coefC = 1;
}

Cuadratica::Cuadratica(int a, int b, int c) {
    coefA = a;
    coefB = b;
    coefC = c;
}

Cuadratica Cuadratica::operator+(const Cuadratica& otra){
    int a = coefA + otra.coefA;
    int b = coefB + otra.coefB;
    int c = coefC + otra.coefC;

    return Cuadratica(a,b,c);
}

Cuadratica Cuadratica::operator-(const Cuadratica& otra){
    int a = coefA - otra.coefA;
    int b = coefB - otra.coefB;
    int c = coefC - otra.coefC;

    return Cuadratica(a,b,c);
}

Cuadratica Cuadratica::operator* (int en){
    int n1 = coefA*en;
    int n2 = coefB*en;
    int n3 = coefC*en;
    return Cuadratica(n1,n2,n3);
}

Cuadratica Cuadratica::operator++(){
    coefC = coefC + 1;
    return *this;   
}

bool Cuadratica::operator == (Cuadratica& otra){
    if (coefA == otra.coefA && coefB == otra.coefB && coefC == otra.coefC){
        return true;
    }else{
        return false;
    }
}

bool Cuadratica::operator != (Cuadratica& otra){
    if (coefA != otra.coefA || coefB != otra.coefB || coefC != otra.coefC){
        return true;
    }else{
        return false;
    }
}

// NO MODIFIQUES NADA EN EL MÉTODO MUESTRA
void Cuadratica::muestra() {
    if (coefA != 0) {
        cout << coefA;
        cout << "x^2 ";
    }
    if (coefB != 0) {
        if (coefB > 0)
            cout << " + ";
        cout << coefB;
        cout << "x ";
    }
    if (coefC != 0) {
        if (coefC > 0)
            cout << " + ";
        cout << coefC << endl;
    }
}



#endif /* Cuadratica_h */