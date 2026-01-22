#include "../includes/Point.hpp"

Point::Point() : x(0), y(0) {};

Point::Point(const float xCoord, const float yCoord) : x(xCoord), y(yCoord) {};

Point::Point(const Point& other) : x(other.getX()), y(other.getY()){};

Point& Point::operator=(const Point& other)
{
    if(this != &other)
        *this = other;
    return (*this);
};

Point::~Point(){};

Fixed Point::getX() const
{
    const Fixed temp(x);
    return (temp);
}

Fixed Point::getY() const
{
    const Fixed temp(y);
    return (temp);
}