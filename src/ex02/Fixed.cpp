/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 18:41:08 by faaraujo          #+#    #+#             */
/*   Updated: 2024/06/18 17:27:31 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/**
 * @brief default constructor 
 * that initializes the fixed-point number value to 0 
 */
Fixed::Fixed() : _fixedPointNumValue(0)
{
	// std::cout << "Default constructor called" << std::endl;
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
	// std::cout << "Int constructor called" << std::endl;
	
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
	// std::cout << "Float constructor called" << std::endl;
	this->_fixedPointNumValue = roundf(floatNum * (1 << _numFractalBits));
}

/**
 * @brief A copy constructor.
 * @param copyObjSrc Como e passado este parametro com `&` o objeto
 * referenciado por &copyObjSrc não pode ser modificado dentro do método.
*/
Fixed::Fixed( const Fixed &copyObjSrc )
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = copyObjSrc;
}
/**
 * @brief A copy assignment operator overload.
 * (Sobrecarga do operador de atribuição de cópia).
*/
Fixed &Fixed::operator=( const Fixed &assignObjSrc )
{
	// std::cout << "Copy assignment operator called" << std::endl;
	
	if (this != &assignObjSrc)
		this->_fixedPointNumValue = assignObjSrc.getRawBits();
	
	return (*this);
}

/**
 * @brief Destructor
*/
Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
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
	// std::cout << "setRawBits member function called" << std::endl;
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

/* COMPARISON OPERATOR */

bool Fixed::operator>( const Fixed &otherObjSrc ) const
{
	return (this->_fixedPointNumValue > otherObjSrc._fixedPointNumValue);
}

bool Fixed::operator<( const Fixed &otherObjSrc ) const
{
	return (this->_fixedPointNumValue < otherObjSrc._fixedPointNumValue);
}

bool Fixed::operator>=( const Fixed &otherObjSrc ) const
{
	return (this->_fixedPointNumValue >= otherObjSrc._fixedPointNumValue);
}

bool Fixed::operator<=( const Fixed &otherObjSrc ) const
{
	return (this->_fixedPointNumValue <= otherObjSrc._fixedPointNumValue);
}

bool Fixed::operator==( const Fixed &otherObjSrc ) const
{
	return (this->_fixedPointNumValue == otherObjSrc._fixedPointNumValue);
}

bool Fixed::operator!=( const Fixed &otherObjSrc ) const
{
	return (this->_fixedPointNumValue != otherObjSrc._fixedPointNumValue);
}

/* ARITHMETIC OPERATORS (MEMBERS OVERLOADS OPERATORS) */

Fixed Fixed::operator+( const Fixed &otherObjSrc ) const
{
	Fixed result = this->toFloat() + otherObjSrc.toFloat();
	return (result);
}

Fixed Fixed::operator-( const Fixed &otherObjSrc ) const
{
	Fixed result = this->toFloat() - otherObjSrc.toFloat();
	return (result);
}

Fixed Fixed::operator*( const Fixed &otherObjSrc ) const
{
	Fixed result = this->toFloat() * otherObjSrc.toFloat();
	return (result);
}

Fixed Fixed::operator/( const Fixed &otherObjSrc ) const
{
	Fixed result(0);
	if (!otherObjSrc._fixedPointNumValue)
		return (result);
	result = this->toFloat() / otherObjSrc.toFloat();
	return (result);
}

/* INCREMENT/DECREMENT OPERATORS (MEMBERS OVERLOADS OPERATORS) */

/**
* Um está incrementando _fixedPointNumValue em 1 / - 1;
* a mudança real do ponto fixo é determinada pelo número de bits usado para a mantissa
* incrementar resultará em uma mudança de 1 / ( 2 ^ N), onde N é o bits da mantissa. 
* No seu caso, o incremento = 1 ( 2 ^ 8), 1 / 256 = 0,00390625;
*/

/**
 * Sobrecarga de pré-incremento,
 * incrementa o original e retorna uma referência a ele 
 * esta referência não é const,
 * o próximo usuário pode alterar o número do ponto fixo
*/
Fixed &Fixed::operator++()
{
	++this->_fixedPointNumValue; // Incrementa o valor do objeto atual.
	return (*this); // Retorna o próprio objeto atual, com o valor incrementado.
}

/**
 * Sobrecarga de pós-incremento,
 * salve uma cópia do original, incremente o original, retorne a cópia.
 * 
 * internamente, ele está chamando a sobrecarga pré-incremento acima
 * na linha ++(*this)
 * 
 * int é uma `variável fictícia` (dummy variable), não se passa nada
 * da linguagem e da análise sintática do compilador, 
 * o que significa que SEMPRE colocamos "int" 
 * como parâmetro para sobrecarregar o operador pós-incremento.
 * (se você colocar "char", ele não compilará :)
 * "erro: postfix ‘Fixed Fixed::operator++(char)’ deve ter ‘int’ como argumento")
 * os sinalizadores -wall -werror -wextra não reclamam que int não é utilizado
 * ele já é levado em consideração no analisador sintático do compilador
 */
Fixed Fixed::operator++(int)
{
	Fixed result(*this); // Cria um objeto temporário com o valor atual.
	this->_fixedPointNumValue++; // Incrementa o valor do objeto atual.
	return (result); // Retorna o objeto temporário que tem o valor antigo.
}

Fixed &Fixed::operator--()
{
	--this->_fixedPointNumValue;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed result(*this);
	this->_fixedPointNumValue--; // Or operator--();
	return (result);
}

/* Public overloaded member functions */

Fixed &Fixed::min( Fixed &objA, Fixed &objB )
{
	return (objA < objB ? objA : objB);
}

const Fixed &Fixed::min( const Fixed &objA, const Fixed &objB )
{
	return (objA < objB ? objA : objB);
}

Fixed &Fixed::max( Fixed &objA, Fixed &objB )
{
	return (objA > objB ? objA : objB);
}

const Fixed &Fixed::max( const Fixed &objA, const Fixed &objB )
{
	return (objA > objB ? objA : objB);
}
