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
#include "WrongCat.hpp"

static void test_correct() {
	std::cout << std::endl << CYAN << BOLD
		<< "🧪 Animal Test" << RESET << std::endl << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << "▶️  j = " << j->getType() << std::endl;
	std::cout << "▶️  i = " << i->getType() << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	delete meta;
	delete j;
	delete i;
}

static void test_wrong() {
	std::cout << std::endl << CYAN << BOLD
		<< "🧪 WrongAnimal Test" << RESET << std::endl << std::endl;
	const WrongAnimal* meta = new WrongAnimal();
	const WrongAnimal* i = new WrongCat();
	std::cout << "▶️  i = " << i->getType() << std::endl;
	i->makeSound();
	meta->makeSound();
	delete meta;
	delete i;
	std::cout << std::endl;
}

int main()
{
	test_correct();
	test_wrong();
	return (0);
}
