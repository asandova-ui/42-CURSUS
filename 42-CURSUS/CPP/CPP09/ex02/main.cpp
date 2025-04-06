/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alonso <alonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 18:37:14 by alonso            #+#    #+#             */
/*   Updated: 2025/04/06 18:37:34 by alonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char** argv) {

    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " <positive integer sequence>" << std::endl;
        return EXIT_FAILURE;
    }

    try {
        PmergeMe<std::vector<int> > v(argv + 1);

        std::cout << "Before:\t";
        v.print_data();

        v.sort();

        PmergeMe<std::deque<int> > dq(argv + 1);
        dq.sort();

        std::cout << "After:\t";
        dq.print_data();

        v.benchmark();
        dq.benchmark();
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    return EXIT_SUCCESS;
}