/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 14:52:30 by jlacerda          #+#    #+#             */
/*   Updated: 2025/11/02 17:31:34 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::~MateriaSource() {
	for (int i = 0; i < storedQuantity; i++) {
		delete materials[i];
	}
}

MateriaSource::MateriaSource() : storedQuantity(0) {
	for (int i = 0; i < MAX_MATERIA; i++) {
		this->materials[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource &other) {
	*this = other;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other) {
	if (this != &other) {
		for (int i = 0; i < storedQuantity; i++) {
			delete materials[i];
		}
		storedQuantity = other.storedQuantity;
		for (int i = 0; i < storedQuantity; i++) {
			materials[i] = other.materials[i]->clone();
		}
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria *m) {
	if (m && storedQuantity < MAX_MATERIA) {
		materials[storedQuantity] = m;
		storedQuantity++;
	}
}

AMateria *MateriaSource::createMateria(const std::string &type) {
	for (int i = 0; i < storedQuantity; i++) {
		if (materials[i]->getType() == type) {
			return materials[i]->clone();
		}
	}
	return 0;
}
