/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 06:32:27 by jlacerda          #+#    #+#             */
/*   Updated: 2025/06/27 00:07:27 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>

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

void Contact::printContactDetails() const {
	if (isEmpty()) {
		std::cout << "Contact is empty." << std::endl;
		return;
	}
	std::cout << "First Name: " << getFirstName() << std::endl;
	std::cout << "Last Name: " << getLastName() << std::endl;
	std::cout << "Nickname: " << getNickname() << std::endl;
	std::cout << "Phone Number: " << getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << getDarkestSecret() << std::endl;
}
