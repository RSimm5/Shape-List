/*
@filename tests.cpp
created by Rovia Simmons
Used to test cases of functions in shape.h and canvaslist.h
below uses the Catch testing framework version that uses a single .hpp file.
*/

#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "shape.h"
#include "canvaslist.h"

using namespace std;

TEST_CASE("(0) no tests") 
{
  //
  // done
  //
}

// #####################################
// I. TEST CASE 1 -  constructor, getters -- make default Shape
// #####################################
TEST_CASE("Shape constructor") {
    Shape s;
    REQUIRE(s.getX() == 0);
    REQUIRE(s.getY() == 0);
    
}

// #####################################
// I. TEST CASE 2 -  constructor, getters -- make parameterized Shape
// #####################################
TEST_CASE("Shape parameterized constructor") {
    Shape s(2,3);
    REQUIRE(s.getX() == 2);
    REQUIRE(s.getY() == 3);
}

// #####################################
// I. TEST CASE 3 -  constructor, setters, getters
// #####################################
TEST_CASE("Shape changes") {
    Shape s;
    s.setX(2);
    s.setY(3);
    REQUIRE(s.getX() == 2);
    REQUIRE(s.getY() == 3);
}

// #####################################
// I. TEST CASE 4 -  constructor, copy, getters
// #####################################
TEST_CASE("Shape copy") {
    Shape s(2,3);
    Shape s2 = *s.copy();
    REQUIRE(&s != &s2);
    REQUIRE(s2.getX() == 2);
    REQUIRE(s2.getY() == 3);
}

// #####################################
// I. TEST CASE 5 -  constructor, getters -- make default Circle
// #####################################
TEST_CASE("Circle constructor") {
    Circle c;
    REQUIRE(c.getX() == 0);
    REQUIRE(c.getY() == 0);
    REQUIRE(c.getRadius() == 0);
}

// #####################################
// I. TEST CASE 6 -  constructor, getters -- make parameterized Circle
// #####################################
TEST_CASE("Circle parameterized constructor") {
    Circle c(2);
    REQUIRE(c.getX() == 0);
    REQUIRE(c.getY() == 0);
    REQUIRE(c.getRadius() == 2);
}

// #####################################
// I. TEST CASE 7 -  constructor, getters -- make fully parameterized Circle
// #####################################
TEST_CASE("Circle fully parameterized constructor") {
    Circle c(1,2,3);
    REQUIRE(c.getX() == 1);
    REQUIRE(c.getY() == 2);
    REQUIRE(c.getRadius() == 3);
}

// #####################################
// I. TEST CASE 8 -  constructor, setters, getters
// #####################################
TEST_CASE("Circle changes") {
    Circle c;
    c.setX(1);
    c.setY(2);
    c.setRadius(3);
    REQUIRE(c.getX() == 1);
    REQUIRE(c.getY() == 2);
    REQUIRE(c.getRadius() == 3);
}

// #####################################
// I. TEST CASE 9 -  constructor, copy, getters
// #####################################
TEST_CASE("Circle copy") {
    Circle c(1,2,3);
    Circle c2 = *c.copy();
    REQUIRE(&c != &c2);
    REQUIRE(c2.getX() == 1);
    REQUIRE(c2.getY() == 2);
    REQUIRE(c2.getRadius() == 3);
}

// // #####################################
// // I. TEST CASE 10 -  constructor, getters -- make default Rectangle
// // #####################################
// TEST_CASE("Rectangle constructor") {
//     Rectangle r;
//     REQUIRE(r.getX() == 0);
//     REQUIRE(r.getY() == 0);
// }

// // #####################################
// // I. TEST CASE 11 -  constructor, getters
// // #####################################
// TEST_CASE("Rectangle parameterized constructor") {
//     Rectangle r(3,4);
//     REQUIRE(r.getX() == 0);
//     REQUIRE(r.getY() == 0);
//     REQUIRE(r.getWidth() == 3);
//     REQUIRE(r.getHeight() == 4);
// }

// // #####################################
// // I. TEST CASE 12 -  constructor, getters
// // #####################################
// TEST_CASE("Rectangle fully parameterized constructor") {
//     Rectangle r(1,2,3,4);
//     REQUIRE(r.getX() == 1);
//     REQUIRE(r.getY() == 2);
//     REQUIRE(r.getWidth() == 3);
//     REQUIRE(r.getHeight() == 4);
// }

// // #####################################
// // I. TEST CASE 13 -  constructor, setters, getters
// // #####################################
// TEST_CASE("Rectangle changes") {
//     Rectangle r();
//     Rectangle.setX(1);
//     Rectangle.setY(2);
//     Rectangle.setWidth(3);
//     Rectangle.setHeight(4);
//     REQUIRE(r.getX() == 1);
//     REQUIRE(r.getY() == 2);
//     REQUIRE(r.getWidth() == 3);
//     REQUIRE(r.getHeight() == 4);
// }

// // #####################################
// // I. TEST CASE 14 -  constructor, copy, getters
// // #####################################
// TEST_CASE("Rectangle copy") {
//     Rectangle r(1,2,3,4);
//     Rectangle r2 = *r.copy();
//     REQUIRE(&r != &r2);
//     REQUIRE(r2.getX() == 1);
//     REQUIRE(r2.getY() == 2);
//     REQUIRE(r2.getWidth() == 3);
//     REQUIRE(r2.getHeight() == 4);
// }

// #####################################
// I. TEST CASE 15 -  constructor, getters -- make default RightTriangle
// #####################################
TEST_CASE("RightTriangle constructor") {
    RightTriangle rt;
    REQUIRE(rt.getX() == 0);
    REQUIRE(rt.getY() == 0);
    REQUIRE(rt.getBase() == 0);
    REQUIRE(rt.getHeight() == 0);
}

// #####################################
// I. TEST CASE 16 -  constructor, getters 
// #####################################
TEST_CASE("RightTriangle parameterized constructor") {
    RightTriangle rt(2, 4);
    REQUIRE(rt.getX() == 0);
    REQUIRE(rt.getY() == 0);
    REQUIRE(rt.getBase() == 2);
    REQUIRE(rt.getHeight() == 4);
}

// #####################################
// I. TEST CASE 17 -  constructor, getters
// #####################################
TEST_CASE("RightTriangle fully parameterized constructor") {
    RightTriangle rt(1,2,3,4);
    REQUIRE(rt.getX() == 1);
    REQUIRE(rt.getY() == 2);
    REQUIRE(rt.getBase() == 3);
    REQUIRE(rt.getHeight() == 4);
}

// #####################################
// I. TEST CASE 18 -  constructor, setters getters
// #####################################
TEST_CASE("RightTriangle changes") {
    RightTriangle rt;
    rt.setX(1);
    rt.setY(2);
    rt.setBase(3);
    rt.setHeight(4);
    REQUIRE(rt.getX() == 1);
    REQUIRE(rt.getY() == 2);
    REQUIRE(rt.getBase() == 3);
    REQUIRE(rt.getHeight() == 4);
}

// #####################################
// I. TEST CASE 19 -  constructor, copy, getters
// #####################################
TEST_CASE("RightTriangle copy") {
    RightTriangle rt(1,2,3,4);
    RightTriangle rt2 = *rt.copy();
    REQUIRE(&rt != &rt2);
    REQUIRE(rt2.getX() == 1);
    REQUIRE(rt2.getY() == 2);
    REQUIRE(rt2.getBase() == 3);
    REQUIRE(rt2.getHeight() == 4);
}

// #####################################
// I. TEST CASE 20 -  constructor, push_back, getters
// #####################################
TEST_CASE("canvaslist push back") {
    CanvasList myCanvas;
    Shape *s = new Shape(1, 3);
    myCanvas.push_back(s);

    REQUIRE(myCanvas.size() == 1);
    REQUIRE(myCanvas.front()->value->getX() == s->getX());
    REQUIRE(myCanvas.front()->value->getY() == s->getY());
}

// #####################################
// I. TEST CASE 21 -  constructor, push_back
// #####################################
TEST_CASE("canvaslist push back multiple") {
    CanvasList myCanvas;
    Shape *s = new Shape(3,4); 

    for(int i = 0; i < 10; i++) {
        REQUIRE(myCanvas.size() == i);
        myCanvas.push_back(s);
    }
}

// #####################################
// I. TEST CASE 22 -  constructor, push_front, getters
// #####################################
TEST_CASE("canvaslist push front") {
    CanvasList myCanvas;
    Shape *s = new Shape(1, 3);
    myCanvas.push_front(s);

    REQUIRE(myCanvas.size() == 1);
    REQUIRE(myCanvas.front()->value->getX() == s->getX());
    REQUIRE(myCanvas.front()->value->getY() == s->getY());
}

// #####################################
// I. TEST CASE 23 -  constructor, push_front
// #####################################
TEST_CASE("canvaslist push front multiple") {
    CanvasList myCanvas;
    Shape *s = new Shape(3,4); 

    for(int i = 0; i < 10; i++) {
        REQUIRE(myCanvas.size() == i);
        myCanvas.push_front(s);
    }
}

// #####################################
// I. TEST CASE 24 -  constructor, push_back, pop_back, getters
// #####################################
TEST_CASE("canvaslist pop back") {
    CanvasList myCanvas;
    Shape *s = new Shape(1, 3);
    myCanvas.push_back(s);
    Circle *c = new Circle(2, 4, 3);
	myCanvas.push_back(c);

    REQUIRE(myCanvas.pop_back() == c);

    REQUIRE(myCanvas.front()->value->getX() == 1);
    REQUIRE(myCanvas.front()->value->getY() == 3);
    REQUIRE(myCanvas.front()->next == nullptr);
    REQUIRE(myCanvas.size() == 1);

}

// #####################################
// I. TEST CASE 25 -  constructor, pop_back
// #####################################
TEST_CASE("canvaslist pop back empty") {
    CanvasList myCanvas;

    REQUIRE(myCanvas.pop_back() == nullptr);
}

// #####################################
// I. TEST CASE 26 -  constructor, push_back, pop_back
// #####################################
TEST_CASE("canvaslist pop back multiple") {
    CanvasList myCanvas;
    Shape *s = new Shape(1, 3);

    for(int i = 0; i < 10; i++) {
        REQUIRE(myCanvas.size() == i);
        myCanvas.push_back(s);
    }

    for(int i = 10; i > 1; --i) {
        REQUIRE(myCanvas.size() == i );
        REQUIRE(myCanvas.pop_back() == s);
    }
}

// #####################################
// I. TEST CASE 27 -  constructor, push_back, pop_front, getters
// #####################################
TEST_CASE("canvaslist pop front") {
    CanvasList myCanvas;
    Shape *s = new Shape(1, 3);
    myCanvas.push_back(s);
    Circle *c = new Circle(2, 4, 3);
	myCanvas.push_back(c);

    REQUIRE(myCanvas.pop_front() == s);

    REQUIRE(myCanvas.front()->value->getX() == 2);
    REQUIRE(myCanvas.front()->value->getY() == 4);
    REQUIRE(myCanvas.front()->next == nullptr);
    REQUIRE(myCanvas.size() == 1);

}

// #####################################
// I. TEST CASE 28 -  constructor, pop_front
// #####################################
TEST_CASE("canvaslist pop front empty") {
    CanvasList myCanvas;

    REQUIRE(myCanvas.pop_front() == nullptr);
}

// #####################################
// I. TEST CASE 29 -  constructor, push_front, pop_front
// #####################################
TEST_CASE("canvaslist pop front multiple") {
    CanvasList myCanvas;
    Shape *s = new Shape(1, 3);

    for(int i = 0; i < 10; i++) {
        REQUIRE(myCanvas.size() == i);
        myCanvas.push_front(s);
    }

    for(int i = 10; i > 0; --i) {
        REQUIRE(myCanvas.size() == i );
        REQUIRE(myCanvas.pop_front() == s);
    }
    REQUIRE(myCanvas.pop_front() == nullptr);
}


// #####################################
// I. TEST CASE 30 -  constructor, push_front, pop_front, isempty
// #####################################
TEST_CASE("Is Empty") {
    CanvasList myCanvas;
    Shape *s = new Shape(1, 3);

    REQUIRE(myCanvas.isempty() == true);
    myCanvas.push_front(s);
    REQUIRE(myCanvas.isempty() == false);
    REQUIRE(myCanvas.pop_front() == s);
    REQUIRE(myCanvas.isempty() == true);
}

// #####################################
// I. TEST CASE 31 -  constructor, removeAt
// #####################################
TEST_CASE("Remove at out of bounds") {
    CanvasList myCanvas;
    myCanvas.removeAt(-1);
    myCanvas.removeAt(99);
    REQUIRE(myCanvas.isempty() == true);
}

// #####################################
// I. TEST CASE 32 -  constructor, push_back, push_front, removeAt, shapeAt, find
// #####################################
TEST_CASE("remove at index") {
    CanvasList myCanvas;

    Shape *s = new Circle(5, 4, 2);
    myCanvas.push_back(s);
    s = new Shape(1, 3);
    myCanvas.push_front(s);
    myCanvas.push_back(s);

    myCanvas.removeAt(1);

    REQUIRE(myCanvas.shapeAt(1) == s);
    REQUIRE(myCanvas.find(5, 4) == -1);
}

// // #####################################
// // I. TEST CASE 33 -  constructor, push_back, copy, find, removeAt
// // #####################################
// TEST_CASE("canvaslist copy constructor") {
//     CanvasList myCanvas;

//     Shape *s = new Circle(5, 4, 2);
//     myCanvas.push_back(s);
//     s = new Shape(1, 3);
//     myCanvas.push_front(s);
//     myCanvas.push_back(s);
    
//     CanvasList newCanvas(myCanvas);

//     REQUIRE(newCanvas.size() == myCanvas.size());
//     REQUIRE(myCanvas.find(5,4) == newCanvas.find(5,4));
//     newCanvas.removeAt(1);
//     REQUIRE(myCanvas.find(5,4) != newCanvas.find(5,4));
// }

// // #####################################
// // I. TEST CASE 34 -  operator= , push_back, copy, find, removeAt
// // #####################################
// TEST_CASE("canvaslist = operator") {
//     CanvasList myCanvas;

//     Shape *s = new Circle(5, 4, 2);
//     myCanvas.push_back(s);
//     s = new Shape(1, 3);
//     myCanvas.push_front(s);
//     myCanvas.push_back(s);
    
//     CanvasList newCanvas;
//     newCanvas = myCanvas;

//     REQUIRE(newCanvas.size() == myCanvas.size());
//     REQUIRE(myCanvas.find(5,4) == newCanvas.find(5,4));
//     newCanvas.removeAt(1);
//     REQUIRE(myCanvas.find(5,4) != newCanvas.find(5,4));
// }


