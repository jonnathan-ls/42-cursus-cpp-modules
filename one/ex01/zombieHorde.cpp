/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 14:52:30 by jlacerda          #+#    #+#             */
/*   Updated: 2025/07/12 18:26:04 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

/**
 * @brief Creates a Zombie on the stack with the given name and announces itself.
 * @param name The name of the Zombie.
 * @return A Zombie horde object that is dynamically allocated on the heap.
 * The object apoint for the first Zombie in the horde.
 */
Zombie* zombieHorde( int N, std::string name ) {
	Zombie* horde = new Zombie[N];
	for (int i = 0; i < N; i++) {
		horde[i].setName(name);
	}
	return horde;
}