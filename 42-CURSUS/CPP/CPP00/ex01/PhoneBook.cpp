/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alonso <alonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:42:12 by alonso            #+#    #+#             */
/*   Updated: 2024/10/07 21:04:31 by alonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _numberContacts(0)
{
}

PhoneBook::~PhoneBook()
{
}

void    PhoneBook::welcome(void) const {
    std::cout << std::endl;
    std::cout << "ESTO ES EL PHONEBOOK" << std::endl;
    std::cout << std::endl;
    std::cout << "--------------COMANDOS---------------" << std::endl;
    std::cout << "ADD\t--> Añadir contacto." << std::endl;
    std::cout << "SEARCH\t--> Buscar contacto." << std::endl;
    std::cout << "EXIT\t--> Finalizar Phonebook." << std::endl;
    std::cout << "----------------------------------" << std::endl;
    std::cout << std::endl;
}

void    PhoneBook::addContact(void) {
    static int  i;
    this->_contacts[i % 8].init();
    this->_contacts[i % 8].setIndex(i % 8);
    if (_numberContacts < 8)
        _numberContacts++;
    i++;
}

void    PhoneBook::printContacts(void) const {
    std::cout << "------------- PHONBOOK CONTACTS -------------" << std::endl;
    for (size_t i = 0; i < 8; i++) {
        this->_contacts[i].view(i);
    }
    std::cout << std::endl;
}

int     PhoneBook::_readInput() const {
    int     input = -1;
    bool    valid = false;
    do
    {
        std::cout << "Please enter the contact index: " << std::flush;
        std::cin >> input;
        if (std::cin.good() && (input >= 0 && input <= 8)) {
            //everything went well, we'll get out of the loop and return the value
            valid = true;
        } else {
            //something went wrong, we reset the buffer's state to good
            std::cin.clear();
            //and empty it
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout << "Invalid index; please re-enter." << std::endl;
        }
    } while (!valid);
    return (input);
}

void    PhoneBook::search(void) const {
    int i = this->_readInput();
    if (i < 0 || i >= _numberContacts)
        std::cout << "Ponme un buen numerin" << std::endl;
    this->_contacts[i].display(i);
}