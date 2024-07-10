/***********************************************
 * File name: point.cpp
 * 
 * This file contains the class method definitions 
 * for the point class 
 *********************************************/

#include "point.h"


point::point() : x(0), y(0) {

    std::cout << this <<" "<< &x << " "<< &y<< std::endl;
}

point::point(COORDINATE x_in, COORDINATE y_in)
    : x(x_in), y(y_in) {

        std::cout << this <<" "<< &x << " "<< &y<< std::endl;
    }

/*COORDINATE point::getX() const {
    return x;
}

COORDINATE point::getY() const {
    return y;
}

void point::set_x(COORDINATE x_in){

    x=x_in;
}*/

void point::set_y(COORDINATE y_in){

    y=y_in;
}

std::ostream& operator<<(std::ostream& out, const point& print_point){

    out<< "("<< print_point.x <<", "<< print_point.y <<")";

    return out;
}

std::istream& operator<<(std::istream& in,point& print_point){
    in >> print_point.x;
    in >> print_point.y;

    return in;
}