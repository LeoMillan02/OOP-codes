#ifndef CIRCLE_H
#define CIRCLE_H
#include "shape.h"

const double PI = 3.1416;

class Circle:public Shape{
    public:
        Circle();
        Circle(double, double, double);
        double getRatio() const;
        void setRatio(double);
        string draw() override;
        double area();
    private:
        double ratio;
};

Circle::Circle(){
    ratio = 1;
}

Circle::Circle(double x_, double y_, double rat):Shape(x_, y_){
    ratio = rat;

}

double Circle::getRatio() const{
    return ratio;
}
void Circle::setRatio(double rat){
    ratio = rat;
}
string Circle::draw(){
    return Shape::draw()+ ": Circulo";
}

double Circle::area(){
    return PI*ratio*ratio;
}

#endif

