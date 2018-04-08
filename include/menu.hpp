//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#ifndef _MENU_HPP_
# define _MENU_HPP_

#include <iostream>
#include <vector>
#include "IGraphic.hpp"
#include <algorithm>
#include "Parser.hpp"

class menu
{
public:
	menu(IGraphic **, std::vector<std::string> const &vetGame
	     , std::vector<std::string> const &vectLib);
	virtual ~menu();
	void homePage();

private:
	IGraphic **_igraph;
	bool	_initGame;
	int	_init;
	void chooseGame();
	std::vector<std::string> _vectGame;
	std::vector<std::string> _vectLib;
	std::vector<std::string> _areaName;
};

#endif /* !_MENU_HPP_ */
