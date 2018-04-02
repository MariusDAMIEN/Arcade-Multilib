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
}

ShapeN::ShapeN(std::pair<int, int> dim, std::pair<int, int> pos, int color,
	std::string text)
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
	// exit(dim.first);
	_dim = dim;
	_pos = pos;
	_color = color;
	_type = IGraphic::TYPE::TEXT;
	_strLower(text);
	_text = text;
}

ShapeN::~ShapeN()
{}

void ShapeN::_strLower(std::string &str)
{
	for (unsigned int i = 0; i < str.length(); ++i)
		str[i] = tolower(str[i]);
}

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

bool ShapeN::_verifFile(const std::string &file, int &x, int &y)
{
	std::fstream fs;
	std::string line;
	int posLine = y;
	int size = _dim.first * 10;
	bool isOpen = false;

	while (isOpen == false) {
		if (size < 10)
			break ;
		fs.open(DIRFONT + file + std::to_string(size), std::fstream::in);
		size -= 10;
		isOpen = fs.is_open();
	}
	if (fs.is_open()) {
		while (std::getline(fs, line)) {
			// exit(8);
			mvprintw(posLine, x, "%s", line.c_str());
			++posLine;
		}
		// exit(7);
		x = x + _dim.first;
		// exit(_dim.first);
		fs.close();
	} else {
		// std::cout << DIRFONT + file << std::endl;
		// exit(9);
		return false;
	}
	return true;
}

void ShapeN::_drawText()
{
	// int sizeC = _dim.first * 10;
	int x = _pos.first;
	int y = _pos.second;
	int div;
	// exit(x);

	for (auto c : _text) {
		if (c == '\n') {
			div = (int)ceil((_dim.first + 1) / 2);
			y = _pos.second + div + 1;
			x = _pos.first;
		} else if (c == ' ' || c == '\'') {
			mvprintw(y, x, "%c", c);
			x += 1;
		} else if (!_verifFile(std::string(1, c) + ".", x, y)) {
			// printf("%c\n", c);
			// exit(0);
			mvprintw(y, x, "%c", c);
			x += _dim.first;
		}
	}
}

void ShapeN::draw()
{
	// static int i = 0;

	if (_type == IGraphic::TYPE::TEXT) {
		// mvprintw(i, 0, "lol");
		// ++i;
		// mvprintw(0, 0, "lol");
		_drawText();
	} else {
		for (int y = _pos.second; y < (_pos.second + _dim.second); ++y) {
			for (int x = _pos.first; x < (_pos.first + _dim.first); ++x) {
				attron(COLOR_PAIR(_color));
				mvprintw(y, x, "%c", _typeChar);
				attroff(COLOR_PAIR(_color));
			}
		}
	}
	// while (1) {
	// 	timeout(1);
	// 	getch();
	// }
}