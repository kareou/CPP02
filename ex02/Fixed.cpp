#include "Fixed.hpp"

Fixed::Fixed(void)
{
    Fixed::_value = 0;
}

Fixed::Fixed(const int value)
{
    Fixed::_value = value << Fixed::_bits;
}

Fixed::Fixed(const float value)
{
    Fixed::_value = roundf(value * (1 << Fixed::_bits));
}

Fixed::Fixed(const Fixed &src)
{
    *this = src;
}

Fixed::~Fixed(void)
{
}

Fixed				&Fixed::operator=(const Fixed &rhs)
{
    if (this != &rhs)
        this->_value = rhs.getRawBits();
    return (*this);
}

bool				Fixed::operator>(const Fixed &rhs) const
{
    return (this->_value > rhs.getRawBits());
}

bool				Fixed::operator<(const Fixed &rhs) const
{
    return (this->_value < rhs.getRawBits());
}

bool				Fixed::operator>=(const Fixed &rhs) const
{
    return (this->_value >= rhs.getRawBits());
}

bool				Fixed::operator<=(const Fixed &rhs) const
{
    return (this->_value <= rhs.getRawBits());
}

bool				Fixed::operator==(const Fixed &rhs) const
{
    return (this->_value == rhs.getRawBits());
}

bool				Fixed::operator!=(const Fixed &rhs) const
{
    return (this->_value != rhs.getRawBits());
}

Fixed				Fixed::operator+(const Fixed &rhs) const
{
    return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed				Fixed::operator-(const Fixed &rhs) const
{
    return (Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed				Fixed::operator*(const Fixed &rhs) const
{
    return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed				Fixed::operator/(const Fixed &rhs) const
{
    return (Fixed(this->toFloat() / rhs.toFloat()));
}

Fixed				&Fixed::operator++(void)
{
    this->_value++;
    return (*this);
}

Fixed				Fixed::operator++(int)
{
    Fixed tmp(*this);
    operator++();
    return (tmp);
}

Fixed				&Fixed::operator--(void)
{
    this->_value--;
    return (*this);
}

Fixed				Fixed::operator--(int)
{
    Fixed tmp(*this);
    operator--();
    return (tmp);
}

Fixed				&Fixed::min(Fixed &a, Fixed &b)
{
    if (a < b)
        return (a);
    return (b);
}

Fixed				&Fixed::max(Fixed &a, Fixed &b)
{
    if (a > b)
        return (a);
    return (b);
}

const Fixed			&Fixed::min(const Fixed &a, const Fixed &b)
{
    if (a < b)
        return (a);
    return (b);
}

const Fixed			&Fixed::max(const Fixed &a, const Fixed &b)
{
    if (a > b)
        return (a);
    return (b);
}

int					Fixed::getRawBits(void) const
{
    return (this->_value);
}

void				Fixed::setRawBits(int const raw)
{
    this->_value = raw;
}

float				Fixed::toFloat(void) const
{
    return ((float)this->_value / (float)(1 << Fixed::_bits));
}

int					Fixed::toInt(void) const
{
    return (this->_value >> Fixed::_bits);
}

std::ostream		&operator<<(std::ostream &o, const Fixed &rhs)
{
    o << rhs.toFloat();
    return (o);
}
