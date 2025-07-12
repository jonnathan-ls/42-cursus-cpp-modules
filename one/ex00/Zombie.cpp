/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 14:52:30 by jlacerda          #+#    #+#             */
/*   Updated: 2025/07/12 16:02:31 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "style.hpp"

Zombie::Zombie(std::string name) : name(name) {}

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
