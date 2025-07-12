/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 14:52:30 by jlacerda          #+#    #+#             */
/*   Updated: 2025/07/12 18:25:10 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "style.hpp"

Zombie::Zombie() {}

Zombie::~Zombie() {
	std::cout << "💀 "
	<< BOLD << MAGENTA
	<< this->name
	<< RESET 
	<< " Zombie destructor called. "
	<< std::endl;
}

void Zombie::announce() const {
	std::cout << "🧟 "
	<< BOLD << GREEN
	<< this->name
	<< RESET
	<< ": BraiiiiiiinnnzzzZ..."
	<< std::endl;
}

void Zombie::setName(const std::string& newName) {
	this->name = newName;
}

