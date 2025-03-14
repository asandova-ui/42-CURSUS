/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alonso <alonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 10:35:23 by alonso            #+#    #+#             */
/*   Updated: 2025/03/14 10:35:35 by alonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

# include <iostream>
# include <ctime>
# include <cstdlib>

class   Base {
    public:
        virtual ~Base() {};
};

Base*   generate(void);
void    identify(Base* p);
void    identify(Base& p);

#endif