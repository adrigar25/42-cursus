#include <iostream>
#include <cmath>
#include "Fixed.hpp"

int main( void ) {

    Fixed x1 ( (float)0.0 );
    Fixed y1 ( (float)0.0 );
    Fixed x2 ( (float)2.5 );
    Fixed y2 ( (float)7.5 );
    Fixed x3 ( (float)5.0 );
    Fixed y3 ( (float)0.0 );
    Fixed x4 ( (float)2.5 );
    Fixed y4 ( (float)3.75 );

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

   
    x4 = Fixed((float)7.5);
    y4 = Fixed((float)3.75);
    
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

  

    x4 = Fixed((float)3.75);
    y4 = Fixed((float)3.75);
    
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

// Test 1: Punto DENTRO del triángulo P4(2.5, 3.75)
/*
    y
7.5 |       P2(2.5, 7.5)
7   |       *
6   |      /|\
5   |     / | \
4   |    /P4|  \
3.75|   / * |   \
3   |  /    |    \
2   | /     |     \
1   |/      |      \
0   *-------+-------*-----> x
    P1(0,0) 2.5      P3(5,0)
*/

    // Test 2: Punto FUERA del triángulo P4(7.5, 3.75)
/*
    y
7.5 |       P2(2.5, 7.5)
7   |       *
6   |      /|\
5   |     / | \
4   |    /  |  \
3.75|   /   |   \       * P4(7.5, 3.75)
3   |  /    |    \
2   | /     |     \
1   |/      |      \
0   *-------+-------*-----> x
    P1(0,0) 2.5      P3(5,0) 7.5
*/

    // Test 3: Punto en un VÉRTICE del triángulo P4(0, 0) = P1
/*
    y
7.5 |       P2(2.5, 7.5)
7   |       *
6   |      /|\
5   |     / | \
4   |    /  |  \
3   |   /   |   \
2   |  /    |    \
1   | /     |     \
0   *-------+-------*-----> x
    P1/P4   2.5      P3(5,0)
    (0,0)
*/

    // Test 4: Punto en el BORDE del triángulo P4(3.75, 3.75) - línea entre P2 y P3
/*
    y
7.5 |       P2(2.5, 7.5)
7   |       *
6   |      /|\
5   |     / | \
4   |    /  |  \
3.75|   /   |   *P4
3   |  /    |    \
2   | /     |     \
1   |/      |      \
0   *-------+-------*-----> x
    P1(0,0) 2.5    P3(5,0)
                3.75
*/