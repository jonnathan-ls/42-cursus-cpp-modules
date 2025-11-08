/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 14:52:30 by jlacerda          #+#    #+#             */
/*   Updated: 2025/10/25 21:47:06 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include "style.hpp"
#include <iostream>
#include <sstream>

Brain::Brain() {
	std::ostringstream oss;
	for (int i = 0; i < IDEAS_SIZE; ++i) {
		oss << "Idea" << " #" << (i + 1);
		this->ideas[i] = oss.str();
		oss.str("");
		oss.clear();
	}
	std::cout << GREEN << "🔒 Brain has been created!" << RESET << std::endl;
}

Brain::~Brain() {
	std::cout << RED << "🔒 Brain has been destroyed!" << RESET << std::endl;
}

Brain::Brain(const Brain &other) {
	*this = other;
	std::cout << MAGENTA 
		<< "🔒 Brain copy constructor called!" << RESET << std::endl;
}

Brain &Brain::operator=(const Brain &other) {
	if (this != &other) {
		for (int i = 0; i < IDEAS_SIZE; ++i) {
			this->ideas[i] = other.ideas[i];
		}
	}
	std::cout << ORANGE
		<< "🔒 Brain copy assignment operator called!" << RESET << std::endl;
	return *this;
}

std::string Brain::think(int index) const  {
	if (index < 0 || index >= IDEAS_SIZE) {
		return "No idea";
	}
	return this->ideas[index];
}

void Brain::clearIdeas() {
	for (int i = 0; i < IDEAS_SIZE; ++i) {
		this->ideas[i] = "No idea";
	}
}
