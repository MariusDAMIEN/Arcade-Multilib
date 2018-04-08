//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#include "CENTIPEDE/shoot.hpp"

Shoot::Shoot(std::pair<int, int> pos, IGraphic *igraph)
        : _pos(pos), _igraph(igraph)
{
        _init = false;
}

Shoot::~Shoot()
{}

void Shoot::setPos(std::pair<int, int> pos)
{
        _pos = pos;
}

std::pair<int, int> Shoot::getPos(void)
{
        return _pos;
}

void Shoot::moove(void)
{
        _pos.second -= 30;
}

void Shoot::setBodyPos(std::vector<Bug> &bug)
{
        _bug = bug;
}

void Shoot::checkCol()
{
        for (auto &it : _bug) {
                for (auto &it2 : it.getBodies())
                        if ((it2.getPos().first >= _pos.first && it2.getPos().first <= _pos.first + 30)
                            && (it2.getPos().second >= _pos.second
                                && it2.getPos().second <= _pos.second + 30)) {
                                it.splitBody(it2);
                                break;
                }
        }
}


void Shoot::printShoot(int i)
{
        moove();
        checkCol();
        if (!_init)
                _igraph->createArea(std::make_pair(10, 10), _pos
                                    , std::make_pair("shoot" + std::to_string(i), "blue")
                                    , IGraphic::TYPE::OBSTACLE);
        _igraph->setpos(_pos, "shoot" + std::to_string(i));
        _init = true;
}
