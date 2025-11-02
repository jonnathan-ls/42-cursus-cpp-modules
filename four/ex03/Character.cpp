/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 14:52:30 by jlacerda          #+#    #+#             */
/*   Updated: 2025/11/02 17:30:28 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Constants.hpp"

Character::~Character() {
	for (int i = 0; i < MAX_MATERIA; i++) {
		if (this->inventory[i]) {
			delete this->inventory[i];
		}
	}
}

Character::Character(const std::string &name) : name(name) {
	for (int i = 0; i < MAX_MATERIA; i++) {
		this->inventory[i] = NULL;
	}
}

Character::Character(const Character &other) : name(other.name) {
	for (int i = 0; i < MAX_MATERIA; i++) {
		this->inventory[i] = NULL;
		if (other.inventory[i])
			this->inventory[i] = other.inventory[i]->clone();
	}
}

Character &Character::operator=(const Character &other) {
	if (this != &other) {
		this->name = other.name;
		for (int i = 0; i < MAX_MATERIA; i++) {
			if (this->inventory[i])
				delete this->inventory[i];
			this->inventory[i] = NULL;
			if (other.inventory[i])
				this->inventory[i] = other.inventory[i]->clone();
		}
	}
	return *this;
}

std::string const &Character::getName() const {
	return this->name;
}

void Character::equip(AMateria *m) {
	for (int i = 0; i < MAX_MATERIA; i++) {
		if (this->inventory[i] == NULL) {
			this->inventory[i] = m;
			return;
		}
	}
}

void Character::unequip(int idx) {
	if (idx < 0 || idx >= MAX_MATERIA)
		return;
	this->inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target) {
	if (idx < 0 || idx >= MAX_MATERIA)
		return;
	if (this->inventory[idx])
		this->inventory[idx]->use(target);
}