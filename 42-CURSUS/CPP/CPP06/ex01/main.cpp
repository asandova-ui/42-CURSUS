/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alonso <alonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 10:21:44 by alonso            #+#    #+#             */
/*   Updated: 2025/03/14 10:22:42 by alonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"

int main() {
    Data       data = {0, 0};
    Data*      data_ptr = &data;
    Data*      data_ptr2;

    data_ptr2 = Serialization::deserialize(Serialization::serialize(data_ptr));
    std::cout << data_ptr << std::endl;
    std::cout << data_ptr2 << std::endl;
    if (data_ptr == data_ptr2)
    {
        std::cout << "Equal pointers" << std::endl;
    }
    else
    {
        std::cout << "Different pointers" << std::endl;
    }
    return 0;
}