/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 06:32:27 by jlacerda          #+#    #+#             */
/*   Updated: 2025/07/05 18:47:14 by jlacerda         ###   ########.fr       */
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

/**
 * @brief Gets the command based on user input.
 * This function checks the input string and returns the corresponding
 * Command enum value. If the input does not match any known command,
 * it returns INVALID.
 * @param input The command input by the user.
 * @return The corresponding Command enum value.
 */
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

/**
 * @brief Prints a welcome message for the PhoneBook application.
 * This function displays a welcome message with the application name
 * and a brief description of the available commands.
 * It uses ANSI escape codes for styling the output.
 */
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

/**
 * @brief Prints an error message for an invalid command.
 * This function displays a message indicating that the command
 * entered by the user is invalid.
 * It also provides a list of valid commands that the user can use.
 * @param input The invalid command input by the user.
 */
static void printInvalidCommandMessage(const std::string &input)
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

/**
 * @brief Adds a new contact to the phone book.
 * This function prompts the user to enter contact details,
 * reads the input, and adds the contact to the phone book.
 * It displays a success message upon successful addition.
 */
static void addContact()
{
	Contact contact;
	contact.readFields();
	g_phoneBook.addContact(contact);
	std::cout << GREEN << ICON_SUCCESS 
		<< "Contact added successfully!" << RESET << std::endl;
}

/**
 * @brief Searches for contacts in the phone book.
 * This function prompts the user to enter a contact number
 * to view its details.
 * It validates the input and displays the contact details
 * if the contact exists.
 * If no contacts are available, it informs the user to add a contact first.
 * If the input is invalid, it prompts the user to re-enter a valid contact number.
 * @note The contact number is 1-based, meaning the first contact is number 1.
 * If the user enters an invalid number, it will prompt them to enter a number
 * between 1 and the total number of contacts available.
 */
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

/**
 * @brief Executes the main program loop.
 * This function continuously prompts the user for commands
 * until the user decides to exit. It handles the commands
 * to add contacts, search for contacts, or exit the program.
 * It also handles invalid commands and provides feedback to the user.
 */
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
			printInvalidCommandMessage(input);
		}
	}
}

int main(void)
{
	printWelcomeMessage();
	execute_program();
	return (0);
}
