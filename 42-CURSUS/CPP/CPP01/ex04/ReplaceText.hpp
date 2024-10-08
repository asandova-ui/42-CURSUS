/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReplaceText.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alonso <alonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:55:40 by alonso            #+#    #+#             */
/*   Updated: 2024/10/08 14:06:05 by alonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACETEXT_HPP
#define REPLACETEXT_HPP

#include <fstream>
#include <iostream>
#include <cstdlib>
class ReplaceText
{
private:
    std::string _inFile;
    std::string _outFile;

public:
    ReplaceText( std::string filename);
    ~ReplaceText();

    void replace( std::string s1, std::string s2);
};

#endif
