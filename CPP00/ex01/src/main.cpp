/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhang2 <yzhang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 22:27:51 by yzhang2           #+#    #+#             */
/*   Updated: 2026/01/30 22:33:03 by yzhang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PhoneBook.hpp"

#include <iostream>
#include <string>

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

int main(void)
{
    PhoneBook   phoneBook;
    std::string command;

    while (true)
    {
        std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
        if (!readTrimmedLine(command))
            break;
        if (command == "EXIT")
            break;
        if (command == "ADD")
            phoneBook.addContact();
        else if (command == "SEARCH")
            phoneBook.searchAndPrint();
        else if (command.empty())
            continue;
        else
            std::cout << "Unknown command. Please type ADD, SEARCH, or EXIT.\n";
    }
    return 0;
}
