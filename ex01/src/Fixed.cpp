#include "Fixed.hpp"

#include <iostream>

Fixed::Fixed(void) : rawbits_(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int integer) : rawbits_(integer << fractbitswidth_) {
  std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float floater) : rawbits_(floater * (1 << fractbitswidth_)) {
  std::cout << "Float constructor called" << std::endl;
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
    // this->rawbits_ = other.rawbits_;
    this->setRawBits(other.getRawBits());
  }
  return *this;
}

int Fixed::getRawBits(void) const {
  std::cout << "getRawBits member function called" << std::endl;
  return rawbits_ << fractbitswidth_;
}

void Fixed::setRawBits(int const raw) {
  std::cout << "setRawBits member function called" << std::endl;
  rawbits_ = raw >> fractbitswidth_;
}
