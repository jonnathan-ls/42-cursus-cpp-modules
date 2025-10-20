/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 14:52:30 by jlacerda          #+#    #+#             */
/*   Updated: 2025/10/19 21:53:16 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <string>

class DiamondTrap: public ScavTrap, public FragTrap {
	private:
		std::string name;

	public:
	DiamondTrap(std::string const &name);
		DiamondTrap(DiamondTrap const &other);
		DiamondTrap &operator=(DiamondTrap const &other);
		~DiamondTrap();
		void whoAmI();

		void attack(const std::string &target);
};

#endif