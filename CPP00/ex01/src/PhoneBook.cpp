/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhang2 <yzhang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 22:27:56 by yzhang2           #+#    #+#             */
/*   Updated: 2026/01/30 22:32:24 by yzhang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PhoneBook.hpp"

#include <iostream>
#include <string>
#include <cctype>

PhoneBook::PhoneBook(void)
{
    this->savedCount = 0;
    this->nextWriteIndex = 0;
}

PhoneBook::~PhoneBook(void)
{
    return;
}

int PhoneBook::getSavedCount(void) const
{
    return (this->savedCount);
}

bool PhoneBook::isIndexValid(int index) const
{
    if (index < 0)
        return false;
    if (index >= this->savedCount)
        return false;
    return true;
}

static std::string trimSpaces(const std::string &text)
{
    size_t start;
    size_t end;

    start = text.find_first_not_of(" \t\v\f\r\n");
    if (start == std::string::npos)
        return "";
    end = text.find_last_not_of(" \t\v\f\r\n");
    return text.substr(start, end - start + 1);
}

static bool readTrimmedLine(std::string &outLine)
{
    std::string rawLine;

    if (!std::getline(std::cin, rawLine))
        return false;
    outLine = trimSpaces(rawLine);
    return true;
}

static std::string askNonEmptyField(const std::string &prompt, bool &readOk)
{
    std::string value;

    while (readOk)
    {
        std::cout << prompt;
        if (!readTrimmedLine(value))
        {
            readOk = false;
            break;
        }
        if (!value.empty())
            return value;
        std::cout << "Empty field is not allowed. Please try again.\n";
    }
    return "";
}

void PhoneBook::addContact(void)
{
    bool        readOk;
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;
    Contact     newContact;

    readOk = true;
    firstName = askNonEmptyField("First name: ", readOk);
    lastName = askNonEmptyField("Last name: ", readOk);
    nickname = askNonEmptyField("Nickname: ", readOk);
    phoneNumber = askNonEmptyField("Phone number: ", readOk);
    darkestSecret = askNonEmptyField("Darkest secret: ", readOk);
    if (!readOk)
        return;

    newContact.setAll(firstName, lastName, nickname, phoneNumber, darkestSecret);
    this->contacts[this->nextWriteIndex] = newContact;

    if (this->savedCount < 8)
        this->savedCount = this->savedCount + 1;

    this->nextWriteIndex = (this->nextWriteIndex + 1) % 8;
}

static bool parseSingleDigit(const std::string &text, int &numberOut)
{
    if (text.size() != 1)
        return false;
    if (text[0] < '0' || text[0] > '9')
        return false;
    numberOut = (int)(text[0] - '0');
    return true;
}

void PhoneBook::searchAndPrint(void) const
{
    int         i;
    std::string inputLine;
    int         chosenIndex;

    if (this->savedCount == 0)
    {
        std::cout << "Your phone book is empty.\n";
        return;
    }

    std::cout << "|-------------------------------------------|\n";
    std::cout << "|     Index|First name| Last name|  Nickname|\n";
    std::cout << "|-------------------------------------------|\n";

    i = 0;
    while (i < this->savedCount)
    {
        this->contacts[i].printTableRow(i);
        std::cout << "|-------------------------------------------|\n";
        i = i + 1;
    }

    while (true)
    {
        std::cout << "Choose an index (0 to " << (this->savedCount - 1) << "): ";
        if (!readTrimmedLine(inputLine))
            return;
        if (!parseSingleDigit(inputLine, chosenIndex) || !this->isIndexValid(chosenIndex))
        {
            std::cout << "Invalid index. Please try again.\n";
            continue;
        }
        this->contacts[chosenIndex].printFull();
        return;
    }
}
