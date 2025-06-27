/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 06:32:27 by jlacerda          #+#    #+#             */
/*   Updated: 2025/06/26 22:36:40 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

/**
 * @file Contact.hpp
 * @brief Header file for the Contact class,
 * which represents a contact in a phone book.
 *
 * This class provides methods to set and get contact details such as first name,
 * last name, nickname, phone number, and darkest secret. It also includes methods
 * to check if the contact is empty and to print contact details.
 */
class Contact
{
	private:
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string phoneNumber;
		std::string darkestSecret;

	public:
		Contact();
		~Contact();
		void setFirstName(const std::string &firstName);
		void setLastName(const std::string &lastName);
		void setNickname(const std::string &nickname);
		void setPhoneNumber(const std::string &phoneNumber);
		void setDarkestSecret(const std::string &darkestSecret);
		std::string getFirstName() const;
		std::string getLastName() const;
		std::string getNickname() const;
		std::string getPhoneNumber() const;
		std::string getDarkestSecret() const;
		/**
		 * @brief Checks if the contact is empty.
		 * @return true if the contact is empty, false otherwise.
		 */
		bool isEmpty() const;
		/**
		 * @brief Prints the contact information.
		 */
		void printContactDetails() const;
};

#endif