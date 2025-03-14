/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alonso <alonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 10:21:32 by alonso            #+#    #+#             */
/*   Updated: 2025/03/14 10:22:29 by alonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZATION_HPP
#define SERIALIZATION_HPP

# include <iostream>
# include <string>
# include <stdint.h>

struct Data
{
    int     a;
    int     b;
};

class Serialization {
    private:
        Serialization();
        Serialization(Serialization const&);
        ~Serialization();
        Serialization& operator=(Serialization const&);
    public:
        static uintptr_t    serialize(Data* ptr);
        static Data*        deserialize(uintptr_t raw);
};


#endif