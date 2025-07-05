/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 06:32:27 by jlacerda          #+#    #+#             */
/*   Updated: 2025/07/05 18:39:34 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "utils.hpp"
#include "styles.hpp"
#include <iostream>

#define EMPTY_STRING ""

Contact::Contact() {}

Contact::~Contact() {}

std::string Contact::getFirstName() const
{
	return firstName;
}

std::string Contact::getLastName() const
{
	return lastName;
}

std::string Contact::getNickname() const
{
	return nickname;
}

std::string Contact::getPhoneNumber() const
{
	return phoneNumber;
}

std::string Contact::getDarkestSecret() const
{
	return darkestSecret;
}

void Contact::setFirstName(const std::string &firstName)
{
	this->firstName = firstName;
}

void Contact::setLastName(const std::string &lastName)
{
	this->lastName = lastName;
}

void Contact::setNickname(const std::string &nickname)
{
	this->nickname = nickname;
}

void Contact::setPhoneNumber(const std::string &phoneNumber)
{
	this->phoneNumber = phoneNumber;
}

void Contact::setDarkestSecret(const std::string &darkestSecret)
{
	this->darkestSecret = darkestSecret;
}

bool Contact::isEmpty() const
{
	return firstName.empty() && lastName.empty() && nickname.empty()
		&& phoneNumber.empty() && darkestSecret.empty();
}

void Contact::printDetails() const
{
	if (isEmpty())
	{
		std::cout << YELLOW << std::endl << ICON_WARNING 
				  << "Contact is empty" << RESET << std::endl;
		return;
	}
	std::cout << std::endl
		<< BOLD << CYAN << ICON_INFO << "Contact Details" 
		<< RESET << std::endl << std::endl
		<< GREEN << "👤 First Name: " 
		<< WHITE << getFirstName() << RESET << std::endl
		<< GREEN << "👤 Last Name: " 
		<< WHITE << getLastName() << RESET << std::endl
		<< GREEN << "🏷️  Nickname: " 
		<< WHITE << getNickname() << RESET << std::endl
		<< GREEN << "📱 Phone Number: " 
		<< WHITE << getPhoneNumber() << RESET << std::endl
		<< GREEN << "🤐 Darkest Secret: " 
		<< WHITE << getDarkestSecret() << RESET << std::endl;
}

std::string Contact::readField(const std::string &fieldName)
{
	std::string input = EMPTY_STRING;
	std::cout << CYAN << "📝 Enter " << fieldName << ": " << RESET;
	while (true)
	{
		std::getline(std::cin, input);
		if (endOfFileDetected()) return EMPTY_STRING;
		input = trim(input);
		if (trim(input).empty()) {
			std::cout
				<< RED << ICON_ERROR 
				<< fieldName << " cannot be empty. " << RESET << std::endl
				<< YELLOW << "Please try again: " << RESET;
			continue;
		}
		break;
	}
	return input;
}

void Contact::readFields()
{
	std::string input;

	std::cout 
		<< std::endl << BOLD << BLUE 
		<< "📋 Please fill in the contact information:"
		<< std::endl << std::endl;

	input = readField("first name");
	setFirstName(input);

	input = readField("last name");
	setLastName(input);

	input = readField("nickname");
	setNickname(input);

	input = readField("phone number");
	while (!isNumeric(input))
	{
		std::cout
			<< RED << ICON_ERROR
			<< "Phone number must be numeric. " << RESET << std::endl
			<< YELLOW << "Please try again: " << RESET;
		std::getline(std::cin, input);
		if(endOfFileDetected()) return ;
	}
	setPhoneNumber(input);

	input = readField("darkest secret");
	setDarkestSecret(input);
}