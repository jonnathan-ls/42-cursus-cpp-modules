/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 06:32:27 by jlacerda          #+#    #+#             */
/*   Updated: 2025/06/26 21:53:45 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

# define NO_ARGUMENT_TEXT "* LOUD AND UNBEARABLE FEEDBACK NOISE *"

int main(int argc, char *argv[]) {
	if (argc < 2) {
		std::cout << NO_ARGUMENT_TEXT << std::endl;
		return (0);
	} else {
		for (int i = 1; i < argc; i++) {
			for (char *chr = argv[i]; *chr; chr++) {
				std::cout << static_cast<char>(std::toupper(*chr));
			}
		}
		std::cout << std::endl;
	}
	return (0);
}