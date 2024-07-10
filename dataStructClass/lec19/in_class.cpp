/***********************************************
 * File name: in_class.cpp
 * 
 * This file contains the main driver function 
 * for the in-class coding opportunity
 *********************************************/
 #include "line.h"
 
 
 int main( void ){
	 
	 point point_1;
	 
	 point point_2(1.1,-1.7);

	 point_1.set_y(3.7);
	 
	 std::cout << point_1 << " "<< point_2 << std::endl;

	line line1;

	line line2(point_1, point_2);

	std::cout <<line1<< std::endl;

	std::cout <<line2<< std::endl;

	line* line3 = new line(point_1, point_2);

	std::cout <<"After: "<< &line3 << " " << line3 << std::endl;

	delete line3;

	 return 0;
 }