/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhang2 <yzhang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 22:27:19 by yzhang2           #+#    #+#             */
/*   Updated: 2026/02/09 16:43:49 by yzhang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <iostream>

int main(int ac, char **av)
{
    if (ac < 2)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
        return (0);
    }
    int i = 1;
    while (i < ac)
    {
        int j = 0;
        while (av[i][j])
        {
            unsigned char c = static_cast<unsigned char>(av[i][j]);
            std::cout << static_cast<char>(std::toupper(c));
            j++;
        }
        i++;
    }
    std::cout << '\n';
    return (0);
}
