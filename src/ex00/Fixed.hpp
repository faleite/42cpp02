/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 18:37:26 by faaraujo          #+#    #+#             */
/*   Updated: 2024/06/14 20:41:45 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int	_fixedPointNumValue;
		static const int _numFractalBits = 8;
	public:
		Fixed( void );
		Fixed( const Fixed &RefConstObjSrc );
		Fixed & operator=( const Fixed &RefConstObjSrc );
		~Fixed();
		
		int	getRawBits( void ) const;
		void setRawBits( int const raw );
};

#endif /* FIXED_HPP */