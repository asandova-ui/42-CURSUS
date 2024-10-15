/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alonso <alonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:34:22 by alonso            #+#    #+#             */
/*   Updated: 2024/10/15 13:09:55 by alonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int                 _fixedPointNumberValue;
        static const int    _nBits = 8;
    public:
        Fixed();
        Fixed(const Fixed &other);
        Fixed &operator=(const Fixed &other);
        ~Fixed();
        Fixed( const int value);
        Fixed( const float value);

        int     getRawBits( void ) const;
        void    setRawBits( int const raw );

        float toFloat( void ) const;
        int toInt( void ) const;

        static          Fixed& min( Fixed &a, Fixed &b );
        static const    Fixed& min( const Fixed &a, const Fixed &b );
        static          Fixed& max( Fixed &a, Fixed &b );
        static const    Fixed& max( const Fixed &a, const Fixed &b );


        //Operadores:
        bool    operator>( const Fixed &rhs ) const ;
        bool    operator<( const Fixed &rhs ) const ;
        bool    operator>=( const Fixed &rhs ) const ;
        bool    operator<=( const Fixed &rhs ) const ;
        bool    operator==( const Fixed &rhs ) const ;
        bool    operator!=( const Fixed &rhs ) const ;

        Fixed   operator+( const Fixed &rhs ) const ;
        Fixed   operator-( const Fixed &rhs ) const ;
        Fixed   operator*( const Fixed &rhs ) const ;
        Fixed   operator/( const Fixed &rhs ) const ;

        Fixed&  operator++( void ); // prefix
        Fixed   operator++( int ); // postfix
        Fixed&  operator--( void ); // prefix
        Fixed   operator--( int ); // postfix
};

std::ostream & operator<<( std::ostream & o, Fixed const & i );

#endif