//
//  main.cpp
//  sobrecargaFraccionClase
//
//  Created by Yolanda Martinez on 5/31/2020
//  Copyright © 2020 com.itesm. All rights reserved.
//

#include <iostream>
using namespace std;

#include "Fraccion.h"

int main() {

    char opcion;
    Fraccion f1(1,4), f2(3,5), f3;
    
    cout << "Opcion: ";
    cin >> opcion;
    
    switch (opcion) {
        case 'a':
            // suma
            cout << f1 << " + " << f2 << " = " << f1 + f2 << endl;
            break;
           
        case 'b':
            // negativo
            cout << "f2 = "<< f2 << endl;
            cout << "el negativo de f2 lo guardo en f3" << endl;
            f3 = -f2;
            cout << "f2 = "<< f2 << endl;
            cout << "f3 = "<< f3 << endl;
            break;
            
        case 'c':
            // igual
            cout << "f2 = "<< f2 << endl;
            cout << "f3 = "<< f3 << endl;
            if (f2 == f3)
                cout << "f2 y f3 son iguales " << endl;
            else
                cout << "f2 y  f3 son diferentes" << endl;
            break;

         case 'd':
            // suma fraccion + entero.
            cout << "f1 = "<< f1 << endl;            
            cout << "suma de f1 + 2; " << endl;
            f3 = f1 + 2;
            
            cout << "f1 = "<< f1 << endl;
            cout << "f3 = "<< f3 << endl;

            break;
            
        case 'e':
            // incrmenta 1 unidad a la fracción.
                        
            cout << "f1 = "<< f1 << endl;
            cout << "incrementa f3 = ++f1; " << endl;
            f3 = ++f1;
            cout << "f1 = "<< f1 << endl;
            cout << "f3 = "<< f3 << endl;


            break;
            
        case 'f':
            // += suma lo del lado derecho a la fracción del lado izquierdo
            cout << "f1 = "<< f1 << endl;
            cout << "f2 = "<< f2 << endl;
            cout << " f1 += f2; " << endl;
            f1 += f2;
            cout << "f1 = "<< f1 << endl;
            cout << "f2 = "<< f2 << endl;
            break;
    }

    
    return 0;
}
