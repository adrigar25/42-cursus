#include "../includes/Fixed.hpp"

#ifndef POINT_HPP
#define POINT_HPP

class Point
{
private:
    Fixed const   x;
    Fixed const   y;
public:
    Point();
    Point(const float xCoord, const float yCoord);
    Point(const Point& other);
    ~Point();
    Point& operator=(const Point& other);
    Fixed getX() const;
    Fixed getY() const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif