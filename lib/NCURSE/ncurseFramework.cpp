//
// EPITECH PROJECT, 2018
//
// File description:
//
//



#include <cstdlib>
#include <cstring>
//#include <iostream>
#include <cctype>
#include <exception>
#include <cstddef>
#include "NCURSE/ncurseFramework.hpp"

void ncurseFramework::init_keys()
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
		{"left", KEY_LEFT},
		{"right", KEY_RIGHT},
		{"up", KEY_UP},
		{"down", KEY_DOWN},
		{"escape", 27}
	};
}
void ncurseFramework::init_colors()
{
	init_pair(1, COLOR_BLACK, COLOR_WHITE);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_BLUE, COLOR_BLACK);
	init_pair(4, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(5, COLOR_CYAN, COLOR_BLACK);
	init_pair(6, COLOR_WHITE, COLOR_BLACK);
	init_pair(7, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(8, COLOR_RED, COLOR_BLACK);
	init_pair(9, COLOR_RED, COLOR_BLUE);
}

ncurseFramework::ncurseFramework()
	: _ch(0), _mainWin(NULL)
{
	init_keys();
	//attron(COLOR_PAIR(3));
	mvprintw(1, 1, "wsh magl bien??");
}

ncurseFramework::~ncurseFramework()
{}

IGraphic::TYPE ncurseFramework::getType(std::string name)
{
	for (unsigned int i = 0; i < _areasVec.size(); ++i) {
		if (name == _areasVec[i]->_nameTex.first)
			return (_areasVec[i]-> _type);
	}
	return TYPE::CHARAC;
}

void ncurseFramework::init()
{
//	int x,y = 0;
	// printf("%d  %d\n");
	// getmaxyx(stdscr, x ,y);
	initscr();
	noecho();
	keypad(stdscr, TRUE);
	curs_set(FALSE);
	start_color();
	init_colors();
	box(stdscr, ACS_VLINE, ACS_HLINE);
}

void ncurseFramework::crWin(std::pair<int, int> dim)
{
	int y = 0;
	int x;
	std::string str = "";
	_mainWin = (char **)malloc(sizeof(char *) * (dim.second + 1));

	if (_mainWin == NULL)
		throw errHand::Error("Err maloc.");
	
	for (; y < (dim.second / 10); ++y) {
		_mainWin[y] = (char *)malloc(sizeof(char) * dim.first);
		if (_mainWin[y] == NULL)
			throw errHand::Error("Err maloc.");
		x = 0;
		for (; x < (dim.first / 10); ++x) {
			_mainWin[y][x] = ' ';
			if (y == 0 || y == dim.second / 10 - 1)
				_mainWin[y][x] = '#';
			if (x == 0 || x == dim.first / 10 - 1)
				_mainWin[y][x] = '#';
		}
		_mainWin[y][x] = '\0';
	}
	_mainWin[y] = NULL;
}

void ncurseFramework::printWin()
{
	unsigned int i = 0;

	attron(COLOR_PAIR(4));
	do {
		mvprintw(2 + i, 3, "%s\n", _mainWin[i]);
		++i;
	} while (_mainWin[i]);
	attroff(COLOR_PAIR(4));
}

bool ncurseFramework::createWindow(std::pair<int, int> dim, std::string name)
{
	init();
	crWin(dim);
	_nameWin = name;
	return true;
}

bool ncurseFramework::createArea(std::pair<int, int> dim, std::pair<int, int> pos,
				 std::pair<std::string, std::string> nameTex, IGraphic::TYPE type)
{
	t_area *area = new t_area;

	if (_areasVec.size() != 0) {
		for (unsigned int i = 0; i < _areasVec.size(); ++i) {
			if (nameTex == _areasVec[i]->_nameTex)
				throw errHand::Error("error while loading program.");
		}
	}
	area->_pos = pos;
	area->_nameTex = nameTex;
	area->_type = type;
	area->_dim = dim;
	_areasVec.push_back(area);
	return true;
}

bool ncurseFramework::clearWindow()
{
	timeout(1);
	mvprintw(1, COLS / 2, _nameWin.c_str());
	printWin();
	_ch = getch();
	refresh();
	return true;
}

bool ncurseFramework::isKeyPressed(std::string key)
{
	_strLower(key);
	if (_keys[key] == _ch)
		return true;
	return false;
}

bool ncurseFramework::deleteArea(std::string name)
{
	for (unsigned int i = 0; i < _areasVec.size(); ++i) {
		if (name == _areasVec[i]->_nameTex.first)
			_areasVec.erase(_areasVec.begin() + i);
	}
	return true;
}

void ncurseFramework::_strLower(std::string &str)
{
	for (unsigned int i = 0; i < str.length(); ++i)
		str[i] = tolower(str[i]);
}

bool ncurseFramework::setpos(std::pair<int, int> pos, std::string name)
{
	for (unsigned int i = 0; i < _areasVec.size(); ++i) {
		if (name == _areasVec[i]->_nameTex.first) {
			_areasVec[i]->_pos.first = pos.first;
			_areasVec[i]->_pos.second = pos.second;
			return true;
		}
	}
	return false;
}
bool ncurseFramework::setdim(std::pair<int, int> dim, std::string name)
{
	for (unsigned int i = 0; i < _areasVec.size(); ++i) {
		if (name == _areasVec[i]->_nameTex.first) {
			_areasVec[i]->_dim.first = dim.first;
			_areasVec[i]->_dim.second = dim.second;
			return true;
		}
	}
	return false;
}

std::pair<int, int> ncurseFramework::getpos(std::string name)
{
	for (unsigned int i = 0; i < _areasVec.size(); ++i) {
		if (name == _areasVec[i]->_nameTex.first)
			return _areasVec[i]->_pos;
	}
	throw errHand::Error("Create an object before to get his dimention.");
}

std::pair<int, int> ncurseFramework::getdim(std::string name)
{
	for (unsigned int i = 0; i < _areasVec.size(); ++i) {
		if (name == _areasVec[i]->_nameTex.first)
			return _areasVec[i]->_dim;
	}
	throw errHand::Error("Create an object before to get his dimention.");
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

int maplen(char **map) {
	int i = 0;

	for (; map[i]; ++i);
	return i;
}

void ncurseFramework::modifWin()
{
	int x_tx,y_tx = 0;

	for (unsigned int i = 0; i < _areasVec.size(); ++i) {
		if (((_areasVec[i]->_dim.second + _areasVec[i]->_pos.second) / 10) > maplen(_mainWin)) {
			printf(">>>>>>>>>\n");
			//exit(84);
			throw errHand::Error("ERROR: Window overflow");
			printf(">>>>>>>>>\n");
			
		} else if (_areasVec[i]->_type == IGraphic::TYPE::TEXT) {
			y_tx = _areasVec[i]->_pos.first / 10;
			x_tx = _areasVec[i]->_pos.second / 10;
			for (unsigned int inc = 0; inc < strlen(_areasVec[i]->_nameTex.second.c_str()); ++inc)
				_mainWin[x_tx][y_tx++] = _areasVec[i]->_nameTex.second.c_str()[inc];
		} else {
			for (int y = _areasVec[i]->_pos.second / 10; y < ((_areasVec[i]->_dim.second + _areasVec[i]->_pos.second) / 10); ++y) {
				for (int x = _areasVec[i]->_pos.first / 10; x < ((_areasVec[i]->_dim.first + _areasVec[i]->_pos.first) / 10); ++x)
				{
					_mainWin[y][x] = ' ';
					if (y == _areasVec[i]->_pos.second / 10 || y == ((_areasVec[i]->_dim.second + _areasVec[i]->_pos.second) / 10) - 1)
						_mainWin[y][x] = '#';
					if (x == _areasVec[i]->_pos.first / 10 || x == ((_areasVec[i]->_dim.first + _areasVec[i]->_pos.first) / 10) - 1)
						_mainWin[y][x] = '#';
					
				}
			}
		}
	}
}

bool ncurseFramework::displayObj()
{
	modifWin();
	return true;
}

extern "C" IGraphic *create()
{
	return (new ncurseFramework());
}