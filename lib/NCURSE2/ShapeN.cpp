//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#include "NCURSE2/ShapeN.hpp"

ShapeN::ShapeN(std::pair<int, int> dim, std::pair<int, int> pos, int color,
	int type)
{
	_tabType = {
		{0, 'x'},
		{1, 'o'},
		{2, 'I'},
		{3, '!'},
		{4, 'x'},
		{5, '$'},
		{6, '#'}
	};
	_dim = dim;
	_pos = pos;
	_color = color;
	_type = type;
	_typeChar = _tabType[type];
	// _win = win;
	// _win = newwin(1200, 800, 0, 0);
}

ShapeN::~ShapeN()
{}

std::pair<int, int> ShapeN::getPos() const
{
	return _pos;
}

std::pair<int, int> ShapeN::getDim() const
{
	return _dim;
}

IGraphic::TYPE ShapeN::getType() const
{
	return (IGraphic::TYPE)_type;
}

bool ShapeN::setDim(std::pair<int, int> dim)
{
	if (dim.first < 10)
		dim.first = 10;
	if (dim.second < 20)
		dim.second = 20;
	dim.first = (int)floor((dim.first) / 10);
	dim.second = (int)floor((dim.second) / 20);
	if (dim.first < 1 || dim.second < 1)
		return false;
	_dim = dim;
	return true;
}

bool ShapeN::setPos(std::pair<int, int> pos)
{
	if (pos.first < 10)
		pos.first = 10;
	if (pos.second < 20)
		pos.second = 20;
	pos.first = (int)floor((pos.first) / 10);
	pos.second = (int)floor((pos.second) / 20);
	if (pos.first < 1 || pos.second < 1)
		return false;
	_pos.first = pos.first;
	_pos.second = pos.second;
	return true;
}

void ShapeN::draw()
{
	for (int y = _pos.second; y < (_pos.second + _dim.second); ++y) {
		for (int x = _pos.first; x < (_pos.first + _dim.first); ++x) {
			attron(COLOR_PAIR(_color));
			mvprintw(y, x, "%c", _typeChar);
			attroff(COLOR_PAIR(_color));
		}
	}
	// while (1) {
	// 	timeout(1);
	// 	getch();
	// }
}