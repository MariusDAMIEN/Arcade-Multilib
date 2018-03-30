//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

// #include <SFML/Graphics.hpp>
#include <iostream>
#include "SFML/sfmlFramework.hpp"
#include "NCURSE/ncurseFramework.hpp"
#include "arcade.hpp"
#include "ERROR/ErrorHandling.hpp"

int launch(char *lib);

bool my_loop()
{
	IGraphic *_igraph(new ncurseFramework);
	char marius[11] = "ewew\n";

	_igraph->createWindow(std::make_pair(2000, 500), "oklm");
	_igraph->createArea(std::make_pair(250, 250 / 2), std::make_pair(250, 250)
			    , std::make_pair(marius, "blue"), IGraphic::TYPE::CHARAC);	
	_igraph->createArea(std::make_pair(100, 100), std::make_pair(30, 300)
			    , std::make_pair("Name", "trop fort chieffff marius"), IGraphic::TYPE::TEXT);
	while (1) {
		if (_igraph->isKeyPressed("escape") == true)
			exit(6);
		_igraph->clearWindow();
		_igraph->displayObj();
	}
}

int main(int ac, char **av)
{
	(void)ac;
	(void)av;
	// if (ac != errHand::ARGS_REQUIRED) {
	// 	std::cerr << "tu remplacera" << std::endl;
	// 	return errHand::ERR;
	// }
	try {
		my_loop();
	} catch (std::exception const &err) {
		std::cerr << err.what() << std::endl;
		return errHand::ERR;
	}
	return errHand::OK;
}
