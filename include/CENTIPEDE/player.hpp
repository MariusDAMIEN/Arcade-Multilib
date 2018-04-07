//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#ifndef _CENTI_PLAYER_HPP_
# define _CENTI_PLAYER_HPP_

#include <iostream>
#include <utility>
#include <vector>
#include "IGraphic.hpp"
#include "CENTIPEDE/shoot.hpp"

class Player {
public:
        Player(IGraphic *, std::pair<int, int>);
        ~Player();
        void setBodyPos(std::vector<Bug> &);
        void setPos(std::pair<int, int> pos);
        std::pair<int, int> getPos();
        void shootGestion(void);
        void printShip();
        void  moove();

private:
        std::pair<int, int> _pos;
        std::vector<std::string> _name;
        std::vector<Shoot> _sho;
        std::vector<Bug> _bug;
        IGraphic *_igraph;
        bool      _init;
};

#endif /*!_CENTI_PLAYER_HPP_*/
