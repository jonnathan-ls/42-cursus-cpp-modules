/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 06:32:27 by jlacerda          #+#    #+#             */
/*   Updated: 2025/07/04 00:19:10 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

#define MAX_CONTACTS 8
#define WIDTH_VIEW_SIZE 10
#define CONTACT_COUNT_INITIAL 0

class PhoneBook {
	private:
		int contactCount;
		Contact contacts[MAX_CONTACTS];
		/**
		 * @brief Displays a single contact in the phone book.
		 * This method prints the details of a contact
		 * at a specific index in a formatted manner.
		 * @param contact The contact to be displayed.
		 * @param index The index of the contact in the phone book.
		 * @details The contact details are displayed in a table format,
		 * with each field aligned in columns. The index is displayed
		 * starting from 1, followed by the first name, last name,
		 * and nickname of the contact. The method uses a fixed width
		 * for each column to ensure consistent formatting.
		 * If the contact is empty, it will not display any information.
		 */
		void displayContact(const Contact &contact, int index) const;
		/**
		 * @brief Formats a string for display in the phone book.
		 * This method ensures that the string is truncated to fit
		 * within a specified width for display purposes.
		 * If the string exceeds the width, it will be truncated
		 * and an ellipsis will be added at the end.
		 * @param prop The string to be formatted.
		 * @return A formatted string that fits within the display width.
		 * @details The formatted string will have a maximum length
		 * defined by WIDTH_VIEW_SIZE. If the input string is longer,
		 * it will be truncated to WIDTH_VIEW_SIZE - 1 characters,
		 * and an ellipsis ('.') will be appended to indicate truncation.
		 */
		std::string format(const std::string &prop) const;

	public:
		PhoneBook();
		~PhoneBook();
		int getContactAmount() const;
		/**
		 * @brief Retrieves a contact by index.
		 * This method returns the contact at the specified index.
		 * @param index The index of the contact to retrieve.
		 * @return The contact at the specified index.
		 */
		Contact getContact(int index) const;
		/**
		 * @brief Displays the contacts in the phone book.
		 * This method prints a formatted list of contacts,
		 * including their index, first name, last name, and nickname.
		 * If there are no contacts, it does nothing.
		 * @details The contacts are displayed in a table format,
		 * with each contact's details aligned in columns.
		 * The method uses a fixed width for each column to ensure
		 * consistent formatting. The first column shows the contact number,
		 * starting from 1, followed by the first name, last name, and nickname.
		 * If the phone book is empty, no output is produced.
		 */
		void displayContacts() const;
		/**
		 * @brief Adds a contact to the phone book.
		 * This method adds a new contact to the phone book.
		 * It replaces the contact at the current index (determined by 
		 * the contact count modulo the maximum number of contacts)
		 * with the new contact. If the phone book is full,
		 * the oldest contact will be overwritten.
		 * @param contact The contact to be added.
		 * @details The contact is added to the phone book
		 * at the index determined by the current contact count.
		 * If the contact count exceeds the maximum number of contacts,
		 * the oldest contact will be replaced. This ensures that
		 * the phone book always contains the most recent contacts,
		 * up to the maximum limit defined by MAX_CONTACTS.
		 */
		void addContact(const Contact &contact);
};

#endif