/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhang2 <yzhang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 22:27:44 by yzhang2           #+#    #+#             */
/*   Updated: 2026/01/30 22:31:56 by yzhang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Contact.hpp"

#include <iostream>
#include <iomanip>

Contact::Contact(void)
{
    this->firstName = "";
    this->lastName = "";
    this->nickname = "";
    this->phoneNumber = "";
    this->darkestSecret = "";
    this->hasValue = false;
}

Contact::~Contact(void)
{
    return;
}

bool Contact::isEmpty(void) const
{
    return (this->hasValue == false);
}

void Contact::setAll(
    const std::string &newFirstName,
    const std::string &newLastName,
    const std::string &newNickname,
    const std::string &newPhoneNumber,
    const std::string &newDarkestSecret)
{
    this->firstName = newFirstName;
    this->lastName = newLastName;
    this->nickname = newNickname;
    this->phoneNumber = newPhoneNumber;
    this->darkestSecret = newDarkestSecret;
    this->hasValue = true;
}

static void printColumn10(const std::string &text)
{
    if (text.size() > 10)
    {
        std::cout << text.substr(0, 9) << '.';
        return;
    }
    std::cout << std::setw(10) << text;
}

void Contact::printTableRow(int index) const
{
    std::cout << "|" << std::setw(10) << index << "|";
    printColumn10(this->firstName);
    std::cout << "|";
    printColumn10(this->lastName);
    std::cout << "|";
    printColumn10(this->nickname);
    std::cout << "|\n";
}

void Contact::printFull(void) const
{
    std::cout << "First name: " << this->firstName << "\n";
    std::cout << "Last name: " << this->lastName << "\n";
    std::cout << "Nickname: " << this->nickname << "\n";
    std::cout << "Phone number: " << this->phoneNumber << "\n";
    std::cout << "Darkest secret: " << this->darkestSecret << "\n";
}
