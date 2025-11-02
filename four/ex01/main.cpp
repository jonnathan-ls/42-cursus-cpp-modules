/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 14:52:30 by jlacerda          #+#    #+#             */
/*   Updated: 2025/07/12 17:34:58 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Cat.hpp"
#include "Dog.hpp"
#include "style.hpp"

#define SIZE 4

static void test_whitout_brain() {
	Animal animal;
	std::cout << CYAN << BOLD
		<< std::endl << "🧪 Test Animal without Brain"
		<< std::endl << std::endl;
	animal.makeSound();
}

static void test_with_brain() {
	Animal* animals[SIZE];
	std::cout << CYAN << BOLD
		<< std::endl << "🧪 Test Cats and Dogs with Brains"
		<< std::endl << std::endl;

	for (int i = 0; i < SIZE; ++i) {
		if (i % 2 == 0) {
			animals[i] = new Dog();
		} else {
			animals[i] = new Cat();
		}
	}
	for (int i = 0; i < SIZE; ++i) {
		animals[i]->makeSound();
	}
	for (int i = 0; i < SIZE; ++i) {
		delete animals[i];
	}
}

static void test_deep_copy() {
	std::cout << CYAN << BOLD
		<< std::endl << "🧪 Test Deep Copy"
		<< RESET << std::endl << std::endl;

	Cat cat;
	std::cout << "▶️  Original Cat ideas before copy" << std::endl;
	cat.makeSound();
	std::cout << "▶️  Original Cat ideas after copy" << std::endl;
	Cat catClone = Cat(cat);
	std::cout << "▶️  Cloned Cat ideas after copy" << std::endl;
	catClone.makeSound();
	cat.sleep();
	std::cout << "▶️  Original Cat ideas after sleep" << std::endl;
	cat.makeSound();
	std::cout << "▶️  Cloned Cat ideas should remain unchanged" << std::endl;
	catClone.makeSound();

	std::cout << "📝 it is expected that cat and catClone have different ideas."
		<< std::endl << "📝 And that they do not share the same Brain instance."
		<< std::endl << "📝 And destructor of both without issues." << std::endl;
}

static void test_deep_copy_in_atribution() {
	std::cout << CYAN << BOLD
		<< std::endl << "🧪 Test Deep Copy in Assignment Operator"
		<< RESET << std::endl << std::endl;

	Dog dog;
	std::cout << "▶️  Original Dog ideas before assignment" << std::endl;
	dog.makeSound();
	std::cout << "▶️  Original Dog ideas after assignment" << std::endl;
	Dog dogClone;
	dogClone = dog;
	std::cout << "▶️  Cloned Dog ideas after assignment" << std::endl;
	dogClone.makeSound();
	dog.sleep();
	std::cout << "▶️  Original Dog ideas after sleep" << std::endl;
	dog.makeSound();
	std::cout << "▶️  Cloned Dog ideas should remain unchanged" << std::endl;
	dogClone.makeSound();

	std::cout << "📝 it is expected that dog and dogClone have different ideas."
		<< std::endl << "📝 And that they do not share the same Brain instance."
		<< std::endl << "📝 And destructor of both without issues." << std::endl;
}

int main()
{
	test_whitout_brain();
	test_with_brain();
	test_deep_copy();
	test_deep_copy_in_atribution();
	return (0);
}
