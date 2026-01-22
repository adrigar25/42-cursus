
#include "../includes/Point.hpp"

#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

class Triangle
{
private:
    Point _p1;
    Point _p2;
    Point _p3;
public:
    Triangle();
    Triangle(Point p1, Point p2, Point p3);
    Triangle(Triangle& other);
    Triangle& operator=(const Triangle& other);
    ~Triangle();
    Point getPoint(const int p);
    Fixed getArea();
};


#endif