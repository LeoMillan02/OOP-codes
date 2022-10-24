#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

#include "Automovil.h"
#include "Camion.h"

//constante para el número máximo de datos
const int MAX=10;

/* Funcion que lee un archivo de texto donde los datos están separados por "," 
   cada renglón es un vehículo observa el archivo inventario.txt para que veas
   el formato y trata de entender el código pero no lo cambies*/
int cargaDatos(Vehiculo* invent[]){
    ifstream archivo;
    archivo.open("inventario.txt");
    char tipo;
    string marca, color, modelo, trans;
    double precio, largo, ancho, alto;
    int numPuertas, tipoCom, i=0;
    if (archivo.is_open()){ //Si pudo abrir el archivo
        string linea;
        while(getline(archivo,linea)){ //leo la primera línea
            stringstream sstr(linea); // Declaro un stringstream para poder leer los datos separados por ","
            string dato;
            vector<string> datos; //un vector para guardar cada dato del renglón
            while (getline(sstr, dato,',')) { 
                datos.push_back(dato); //Por cada dato del renglón lo agrego al vector
            }
            tipo=datos[0].at(0); //en la posición 0 obtengo el char de tipo de vehículo
            marca=datos[1]; 
            color=datos[2];
            modelo=datos[3];
            precio=stod(datos[4]);
            if(tipo=='a'){ //Si el tipo es automovil los datos que siguen son:
                trans=datos[5];
                numPuertas=stoi(datos[6]);
                tipoCom=stoi(datos[7]);
                //Creo el objeto Automóvil y lo agrego al arreglo
                invent[i]=new Automovil(marca, color, modelo, precio, trans,  numPuertas, tipoCom);
                i++;

            }
            else if(tipo=='c'){ //Si el tipo es camion los datos que siguen deben ser:
                 largo=stod(datos[5]);
                 ancho=stod(datos[6]);
                 alto=stod(datos[7]);
                //Creo el objeto camnión
                 invent[i]=new Camion(marca, color, modelo, precio, largo, ancho, alto);  
                 i++;
            }
        }      
        archivo.close(); //Se acabaron los renglones del archivo, cierro el archivo
    }
    else{
        //Si no pudo abrir el archivo cierro el flujo hacia el archivo
        cout<< "Error de lectura de archivo"<<endl;
    }
    //Regreso el número de renglones que leí y que corresponderá al número de vehiculos creados
    return i;
}

int main() { 
    //1. DECLARA un arreglo de apuntadores a Vehiculo con número MAX de localidades
    Vehiculo* arr[MAX];
    /*Llenamos el arreglo con los datos del archivo llamando a la función y
      guardamos en num el número de objetos creados*/
    int num=cargaDatos(arr);
    //Mostramos el polimorfismo, recorro el arreglo e imprimo los datos
    for(/*2. COMPLETA*/int i = 0; i<num; i++){
        cout << "------------------- VEHICULO " << i+1 << " --------------------" <<endl;
        //3. IMPRIMIR el Vehiculo correspondiente
        arr[i] -> imprimeVehiculo();
        cout << "---------------------------------------------------" << endl;
    }
    return 0;
}