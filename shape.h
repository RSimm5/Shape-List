/* 
shape.h
Starter code created by Dr. Adam T. Koehler
File completed by Rovia Simmons
shape.h is used to define shape classes and classes that inherit Shape, and any info inside of them.
*/

#pragma once

using namespace std;

class Shape
{
    protected:
        int x;
        int y;

    public: 
        Shape();
        Shape(int x, int y);

        virtual ~Shape();
        virtual Shape* copy();

        int getX() const;
        int getY() const;
        void setX(int);
        void setY(int);
        
        virtual void printShape() const;
};

//default constructor
Shape:: Shape() {
    this->x = 0;
    this->y = 0;
}

//parameterized constructor
Shape:: Shape(int x, int y) {
    this->x = x;
    this->y = y;
}

//destructor
Shape::~Shape() {

}

//returns a new copy of the object with its own memory location
Shape* Shape:: copy() {
    return new Shape(*this);
}

//getter functions
int Shape:: getX() const {
    return x;
}

int Shape:: getY() const {
    return y;
}

//setter functions
void Shape:: setX(int x) {
    this->x = x;
}

void Shape:: setY(int y) {
    this->y = y;
}

//prints shape information
void Shape:: printShape() const {
    cout << "It's a Shape at x: " << x << ", y: " << y << endl;
}


class Circle : public Shape 
{
    private:
        int radius;

    public: 
        Circle();
        Circle(int r);
        Circle(int x, int y, int r);

        virtual ~Circle();
        virtual Circle* copy();
        
        int getRadius() const;
        void setRadius(int);
        
        virtual void printShape() const;
};

//default constructor
Circle::Circle(): Shape() {
    radius = 0;
}

//paramaterized constructor
Circle::Circle(int r): Shape() {
    radius = r;
}

//fully parameterized constructor
Circle::Circle(int x, int y, int r): Shape(x, y) {
    radius = r;
}

//destructor
Circle:: ~Circle() {

}

//returns a new copy of the object with its own memory location
Circle* Circle:: copy() {
    return new Circle(*this);
}

//getter
int Circle:: getRadius() const{
    return radius;
}

//setter
void Circle:: setRadius(int r) {
    radius = r;
}

//prints shape information
void Circle:: printShape() const {
    cout << "It's a Circle at x: " << x << ", y: " << y << ", radius: " << radius << endl;
}


class Rectangle : public Shape 
{
    private:
        int width;
        int height;

    public: 
        Rectangle();
        Rectangle(int w, int h);
        Rectangle(int x, int y, int w, int h);
        
        virtual ~Rectangle();
        virtual Rectangle* copy() {
            return new Rectangle(*this);
        }
        
        int getWidth() const;
        int getHeight() const;
        void setWidth(int);
        void setHeight(int);
        
        virtual void printShape() const;
};

//default constructor
Rectangle:: Rectangle(): Shape() {
    width = 0;
    height = 0;
}

//parameterized constructor
Rectangle:: Rectangle(int w, int h): Shape() {
    width = w;
    height = h;
}

//fully parameterized constructor
Rectangle:: Rectangle(int x, int y, int w, int h): Shape(x, y) {
    width = w;
    height = h;
}

//destructor
Rectangle:: ~Rectangle() {

}

//getter functions
int Rectangle:: getWidth() const {
    return width;
}
int Rectangle:: getHeight() const {
    return height;
}

//setter functions
void Rectangle:: setWidth(int w) {
    width = w;
}
void Rectangle:: setHeight(int h) {
    height = h;
}

//prints shape information
void Rectangle:: printShape() const {
    cout << "It's a Rectangle at x: " << x << ", y: " << y << " with width: " << width << " and height: " << height << endl;
}


class RightTriangle : public Shape 
{
    private:
        int base;
        int height;

    public: 
        RightTriangle();
        RightTriangle(int b, int h);
        RightTriangle(int x, int y, int b, int h);
        
        virtual ~RightTriangle();
        virtual RightTriangle* copy();
        
        int getBase() const;
        int getHeight() const;
        void setBase(int);
        void setHeight(int);

        virtual void printShape() const;
};

//default constructor
RightTriangle:: RightTriangle(): Shape() {
    base = 0;
    height = 0;
}

//parameterized constructor
RightTriangle:: RightTriangle(int b, int h): Shape() {
    base = b;
    height = h;
}

//fully parameterized constructor
RightTriangle:: RightTriangle(int x, int y, int b, int h): Shape(x, y) {
    base = b;
    height = h;
}

//destructor
RightTriangle:: ~RightTriangle() {
    
}

//returns a new copy of the object with its own memory location
RightTriangle* RightTriangle:: copy() {
    return new RightTriangle(*this);
}

int RightTriangle:: getBase() const {
    return base;
}
int RightTriangle:: getHeight() const {
    return height;
}
void RightTriangle:: setBase(int b) {
    base = b;
}
void RightTriangle:: setHeight(int h) {
    height = h;
}

//prints shape information
void RightTriangle:: printShape() const {
    cout << "It's a Right Triangle at x: " << x << ", y: " << y << " with base: " << base << " and height: " << height << endl;
}