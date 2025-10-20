/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 14:52:30 by jlacerda          #+#    #+#             */
/*   Updated: 2025/10/18 17:34:58 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

class ClapTrap {
	protected:
		std::string name;
		int hitPoints;
		int energyPoints;
		int attackDamage;
	
	public:
	ClapTrap(std::string const &paramName);
		ClapTrap(ClapTrap const &other);
		ClapTrap &operator=(ClapTrap const &other);
		virtual ~ClapTrap();
	
		virtual void attack(const std::string &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		std::string getName() const;
		int getHitPoints() const;
		int getEnergyPoints() const;
		int getAttackDamage() const;
};

#endif
