#include "Point.hpp"

#include <iostream>
#include <cmath>

Point::Point(void) : x(Fixed(0)), y(Fixed(0)) {
  // std::cout << "Default constructor called" << std::endl;
}

Point::Point(float x, float y) : x(Fixed(x)), y(Fixed(y)) {
  // std::cout << "Int constructor called" << std::endl;
}

Point::Point(Fixed x, Fixed y) : x(x), y(y) {
  // std::cout << "Int constructor called" << std::endl;
}

Point::Point(const Point& other) {
  // std::cout << "Copy constructor called" << std::endl;
  *this = other;
}

Point::~Point(void) {
  // std::cout << "Destructor called" << std::endl;
}

Point& Point::operator=(const Point& other) {
  // std::cout << "Copy assignment operator called" << std::endl;
  if (this != &other) {
    Fixed thisX = this->getX();
    Fixed thisY = this->getY();
    thisX = other.getX();
    thisY = other.getY();
  }
  return *this;
}

Fixed& Point::getX(void) const {
  return const_cast<Fixed &>(x);
}

Fixed& Point::getY(void) const {
  return const_cast<Fixed &>(y);
}

Point Point::getDelta(const Point to) const {
  return Point(to.getX() - this->getX(), to.getY() - this->getY());
}

int Point::cross(const Point &p1, const Point &center, const Point &p2) {
  // Point center_to_1 = center.getDelta(p1);
  // Point center_to_2 = center.getDelta(p2);

  std::cout << p1.getX() << std::endl;
  std::cout << center.getX() << std::endl;
  std::cout << p1.getX() - center.getX() << std::endl;
  // std::cout << p1.getY() - center.getY() << std::endl;
  // std::cout << p2.getX() - center.getX() << std::endl;
  // std::cout << p2.getY() - center.getY() << std::endl;
  // std::cout << center_to_1 << std::endl;
  // std::cout << center_to_2 << std::endl;

  // Fixed dir = center_to_1.getX() * center_to_2.getY() - center_to_1.getY() * center_to_2.getX();
  // std::cout << dir << std::endl;
  // if (dir > 0)
  //   return (1);
  return (-1);
}

std::ostream& operator<<(std::ostream& lhs, const Point& rhs) {
  lhs << "x : ";
  lhs << rhs.getX();
  lhs << " ";
  lhs << "y : ";
  lhs << rhs.getY();
  return lhs;
}
