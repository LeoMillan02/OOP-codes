#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "shape.h"

class Rectangle:public Shape{
    public:
        Rectangle();
        Rectangle(double, double, double, double);
        double getWidth() const;
        double getHeigth() const;
        void setWidth(double);
        void setHeigth(double);
        string draw() override;
        double area();
    private:
        double width, heigth;  
};

Rectangle::Rectangle(){
    heigth = 1;
    width = 1;  
}
Rectangle::Rectangle(double x_, double y_, double wid, double hei):Shape(x_, y_){
    width = wid;
    heigth = hei;
    
}
double Rectangle::getWidth() const{
    return width;
}
double Rectangle::getHeigth() const{
    return heigth;
}
void Rectangle::setWidth(double wid){
    width = wid;
}
void Rectangle::setHeigth(double hei){
    heigth = hei;
}

string Rectangle::draw(){
    return Shape::draw()+ ": Rectangulo";
}

double Rectangle::area(){
    return heigth * width;
}
#endif