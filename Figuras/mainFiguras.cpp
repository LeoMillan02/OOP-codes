#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "circle.h"
#include "rectangle.h"

int main(){
    
    Shape* arr[5];
    arr[0] = new Circle(0,0,3);
    arr[1] = new Rectangle(1,1,3,4);
    arr[2] = new Circle(5,-1,4);
    arr[3] = new Circle(3,4,3);
    arr[4] = new Rectangle(2,2,3,6);
    for(int i = 0; i<5; i++){
        cout << arr[i] -> draw() << endl;
    }
    cout << "-------- Con Vector --------" << endl;
    vector<Shape*> fig2;
    fig2.push_back(new Circle(3,2,1));
    fig2.push_back(new Circle(0,2,3));
    fig2.push_back(new Rectangle(2,2,5,6));
    for(int i=0; i<fig2.size(); i++){
        cout << fig2[i] -> draw() << endl;
        cout << "El area es: " << fig2[i]->area() <<endl;    
        Circle* c=dynamic_cast<Circle*>(fig2[i]);
        if(c){
            cout << "El radio del circulo es: " << c->getRatio() << endl;
        }
    }
    return 0;
}