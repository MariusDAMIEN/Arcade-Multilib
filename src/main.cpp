//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#include <iostream>
#include "arcade.hpp"
#include "ERROR/ErrorHandling.hpp"

int launch(char *lib);

int main(int ac, char **av)
{
	(void)ac;
	(void)av;
	// if (ac != errHand::ARGS_REQUIRED) {
	// 	std::cerr << "tu remplacera" << std::endl;
	// 	return errHand::ERR;
	// }
	try {
          launch(av[1]);
	} catch (const std::exception &err) {
		std::cerr << err.what() << std::endl;
		return errHand::ERR;
	}
	return errHand::OK;
}
