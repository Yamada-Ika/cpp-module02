#include "Fixed.hpp"

#include <iostream>
#include <cmath>

Fixed::Fixed(void) : rawbits_(0) {
  // std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int integer) : rawbits_(integer << fractbitswidth_) {
  // std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float floater) : rawbits_((int)(roundf(floater * (1 << fractbitswidth_)))) {
  // std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
  // std::cout << "Copy constructor called" << std::endl;
  *this = other;
}

Fixed::~Fixed(void) {
  // std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other) {
  // std::cout << "Copy assignment operator called" << std::endl;
  if (this != &other) {
    this->rawbits_ = other.rawbits_;
  }
  return *this;
}

int Fixed::getRawBits(void) const {
  // std::cout << "getRawBits member function called" << std::endl;
  return rawbits_ << fractbitswidth_;
}

void Fixed::setRawBits(int const raw) {
  // std::cout << "setRawBits member function called" << std::endl;
  rawbits_ = raw >> fractbitswidth_;
}

int Fixed::toInt(void) const {
  return rawbits_ >> fractbitswidth_;
}

float Fixed::toFloat(void) const {
  return (float)rawbits_ / (float)(1 << fractbitswidth_);
}

std::ostream& operator<<(std::ostream& lhs, const Fixed& rhs) {
  lhs << rhs.toFloat();
  return lhs;
}

Fixed Fixed::operator+ (const Fixed& rhs) const {
  return Fixed(rawbits_ + rhs.getRawBits());
}

Fixed Fixed::operator- (const Fixed& rhs) const {
  return Fixed(rawbits_ - rhs.getRawBits());
}

Fixed Fixed::operator* (const Fixed& rhs) const {
  return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/ (const Fixed& rhs) const {
  return Fixed(this->toFloat() / rhs.toFloat());
}

bool Fixed::operator< (const Fixed& rhs) const {
  return rawbits_ < rhs.getRawBits();
}

bool Fixed::operator<= (const Fixed& rhs) const {
  return rawbits_ <= rhs.getRawBits();
}

bool Fixed::operator> (const Fixed& rhs) const {
  return rawbits_ > rhs.getRawBits();
}

bool Fixed::operator>= (const Fixed& rhs) const {
  return rawbits_ >= rhs.getRawBits();
}

bool Fixed::operator== (const Fixed& rhs) const {
  return rawbits_ == rhs.getRawBits();
}

bool Fixed::operator!= (const Fixed& rhs) const {
  return rawbits_ != rhs.getRawBits();
}

Fixed& Fixed::operator++() {
  rawbits_++;
  return *this;
}

Fixed Fixed::operator++(int) {
  Fixed prev = *this;

  rawbits_++;
  return prev;
}

Fixed& Fixed::operator--() {
  rawbits_--;
  return *this;
}

Fixed Fixed::operator--(int) {
  Fixed prev = *this;

  rawbits_--;
  return prev;
}

Fixed& Fixed::max(Fixed& lhs, Fixed& rhs) {
  if (lhs > rhs) {
    return lhs;
  }
  if (lhs < rhs) {
    return rhs;
  }
  return lhs;
}

const Fixed& Fixed::max(const Fixed& lhs, const Fixed& rhs) {
  if (lhs > rhs) {
    return lhs;
  }
  if (lhs < rhs) {
    return rhs;
  }
  return lhs;
}

Fixed& Fixed::min(Fixed& lhs, Fixed& rhs) {
  if (lhs < rhs) {
    return lhs;
  }
  if (lhs > rhs) {
    return rhs;
  }
  return lhs;
}

const Fixed& Fixed::min(const Fixed& lhs, const Fixed& rhs) {
  if (lhs < rhs) {
    return lhs;
  }
  if (lhs > rhs) {
    return rhs;
  }
  return lhs;
}
