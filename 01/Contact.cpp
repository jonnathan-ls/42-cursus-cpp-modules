/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 06:32:27 by jlacerda          #+#    #+#             */
/*   Updated: 2025/07/04 00:10:04 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "utils.hpp"
#include <iostream>

#define EMPTY_STRING ""

Contact::Contact() {}

Contact::~Contact() {}

std::string Contact::getFirstName() const {
	return firstName;
}

std::string Contact::getLastName() const {
	return lastName;
}

std::string Contact::getNickname() const {
	return nickname;
}

std::string Contact::getPhoneNumber() const {
	return phoneNumber;
}

std::string Contact::getDarkestSecret() const {
	return darkestSecret;
}

void Contact::setFirstName(const std::string &firstName) {
	this->firstName = firstName;
}

void Contact::setLastName(const std::string &lastName) {
	this->lastName = lastName;
}

void Contact::setNickname(const std::string &nickname) {
	this->nickname = nickname;
}

void Contact::setPhoneNumber(const std::string &phoneNumber) {
	this->phoneNumber = phoneNumber;
}

void Contact::setDarkestSecret(const std::string &darkestSecret) {
	this->darkestSecret = darkestSecret;
}

bool Contact::isEmpty() const {
	return firstName.empty() && lastName.empty() && nickname.empty()
		&& phoneNumber.empty() && darkestSecret.empty();
}

void Contact::printDetails() const {
	if (isEmpty()) {
		std::cout << "Contact is empty." << std::endl;
		return;
	}
	std::cout << std::endl
		<< "First Name: " << getFirstName() << std::endl
		<< "Last Name: " << getLastName() << std::endl
		<< "Nickname: " << getNickname() << std::endl
		<< "Phone Number: " << getPhoneNumber() << std::endl
		<< "Darkest Secret: " << getDarkestSecret() << std::endl;
}

std::string Contact::readField(const std::string &fieldName) {
	std::string input = EMPTY_STRING;
	std::cout << "Enter " << fieldName << ": ";
	std::getline(std::cin, input);
	while (trim(input).empty()) {
		std::cout << fieldName << " cannot be empty. "
			<< std::endl << "Please try again: ";
		std::getline(std::cin, input);
		if (std::cin.eof()) continue;
	}
	return input;
}
void Contact::readFields() {
	std::string input;

	std::cout << std::endl;
	input = readField("first name");
	setFirstName(input);
	input = readField("last name");
	setLastName(input);
	input = readField("nickname");
	setNickname(input);
	input = readField("phone number");
	while (!isNumeric(input)) {
		std::cout << "Phone number must be numeric. "
			<< std::endl << "Please try again: ";
		std::getline(std::cin, input);
		if (std::cin.eof()) continue;
	}
	setPhoneNumber(input);
	input = readField("darkest secret");
	setDarkestSecret(input);
}
