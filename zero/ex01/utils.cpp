/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 06:32:27 by jlacerda          #+#    #+#             */
/*   Updated: 2025/07/05 18:38:00 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"
#include "styles.hpp"

#define SPACE_CHAR ' '
#define EMPTY_STRING ""
#define WHITESPACES " \t\n\r\f\v"

/**
 * @brief Trims leading and trailing whitespace from a string.
 * 
 * This function removes all leading and trailing whitespace characters
 * from the input string, including spaces, tabs, newlines, and other
 * common whitespace characters.
 * 
 * @param str The input string to be trimmed.
 * @return A new string with leading and trailing whitespace removed.
 */
std::string trim(const std::string &str) {
	size_t first = str.find_first_not_of(WHITESPACES);
	if (first == std::string::npos) return EMPTY_STRING;
	size_t last = str.find_last_not_of(SPACE_CHAR);
	return str.substr(first, (last - first + 1));
}

/**
 * @brief Checks if a string contains only numeric characters.
 * This function iterates through each character in the string
 * and checks if it is a digit. If any character is not a digit,
 * the function returns false. If all characters are digits,
 * it returns true.
 */
bool isNumeric(const std::string& str) {
	if (str.empty()) return false;
	
	for (size_t i = 0; i < str.length(); i++) {
		if (!std::isdigit(str[i])) {
			return false;
		}
	}
	return true;
}

/**
 * @brief Checks if the end of file (EOF) has been detected.
 * 
 * This function checks if the standard input stream has reached
 * the end of file. If EOF is detected, it clears the input stream
 * and prints a warning message.
 * 
 * @return true if EOF is detected, false otherwise.
 */
bool endOfFileDetected(void)
{
	if (std::cin.eof()) {
		std::cout
			<< std::endl << YELLOW << ICON_WARNING 
			<< "EOF detected. Exiting of interaction" << RESET << std::endl;
		std::cin.clear();
		return true;
	}
	return false;
}