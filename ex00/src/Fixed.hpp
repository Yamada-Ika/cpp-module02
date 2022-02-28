#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed {
 private:
    int integer_;
    static const int fract_ = 8;

 public:
    Fixed(void);
    Fixed(const Fixed& other);
    ~Fixed(void);
    Fixed& operator=(const Fixed& other);
    int getRawBits(void) const;
    void setRawBits(int const raw);
};

#endif
