//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#ifndef _SHAPEN_HPP_
# define _SHAPEN_HPP_

#include <utility>
#include <unordered_map>
#include <iostream>
#include <ncurses.h>
#include <curses.h>
#include <unistd.h>
#include <math.h>
#include "IGraphic.hpp"

class ShapeN
{
public:
	ShapeN(std::pair<int, int> dim, std::pair<int, int> pos, int color,
		int type);
	~ShapeN();
	std::pair<int, int> getPos() const;
	std::pair<int, int> getDim() const;
	IGraphic::TYPE getType() const;
	bool setPos(std::pair<int, int> pos);
	bool setDim(std::pair<int, int> dim);
	void draw();
private:
	int _color;
	std::pair<int, int> _pos;
	std::pair<int, int> _dim;
	int _type;
	char _typeChar;
	std::unordered_map<int, char> _tabType;
	WINDOW *_win;
};

#endif /*_SHAPEN_HPP_*/