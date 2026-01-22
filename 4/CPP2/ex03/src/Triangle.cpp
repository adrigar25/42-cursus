#include "../includes/Triangle.hpp"

Triangle::Triangle() : _p1(0, 0), _p2(0,0), _p3(0, 0) {};

Triangle::Triangle(Point p1, Point p2, Point p3) : _p1(p1), _p2(p2), _p3(p3) {};

Triangle::Triangle(Triangle& other) : _p1(other.getPoint(1)), _p2(other.getPoint(2)), _p3(other.getPoint(3)){};

Triangle& Triangle::operator=(const Triangle& other)
{
    if(this != &other)
        *this = other;
    return (*this);
}

Triangle::~Triangle(){};

Point Triangle::getPoint(const int p)
{
    Point points[3] = {_p1, _p2, _p3};
    if(p < 1 || p > 3)
        std::cout << "Punto inválido, solo existen los puntos 1, 2 y 3" << std::endl;
    return (points[p - 1]);
}

Fixed Triangle::getArea()
{
    Fixed temp =    (_p1.getX() * (_p2.getY() - _p3.getY()) 
                    + _p2.getX() * (_p3.getY() - _p1.getY()) 
                    + _p3.getX() * (_p1.getY() - _p2.getY()));
    return (temp < Fixed(0) ? temp * Fixed(-1) : temp) / Fixed(2);
}