//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

// #include <SFML/Graphics.hpp>
#include <iostream>
#include "SFML/sfmlFramework.hpp"
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
	// try {
	launch(av[1]);
		//jeumoha();
	// } catch (std::exception const &err) {
	// 	std::cerr << err.what() << std::endl;
	// 	return errHand::ERR;
	// }
	return errHand::OK;
}
