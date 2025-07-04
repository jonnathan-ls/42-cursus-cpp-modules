/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 06:32:27 by jlacerda          #+#    #+#             */
/*   Updated: 2025/07/04 00:08:44 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstdlib>
#include "utils.hpp"
#include "PhoneBook.hpp"

PhoneBook g_phoneBook;

enum Command { ADD, EXIT, SEARCH, INVALID }; 

static Command getCommand(const std::string& input) {
    if (input == "ADD") return ADD;
    if (input == "SEARCH") return SEARCH;
    if (input == "EXIT") return EXIT;
    return INVALID;
}

static void addContact() {
	Contact contact;
	contact.readFields();
	g_phoneBook.addContact(contact);
}

static void invalidCommand(const std::string& input) {
	std::cout << "Invalid command '" << input << "'. "
		<< "The valid commands are: "
		<< "ADD, SEARCH, or EXIT" << std::endl;
}

static void searchContacts() {
	std::string input;
	int contactNumber;
	int contactAmount = g_phoneBook.getContactAmount();

	if (contactAmount == 0) {
		std::cout << "No contacts available. "
			<< "Please add a contact first." << std::endl;
		return;
	}
	g_phoneBook.displayContacts();
	while (true) {
		std::cout << std::endl 
			<< "Enter a contact number to view details: ";
		std::getline(std::cin, input);
		if (!isNumeric(input)) {
			std::cout << "Invalid input. "
				<< "Please enter a valid contact number."
				<< std::endl;
			continue;
		}
		contactNumber = atoi(input.c_str());
		int sizeList = contactAmount < MAX_CONTACTS 
			? contactAmount : MAX_CONTACTS;
		if (contactNumber < 1 || contactNumber > sizeList) {
			std::cout << "Invalid contact number. "
				<< "Please enter a number between 1 and "
				<< sizeList << "." << std::endl;
			continue;
		}
		break;
	}
	Contact contact = g_phoneBook.getContact(contactNumber - 1);
	contact.printDetails();
}

static void printWelcomeMessage() {
	std::cout << std::endl
		<< "Welcome to the PhoneBook application!"
		<< std::endl << std::endl
		<< "You can add contacts, search for them, "
		<< "or exit the application." << std::endl;
}

static void execute_program(void) {
	std::string input;
	
	while (true) {
		std::cout << std::endl <<  "Please enter a command: ";
		std::getline(std::cin, input);
		Command command = getCommand(input);
		switch (command) {
			case ADD: addContact(); break;
			case SEARCH: searchContacts(); break;
			case EXIT: return;
			default: invalidCommand(input);
		}
	}
}

int main(void) {
	printWelcomeMessage();
	execute_program();
	return (0);
}