/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 14:52:30 by jlacerda          #+#    #+#             */
/*   Updated: 2025/07/12 15:38:23 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

/**
 * @brief Creates a Zombie on the stack with the given name and announces itself.
 * @param name The name of the Zombie.
 * This Zombie will be automatically destroyed when it goes out of scope.
 * It will announce itself before being destroyed.
 */
void randomChump(std::string name) {
	Zombie zombie(name);
	zombie.announce();
}
