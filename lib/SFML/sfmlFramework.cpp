//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#include <unistd.h>
#include <iostream>
#include <cctype>
#include <exception>
#include <cstddef>
#include "SFML/sfmlFramework.hpp"
#include "SFML/SfmlManageSprite.hpp"
#include "ERROR/ErrorHandling.hpp"
#include "SFML/SfmlCircle.hpp"

sfmlFramework::sfmlFramework()
{
	_keys = {
		{"a", sf::Keyboard::A},
		{"b", sf::Keyboard::B},
		{"c", sf::Keyboard::C},
		{"d", sf::Keyboard::D},
		{"e", sf::Keyboard::E},
		{"f", sf::Keyboard::F},
		{"g", sf::Keyboard::G},
		{"h", sf::Keyboard::H},
		{"i", sf::Keyboard::I},
		{"j", sf::Keyboard::J},
		{"k", sf::Keyboard::K},
		{"m", sf::Keyboard::M},
		{"n", sf::Keyboard::N},
		{"o", sf::Keyboard::O},
		{"p", sf::Keyboard::P},
		{"q", sf::Keyboard::Q},
		{"r", sf::Keyboard::R},
		{"s", sf::Keyboard::S},
		{"t", sf::Keyboard::T},
		{"u", sf::Keyboard::U},
		{"v", sf::Keyboard::V},
		{"w", sf::Keyboard::W},
		{"x", sf::Keyboard::X},
		{"y", sf::Keyboard::Y},
		{"z", sf::Keyboard::Z},
		{"escape", sf::Keyboard::Escape},
		{"left", sf::Keyboard::Left},
		{"right", sf::Keyboard::Right},
		{"up", sf::Keyboard::Up},
		{"down", sf::Keyboard::Down}
	};
	_colors = {
		{"black", sf::Color::Black},
		{"white", sf::Color::White},
		{"red", sf::Color::Red},
		{"green", sf::Color::Green},
		{"blue", sf::Color::Blue},
		{"yellow", sf::Color::Yellow},
		{"magenta", sf::Color::Magenta},
		{"cyan", sf::Color::Cyan},
		{"transparent", sf::Color::Transparent}
	};
	_keys2 = {
		{"close", sf::Event::Closed},
		{"resize", sf::Event::Resized}
	};
	// rectangle
	_pointerFunc.insert(std::make_pair(0, std::bind(&sfmlFramework::_rectangle,
		this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3,
		std::placeholders::_4)));
	// text
	_pointerFunc.insert(std::make_pair(4, std::bind(&sfmlFramework::_text,
		this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3,
		std::placeholders::_4)));
	// circle
	_pointerFunc.insert(std::make_pair(1, std::bind(&sfmlFramework::_circle,
		this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3,
		std::placeholders::_4)));
	_pointerFunc.insert(std::make_pair(2, std::bind(&sfmlFramework::_rectangle,
		this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3,
		std::placeholders::_4)));
	_pointerFunc.insert(std::make_pair(3, std::bind(&sfmlFramework::_rectangle,
		this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3,
		std::placeholders::_4)));
	_pointerFunc.insert(std::make_pair(5, std::bind(&sfmlFramework::_rectangle,
		this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3,
		std::placeholders::_4)));
	_pointerFunc.insert(std::make_pair(6, std::bind(&sfmlFramework::_rectangle,
		this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3,
		std::placeholders::_4)));
}

sfmlFramework::~sfmlFramework()
{}

bool sfmlFramework::createWindow(std::pair<int, int> dim, std::string name)
{
	_window = std::make_unique<sf::RenderWindow>(sf::VideoMode(dim.first, dim.second), name);
	if (_window->isOpen()) {
		_window->pollEvent(_event);
		return true;
	}
	return false;
}

bool sfmlFramework::clearWindow()
{
	_window->clear();
	return true;
}

void sfmlFramework::_rectangle(std::pair<int, int> dim, std::pair<int, int> pos,
	std::pair<std::string, std::string> nameTex, TYPE type)
{
	SfmlSquare *tmp = new SfmlSquare(sf::Vector2f(dim.first, dim.second), _colors[nameTex.second]);

	_mapDim[nameTex.first] = dim;
	_mapPos[nameTex.first] = pos;
	_mapTex[nameTex.first] = nameTex.second;
	_mapType[nameTex.first] = type;
	tmp->setPos(pos.first, pos.second);
	// _mapDownCast[nameTex.first] = tmp;
	_mapDownCast.push_back(std::make_pair(nameTex.first, tmp));
}

void sfmlFramework::_text(std::pair<int, int> dim, std::pair<int, int> pos,
	std::pair<std::string, std::string> nameTex, TYPE type)
{
	SfmlText *tmp = new SfmlText(dim, pos, nameTex.second);

	_mapDim[nameTex.first] = dim;
	_mapPos[nameTex.first] = pos;
	_mapTex[nameTex.first] = nameTex.second;
	_mapType[nameTex.first] = type;
	// _mapDownCast[nameTex.first] = tmp;
	_mapDownCast.push_back(std::make_pair(nameTex.first, tmp));
}

void sfmlFramework::_circle(std::pair<int, int> dim, std::pair<int, int> pos,
	std::pair<std::string, std::string> nameTex, TYPE type)
{
	SfmlCircle *tmp = new SfmlCircle(dim, pos, _colors[nameTex.second]);

	_mapDim[nameTex.first] = dim;
	_mapPos[nameTex.first] = pos;
	_mapTex[nameTex.first] = nameTex.second;
	_mapType[nameTex.first] = type;
	// _mapDownCast[nameTex.first] = tmp;
	_mapDownCast.push_back(std::make_pair(nameTex.first, tmp));
}

void sfmlFramework::_makeSpriteTex(std::pair<int, int> dim, std::pair<int, int> pos,
	std::pair<std::string, std::string> nameTex, TYPE type)
{
	SfmlManageSprite *tmp = new SfmlManageSprite(nameTex.second, dim, pos);

	(void)type;
	_mapDim[nameTex.first] = dim;
	_mapPos[nameTex.first] = pos;
	_mapTex[nameTex.first] = nameTex.second;
	_mapType[nameTex.first] = -1;
	tmp->setPos(pos.first, pos.second);
	// _mapDownCast[nameTex.first] = tmp;
	_mapDownCast.push_back(std::make_pair(nameTex.first, tmp));
}

bool sfmlFramework::createArea(std::pair<int, int> dim, std::pair<int, int> pos,
	std::pair<std::string, std::string> nameTex, IGraphic::TYPE type)
{
	if (_mapType.find(nameTex.first) == _mapType.end() &&
		(_colors.find(nameTex.second) != _colors.end() || type == IGraphic::TYPE::TEXT))
		_pointerFunc[type](dim, pos, nameTex, type);
	else if (_mapType.find(nameTex.first) == _mapType.end())
		_makeSpriteTex(dim, pos, nameTex, type);
	else
		throw errHand::Error("This area is already created");
	return true;
}

template<class T>
std::pair<int, int> sfmlFramework::_getPosT(std::string name)
{
	int i = 0;
	for (std::vector<std::pair<std::string, IShape *>>::iterator it = _mapDownCast.begin();
		it != _mapDownCast.end(); ++it) {
		if (it->first == name)
			break ;
		++i;
	}
	T *tmp = static_cast<T *>(_mapDownCast[i].second);

	return tmp->getPos();
}

std::pair<int, int> sfmlFramework::getpos(std::string name)
{
	if (_mapType.find(name) != _mapType.end()) {
		switch (_mapType[name]) {
			case -1:
				return _getPosT<SfmlManageSprite>(name);
			case IGraphic::TYPE::RECT: case IGraphic::TYPE::CHARAC:
			case IGraphic::TYPE::ENEMY: case IGraphic::TYPE::ITEM:
			case IGraphic::TYPE::OBSTACLE:
				return _getPosT<SfmlSquare>(name);
			case IGraphic::TYPE::TEXT:
				return _getPosT<SfmlText>(name);
			case IGraphic::TYPE::CICLE:
				return _getPosT<SfmlCircle>(name);
			default:
  				break ;
		}
	} else
		throw errHand::Error("getPos object don't exist");
	return std::make_pair(0, 0);
}

template<class T>
std::pair<int, int> sfmlFramework::_getDimT(std::string name)
{
	int i = 0;
	for (std::vector<std::pair<std::string, IShape *>>::iterator it = _mapDownCast.begin();
		it != _mapDownCast.end(); ++it) {
		if (it->first == name)
			break ;
		++i;
	}
	T *tmp = static_cast<T *>(_mapDownCast[i].second);

	return tmp->getDim();
}

std::pair<int, int> sfmlFramework::getdim(std::string name)
{
	if (_mapType.find(name) != _mapType.end()) {
		switch (_mapType[name]) {
			case -1:
				return _getDimT<SfmlManageSprite>(name);
			case IGraphic::TYPE::RECT: case IGraphic::TYPE::CHARAC:
			case IGraphic::TYPE::ENEMY: case IGraphic::TYPE::ITEM:
			case IGraphic::TYPE::OBSTACLE:
				return _getDimT<SfmlSquare>(name);
			case IGraphic::TYPE::TEXT:
				return _getDimT<SfmlText>(name);
			case IGraphic::TYPE::CICLE:
				return _getDimT<SfmlCircle>(name);
			default:
  				break ;
		}
	} else
		throw errHand::Error("getDim object don't exist");
	return std::make_pair(0, 0);
}

IGraphic::TYPE sfmlFramework::getType(std::string name)
{
	if (_mapType.find(name) != _mapType.end())
		return (IGraphic::TYPE)_mapType[name];
	throw errHand::Error("getType: this area doesn't exist");
}

template<class T>
bool sfmlFramework::_setPosT(std::pair<int, int> pos, std::string name)
{
	int i = 0;
	for (std::vector<std::pair<std::string, IShape *>>::iterator it = _mapDownCast.begin();
		it != _mapDownCast.end(); ++it) {
		if (it->first == name)
			break ;
		++i;
	}
	T *tmp = static_cast<T *>(_mapDownCast[i].second);

	return tmp->setPos(pos.first, pos.second);
}

bool sfmlFramework::setpos(std::pair<int, int> pos, std::string name)
{
	if (_mapType.find(name) != _mapType.end()) {
		switch (_mapType[name]) {
			case -1:
				return _setPosT<SfmlManageSprite>(pos, name);
			case IGraphic::TYPE::RECT: case IGraphic::TYPE::CHARAC:
			case IGraphic::TYPE::ENEMY: case IGraphic::TYPE::ITEM:
			case IGraphic::TYPE::OBSTACLE:
				return _setPosT<SfmlSquare>(pos, name);
			case IGraphic::TYPE::TEXT:
				return _setPosT<SfmlText>(pos, name);
			case IGraphic::TYPE::CICLE:
				return _setPosT<SfmlCircle>(pos, name);
			default:
  				break ;
		}
	} else
		throw errHand::Error("setpos object don't exist");
	return false;
}

template<class T>
bool sfmlFramework::_setDimT(std::pair<int, int> dim, std::string name)
{
	int i = 0;
	for (std::vector<std::pair<std::string, IShape *>>::iterator it = _mapDownCast.begin();
		it != _mapDownCast.end(); ++it) {
		if (it->first == name)
			break ;
		++i;
	}
	T *tmp = static_cast<T *>(_mapDownCast[i].second);

	return tmp->setDim(dim.first, dim.second);
}

bool sfmlFramework::setdim(std::pair<int, int> dim, std::string name)
{
	if (_mapType.find(name) != _mapType.end()) {
		switch (_mapType[name]) {
			case -1:
				return _setDimT<SfmlManageSprite>(dim, name);
			case IGraphic::TYPE::RECT: case IGraphic::TYPE::CHARAC:
			case IGraphic::TYPE::ENEMY: case IGraphic::TYPE::ITEM:
			case IGraphic::TYPE::OBSTACLE:
				return _setDimT<SfmlSquare>(dim, name);
			case IGraphic::TYPE::TEXT:
				return _setDimT<SfmlText>(dim, name);
			case IGraphic::TYPE::CICLE:
				return _setDimT<SfmlCircle>(dim, name);
			default:
  				break ;
		}
	} else
		throw errHand::Error("setdim object don't exist");
	return false;
}

bool sfmlFramework::isKeyPressed(std::string key)
{
	_strLower(key);
	if (_keys.find(key) != _keys.end() || _keys2.find(key) != _keys2.end()) {
		usleep(2000);
		if (sf::Keyboard::isKeyPressed(_keys[key])) {
			usleep(97000);
			return true;
		}
	} else
		throw errHand::Error("key doesn't exist in map _keys");
	return false;
}

void sfmlFramework::_strLower(std::string &str)
{
	for (unsigned int i = 0; i < str.length(); ++i)
		str[i] = tolower(str[i]);
}

template<class T>
bool sfmlFramework::_displayObjSfml(std::string name)
{
	int i = 0;
	for (std::vector<std::pair<std::string, IShape *>>::iterator it = _mapDownCast.begin();
		it != _mapDownCast.end(); ++it) {
		if (it->first == name)
			break ;
		++i;
	}
	T *tmp = static_cast<T *>(_mapDownCast[i].second);

	_window->draw(tmp->getShape());
	return true;
}

bool sfmlFramework::displayObj()
{
	for (auto &it : _mapDownCast) {
		switch (_mapType[it.first]) {
			case -1:
				_displayObjSfml<SfmlManageSprite>(it.first);
				break ;
			case IGraphic::TYPE::RECT: case IGraphic::TYPE::CHARAC:
			case IGraphic::TYPE::ENEMY: case IGraphic::TYPE::ITEM:
			case IGraphic::TYPE::OBSTACLE:
				_displayObjSfml<SfmlSquare>(it.first);
				break ;
			case IGraphic::TYPE::TEXT:
				_displayObjSfml<SfmlText>(it.first);
				break ;
			case IGraphic::TYPE::CICLE:
				_displayObjSfml<SfmlCircle>(it.first);
				break ;
			default:
  				break ;
		}
	}
	_window->display();
	return true;
}

bool sfmlFramework::deleteArea(std::string name)
{
	if (_mapDim.find(name) != _mapDim.end()) {
		_mapDim.erase(name);
		_mapPos.erase(name);
		_mapTex.erase(name);
		_mapType.erase(name);
		// delete _mapDownCast[i].second;
		for (std::vector<std::pair<std::string, IShape *>>::iterator it = _mapDownCast.begin();
			it != _mapDownCast.end(); ++it) {
			if (it->first == name) {
				_mapDownCast.erase(it);
				break ;
			}
		}
		// delete _mapDownCast[name];
		// _mapDownCast.erase(name);
	} else
		return false;
		// throw errHand::Error("deleteArea: obj doesn't exist in map");
	return true;
}

bool sfmlFramework::changeTexture(std::string name, std::string path)
{
	if (_mapTex.find(name) != _mapTex.end()) {
		if ((_mapType[name] == -1 && _colors.find(path) == _colors.end()) ||
			(_mapType[name] != -1 && _colors.find(path) != _colors.end()))
			_mapTex[name] = path;
		else
			throw errHand::Error("changeTexture: you can't change\
				color in texture or texture in color");
	}
	else
		throw errHand::Error("changeTexture: obj doesn't exist in map");
	return true;
}

bool sfmlFramework::destroyWindow()
{
	_window->close();
	return true;
}

bool sfmlFramework::destroyAllArea()
{
	_mapDownCast.clear();
	_mapType.clear();
	_mapTex.clear();
	_mapPos.clear();
	_mapDim.clear();
	return true;
}

extern "C" IGraphic *create()
{
	return new sfmlFramework();
}

extern "C" void destroy(IGraphic* p) {
	delete p;
}
