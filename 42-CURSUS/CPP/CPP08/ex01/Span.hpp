/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 22:53:47 by marvin            #+#    #+#             */
/*   Updated: 2025/04/01 22:53:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <iterator>
#include <vector>

class Span {
	private:
		std::vector<int>		storage;
		unsigned int			N;
	public:
		Span(void);
		Span(unsigned int N);
		Span(const Span& other);
		~Span(void);

		Span&	operator=(const Span& other);
		int		size(void) const;
		int		capacity(void) const;
		void	addNumber(int n);
		int		shortestSpan(void) const;
		int		longestSpan(void) const;

		template <typename It>
		void	addNumber(It begin, It end)
		{
			while (begin != end)
			{
				this->addNumber(*begin);
				begin++;
			}
		}
};

std::ostream&	operator<<(std::ostream& out, const Span& instance);