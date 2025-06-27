/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 06:32:27 by jlacerda          #+#    #+#             */
/*   Updated: 2025/06/26 23:47:15 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

#define MAX_CONTACTS 8

class PhoneBook
{
public:
	PhoneBook();
	~PhoneBook();
	void addContact(const Contact &contact);
	void displayContacts() const;

private:
	int contactCount;
	Contact contacts[MAX_CONTACTS];
	void printContact(const Contact &contact) const;
	void displayContact(const Contact &contact, int index) const;
	void displayLine(const std::string &prop) const;
};

#endif