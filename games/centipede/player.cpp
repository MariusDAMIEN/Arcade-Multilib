//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#include "CENTIPEDE/player.hpp"

Player::Player(IGraphic *igraph, std::pair<int, int> pos)
        : _pos(pos), _igraph(igraph)
{
        _name.push_back("ship");
        _name.push_back("ship1");
        _init = false;
}

Player::~Player()
{}

void Player::setPos(std::pair<int, int> pos)
{
        _pos = pos;
}

void Player::setBodyPos(std::vector<Bug> &bug)
{
        _bug = bug;
}


std::pair<int, int> Player::getPos(void)
{
        return _pos;
}

void Player::shootGestion(void)
{
        int i = 0;

        for (auto &it : _sho) {
                it.setBodyPos(_bug);
                it.printShoot(i);
                i++;
        }
}

void Player::moove(void)
{
        if (_igraph->isKeyPressed("right") == true) {
                _pos.first += 30;
        }
        if (_igraph->isKeyPressed("left") == true) {
                _pos.first -= 30;
        }
        if (_igraph->isKeyPressed("down") == true) {
                _pos.second += 30;
        }
        if (_igraph->isKeyPressed("up") == true) {
                _pos.second -= 30;
        }
        if (_igraph->isKeyPressed("v") == true) {
                Shoot sho(_pos, _igraph);
                _sho.push_back(sho);
        }

}

void Player::printShip()
{
        moove();
        shootGestion();
        if (!_init)
                _igraph->createArea(std::make_pair(50, 30), _pos
                                    , std::make_pair("ship", "ship.png"), IGraphic::TYPE::RECT);
        _igraph->setpos(_pos, "ship");
        _init = true;
}
