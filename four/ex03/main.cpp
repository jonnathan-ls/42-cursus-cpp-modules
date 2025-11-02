/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 14:52:30 by jlacerda          #+#    #+#             */
/*   Updated: 2025/11/02 18:14:41 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include <iostream>
#include "style.hpp"

static void	test_subject()
{
	std::cout << CYAN << BOLD
		<< std::endl << "🧪 Subject Example"
		<< RESET << std::endl << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
}

static void test_inventory_limits()
{
	std::cout << CYAN << BOLD
		<< std::endl << "🧪 Inventory and Source Limits"
		<< RESET << std::endl << std::endl;
	
	IMateriaSource* src = new MateriaSource();
	
	std::cout << YELLOW << "📝 Learning 4 materias (max)..." << RESET << std::endl;
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	
	std::cout << YELLOW << "📝 Trying to learn 5th materia..." << RESET << std::endl;
	AMateria* extraSource = new Ice();
	src->learnMateria(extraSource);
	delete extraSource;
	
	ICharacter* hero = new Character("hero");
	
	std::cout << YELLOW << "📝 Equipping 4 materias (max)..." << RESET << std::endl;
	hero->equip(src->createMateria("ice"));
	hero->equip(src->createMateria("cure"));
	hero->equip(src->createMateria("ice"));
	hero->equip(src->createMateria("cure"));
	
	std::cout << YELLOW << "📝 Trying to equip 5th materia..." << RESET << std::endl;
	AMateria* extraChar = src->createMateria("ice");
	hero->equip(extraChar);
	delete extraChar;
	
	ICharacter* target = new Character("target");
	hero->use(0, *target);
	hero->use(1, *target);
	hero->use(2, *target);
	hero->use(3, *target);
	
	delete target;
	delete hero;
	delete src;
}

static void test_unequip_and_delete()
{
	std::cout << CYAN << BOLD
		<< std::endl << "🧪 Unequip and Manual Delete"
		<< RESET << std::endl << std::endl;
	
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	
	ICharacter* warrior = new Character("warrior");
	ICharacter* dummy = new Character("dummy");
	
	AMateria* ice = src->createMateria("ice");
	AMateria* cure = src->createMateria("cure");
	
	warrior->equip(ice);
	warrior->equip(cure);
	
	std::cout << YELLOW << "📝 Using equipped materias..." << RESET << std::endl;
	warrior->use(0, *dummy);
	warrior->use(1, *dummy);
	
	std::cout << YELLOW << "📝 Unequipping slot 0..." << RESET << std::endl;
	warrior->unequip(0);
	
	std::cout << YELLOW << "📝 Trying to use unequipped slot..." << RESET << std::endl;
	warrior->use(0, *dummy);
	
	std::cout << YELLOW << "📝 Deleting unequipped materia..." << RESET << std::endl;
	delete ice;
	
	delete dummy;
	delete warrior;
	delete src;
}

static void test_deep_copy()
{
	std::cout << CYAN << BOLD
		<< std::endl << "🧪 Deep Copy (Constructor and Assignment)"
		<< RESET << std::endl << std::endl;
	
	IMateriaSource* src = new MateriaSource();
	AMateria *ice = src->createMateria("ice");
	AMateria *cure = src->createMateria("cure");
	src->learnMateria(ice);
	src->learnMateria(cure);
	
	std::cout << YELLOW << "📝 Creating original with equipment..." << RESET << std::endl;
	Character original("original");
	original.equip(ice);
	original.equip(cure);

	std::cout << YELLOW << "📝 Copy via constructor..." << RESET << std::endl;
	Character copy1(original);
	
	std::cout << YELLOW << "📝 Copy via assignment operator..." << RESET << std::endl;
	Character copy2("copy2");
	copy2 = original;
	
	Character target("target");
	
	std::cout << YELLOW << "📝 Modifying original..." << RESET << std::endl;
	original.unequip(0);
	
	std::cout << YELLOW << "📝 Using copy1 (should be independent)..." << RESET << std::endl;
	copy1.use(0, target);
	copy1.use(1, target);
	
	std::cout << YELLOW << "📝 Using copy2 (should be independent)..." << RESET << std::endl;
	copy2.use(0, target);
	copy2.use(1, target);
	
	std::cout << YELLOW << "📝 Self-assignment test..." << RESET << std::endl;
	copy1 = copy1;
	copy1.use(0, target);
	
	delete src;
	delete ice;
	delete cure;
}

static void test_edge_cases()
{
	std::cout << CYAN << BOLD
		<< std::endl << "🧪 Edge Cases and Invalid Operations"
		<< RESET << std::endl << std::endl;
	
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	
	ICharacter* player = new Character("player");
	ICharacter* enemy = new Character("enemy");
	
	std::cout << YELLOW << "📝 Using empty/invalid slots..." << RESET << std::endl;
	player->use(0, *enemy);
	player->use(-1, *enemy);
	player->use(99, *enemy);
	
	std::cout << YELLOW << "📝 Unequipping empty/invalid slots..." << RESET << std::endl;
	player->unequip(0);
	player->unequip(-5);
	player->unequip(10);
	
	std::cout << YELLOW << "📝 Equipping NULL..." << RESET << std::endl;
	player->equip(NULL);
	
	std::cout << YELLOW << "📝 Creating unknown type..." << RESET << std::endl;
	AMateria* unknown = src->createMateria("fire");
	if (unknown == NULL) {
		std::cout << GREEN << "✓ NULL for unknown type" << RESET << std::endl;
	}
	
	delete enemy;
	delete player;
	delete src;
}

int main()
{
	test_subject();
	test_inventory_limits();
	test_unequip_and_delete();
	test_deep_copy();
	test_edge_cases();
	
	return (0);
}