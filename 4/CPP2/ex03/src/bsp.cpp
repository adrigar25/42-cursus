/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 16:30:00 by agarcia           #+#    #+#             */
/*   Updated: 2026/01/22 17:13:14 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Point.hpp"
#include "../includes/Triangle.hpp"
#include <cmath>

/*
 * BSP - Binary Space Partitioning
 * ================================
 * 
 * Determines if a point is strictly inside a triangle using the area method.
 * 
 * Algorithm:
 * 1. Calculate the area of the main triangle (a, b, c)
 * 2. Calculate the areas of 3 sub-triangles formed by the point and each side
 * 3. If any sub-area is 0, the point is on a vertex or edge → return false
 * 4. If sum of sub-areas equals main area, point is inside → return true
 * 
 * Returns:
 *   - true: point is strictly INSIDE the triangle
 *   - false: point is OUTSIDE, on a vertex, or on an edge
 */

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Triangle t1(a, b, c);
    Triangle t2(a, b, point);
    Triangle t3(a, point, c);
    Triangle t4(point, b, c);

    Fixed area1 = t2.getArea();
    Fixed area2 = t3.getArea();
    Fixed area3 = t4.getArea();

    if (area1.toFloat() == 0.0f || area2.toFloat() == 0.0f || area3.toFloat() == 0.0f)
        return false;

    return(roundf(t1.getArea().toFloat()) == roundf((area1 + area2 + area3).toFloat()));
}
