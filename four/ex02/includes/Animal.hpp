/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 14:52:30 by jlacerda          #+#    #+#             */
/*   Updated: 2025/11/02 14:24:34 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

/**
 * @class Animal
 * @brief Abstract base class representing a generic animal.
 *
 * The Animal class serves as a base for specific animal types.
 * It contains a type attribute and a pure virtual function makeSound,
 * which must be implemented by derived classes to provide specific sounds.
 */
class Animal
{
	protected:
		std::string type;
	public:
		Animal();
		virtual ~Animal();
		Animal(const Animal &other);
		Animal &operator=(const Animal &other);

		/**
		 * @brief makes a sound specific to the animal type.
		 * @note This is a pure virtual function 
		 * that must be overridden in derived classes.
		 */
		virtual void makeSound() const = 0;

		/**
		 * @brief makes the animal sleep, affecting its state.
		 * @note This is a pure virtual function 
		 * that must be overridden in derived classes.
		 */
		virtual void sleep() const = 0;
};

#endif