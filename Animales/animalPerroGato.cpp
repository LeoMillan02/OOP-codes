
#include <iostream>
#include <string>
using namespace std;

#include "Perro.h"
#include "Gato.h"

int main()
{
    
//  ***Sigue los pasos de la sección "Instructions" para construir este programa***
//    Este sería el menú, si se desplegara, pero déjalo como comentario, es sólo guía para ti.
//    cout << "a) mostrar los 3 datos de ejemplo " << endl;
//    cout << "b) pedir al usuario los datos y mostrarlos " << endl;
//    cout << "opcion? " << endl;
  char opcion;
  cin>> opcion;
  Animal* arr[3];
  char tipo;
  string nombre;
  int anio;

  switch (opcion){
    case('a'):
      
      arr[0] = new Gato("Silvestre",1947);
      arr[1] = new Perro("Fido", 2008);
      arr[2] = new Gato("Tom", 1940);

      for(int i=0; i<3;i++){
          arr[i]->muestra();
          arr[i]->habla();
    }
    break;
    case('b'):

        for(int i=0;i<3;i++){

            cin>>tipo>>nombre>>anio;
            if(tipo == 'g'&& 'G'){
                arr[i]=new Gato(nombre, anio);
            }
            else if(tipo == 'p' && 'P'){
                arr[i] = new Perro(nombre, anio);
            }
        }

        for(int i=0; i<3;i++){
            arr[i]->muestra();
            arr[i]->habla();
        }
    break;
  default:
      break;
  }
    return 0; 
}