/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alonso <alonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 10:21:39 by alonso            #+#    #+#             */
/*   Updated: 2025/03/14 10:21:57 by alonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"

Serialization::Serialization()
{
}

Serialization::Serialization(Serialization const& src)
{
    *this = src;
}

Serialization::~Serialization()
{
}

Serialization& Serialization::operator=(Serialization const& src)
{
    (void)src;
    return *this;
}

uintptr_t   Serialization::serialize(Data* ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data*       Serialization::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data*>(raw);
}