/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alonso <alonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 10:38:55 by alonso            #+#    #+#             */
/*   Updated: 2025/03/14 10:38:56 by alonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main()
{
    Base*   p;

    for (int i = 0; i < 10; i++)
    {
        std::cout << "Test " << i << std::endl;
        p = generate();
        identify(p);
        identify(*p);
        delete p;
    }
    return 0;
}