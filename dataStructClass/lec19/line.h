/***********************************************
 * File name: line.h
 * 
 * This file contains the class declarations 
 * for the line class 
 *********************************************/

#ifndef LINE_H
#define LINE_H

#include "point.h"

class line{

    private:
        point origin;
        point destin;

    public:
        line();

        line( point& org_in, point& dest_in);

        friend std::ostream& operator<<(std::ostream& out, 
            const line& print_line);

};

#endif
