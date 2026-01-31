/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhang2 <yzhang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 22:27:19 by yzhang2           #+#    #+#             */
/*   Updated: 2026/01/30 22:29:47 by yzhang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

// ex00: Megaphone
// - If there are arguments, print them all in UPPERCASE.
// - If there is no argument, print the fixed sentence.

int main(int argumentCount, char **argumentValues)
{
    int argIndex;

    if (argumentCount <= 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
        return 0;
    }

    argIndex = 1;
    while (argIndex < argumentCount)
    {
        int charIndex;

        charIndex = 0;
        while (argumentValues[argIndex][charIndex] != '\0')
        {
            unsigned char ch;

            ch = (unsigned char)argumentValues[argIndex][charIndex];
            std::cout << (char)std::toupper(ch);
            charIndex = charIndex + 1;
        }
        argIndex = argIndex + 1;
    }
    std::cout << '\n';
    return 0;
}
