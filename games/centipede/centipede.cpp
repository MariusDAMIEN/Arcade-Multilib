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

void Centipede::movCent()
{
  // int i = 0;

  // for (auto &it : _posCen) {
  //   bool swi = false;
  //   std::string cent("cen");
  //   cent += std::to_string(i);
  //   if (it.first + 30 >= WIDTH)
  //     swi = true;
  //   if (!swi) {
  //     if (it.first <= WIDTH) {
  //       it.first += 30;
  //       std::cout << "test\n";
  //     }
  //     else {
  //       std::cout << "test1\n";
  //       it.second += 30;
  //      }
  //   }
  //   else {
  //     if (it.first > 0) {
  //       std::cout << "test2\n";
  //       it.first -= 30;
  //     }
  //     else {
  //       it.second += 30;
  //      }
  //   }
  //   _igraph->setpos(it, cent);
  //   i++;
  // }
}

void Centipede::initCent()
{
  int x = WIDTH / 2;
  int y = 0;

  Bug test(12, std::make_pair(x, y), Body::DIRECTION::RIGHT, _igraph);
  Player player(_igraph, std::make_pair(WIDTH - 300, HEIGHT - 300));
  _player.push_back(player);
  _bodies.push_back(test);
}

void Centipede::algo()
{
  if (!_init)
    initCent();
  _init = true;
  for (auto &it : _bodies) {
    it.setMush(_posMush);
    it.printBody();
  }
  for (auto &it : _player) {
    it.setBodyPos(_bodies);
    it.printShip();
  }
}

void Centipede::displayMush()
{
        int x = 30;
        int y = 30;

        std::srand(std::time(0));
        while (y < HEIGHT - 200) {
          x = 30;
          while (x < WIDTH) {
            int i = std::rand() % 10;
            if(i == 3) {
              std::string mush("mush");
              mush = mush + std::to_string(x) + std::to_string(y);
              _posMush.push_back(std::make_pair(x, y));
              _igraph->createArea(std::make_pair(30, 30), std::make_pair(x, y)
                                  , std::make_pair(mush, "mush.png"), IGraphic::TYPE::ITEM);
            }
            x += 30;
          }
          y += 30;
        }
}

int Centipede::loop()
{
  _igraph->createWindow(std::make_pair(WIDTH, HEIGHT), "oklm");
  bool bo = false;
  _init = false;
  _meaning = false;
  while (1) {
    _igraph->clearWindow();
    if (_igraph->isKeyPressed("escape") == true)
      exit (1);
    if (_igraph->isKeyPressed("i") == true)
      return (42);
    if (_igraph->isKeyPressed("n") == true)
      return (84);
    if (_igraph->isKeyPressed("m") == true)
      return (0);
    if (!bo)
      displayMush();
    algo();
    bo = true;
    //_igraph->destroyAllArea();
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

