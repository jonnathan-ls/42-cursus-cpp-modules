/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 06:32:27 by jlacerda          #+#    #+#             */
/*   Updated: 2025/07/05 17:45:21 by jlacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP
#include <string>
#include <iostream>

std::string trim(const std::string &str);
bool isNumeric(const std::string& str);
bool endOfFileDetected(void);

#endif