//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#ifndef _CENTI_SHOOT_HPP_
# define _CENTI_SHOOT_HPP_

#include <iostream>
#include <utility>
#include <vector>
#include "IGraphic.hpp"
#include "CENTIPEDE/bodyGestion.hpp"

class Shoot {
public:
        Shoot(std::pair<int, int>, IGraphic *igraph);
        ~Shoot();
        void setPos(std::pair<int, int> pos);
        std::pair<int, int> getPos();
        void printShoot(int i);
        void setBodyPos(std::vector<Bug> &);
        void  moove();
        void checkCol();

private:
        std::pair<int, int> _pos;
        std::vector<Bug> _bug;
        IGraphic  *_igraph;
        bool      _init;
};

#endif /*!_CENTI_PLAYER_HPP_*/
