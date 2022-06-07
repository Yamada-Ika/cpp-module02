#include <Fixed.hpp>

#include <iostream>

void normalTest(void) {
    Fixed a;
    Fixed const b(10);
    Fixed const c(42.42f);
    Fixed const d(b);
    a = Fixed(1234.4321f);
    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;
    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;
}

//                         Fixed point
//
// |0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0 |0|0|0|0|0|0|0|0|
//                  integer part (24 bit)           fract part (8 bit)
// 
// Max integer part : 2^23 - 1 = 8388607
// Min integer part : -2^23 = -8388608
// Max fract part   : 2^(-1) + 2^(-2) + 2^(-3) + 2^(-4) + 2^(-5) + 2^(-6) + 2^(-7) + 2^(-8) = 0.99609375
// smallest diff    : 2^(-8) = 0.00390625
// 
//
int main(void) {
    normalTest();
    std::cout << std::endl;

    // Fixed e(8388607); // 2^23 - 1
    // std::cout << "Max integer   : " << e << std::endl;
    // Fixed f(-8388608); // -2^23
    // std::cout << "Min integer   : " << f << std::endl;
    // Fixed g(0.99609375f); // Max fract part
    // std::cout << "Max fraction  : " << g << std::endl;
    // Fixed h(0.00390625f); // smallest diff
    // std::cout << "smallest diff : " << h << std::endl;

    return 0;
}
