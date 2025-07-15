/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 14:52:30 by jlacerda          #+#    #+#             */
/*   Updated: 2025/07/14 23:35:03 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

#define BOLD "\033[1m"
#define RESET "\033[0m"
#define PINK "\033[35m"
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define CYAN "\033[36m"
#define ORANGE "\033[38;5;208m"

#define EMPTY_STR ""
#define LEVELS_SIZE 4
#define WARN_ICON "⚠️  "
#define INFO_ICON "ℹ️  "
#define DEBUG_ICON "🐞 "
#define ERROR_ICON "❌ "
#define UNKNOWN_ICON "❓ "

/**
 * Typedef for member function pointers in the Harl class.
 */
typedef void (Harl::*HarlFunction)(void);

/**
 * Array of log levels used to identify the type of complaint.
 * Each level corresponds to a specific type of message.
 */
std::string HARL_LEVELS[LEVELS_SIZE] = { "INFO", "ERROR", "DEBUG", "WARNING" };

/**
 * Trims leading and trailing whitespace from a string.
 * @param str The string to trim.
 * @return A new string with leading and trailing whitespace removed.
 */
LogLevel Harl::getLogLevel(const std::string &level) {
	for (int i = 0; i < LEVELS_SIZE; i++) {
		if (level == HARL_LEVELS[i]) {
			return static_cast<LogLevel>(i);
		}
	}
	return UNKNOWN;
}

/**
 * Filters and displays messages based on the provided log level.
 * @param level The log level to filter messages by.
 * This function will call the appropriate complain method
 * for the specified log level and all levels above it.
 */
void Harl::filterMessagesByLevel(LogLevel level) {
	switch (level) {
		case DEBUG: 
			complain("DEBUG");
			/* FALLTHROUGH */
		case INFO: 
			complain("INFO");
			/* FALLTHROUGH */
		case WARNING: 
			complain("WARNING");
			/* FALLTHROUGH */
		case ERROR: 
			complain("ERROR"); 
			break;
		default:
			std::cout << ORANGE
				<< "[ Probably complaining about insignificant problems ]"
				<< RESET << std::endl << std::endl;
			break;
	}
}

/**
 * Trims leading and trailing whitespace from a string.
 * @param str The string to trim.
 * @return A new string with leading and trailing whitespace removed.
 */
std::string trim(const std::string& str) {
	size_t first = str.find_first_not_of(" ");
	size_t last = str.find_last_not_of(" ");
	return (first == std::string::npos)
		? EMPTY_STR : str.substr(first, last - first + 1);
}

void Harl::complain(const std::string level) {
	HarlFunction functions[LEVELS_SIZE] = {
		&Harl::info, &Harl::error, &Harl::debug, &Harl::warning
	};

	if (trim(level).empty()) {
		std::cout << UNKNOWN_ICON << ORANGE
			<< "[UNKNOWN] No level provided." << RESET << std::endl;
		return;
	}

	for (int i = 0; i < LEVELS_SIZE; i++) {
		if (level == HARL_LEVELS[i]) {
			(this->*functions[i])();
			return;
		}
	}
	
	std::cout << UNKNOWN_ICON << ORANGE
		<< "[UNKNOWN]" << RESET << std::endl
		<< "I don't know how to respond to that level: "
		<< level << std::endl << std::endl;
}

void Harl::debug(void) {
	std::cout << DEBUG_ICON << PINK
		<< "[DEBUG]" << RESET << std::endl << std::endl
		<< "I love having extra bacon for my "
		<< "7XL-double-cheese-triple-pickle-special-ketchup burger."
		<< std::endl
		<< "I really do!" << std::endl << std::endl;
}

void Harl::info(void) {
	std::cout << INFO_ICON << CYAN
		<< "[INFO]" << RESET << std::endl << std::endl
		<< "I cannot believe adding extra bacon costs more money."
		<< std::endl
		<< "You didn't put enough bacon in my burger! "
		<< "If you did, I wouldn't be asking for more!"
		<< std::endl << std::endl;
}

void Harl::warning(void) {
	std::cout << WARN_ICON << YELLOW
		<< "[WARNING]" << RESET << std::endl << std::endl
		<< "I think I deserve to have some extra bacon for free."
		<< std::endl
		<< "I've been coming for years, whereas you started "
		<< "working here just last month."
		<< std::endl << std::endl;
}

void Harl::error(void) {
	std::cout << ERROR_ICON << RED
		<< "[ERROR]" << RESET << std::endl << std::endl
		<< "This is unacceptable! "
		<< "I want to speak to the manager now."
		<< std::endl << std::endl;
}
