/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhang2 <yzhang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 22:27:37 by yzhang2           #+#    #+#             */
/*   Updated: 2026/01/30 22:31:15 by yzhang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

// PhoneBook: stores up to 8 contacts.
// (Class name PhoneBook is required by the subject.)
class PhoneBook
{
private:
    Contact contacts[8];
    int     savedCount;
    int     nextWriteIndex;

public:
    PhoneBook(void);
    ~PhoneBook(void);

    void addContact(void);
    void searchAndPrint(void) const;

    int  getSavedCount(void) const;
    bool isIndexValid(int index) const;
};

#endif
