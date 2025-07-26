/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 14:52:30 by jlacerda          #+#    #+#             */
/*   Updated: 2025/07/26 14:38:12 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define RED     "\033[31m"
#define YELLOW  "\033[33m"
#define GREEN   "\033[32m"
#define INFO_EMOJI   "ℹ️  "
#define BOX_EMOJI   "📦 "
#define VALUE_EMOJI "📄 "

int main() {
	std::string str = "HI THIS IS BRAIN";
	std::string* stringPTR = &str;
	std::string& stringREF = str;

	std::cout << std::endl << BOLD << GREEN << INFO_EMOJI 
		<< "This program demonstrates pointers and references in C++." 
		<< RESET << std::endl << std::endl;
	std::cout << BOX_EMOJI << "Address of str:      " << &str << std::endl;
	std::cout << BOX_EMOJI << "Address held by PTR: " << stringPTR << std::endl;
	std::cout << BOX_EMOJI << "Address held by REF: " << &stringREF << std::endl;

	std::cout<< std::endl;
	
	std::cout << VALUE_EMOJI << "Value of str:  " << str << std::endl;
	std::cout << VALUE_EMOJI << "Value via PTR: " << *stringPTR << std::endl;
	std::cout << VALUE_EMOJI << "Value via REF: " << stringREF << std::endl;

	std::cout << BOLD << GREEN
		<< "\n✅ All addresses match and values are identical!" 
		<< RESET << std::endl;
	
	std::cout << BOLD << YELLOW
		<< "\n⚠️  Notes abouts pointers and references:" << RESET << std::endl;
	std::cout << "- A pointer is a variable that holds a memory address, while a reference is an alias for another variable." << std::endl;
	std::cout << "- A pointer can be reassigned to point to another variable, a reference cannot." << std::endl;
	std::cout << "- A reference must be initialized when declared, a pointer can be initialized later." << std::endl;
	std::cout << "- Dereferencing a null pointer leads to undefined behavior, while a reference always refers to a valid object." << std::endl;
	std::cout << "- Use pointers when you need to represent the absence of a value (e.g., null pointers)." << std::endl;
	std::cout << "- Use references for simpler syntax and when you know the reference will always be valid." << std::endl;
	std::cout << BOLD << RED
		<< "\n❗ Always ensure pointers are valid before dereferencing to avoid undefined behavior!" 
		<< RESET << std::endl << std::endl;
	return 0;
}