/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 18:37:26 by faaraujo          #+#    #+#             */
/*   Updated: 2024/06/15 15:02:16 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

/**
 * @brief Representação de números de ponto fixo (Fixed point) do tipo <32, 8>,
 * significando:
 * 32 bits no total
 * 8 bits mais à direita são usados ​​para a fração
 * 
 * @param _fixedPointNumValue todos os bits representados como se fossem um inteiro
 * @param _numFractalBits número de bits mais à direita usados ​​para a parte da fração:
 * 23 bits para a parte inteira
 * 8 bits para a parte flutuante (const estática inicializada imediatamente)
 * 1 bit para sinal do número
 * 
 * siiiiiiiiiiiiiiiiiiiiiiiffffffff    meaning
 * 31                             0    bit
 * s = sign bit, f = fractal bits, i = integer bits
 *
 * A representação de números de ponto fixo é uma maneira de representar
 * números fracionários sem usar a vírgula flutuante (floating point). 
 * Em vez de armazenar uma fração e um expoente separadamente, 
 * como em ponto flutuante, um número de ponto fixo armazena um número
 * inteiro que representa o valor fracionário.
*/
class Fixed
{
	private:
		int	_fixedPointNumValue;
		static const int _numFractalBits = 8;
	public:
		Fixed( void ); /* Default Constructor */
		Fixed( const Fixed &RefConstObjSrc ); /* Copy Constructor */
		Fixed & operator=( const Fixed &RefConstObjSrc ); /* copy assignment operator overload. */
		~Fixed(); /* Destructor */
		
		int	getRawBits( void ) const; /* Getter */
		void setRawBits( int const raw ); /* Setter */
};

#endif /* FIXED_HPP */