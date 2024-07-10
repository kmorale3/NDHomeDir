/***********************************************
 * File name: line.cpp
 * 
 * This file contains the class method definitions 
 * for the line class 
 *********************************************/

#include "line.h"

line::line() : origin(), destin() {}

line::line( point& org_in, point& dest_in) :
    origin(org_in), destin(dest_in) {

        std::cout << this <<" " << &origin << ", " << &destin << std::endl;
    }

std::ostream& operator<<(std::ostream& out, 
            const line& print_line){

                out <<print_line.origin<<", "<<print_line.destin;

            return out;
            }