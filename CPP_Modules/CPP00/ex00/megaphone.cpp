/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzhakhan <dzhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:29:00 by dzhakhan          #+#    #+#             */
/*   Updated: 2025/03/19 10:32:59 by dzhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <algorithm>

int main(int ac, char **av) {
	if (ac == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return 0;
	}
	for (int i = 1; i < ac; ++i){
		std::string str(av[i]);
		if (str.empty()) continue;
		std::transform(str.begin(), str.end(), str.begin(), ::toupper);
		std::cout << str;
		if (i < ac)
			std::cout << " ";
	}
	std::cout << "\n";
	return 0;
}