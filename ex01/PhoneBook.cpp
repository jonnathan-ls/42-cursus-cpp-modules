/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 06:32:27 by jlacerda          #+#    #+#             */
/*   Updated: 2025/07/04 00:18:14 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook() : contactCount(CONTACT_COUNT_INITIAL) {}

PhoneBook::~PhoneBook() {}

int PhoneBook::getContactAmount() const {
	return contactCount;
}

Contact PhoneBook::getContact(int index) const {
	return contacts[index];
}

void PhoneBook::addContact(const Contact &contact) {
	int index = contactCount % MAX_CONTACTS;
	contacts[index] = contact;
	contactCount++;
}

void PhoneBook::displayContacts() const {
	int sizeList = contactCount < MAX_CONTACTS 
		? contactCount : MAX_CONTACTS;

	if (contactCount == 0) return;
	std::cout << std::endl
		<< "|" << std::setw(WIDTH_VIEW_SIZE) << "Contact No"
		<< "|" << std::setw(WIDTH_VIEW_SIZE) << "First Name"
		<< "|" << std::setw(WIDTH_VIEW_SIZE) << "Last Name"
		<< "|" << std::setw(WIDTH_VIEW_SIZE) << "Nickname" 
		<< "|" << std::endl;
	for (int i = 0; i < sizeList; i++) {
		displayContact(contacts[i], i);
	}
}

void PhoneBook::displayContact(const Contact &contact, int index) const {
	std::cout
		<< "|" << std::setw(WIDTH_VIEW_SIZE) << index + 1
		<< "|" << std::setw(WIDTH_VIEW_SIZE) << format(contact.getFirstName())
		<< "|" << std::setw(WIDTH_VIEW_SIZE) << format(contact.getLastName())
		<< "|" << std::setw(WIDTH_VIEW_SIZE) << format(contact.getNickname())
		<< "|" << std::endl;
}

std::string PhoneBook::format(const std::string &prop) const {
	std::string formatted = prop;
	if (prop.length() > WIDTH_VIEW_SIZE) {
		formatted = prop.substr(0, WIDTH_VIEW_SIZE - 1) + '.';
	}
	return formatted;
}
