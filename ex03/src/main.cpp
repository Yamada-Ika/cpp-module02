#include <Point.hpp>

#include <iostream>

bool bsp(Point const &a, Point const &b, Point const &c, Point const &point) {
  int dir_cpa = Point::cross(c, point, a);

  if (
    dir_cpa == Point::cross(a, point, b)
    && dir_cpa == Point::cross(b, point, c)
  )
    return true;
  return false;
}

void  test(float p1, float p2, float a1, float a2, float b1, float b2, float c1, float c2) {
  Point a(a1, a2);
  Point b(b1, b2);
  Point c(c1, c2);
  Point point(p1, p2);

  std::cout << a << std::endl;
  std::cout << b << std::endl;
  std::cout << c << std::endl;
  std::cout << point << std::endl;
  if (bsp(a, b, c, point))
    std::cout << "point is in abc" << std::endl;
  else
    std::cout << "point is not in abc" << std::endl;
}

int main( void ) {

  test(2.5, 2.5, 0, 0, 5, 0, 5, 5);
  test(10, 10, 0, 0, 10, 0, 5, 10);
  return 0;
}
