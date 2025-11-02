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

static void	test_correct_instance_for_abstract_class() {
	std::cout << CYAN << BOLD
		<< std::endl << "🧪 Test Correct Instance for Abstract Class"
		<< RESET << std::endl << std::endl;

	Animal* dog = new Dog();
	Animal* cat = new Cat();

	dog->makeSound();
	cat->sleep();

	delete dog;
	delete cat;
}

int main()
{
	test_correct_instance_for_abstract_class();
	return (0);
}
