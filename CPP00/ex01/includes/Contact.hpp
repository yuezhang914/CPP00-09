/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhang2 <yzhang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 22:27:33 by yzhang2           #+#    #+#             */
/*   Updated: 2026/01/30 22:30:12 by yzhang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

// Contact: one entry in the phone book.
// (Class name Contact is required by the subject.)
class Contact
{
private:
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;
    bool        hasValue;

public:
    Contact(void);
    ~Contact(void);

    bool isEmpty(void) const;

    void setAll(
        const std::string &newFirstName,
        const std::string &newLastName,
        const std::string &newNickname,
        const std::string &newPhoneNumber,
        const std::string &newDarkestSecret);

    void printTableRow(int index) const;
    void printFull(void) const;
};

#endif
