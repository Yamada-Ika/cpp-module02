#include <iostream>

#include <cassert>
#include <cmath>
#include "Point.hpp"

bool almostSame(float a, float b) {
    return fabs(a - b) < 1e-5;
}

bool bsp(Point const &a, Point const &b, Point const &c, Point const &point) {
    int dir_cpa = Point::cross(c, point, a);

    return (
        dir_cpa == Point::cross(a, point, b)
        && dir_cpa == Point::cross(b, point, c));
}

int main(void) {
    assert(bsp(Point(0, 0), Point(5, 0), Point(2.5, 5), Point(2.5, 2.5)) == true);
    assert(bsp(Point(0, 0), Point(5, 0), Point(2.5, 5), Point(0, 0)) == false);
    assert(bsp(Point(0, 0), Point(5, 0), Point(2.5, 5), Point(0, 5)) == false);
    assert(bsp(Point(0, 0), Point(5, 0), Point(2.5, 5), Point(2.5, 5)) == false);
    assert(bsp(Point(0, 0), Point(5, 0), Point(2.5, 5), Point(1, 2)) == false);
    assert(bsp(Point(0, 0), Point(5, 0), Point(2.5, 5), Point(2, 0)) == false);
    assert(bsp(Point(0, 0), Point(5, 0), Point(2.5, 5), Point(3.5, 3)) == false);
    assert(bsp(Point(0, 0), Point(5, 0), Point(2.5, 5), Point(3.5, 2.9)) == true);

    return 0;
}
