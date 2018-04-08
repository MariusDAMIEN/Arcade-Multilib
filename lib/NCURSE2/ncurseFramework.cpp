//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#include "NCURSE2/ncurseFramework.hpp"
#include "ERROR/ErrorHandling.hpp"

ncurseFramework::ncurseFramework()
{
	_keys = {
		{"a", 'a'},
		{"b", 'b'},
		{"c", 'c'},
		{"d", 'd'},
		{"e", 'e'},
		{"f", 'f'},
		{"g", 'g'},
		{"h", 'h'},
		{"i", 'i'},
		{"j", 'j'},
		{"k", 'k'},
		{"l", 'l'},
		{"m", 'm'},
		{"n", 'n'},
		{"o", 'o'},
		{"p", 'p'},
		{"q", 'q'},
		{"r", 'r'},
		{"s", 's'},
		{"t", 't'},
		{"u", 'u'},
		{"v", 'v'},
		{"w", 'w'},
		{"x", 'x'},
		{"y", 'y'},
		{"z", 'z'},
		{"space", ' '},
		{"left", 4},
		{"right", 5},
		{"up", 3},
		{"down", 2},
		{"escape", 27}
	};
	_colors = {
		{"red", 1},
		{"green", 2},
		{"yellow", 3},
		{"blue", 4},
		{"magenta", 5},
		{"cyan", 6},
		{"white", 7}
	};
}

ncurseFramework::~ncurseFramework()
{}

bool ncurseFramework::createWindow(std::pair<int, int> dim, std::string name)
{
	initscr();
	start_color();
	init_pair(1,  COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_BLUE, COLOR_BLACK);
	init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(6, COLOR_CYAN, COLOR_BLACK);
	init_pair(7, COLOR_WHITE, COLOR_BLACK);
	init_pair(8, COLOR_BLACK, COLOR_BLACK);
	keypad(stdscr, TRUE);
	refresh();
	noecho();
	if (dim.first < 10)
		dim.first = 10;
	if (dim.second < 20)
		dim.second = 20;
	_width = (int)floor((dim.first) / 10);
	_height = (int)floor((dim.second) / 20);
	if (_width < 1 || _height < 1)
		throw errHand::Error("createWindow: width:" + std::to_string(_width)
			+ "or height:" + std::to_string(_height) + "too little");
	_width += 2;
	_height += 2;
	_nameWindow = name;
	for (int y = 0; y < _height; ++y) {
		mvprintw(y, 0, "x");
		for (int x = 0; x < _width; ++x) {
			if (y == 0 || y == _height - 1) {
				attron(COLOR_PAIR(7));
				mvprintw(y, x, "x");
				attroff(COLOR_PAIR(7));
			}
		}
		mvprintw(y, _width - 1, "x");
	}
	// while (1) {
	// 	timeout(1);
	// 	getch();
	// }
	return true;
}

bool ncurseFramework::clearWindow()
{
	refresh();
	timeout(1);
	_ch = getch();
	for (int y = 1; y < _height - 1; ++y) {
		for (int x = 1; x < _width - 1; ++x) {
			attron(COLOR_PAIR(8));
			mvprintw(y, x, " ");
			attroff(COLOR_PAIR(8));
		}
	}
	// refresh();
	return true;
}

void ncurseFramework::_makeShape(std::pair<int, int> dim, std::pair<int, int> pos,
	std::pair<std::string, std::string> nameTex, IGraphic::TYPE type)
{
	ShapeN *tmp;

	if (dim.first < 10)
		dim.first = 10;
	if (dim.second < 20)
		dim.second = 20;
	if (pos.first < 10)
		pos.first = 10;
	if (pos.second < 20)
		pos.second = 20;
	pos.first = (int)floor((pos.first) / 10);
	pos.second = (int)floor((pos.second) / 20);
	dim.first = (int)floor((dim.first) / 10);
	dim.second = (int)floor((dim.second) / 20);
	if (pos.first < 1 || pos.second < 1 || dim.first < 1 || dim.second < 1)
		throw errHand::Error("createArea: dim or pos too little");
	pos.first += 1;
	pos.second += 1;
	tmp = new ShapeN(dim, pos, _colors[nameTex.second], type);
	_mapShape.push_back(std::make_pair(nameTex.first, tmp));
}

void ncurseFramework::_makeText(std::pair<int, int> dim, std::pair<int, int> pos,
	std::pair<std::string, std::string> nameTex, IGraphic::TYPE type)
{
	ShapeN *tmp;

	(void)type;
	if (pos.first < 10)
		pos.first = 10;
	if (pos.second < 20)
		pos.second = 20;
	if (dim.first < 20)
		dim.first = 20;
	if (dim.second < 20)
		dim.second = 20;
	pos.first = (int)floor((pos.first) / 10);
	pos.second = (int)floor((pos.second) / 20);
	dim.first = (int)floor((dim.first) / 20);
	dim.second = (int)floor((dim.second) / 20);
	if (pos.first < 1 || pos.second < 1 || dim.first < 1 || dim.second < 1)
		throw errHand::Error("createArea: dim or pos too little");
	pos.first += 1;
	pos.second += 1;
	// printf("%d %d %d %d\n", pos.first, pos.second, dim.first, dim.second);
	tmp = new ShapeN(dim, pos, _colors[nameTex.second], nameTex.second);
	_mapShape.push_back(std::make_pair(nameTex.first, tmp));
}

bool ncurseFramework::createArea(std::pair<int, int> dim, std::pair<int, int> pos,
	std::pair<std::string, std::string> nameTex, IGraphic::TYPE type)
{
	for (auto it : _mapShape) {
		if (it.first == nameTex.first)
			return false;
	}
	if (type != IGraphic::TYPE::TEXT) {
		if (_colors.find(nameTex.second) != _colors.end())
			_makeShape(dim, pos, nameTex, type);
		else {
			nameTex.second = "white";
			_makeShape(dim, pos, nameTex, type);
			return true;
		}
	} else if (type == IGraphic::TYPE::TEXT) {
		_makeText(dim, pos, nameTex, type);
	}else
		return false;
	return true;
}

std::pair<int, int> ncurseFramework::getpos(std::string name)
{
	for (auto it : _mapShape) {
		if (it.first == name)
			return it.second->getPos();
	}
	return std::make_pair(-1, -1);
}

std::pair<int, int> ncurseFramework::getdim(std::string name)
{
	for (auto it : _mapShape) {
		if (it.first == name)
			return it.second->getDim();
	}
	return std::make_pair(0, 0);
}

IGraphic::TYPE ncurseFramework::getType(std::string name)
{
	for (auto it : _mapShape) {
		if (it.first == name)
			return it.second->getType();
	}
	return (IGraphic::TYPE)-1;
}

bool ncurseFramework::setpos(std::pair<int, int> pos, std::string name)
{
	for (auto it : _mapShape) {
		if (it.first == name) {
			return it.second->setPos(pos);
		}
	}
	return false;
}

bool ncurseFramework::setdim(std::pair<int, int> dim, std::string name)
{
	for (auto it : _mapShape) {
		if (it.first == name) {
			return it.second->setDim(dim);
		}
	}
	return true;
}

bool ncurseFramework::isKeyPressed(std::string key)
{
	// char c;

	// timeout(1);
	// c = getch();
	if (_keys.find(key) != _keys.end() && _keys[key] == _ch)
		return true;
	return false;
}

bool ncurseFramework::displayObj()
{
	for (auto it : _mapShape) {
		it.second->draw();
	}
	// refresh();
	// timeout(1);
	// getch();
	return true;
}

bool ncurseFramework::deleteArea(std::string name)
{
	for (std::vector<std::pair<std::string, ShapeN *>>::iterator
		it = _mapShape.begin(); it != _mapShape.end(); ++it) {
		if (it->first == name) {
			_mapShape.erase(it);
			return true;
		}
	}
	return false;
}

bool ncurseFramework::changeTexture(std::string name, std::string path)
{
	(void)name;
	(void)path;
	return true;
}

bool ncurseFramework::destroyWindow()
{
	endwin();
	return true;
}

bool ncurseFramework::destroyAllArea()
{
	_mapShape.clear();
	return true;
}

extern "C" IGraphic *create()
{
	return new ncurseFramework();
}

extern "C" void destroy(IGraphic* p) {
	delete p;
}
