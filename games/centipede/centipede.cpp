//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#include "CENTIPEDE/centipede.hpp"

Centipede::Centipede(IGraphic *igraph) : _igraph(igraph)
{
  loop();
}

Centipede::~Centipede()
{}

void Centipede::loop()
{
  _igraph->createWindow(std::make_pair(WIDTH, HEIGHT), "oklm");
  _igraph->createArea(std::make_pair(180, 180), std::make_pair(250, 0)
                      , std::make_pair("Title", "CETIPEDE"), IGraphic::TYPE::TEXT);
  while (1) {
    _igraph->displayObj();
    _igraph->clearWindow();
  }
}

void Centipede::changeLib(IGraphic *igraph)
{
  (void)igraph;
}

extern "C" IGame *start(IGraphic *lib)
{
	return new Centipede(lib);
}

