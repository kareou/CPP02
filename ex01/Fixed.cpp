#include "Fixed.hpp"

Fixed::Fixed(void)
{
    Fixed::_value = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
    Fixed::setRawBits(value << Fixed::_bits);
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value)
{
    Fixed::setRawBits(roundf(value * (1 << Fixed::_bits)));
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &rhs)
{
    std::cout << "Assignation operator called" << std::endl;
    if (this != &rhs)
        Fixed::_value = rhs.getRawBits();
    return (*this);
}

int		Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (Fixed::_value);
}

void	Fixed::setRawBits(int const raw)
{
    Fixed::_value = raw;
}

float	Fixed::toFloat(void) const
{
    return ((float)Fixed::_value / (float)(1 << Fixed::_bits));
}

int		Fixed::toInt(void) const
{
    return (Fixed::_value >> Fixed::_bits);
}

std::ostream &operator<<(std::ostream &o, const Fixed &rhs)
{
    o << rhs.toFloat();
    return (o);
}

