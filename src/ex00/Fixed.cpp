/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 18:41:08 by faaraujo          #+#    #+#             */
/*   Updated: 2024/06/15 17:03:52 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/**
 * @brief default constructor 
 * that initializes the fixed-point number value to 0 
 */
Fixed::Fixed() : _fixedPointNumValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

/**
 * @brief A copy constructor.
 * @param RefConstObjSrc Como e passado este parametro com `&` o objeto
 * referenciado por &RefConstObjSrc não pode ser modificado dentro do método.
*/
Fixed::Fixed( const Fixed &RefConstObjSrc )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = RefConstObjSrc;
}
/**
 * @brief A copy assignment operator overload.
 * (Sobrecarga do operador de atribuição de cópia).
*/
Fixed &Fixed::operator=( const Fixed &RefConstObjSrc )
{
	std::cout << "Copy assignment operator called" << std::endl;
	
	if (this != &RefConstObjSrc)
		this->_fixedPointNumValue = RefConstObjSrc.getRawBits();
	
	return (*this);
}

/**
 * @brief Destructor
*/
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}
/**
 * @brief Getter the raw value of the fixed-point value.
 * @return that returns the raw value of the fixed-point value.
*/
int	Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	
	return (this->_fixedPointNumValue);
}

/**
 * @brief Setter the raw value of the fixed-point number.
*/
void Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_fixedPointNumValue = raw;
}
