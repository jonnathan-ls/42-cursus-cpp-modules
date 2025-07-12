/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 14:52:30 by jlacerda          #+#    #+#             */
/*   Updated: 2025/07/12 16:45:43 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

std::string intToString(int value) {
	std::stringstream ss;
	ss << value;
	return ss.str();
}

void clearScreen(void) {
	std::system("clear");
}

void pause(void) {
	std::cout << YELLOW << "\nPressione ENTER para continuar ... " << RESET;
	std::cin.get();
}

bool endOfFileDetected(void)
{
	if (std::cin.eof()) {
		std::cout
			<< std::endl << YELLOW
			<< "⚠️  EOF detected. Exiting of interaction"
			<< RESET << std::endl;
		std::cin.clear();
		return true;
	}
	return false;
}