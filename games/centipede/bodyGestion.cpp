//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#include "CENTIPEDE/bodyGestion.hpp"

Body::Body(std::pair<int, int> pos, Body::DIRECTION dir)
        : _dir(dir), _pos(pos)
{
        _prev = dir;
}

Body::~Body()
{}

std::pair<int, int> Body::getPos()
{
        return _pos;
}

void Body::setPos(std::pair<int, int> pos)
{
        _pos = pos;
}

void Body::setDir(Body::DIRECTION dir)
{
        _prev = _dir;
        _dir = dir;
}

Body::DIRECTION Body::getDir()
{
        return _dir;
}

Body::DIRECTION Body::getPrev()
{
        return _prev;
}

Bug::Bug(int size, std::pair<int, int> pos, Body::DIRECTION dir, IGraphic *igraph)
        : _size(size), _igraph(igraph)
{
        for(; size > 0; size--) {
                Body tmp(pos, dir);
                _part.push_back(tmp);
                pos.first += 30;
        }
        printBody();
}

Bug::~Bug()
{}

int Bug::getSize()
{
        return _size;
}

std::vector<Body> Bug::getBodies()
{
        return _part;
}


void Bug::setSize(int size)
{
        _size = size;
}

void Bug::setCent(std::vector<Bug> &cent)
{
  _cent = cent;
}

void Bug::setMush(std::vector< std::pair<int, int> > const &mush)
{
        _mush = mush;
}

void Bug::changePos()
{
        for (auto &it : _part) {
                std::pair<int, int> tmp(it.getPos());
                switch(it.getDir())
                {
                case Body::DIRECTION::RIGHT: tmp.first += 30;
                        break;
                case Body::DIRECTION::LEFT: tmp.first -= 30;
                        break;
                case Body::DIRECTION::DOWN: tmp.second += 30;
                        break;
                case Body::DIRECTION::UP: tmp.second -= 30;
                  break;
                }
                it.setPos(tmp);
        }

}

bool Bug::checkMush(Body &body, int i)
{
        for (auto &it : _mush) {
                if ((it.first == body.getPos().first + 30 || it.first == body.getPos().first - 30)
                    && it.second == body.getPos().second && i == 0)
                        return true;
                if ((it.first == body.getPos().first - 30 || it.first == body.getPos().first - 30)
                    && it.second == body.getPos().second && i == 1)
                        return true;

        }
        return false;
}

void Bug::changeDir()
{
        for (auto &it : _part) {
                if ((it.getPos().first >= WIDTH - 30 || (checkMush(it, 0) == true))
                     && it.getDir() == Body::DIRECTION::RIGHT)
                        it.setDir(Body::DIRECTION::DOWN);
                else if ((it.getPos().first <= 0  || (checkMush(it, 1) == true))
                         && it.getDir() == Body::DIRECTION::LEFT)
                        it.setDir(Body::DIRECTION::DOWN);
                else if (it.getPos().second >= HEIGHT || it.getDir() == Body::DIRECTION::DOWN) {
                        if (it.getPrev() == Body::DIRECTION::RIGHT)
                                it.setDir(Body::DIRECTION::LEFT);
                        else
                                it.setDir(Body::DIRECTION::RIGHT);
                }
        }
        changePos();
}

void Bug::splitBody(Body &body)
{
        int i = 0;
        std::pair<int, int> pos;

        for (auto &it : _part) {
                if (body.getPos() == it.getPos()) {
                        pos = it.getPos();
                        if (body.getDir() == Body::DIRECTION::RIGHT) {
                          pos.first -= 30;
                          Bug tmp(_size - i, pos, Body::DIRECTION::LEFT, _igraph);
                          _cent.push_back(tmp);
                          tmp.setCent(_cent);
                        }
                        else if (body.getDir() == Body::DIRECTION::LEFT) {
                          pos.first += 30;
                          //                          Bug tmp(_size - i, pos, Body::DIRECTION::RIGHT, _igraph);
                          //                          _cent.push_back(tmp);
                          //                          tmp.setCent(_cent);
                          _part.erase(_part.begin()+i);
                        }
                }
                //                _part.erase(_part.begin()+i);
                i++;
        }
        // for (auto &it = _part.begin() + j; it != _part.end() - 1; it++) {
        //   _part.erase(it);
        //   printf("loop??\n");}
}

void Bug::printBody()
{
        int i = 0;
        changeDir();
        for (auto &it : _part) {
                std::string cent("cen");
                cent += std::to_string(i);
                if (i == _size - 1)
                        _igraph->createArea(std::make_pair(30, 30), it.getPos()
                                            , std::make_pair(cent, "rhead.png"), IGraphic::TYPE::CHARAC);
                else
                        _igraph->createArea(std::make_pair(30, 30), it.getPos()
                                            , std::make_pair(cent, "body.png"), IGraphic::TYPE::CHARAC);
                i++;
        }
        usleep(80000);
        _igraph->clearWindow();
        _igraph->displayObj();
        for (;i >= 0; i--)
                _igraph->deleteArea("cen" + std::to_string(i));
}
