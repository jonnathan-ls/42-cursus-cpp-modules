/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 14:52:30 by jlacerda          #+#    #+#             */
/*   Updated: 2025/07/12 18:24:08 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int main(int argc, char **argv) {
	Harl harl;

	if (argc != 2) {
		std::cerr << "Usage: " << argv[0] << " <log_level>" << std::endl;
		return 1;
	}

	std::string level = argv[1];
	LogLevel logLevel = harl.getLogLevel(level);

	harl.filterMessagesByLevel(logLevel);

	return 0;
}