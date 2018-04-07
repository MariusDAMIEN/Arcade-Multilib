//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#ifndef _BODY_GESTION_HPP_
#define _BODY_GESTION_HPP_

#include <iostream>
#include <utility>
#include <map>
#include <vector>
#include <ctime>
#include <unistd.h>

#include "IGame.hpp"
#include "IGraphic.hpp"
# define WIDTH 1200
# define HEIGHT 800
# define CEN_SIZE 12

class Body
{
public:
        enum DIRECTION {
                RIGHT,
                LEFT,
                UP,
                DOWN
        };
        Body(std::pair<int, int> pos, Body::DIRECTION);
        ~Body();
        std::pair<int, int> getPos();
        DIRECTION getDir();
        DIRECTION getPrev();
        void      setPos(std::pair<int, int> pos);
        void      setDir(DIRECTION dir);
private:
        DIRECTION _dir;
        DIRECTION _prev;
        std::pair<int, int> _pos;
};

class Bug{
public:
        Bug(int size, std::pair<int, int>, Body::DIRECTION, IGraphic *igraph);
        ~Bug();
        int       getSize();
        void      setSize(int size);
        std::vector<Body> getBodies();
        void      setMush(std::vector< std::pair<int, int> > const &);
        bool      checkMush(Body &, int);
        void      changePos();
        void      changeDir();
        void      splitBody();
        void      printBody();
private:
        int _size;
        IGraphic *_igraph;
        std::vector<Body> _part;
        std::vector< std::pair<int, int> > _mush;
};


#endif /* !_BODY_GESTION_HPP_ */
