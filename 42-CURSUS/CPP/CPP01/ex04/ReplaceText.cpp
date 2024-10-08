/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReplaceText.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alonso <alonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:56:14 by alonso            #+#    #+#             */
/*   Updated: 2024/10/08 14:13:37 by alonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ReplaceText.hpp"

// Constructor that initializes the filename, s1, and s2
ReplaceText::ReplaceText(std::string filename) : _inFile(filename){
    this->_outFile = this->_inFile + ".replace";
}

ReplaceText::~ReplaceText ( void ) {

}

void ReplaceText::replace( std::string toFind, std::string replace) {
    std::ifstream ifs(this->_inFile.c_str()); // Aquí usamos .c_str() para convertir el std::string a const char*
    if (ifs.is_open()) {
        std::string content;
        if (std::getline(ifs, content, '\0')) {
            std::ofstream ofs(this->_outFile.c_str()); // También aquí para el archivo de salida
            size_t pos = content.find(toFind);
            while ( pos != std::string::npos ) {
                content.erase(pos, toFind.length());
                content.insert(pos, replace);
                pos = content.find(toFind);
            }
            ofs << content;
            ofs.close();
        }
        else {
            std::cerr << "Empty file found." << std::endl;
        }
        ifs.close();
    } else {
        std::cerr << "Unable to open the file." << std::endl;
        exit(EXIT_FAILURE);
    }
}