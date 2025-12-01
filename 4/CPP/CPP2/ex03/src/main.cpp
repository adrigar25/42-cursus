#include <iostream>
#include <cmath>
#include "Fixed.hpp"

int main( void ) {

    Fixed x1( (int)1 );
    Fixed y1( (int)1 );
    Fixed x2 ( (int)6 );
    Fixed y2 ( (int)1 );
    Fixed x3 ( (int)3 );
    Fixed y3 ( (int)6 );
    Fixed x4 ( (int)3 );
    Fixed y4 ( (int)2 );

    Fixed temp((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) );
    Fixed area = (temp < 0 ? temp * -1 : temp) / 2;
    temp = ((x1 * (y2 - y4) + x2 * (y4 - y1) + x4 * (y1 - y2)) );
    Fixed area1 = (temp < 0 ? temp * -1 : temp) / 2;
    temp = ((x4 * (y3 - y1) + x3 * (y1 - y4) + x1 * (y4 - y3)) );
    Fixed area2 = (temp < 0 ? temp * -1 : temp) / 2 ;
    temp = ((x2 * (y3 - y4) + x3 * (y4 - y2) + x4 * (y2 - y3)) );
    Fixed area3 = (temp < 0 ? temp * -1 : temp) / 2;

    std::cout << "Test 1 - Point (" << x4 << ", " << y4 << "): ";
    if(roundf(area.toFloat()) == roundf((area1 + area2 + area3).toFloat()))
        std::cout << "Inside" << std::endl;
    else
        std::cout << "Outside" << std::endl;

    // Test 2: Punto fuera del triángulo
    x4 = Fixed((int)10);
    y4 = Fixed((int)10);
    
    temp = ((x1 * (y2 - y4) + x2 * (y4 - y1) + x4 * (y1 - y2)) );
    area1 = (temp < 0 ? temp * -1 : temp) / 2;
    temp = ((x4 * (y3 - y1) + x3 * (y1 - y4) + x1 * (y4 - y3)) );
    area2 = (temp < 0 ? temp * -1 : temp) / 2;
    temp = ((x2 * (y3 - y4) + x3 * (y4 - y2) + x4 * (y2 - y3)) );
    area3 = (temp < 0 ? temp * -1 : temp) / 2;
    
    std::cout << "Test 2 - Point (" << x4 << ", " << y4 << "): ";
    if(roundf(area.toFloat()) == roundf((area1 + area2 + area3).toFloat()))
        std::cout << "Inside" << std::endl;
    else
        std::cout << "Outside" << std::endl;

    // Test 3: Punto en el vértice
    x4 = x1;
    y4 = y1;
    
    temp = ((x1 * (y2 - y4) + x2 * (y4 - y1) + x4 * (y1 - y2)) );
    area1 = (temp < 0 ? temp * -1 : temp) / 2;
    temp = ((x4 * (y3 - y1) + x3 * (y1 - y4) + x1 * (y4 - y3)) );
    area2 = (temp < 0 ? temp * -1 : temp) / 2;
    temp = ((x2 * (y3 - y4) + x3 * (y4 - y2) + x4 * (y2 - y3)) );
    area3 = (temp < 0 ? temp * -1 : temp) / 2;
    
    std::cout << "Test 3 - Point (" << x4 << ", " << y4 << "): ";
    if(roundf(area.toFloat()) == roundf((area1 + area2 + area3).toFloat()))
        std::cout << "Inside (on vertex)" << std::endl;
    else
        std::cout << "Outside" << std::endl;

    // Test 4: Punto en el borde
    x4 = Fixed((int)4);
    y4 = Fixed((int)3);
    
    temp = ((x1 * (y2 - y4) + x2 * (y4 - y1) + x4 * (y1 - y2)) );
    area1 = (temp < 0 ? temp * -1 : temp) / 2;
    temp = ((x4 * (y3 - y1) + x3 * (y1 - y4) + x1 * (y4 - y3)) );
    area2 = (temp < 0 ? temp * -1 : temp) / 2;
    temp = ((x2 * (y3 - y4) + x3 * (y4 - y2) + x4 * (y2 - y3)) );
    area3 = (temp < 0 ? temp * -1 : temp) / 2;
    
    std::cout << "Test 4 - Point (" << x4 << ", " << y4 << "): ";
    if(roundf(area.toFloat()) == roundf((area1 + area2 + area3).toFloat()))
        std::cout << "Inside (on edge)" << std::endl;
    else
        std::cout << "Outside" << std::endl;

    return 0;
}
/*
      /\
     /  \
    /    \
   /      \
  /        \
 /__________\
*/