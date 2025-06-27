/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 06:32:27 by jlacerda          #+#    #+#             */
/*   Updated: 2025/06/27 00:07:29 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

# define CONTACT_COUNT_INITIAL 0
# define WIDTH_VIEW_SIZE 10

PhoneBook::PhoneBook() :
	contactCount(CONTACT_COUNT_INITIAL) {}

PhoneBook::~PhoneBook() {}

void PhoneBook::addContact(const Contact &contact) {
	contacts[contactCount] = contact;
	contactCount = (contactCount + 1) % MAX_CONTACTS;
}

void PhoneBook::displayContacts() const {
	if (contactCount == 0) {
		std::cout << "No contacts available." << std::endl;
		return;
	}

	std::cout << std::setw(WIDTH_VIEW_SIZE) << "Index" 
		<< "|" << std::setw(WIDTH_VIEW_SIZE) << "First Name"
		<< "|" << std::setw(WIDTH_VIEW_SIZE) << "Last Name"
		<< "|" << std::setw(WIDTH_VIEW_SIZE) << "Nickname" << std::endl;

	for (int i = 0; i < contactCount; i++) {
		displayContact(contacts[i], i);
	}
}

void PhoneBook::displayContact(const Contact &contact, int index) const {
	std::cout << std::left << std::setw(WIDTH_VIEW_SIZE) << index + 1;
	displayLine(contact.getFirstName());
	displayLine(contact.getLastName());
	displayLine(contact.getNickname());
}

void PhoneBook::displayLine(const std::string &prop) const {
	std::string formatted = prop;
	if (prop.length() > WIDTH_VIEW_SIZE) {
		formatted = prop.substr(0, WIDTH_VIEW_SIZE - 1) + '.';
	}
	std::cout << "|" << std::setw(WIDTH_VIEW_SIZE) << formatted;
}

