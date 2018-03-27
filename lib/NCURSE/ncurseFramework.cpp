//
// EPITECH PROJECT, 2018
//
// File description:
//
//

#include <iostream>
#include <cctype>
#include <exception>
#include <cstddef>
#include "NCURSE/ncurseFramework.hpp"

ncurseFramework::ncurseFramework()
	: _ch(0)
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
		{"escape", ' '},
		{"left", KEY_LEFT},
		{"right", KEY_RIGHT},
		{"up", KEY_UP},
		{"down", KEY_DOWN}
	};
}

ncurseFramework::~ncurseFramework()
{}

void ncurseFramework::init() const
{
	initscr();
	noecho();
	keypad(stdscr, TRUE);
	curs_set(FALSE);
	box(stdscr, ACS_VLINE, ACS_HLINE);
}

bool ncurseFramework::createWindow(std::pair<int, int> dim, std::string name)
{
	init();
	WINDOW *mainWin = subwin(stdscr, 0, 0, dim.first, dim.second);
	box(mainWin, ACS_VLINE, ACS_HLINE);
	mvwprintw(mainWin, 1, 1, name.c_str());
	//_WIN = newwin(nlines, ncols, y0, x0);
        // box(subWin, ACS_VLINE, ACS_HLINE);
        // mvwprintw(subWin, 2, 5, name.c_str());
	return true;
}

bool ncurseFramework::createArea(std::pair<int, int> dim, std::pair<int, int> pos,
	std::pair<std::string, std::string> nameTex, IGraphic::TYPE type)
{
	WINDOW *subWin = subwin(stdscr, pos.first, pos.second, dim.first, dim.second);
	t_area *area = new t_area;

	area->_pos = pos;
	area->_nameTex = nameTex;
	area->_type = type;
	area->_dim = dim;
	area->_win = subwin(subWin, pos.first, pos.second, dim.first, dim.second);
        box(area->_win, ACS_VLINE, ACS_HLINE);
	_areasVec.push_back(area);
	return true;
}

bool ncurseFramework::clearWindow()
{
	_ch = getch();
	refresh();
	for (unsigned int i = 0; i < _areasVec.size(); ++i)
        	wrefresh(_areasVec[i]->_win);
	return true;
}

bool ncurseFramework::loop(void (*func)(void))
{
	while (true)
		func();
	return true;
}

bool ncurseFramework::isKeyPressed(std::string key)
{
	_strLower(key);
	if (_keys.find(key) != _keys.end())
		return true;
	throw errHand::Error("ERROR: The key pressed doesn't exist!");
	return false;
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

bool ncurseFramework::displayObj()
{
	return true;
}

bool ncurseFramework::deleteArea(std::string name)
{
	for (unsigned int i = 0; i < _areasVec.size(); ++i) {
		if (name == _areasVec[i]->_nameTex.first)
			_areasVec.erase(_areasVec.begin() + i);
	}
	return true;
}

bool ncurseFramework::changeTexture(std::string name, std::string path)
{
	(void)name;
	(void)path;
	throw errHand::Error("changeTexture: obj doesn't exist in map");
	return true;
}

bool ncurseFramework::destroyWindow()
{
	endwin();
	return true;
}