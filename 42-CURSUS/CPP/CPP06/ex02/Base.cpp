/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alonso <alonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 10:34:35 by alonso            #+#    #+#             */
/*   Updated: 2025/03/14 10:37:22 by alonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base*   generate(void)
{
    switch (rand() % 3)
    {
        case 0:
            return (new A);
        case 1:
            return (new B);
        case 2:
            return (new C);
    }
    return (0);
}

void    identify(Base* p)
{
    if (dynamic_cast<A*>(p))
    {
        std::cout << "A" << std::endl;
    }
    else if (dynamic_cast<B*>(p))
    {
        std::cout << "B" << std::endl;
    }
    else if (dynamic_cast<C*>(p))
    {
        std::cout << "C" << std::endl;
    }
}

void    identify(Base& p)
{
    try
    {
        A&  a = dynamic_cast<A&>(p);

        (void)a;
        std::cout << "A" << std::endl;
    }
    catch (std::exception& e)
    {
        try
        {
            B&  b = dynamic_cast<B&>(p);

            (void)b;
            std::cout << "B" << std::endl;
        }
        catch (std::exception& e)
        {
            try
            {
                C&  c = dynamic_cast<C&>(p);

                (void)c;
                std::cout << "C" << std::endl;
            }
            catch (std::exception& e)
            {
                std::cout << "Error" << std::endl;
            }
        }
    }
}