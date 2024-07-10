/***********************************************
 * File name: point.h
 * 
 * This file contains the class declarations 
 * for the point class 
 *********************************************/

#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <fstream>


typedef double COORDINATE;

class point{

    private:
        COORDINATE x;
        COORDINATE y;

    public:
        point();

        point(COORDINATE x_in, COORDINATE y_in);

        //COORDINATE getX() const;
        //COORDINATE getY() const;

        //void set_x(COORDINATE x_in);
        void set_y(COORDINATE y_in);

        friend std::ostream& operator<<(std::ostream& out,
            const point& print_point);

        friend std::istream& operator<<(std::istream& out,
             point& print_point);

};

#endif