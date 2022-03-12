#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed {
 private:
    int rawbits_;
    static const int fractbitswidth_ = 8;

 public:
    Fixed(void);
    Fixed(int integer);
    Fixed(float floater);
    Fixed(const Fixed& other);
    ~Fixed(void);
    Fixed& operator=(const Fixed& other);
    int getRawBits(void) const;
    void setRawBits(int const raw);
};

#endif
