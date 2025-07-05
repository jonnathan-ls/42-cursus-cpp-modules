/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 06:32:27 by jlacerda          #+#    #+#             */
/*   Updated: 2025/07/05 18:41:02 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstdlib>
#include "utils.hpp"
#include "styles.hpp"
#include "PhoneBook.hpp"

PhoneBook g_phoneBook;

enum Command { ADD, EXIT, SEARCH, INVALID };

static Command getCommand(const std::string &input)
{
	if (input == "ADD")
		return ADD;
	if (input == "SEARCH")
		return SEARCH;
	if (input == "EXIT")
		return EXIT;
	return INVALID;
}

static void addContact()
{
	Contact contact;
	contact.readFields();
	g_phoneBook.addContact(contact);
	std::cout << GREEN << ICON_SUCCESS 
		<< "Contact added successfully!" << RESET << std::endl;
}

static void invalidCommand(const std::string &input)
{
	std::cout
		<< RED << std::endl << ICON_ERROR << "Invalid command '"
		<< YELLOW << input << RESET << "'" << RESET " ... "
		<< "The valid commands are: "
		<< CYAN << "ADD" << RESET
		<< ", " << CYAN << "SEARCH" << RESET
		<< ", or " << CYAN << "EXIT"
		<< RESET << std::endl;
}

static void searchContacts()
{
	std::string input;
	int contactNumber;
	int contactAmount = g_phoneBook.getContactAmount();

	if (contactAmount == 0)
	{
		std::cout << YELLOW << std::endl << ICON_WARNING
				  << "No contacts available. Please add a contact first" 
				  << RESET << std::endl;
		return;
	}

	g_phoneBook.displayContacts();
	while (true)
	{
		std::cout
			<< std::endl << BOLD << CYAN << ICON_INFO
			<< "Enter a contact number to view details: " << RESET;
		
		std::getline(std::cin, input);
		if(endOfFileDetected()) return ;

		if (!isNumeric(input))
		{
			std::cout
				<< RED << std::endl << ICON_ERROR << "Invalid input '"
				<< YELLOW << input << RED << "'. "
				<< RESET << "Please enter a valid contact number"
				<< RESET << std::endl;
			continue;
		}

		contactNumber = atoi(input.c_str());
		int sizeList = contactAmount < MAX_CONTACTS 
			? contactAmount : MAX_CONTACTS;

		if (contactNumber < 1 || contactNumber > sizeList)
		{
			std::cout
				<< RED << std::endl 
				<< ICON_ERROR << "Invalid contact number. "
				<< RESET << "Please enter a number between " << GREEN << "1"
				<< WHITE << " and " << GREEN << sizeList
				<< RESET << std::endl;
			continue;
		}
		break;
	}

	Contact contact = g_phoneBook.getContact(contactNumber - 1);
	contact.printDetails();
}

static void printWelcomeMessage()
{
	std::cout
		<< std::endl
		<< BOLD << CYAN << ICON_PHONE
		<< "PhoneBook Application " << ICON_PHONE << RESET << std::endl
		<< BOLD << std::endl
		<< WHITE << ICON_MENU << " You can "
		<< GREEN << ICON_ADD << "ADD contacts "
		<< BLUE << ICON_SEARCH << "SEARCH for them "
		<< RED << ICON_EXIT << "EXIT the application"
		<< RESET << std::endl;
}

static void execute_program(void)
{
	std::string input;

	while (true)
	{
		std::cout
			<< std::endl << BOLD << MAGENTA 
			<< "📋 Please enter a command: " << RESET;
		std::getline(std::cin, input);
		if(endOfFileDetected()) return ;
		
		Command command = getCommand(input);

		switch (command)
		{
		case ADD:
			addContact();
			break;
		case SEARCH:
			searchContacts();
			break;
		case EXIT:
			std::cout 
				<< std::endl << GREEN << ICON_EXIT
				<< "Goodbye! Thanks for using PhoneBook!"
				<< RESET << std::endl << std::endl;
			return;
		default:
			invalidCommand(input);
		}
	}
}

int main(void)
{
	printWelcomeMessage();
	execute_program();
	return (0);
}
