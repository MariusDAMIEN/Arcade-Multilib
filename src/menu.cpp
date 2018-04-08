//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#include "menu.hpp"

menu::menu(IGraphic **graph, std::vector<std::string> const &vectGame
           , std::vector<std::string> const &vectLib)
	:_igraph(graph), _vectGame(vectGame), _vectLib(vectLib)
{
  _init = false;
}

menu::~menu()
{}

void menu::chooseGame()
{

  }

void menu::homePage()
{
    chooseGame();
    //         Parser oklm(&_igraph, "test", "red");
    /*
    _areaName.push_back("Title");
    _areaName.push_back("bg_menu");
    _areaName.push_back("Readme");
    _areaName.push_back("first_validation");
    _areaName.push_back("Libliste");
    (*_igraph)->createArea(std::make_pair(WIDTH, HEIGHT), std::make_pair(0, 0)
                           , std::make_pair("bg_menu", "bg_menu.png"), IGraphic::TYPE::RECT);
 
    */
  if ((*_igraph)->isKeyPressed("right") == true) {
    for (auto it : _areaName)
      (*_igraph)->deleteArea(it);
    _init = 2;
  }
}
