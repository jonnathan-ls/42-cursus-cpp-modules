/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 14:52:30 by jlacerda          #+#    #+#             */
/*   Updated: 2025/07/14 23:33:58 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <string>

/**
 * Enum representing different log levels.
 * Each level corresponds to a specific type of message.
 */
enum LogLevel { INFO, ERROR, DEBUG, WARNING, UNKNOWN };

/**
 * Harl class handles different log levels and their corresponding messages.
 * It provides methods to complain about various issues based on the log level.
 */
class Harl {
	public:
		/**
		 * * Handles complaints based on the provided log level.
		 * * @param level The log level to handle.
		 * * This function will call the appropriate complain method
		 * * for the specified log level and all levels above it.
		 * * If the level is unknown, it will print an error message.
		 */
		void complain(const std::string level);
		/**
		 * Retrieves the log level based on the provided string.
		 * @param level The string representation of the log level.
		 * @return The corresponding LogLevel enum value.
		 */
		void filterMessagesByLevel(LogLevel level);
		/**
		 * Retrieves the log level based on the provided string.
		 * @param level The string representation of the log level.
		 * @return The corresponding LogLevel enum value.
		 */
		LogLevel getLogLevel(const std::string &level);
	private:
		void info(void);
		void error(void);
		void debug(void);
		void warning(void);
};

#endif