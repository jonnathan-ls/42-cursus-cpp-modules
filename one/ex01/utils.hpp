/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 14:52:30 by jlacerda          #+#    #+#             */
/*   Updated: 2025/07/12 16:31:04 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

#include <iostream>
#include <sstream>
#include <cstdlib>
#include "style.hpp"

/**
 * @brief Converts an integer to a string.
 * @param value The integer value to convert.
 * @return A string representation of the integer.
 */
std::string intToString(int value);

/**
 * @brief Clears the console screen.
 * This function uses the system command to clear the terminal screen.
 */
void clearScreen(void);

/**
 * @brief Pauses the program and waits for user input.
 * Displays a message prompting the user to press ENTER to continue.
 */
void pause(void);

/**
 * @brief Checks if the end of file (EOF) has been detected.
 * 
 * This function checks if the standard input stream has reached
 * the end of file. If EOF is detected, it clears the input stream
 * and prints a warning message.
 * 
 * @return true if EOF is detected, false otherwise.
 */
bool endOfFileDetected(void);

#endif