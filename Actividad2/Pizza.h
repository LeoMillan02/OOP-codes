#ifndef PIZZA_H
#define PIZZA_H
/*Esta clase describe una comida tipo Pizza, tiene atributos adicionales:
  un arreglo con el nombre de los ingredientes extra
  el número de ingredientes extra que tiene la pizza
  un char que representa el tamaño de la misma*/

#include "Comida.h"

/*Constantes que usa la clase la primera fila son los costos base por tamaño
  y extra representa lo que cuesta agregar un ingrediente extra*/
const double CHICA = 70, MEDIANA = 90, GRANDE = 120, EXTRA=15;
//Esta constante es para el tamaño del arreglo de los ingredientes
const int EXTRA_ING = 3;

class Pizza:public Comida{  //1. Completa el encabezado de la clase, recuerda que deriva de Comida

    public:
        Pizza();
        Pizza(string, double, int, string, char);
        ~Pizza();
        char getTamPizza();
        void setTamPizza(char);
        void setIngredientesExtra(string[], int);
        void muestra();
        void calculaPrecioFinal();

    private:
        int ingredientesExtra; // cantidad de ingredientes extra de la pizza, maximo 3
        string ingredientes[EXTRA_ING]; // nombre de los ingredientes
        char tamPizza; //c chica, m mediana, g grande
};


/*Constructor por default siempre crea una pizza chica sin ingredientes extra.
  Inicia Comida con nombre "Pizza" (Respeta las minúsculas) y con el precio de la CHICA
  Inicia el número de ingredientes a 0 y el arreglo de ingredientes con cadenas vacias 
  en cada localidad, así como el tamaño a c (chica)*/

//2. Escribe el constructor por default siguiendo las características que indica el comentario de arriba

Pizza::Pizza(){
  
  tamPizza = 'c';
  ingredientesExtra = 0;
  ingredientes[EXTRA_ING] = "";
  
}


/* Constructor que recibe el tamaño de la pizza
   Este constructor inicia la comida a nombre "Pizza" y un costo de 0
   Además se incian el número de ingredientes a 0 y se llena el arreglo con cadenas vacías
   Por último se modifica el precio de acuerdo al tamaño recibido en el parámetro,
   recuerda usar las constantes que tienes con los precios de cada tamaño*/

//3. Escribe el constructor que recibe el tamaño de la pizza de acuerdo al comentario de arriba

Pizza::Pizza(string nombre_, double precio_, int ingreEx, string nomEx, char tam):Comida(nombre_,precio_){
  nombre_ = "Pizza";
  precio_ = 0;
  ingreEx = 0;
  nomEx = "";
  tam = 'c';
}



Pizza::~Pizza(){
    
}


//Modificador del tamaño de la pizza
void Pizza::setTamPizza(char tamPizza_){
  tamPizza = tamPizza_;
  //Modificamos el precio porque el precio depende del tamaño
  if (tamPizza == 'c' || tamPizza == 'C' )
    setPrecio(CHICA);
  else if (tamPizza == 'm' || tamPizza == 'M')
    setPrecio(MEDIANA);
  else
    setPrecio(GRANDE);
}


/*Método que recibe arreglo de strings y un entero que representa el número de ingredientes
  Actualiza los datos del arreglo de ingredienes y el atributo ingredientesExtra*/
void Pizza::setIngredientesExtra(string ingredientes_[EXTRA_ING], int ingExtra_){
  ingredientesExtra = ingExtra_;
  for (int i = 0; i < ingredientesExtra && i < EXTRA_ING; i++){
    ingredientes[i] = ingredientes_[i];
  }
}





/*Este método actualiza (incrementa) el precio de acuerdo al número de ingredientes extra, 
  recuerda que cada ingrediente extra tiene un costo dado por la constante EXTRA*/
void Pizza::calculaPrecioFinal(){
  //4. Completa este método, que debe actualizar el atributo precio
  getPrecio();
}

/*Este método muestra la descripción de la pizza con los ingredientes y el precio de la misma
  NO MODIFIQUES ESTE MÉTODO*/
void Pizza::muestra(){
    cout << getNombre() << " con " << ingredientesExtra << " ingredientes extra " << endl;
    for (int i = 0; i < ingredientesExtra; i++)
        cout << "----" << ingredientes[i] << endl;
    cout << "Total: $ " << getPrecio() << endl;
}

#endif // PIZZA_H