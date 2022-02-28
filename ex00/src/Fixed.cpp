#include "Fixed.hpp"

#include <iostream>

Fixed::Fixed(void) : integer_(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
  std::cout << "Copy constructor called" << std::endl;
  *this = other;
}

Fixed::~Fixed(void) {
  std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other) {
  std::cout << "Assignation operator called" << std::endl;
  if (this != &other) {
    // this->integer_ = other.integer_;
    this->setRawBits(other.getRawBits());
  }
  return *this;
}

int Fixed::getRawBits(void) const {
  std::cout << "getRawBits member function called" << std::endl;
  return integer_ << fract_;
}

void Fixed::setRawBits(int const raw) {
  std::cout << "setRawBits member function called" << std::endl;
  integer_ = raw >> fract_;
}
