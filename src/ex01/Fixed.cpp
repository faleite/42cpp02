/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 18:41:08 by faaraujo          #+#    #+#             */
/*   Updated: 2024/06/15 22:00:53 by faaraujo         ###   ########.fr       */
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
 * retorna a parte inteira do valor armazenado em ponto fixo.
 * 
 * Desloca o valor do ponto fixo para a direita pelo número de 
 * bits da parte fracionária.
 * 
 * A conversão do valor de ponto fixo para um inteiro não modifica 
 * o valor armazenado e, portanto, pode ser feita de maneira const.
 */
Fixed::Fixed( const int intNum )
{
	std::cout << "Int constructor called" << std::endl;
	
	// if (intNum > (INT_MAX >> _numFractalBits) ||
	// 	intNum < (INT_MIN >> _numFractalBits))
	// 	std::cerr << "Number Outside Fixed point accuracy range" << std::endl;
	// else
	this->_fixedPointNumValue = (intNum << _numFractalBits);
}
/**
 * Multiplica o número em ponto flutuante pelo valor 1 deslocado para a esquerda
 * por 8 posições. 
 * Isso é equivalente a multiplicar floatNum por 2^_numFractalBits,
 * o que move a vírgula binária para a esquerda _numFractalBits vezes.
 *
 * roundf(...): Função que arredonda o resultado para o inteiro mais próximo.
 * O arredondamento é necessário porque a multiplicação por 2^_numFractalBits
 * pode resultar em um número não inteiro.
 */
Fixed::Fixed( const float floatNum )
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixedPointNumValue = roundf(floatNum * (1 << _numFractalBits));
}

/**
 * @brief A copy constructor.
 * @param copyObjSrc Como e passado este parametro com `&` o objeto
 * referenciado por &copyObjSrc não pode ser modificado dentro do método.
*/
Fixed::Fixed( const Fixed &copyObjSrc )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copyObjSrc;
}
/**
 * @brief A copy assignment operator overload.
 * (Sobrecarga do operador de atribuição de cópia).
*/
Fixed &Fixed::operator=( const Fixed &assignObjSrc )
{
	std::cout << "Copy assignment operator called" << std::endl;
	
	if (this != &assignObjSrc)
		this->_fixedPointNumValue = assignObjSrc.getRawBits();
	
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
	// std::cout << "getRawBits member function called" << std::endl;
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

float Fixed::toFloat( void ) const
{
	return ((float)_fixedPointNumValue / (1 << _numFractalBits));
}

int Fixed::toInt( void ) const
{
	return (_fixedPointNumValue >> _numFractalBits);
}

std::ostream &operator<<(std::ostream &out, const Fixed &numValue)
{
	out << numValue.toFloat();
	
	return (out);
}
