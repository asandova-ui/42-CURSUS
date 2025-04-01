/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 22:53:43 by marvin            #+#    #+#             */
/*   Updated: 2025/04/01 22:53:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
    Span sp(5);
    int n;

    srand(time(NULL));
    std::cout << "Agregando números..." << std::endl;
    for (int i = 0; i < 5; i++)
    {
        n = rand() % 100;
        std::cout << "Número: " << n << std::endl;
        sp.addNumber(n);
    }

    std::cout << sp << std::endl;
    std::cout << "Intentando agregar otro número..." << std::endl;
    try
    {
        sp.addNumber(4);
    }
    catch (std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "Span grande (42000). Agregando..." << std::endl;
    Span sp1(42000);
    for (int i = 0; i < 42000; i++)
    {
        if (i % 2)
            n = rand() % 10000;
        else
            n = (rand() % 100000) * (-1);
        sp1.addNumber(n);
    }
    std::cout << sp1 << std::endl;

    std::cout << "Usando iteradores..." << std::endl;
    std::vector<int> vect;
    Span sp2(10);

    for (int i = 0; i < 10; i++)
        vect.push_back(rand() % 100);

    sp2.addNumber(vect.begin(), vect.end());
    std::cout << sp2 << std::endl;

    return 0;
}
