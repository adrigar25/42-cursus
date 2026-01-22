#include <iostream>
#include "../includes/Point.hpp"

int main( void ) {

    Point p1(0.0f, 0.0f);
    Point p2(2.5f, 7.5f);
    Point p3(5.0f, 0.0f);
    
    std::cout << "==========================================" << std::endl;
    std::cout << "Triangle vertices: P1(0,0) P2(2.5,7.5) P3(5,0)" << std::endl;
    std::cout << "==========================================" << std::endl << std::endl;

    Point inside(2.5f, 3.75f);
    std::cout << "Test 1 - INSIDE THE TRIANGLE" << std::endl;
    std::cout << "Point (" << inside.getX() << ", " << inside.getY() << "): ";
    std::cout << (bsp(p1, p2, p3, inside) ? "Inside" : "Outside") << std::endl;

    Point outside(7.5f, 3.75f);
    std::cout << "Test 2 - OUTSIDE THE TRIANGLE" << std::endl;
    std::cout << "Point (" << outside.getX() << ", " << outside.getY() << "): ";
    std::cout << (bsp(p1, p2, p3, outside) ? "Inside" : "Outside") << std::endl;

    Point vertex(0.0f, 0.0f);
    std::cout << "Test 3 - ON A VERTEX (P1)" << std::endl;
    std::cout << "Point (" << vertex.getX() << ", " << vertex.getY() << "): ";
    std::cout << (bsp(p1, p2, p3, vertex) ? "Inside" : "Outside") << std::endl;

    Point edge(2.5f, 0.0f);
    std::cout << "Test 4 - ON AN EDGE (between P1 and P3)" << std::endl;
    std::cout << "Point (" << edge.getX() << ", " << edge.getY() << "): ";
    std::cout << (bsp(p1, p2, p3, edge) ? "Inside" : "Outside") << std::endl;

    return 0;
}
