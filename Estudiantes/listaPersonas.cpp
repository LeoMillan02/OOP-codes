//
//  main.cpp
//  PolimPersonaMaestroEstudiante
//
//  Created by Yolanda Martinez on 17/05/20.
//  Copyright © 2020 com.itesm. All rights reserved.
//
#include <iostream>
using namespace std;

#include "Estudiante.h"
#include "Maestro.h"

int main() {
    
    // 2. COMPLETAR: Declara un arreglo de apuntadores a objeto de tipo Persona (20 localidades)
    Persona* arr[20];
    int cantPersonas;
    char opcionPersona, opcionMenu;
    int edad, edadIni, edadFin;
    string nombre, carrera, departamento;
    
    //cout << "Cuantas personas hay? "; No lo quites como comentario es sólo para guiarte sobre lo que se está pidiendo
    cin >> cantPersonas;
    
    for (int c = 0; c < cantPersonas; c++){
        //cout << "a) Estudiante, b) Maestro y c) Ninguno de los dos" << endl; No lo quites como comentario
        cin >> opcionPersona;
        
        //cout << "Nombre? ";
        cin >> nombre;
        
        //cout << "Edad? ";
        cin >> edad;
        
        if (opcionPersona == 'a') {
            //cout << "Carrera? "; No lo quites como comentario
            cin >> carrera;
            
            //3. COMPLETAR: Agrega al estudiante a la lista de personas
            arr[c] = new Estudiante(nombre, edad, carrera);
        }
        else if (opcionPersona == 'b') {
            //cout << "Departamento? "; No lo quites como comentario
            cin >> departamento;
            
            // 4. COMPLETAR: Agrega al maestro a la lista de personas
            arr[c] = new Maestro(nombre, edad, departamento);
            }
        else {
            
            // 5. COMPLETAR: Agrega a la persona a la lista de personas
            arr[c] = new Persona(nombre, edad);
        }
    }
    
    
    do{
        //Las siguientes lineas no las quites como comentario, es sólo para guiarte, es lo que sería el despliegue del menú
        //cout << "Menu de opciones " << endl;
        //cout << endl;
        //cout << "a) muestra todas las personas " << endl;
        //cout << "b) muestra personas en un rango de edad " << endl;
        //cout << "c) terminar " << endl;
        //cout << "opcion -> " << endl;
        cin >> opcionMenu;
        
        switch (opcionMenu) {
            case 'a':  
                {
                
                // 6. COMPLETAR: Muestra la lista de personas
                // Recuerda: cada persona tiene que mostrarse usando su propia version del muestraDatos
                    
                   for(int i = 0; i<cantPersonas; i++){
                            arr[i] -> muestraDatos(); 
                    }
                
                
                }
            break;
           
                
            case 'b':  
                {
                int edadTmp;
                //cout << "edad inicial "; No lo quites como comentario
                cin >> edadIni;
                //cout << "edad final? "; No lo quites como comentario
                cin >> edadFin;
                
                // 7. COMPLETAR: Muestra la lista de personas cuya edad cae en el rango especificado
                // Recuerda cada persona tiene que mostrarse usando su propia version del muestraDato
                  for(int i = 0; i<cantPersonas; i++){
                        if(edadIni<=arr[i]->getEdad()&& edadFin>= arr[i] ->getEdad()){
                            arr[i] -> muestraDatos(); 
                        }
                    }
                }
                break;
            }
        }while (opcionMenu != 'c');
    
    return 0;
}