
#include <iostream>
using namespace std;


//Agrega lo que haga falta
#include "Articulo.h"
#include "ArticuloPorPeso.h"
#include "ArticuloPorPieza.h"

int main() {

    
    // crea un arreglo o vector para guardar los artículos
    
    
    int size;
    Articulo* arr[10];
    string desc;
    double pre, peso;
    char tipo;
    int piezas;
    double totalFactura;
    
    //cout << "Cuantos artículos tiene la factura? " << endl; 
    cin >> size;
    
    for (int i = 0; i < size; i++) {
        //cout << "descripción? "; No lo quites como comentario es solo informativo
        cin >> desc;
        
        //cout << "precio? "; No lo quites como comentario es solo informativo
        cin >> pre;
       
        //cout << "Tipo de artículo: a) por pieza o b) por peso "; No lo quites como comentario
        cin >> tipo;
        
        if (tipo == 'a') {
            //cout << "cuantas piezas lleva? "; No lo quites como comentario es solo informativo
            cin >> piezas;
            //Completa lo que hace falta de acuerdo a las instrucciones
            arr[i] = new ArticuloPorPieza(desc,pre,piezas); 

            

        }
        else {
            //cout << "cuanto pesa ? "; No lo quites como comentario es solo informativo
            cin >> peso;
            //Completa lo que hace falta de acuerdo a las instrucciones
            arr[i] = new ArticuloPorPeso(desc,pre,peso); 
    
        }
    }
    
    cout << endl;
    cout << "Factura " << endl;
   
     // Agrega lo necesario para MOSTRAR los datos de los productos
     // Tambien es necesario que se vaya ACUMULANDO el precio a pagar por cada producto para el total a pagar 
    
    for(int i = 0; i < size; i++){
        arr[i]->muestra();
        totalFactura += arr[i]->precioAPagar() ;
    }
    
    
    cout << "Total a pagar " << /*COMPLETA LO QUE FALTA AQUI*/ totalFactura << endl;
    
    return 0;
}

/*Este es un ejemplo de corrida con 3 artículos:
3                            
manzana
38.5
b
1.5
cloro
34.5
a
1
pera
67
b
0.5

Factura
manzana 1.5 Kg 57.75
1 cloro 34.5
pera 0.5 Kg 33.5
Total a pagar 125.75
*/