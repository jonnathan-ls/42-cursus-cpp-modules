/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 14:52:30 by jlacerda          #+#    #+#             */
/*   Updated: 2025/07/26 15:08:39 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

#define ERROR_EMOJI "❌ "
#define INFO_EMOJI "ℹ️  "
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

int main(int argc, char **argv) {
	Harl harl;

	if (argc != 2) {
		std::cerr << ERROR_EMOJI
			<< RED << "Error: " << RESET
			<< "Invalid number of arguments." << std::endl;
		std::cerr << INFO_EMOJI << YELLOW << "Usage: " << RESET
			<< argv[0] << " <log_level>" << std::endl;
		std::cerr << INFO_EMOJI << YELLOW << "Available log levels: "
			<< RESET << "DEBUG, INFO, WARNING, ERROR" << std::endl;
		return 1;
	}

	std::string level = argv[1];
	LogLevel logLevel = harl.getLogLevel(level);

	harl.filterMessagesByLevel(logLevel);

	return 0;
}