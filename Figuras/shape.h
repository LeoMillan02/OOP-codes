#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>
using namespace std;

class Shape {
    public:
        Shape();
        Shape(double, double);
        double getValueX() const;
        double getValueY() const;
        void setValueX(double);
        void setValueY(double);
        virtual string draw();
        virtual double area() = 0;
    private:
        double x;
        double y;
};

Shape::Shape (){
    x=0;
    y=0;
}

Shape::Shape (double valX, double valY){
    x=valX;
    y=valY;
}


double Shape::getValueX() const{
    return x;
}

double Shape::getValueY() const{
    return y;
}

void Shape::setValueX(double x_){
    x=x_;
}

void Shape::setValueY(double y_){
    y=y_;
}

string Shape::draw(){
    return "Soy una figura";
}



#endif //SHAPE_H