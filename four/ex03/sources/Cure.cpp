/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 14:52:30 by jlacerda          #+#    #+#             */
/*   Updated: 2025/11/02 16:50:13 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include <iostream>
#include "ICharacter.hpp"

Cure::Cure() : AMateria("cure") {}
Cure::~Cure() {}
Cure::Cure(const Cure &other) : AMateria(other) {}
Cure &Cure::operator=(const Cure &other) {
	if (this != &other) {
		AMateria::operator=(other);
	}
	return *this;
}

AMateria *Cure::clone() const {
	return new Cure(*this);
}

void Cure::use(ICharacter &target) {
	std::cout << "* heals "
		<< target.getName() << "'s wounds *" << std::endl;
}
