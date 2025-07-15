/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 14:52:30 by jlacerda          #+#    #+#             */
/*   Updated: 2025/07/14 21:22:43 by jlacerda         ###   ########.fr       */
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

#define LEVELS_SIZE 4
#define WARN_ICON "⚠️  "
#define INFO_ICON "ℹ️  "
#define DEBUG_ICON "🐞 "
#define ERROR_ICON "❌ "
#define UNKNOWN_ICON "❓ "

typedef void (Harl::*HarlFunction)(void);

std::string HARL_LEVELS[LEVELS_SIZE] = {
	"INFO", "ERROR", "DEBUG", "WARNING"
};

std::string trim(const std::string& str) {
	size_t first = str.find_first_not_of(" \t");
	size_t last = str.find_last_not_of(" \t");
	return (first == std::string::npos)
		? "" : str.substr(first, last - first + 1);
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
		<< "[UNKNOWN] I don't know how to respond to that level: "
		<< level << RESET << std::endl;
}

void Harl::debug(void) {
	std::cout << DEBUG_ICON << PINK
		<< "[DEBUG] I love having extra bacon for my "
		<< "7XL-double-cheese-triple-pickle-special-ketchup burger. " 
		<< "I really do!" << std::endl;
}

void Harl::info(void) {
	std::cout << INFO_ICON << CYAN
		<< "[INFO] I cannot believe adding extra bacon costs more money. "
		<< "You didn't put enough bacon in my burger! "
		<< "If you did, I wouldn't be asking for more!"
		<< RESET << std::endl;
}

void Harl::warning(void) {
	std::cout << WARN_ICON << YELLOW
		<< "[WARNING] I think I deserve to have some extra bacon for free. "
		<< "I've been coming for years, whereas you started "
		<< "working here just last month." << RESET << std::endl;
}

void Harl::error(void) {
	std::cout << ERROR_ICON << RED
		<< "[ERROR] This is unacceptable! "
		<< "I want to speak to the manager now."
		<< RESET << std::endl;
}