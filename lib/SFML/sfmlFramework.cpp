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
#include "SFML/sfmlFramework.hpp"
#include "ERROR/ErrorHandling.hpp"

// sfmlFramework::sfmlFramework()
// {
// 	std::cout << "framwork sfml creating" << std::endl;
// 	_key = {
// 		{"a", sf::Keyboard::A},
// 		{"b", sf::Keyboard::B},
// 		{"c", sf::Keyboard::C},
// 		{"d", sf::Keyboard::D},
// 		{"e", sf::Keyboard::E},
// 		{"f", sf::Keyboard::F},
// 		{"g", sf::Keyboard::G},
// 		{"h", sf::Keyboard::H},
// 		{"i", sf::Keyboard::I},
// 		{"j", sf::Keyboard::J},
// 		{"m", sf::Keyboard::M},
// 		{"n", sf::Keyboard::N},
// 		{"o", sf::Keyboard::O},
// 		{"p", sf::Keyboard::P},
// 		{"q", sf::Keyboard::Q},
// 		{"r", sf::Keyboard::R},
// 		{"s", sf::Keyboard::S},
// 		{"t", sf::Keyboard::T},
// 		{"u", sf::Keyboard::U},
// 		{"v", sf::Keyboard::V},
// 		{"w", sf::Keyboard::W},
// 		{"x", sf::Keyboard::X},
// 		{"y", sf::Keyboard::Y},
// 		{"z", sf::Keyboard::Z},
// 		{"escape", sf::Keyboard::Escape},
// 		{"left", sf::Keyboard::Left},
// 		{"right", sf::Keyboard::Right},
// 		{"up", sf::Keyboard::Up},
// 		{"down", sf::Keyboard::Down}
// 	};
// 	_colors = {
// 		{"black", sf::Color::Black},
// 		{"white", sf::Color::White},
// 		{"red", sf::Color::Red},
// 		{"green", sf::Color::Green},
// 		{"blue", sf::Color::Blue},
// 		{"yellow", sf::Color::Yellow},
// 		{"magenta", sf::Color::Magenta},
// 		{"cyan", sf::Color::Cyan},
// 		{"transparent", sf::Color::Transparent}
// 	};
// 	// _cast = {
// 	// 	{"rectangle", std::bind(&sfmlFramework::_getRectangle, this, std::placeholders::_1)}
// 	// };
// 	_cast.insert(std::make_pair("rectangle", std::bind(&sfmlFramework::_getRectangle, this)));
// }

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
	_pointerFunc.insert(std::make_pair(0, std::bind(&sfmlFramework::_rectangle,
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
	SfmlSquare *tmp = new SfmlSquare(sf::Vector2f(dim.first, dim.second), sf::Color::Red);

	_mapDim[nameTex.first] = dim;
	_mapPos[nameTex.first] = pos;
	_mapTex[nameTex.first] = nameTex.second;
	_mapType[nameTex.first] = type;
	tmp->setPos(pos.first, pos.second);
	_mapDownCast[nameTex.first] = tmp;
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
	_mapDownCast[nameTex.first] = tmp;
}

bool sfmlFramework::createArea(std::pair<int, int> dim, std::pair<int, int> pos,
	std::pair<std::string, std::string> nameTex, IGraphic::TYPE type)
{
	if (_mapType.find(nameTex.first) == _mapType.end() &&
		(_colors.find(nameTex.second) != _colors.end() ||
			type == IGraphic::TYPE::TEXT))
		_pointerFunc[type](dim, pos, nameTex, type);
	else if (_mapType.find(nameTex.first) == _mapType.end())
		_makeSpriteTex(dim, pos, nameTex, type); //faire le pointer sur func texSprit
	else
		throw errHand::Error("This area is already created");
	return true;
}

/*bool sfmlFramework::loop(void (*func)(void))
{
	while (true)
		func();
		}*/

template<class T>
std::pair<int, int> sfmlFramework::_getPosT(std::string name)
{
	T *tmp = static_cast<T *>(_mapDownCast[name]);

	return tmp->getPos();
}

std::pair<int, int> sfmlFramework::getpos(std::string name)
{
	if (_mapDownCast.find(name) != _mapDownCast.end()) {
		switch (_mapType[name]) {
			case IGraphic::TYPE::RECT:
				return _getPosT<SfmlSquare>(name);
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
	T *tmp = static_cast<T *>(_mapDownCast[name]);

	return tmp->getDim();
}

std::pair<int, int> sfmlFramework::getdim(std::string name)
{
	if (_mapDownCast.find(name) != _mapDownCast.end()) {
		switch (_mapType[name]) {
			case IGraphic::TYPE::RECT:
				return _getDimT<SfmlSquare>(name);
			default:
  				break ;
		}
	} else
		throw errHand::Error("getDim object don't exist");
	return std::make_pair(0, 0);
}

template<class T>
bool sfmlFramework::_setPosT(std::pair<int, int> pos, std::string name)
{
	T *tmp = static_cast<T *>(_mapDownCast[name]);

	return tmp->setPos(pos.first, pos.second);
}

bool sfmlFramework::setpos(std::pair<int, int> pos, std::string name)
{
	if (_mapDownCast.find(name) != _mapDownCast.end()) {
		switch (_mapType[name]) {
			case IGraphic::TYPE::RECT:
				return _setPosT<SfmlSquare>(pos, name);
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
	T *tmp = static_cast<T *>(_mapDownCast[name]);

	return tmp->setDim(dim.first, dim.second);
}

bool sfmlFramework::setdim(std::pair<int, int> dim, std::string name)
{
	if (_mapDownCast.find(name) != _mapDownCast.end()) {
		switch (_mapType[name]) {
			case IGraphic::TYPE::RECT:
				return _setDimT<SfmlSquare>(dim, name);
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
		if (_window->pollEvent(_event) && (sf::Keyboard::isKeyPressed(_keys[key]) ||
			_event.type == _keys2[key])) {
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
bool sfmlFramework::_displayRec(std::string name)
{
	T *tmp = static_cast<T *>(_mapDownCast[name]);

	_window->draw(tmp->getShape());
	return true;
}

bool sfmlFramework::displayObj()
{
	for (auto &it : _mapDownCast) {
		switch (_mapType[it.first]) {
			case IGraphic::TYPE::RECT:
				_displayRec<SfmlSquare>(it.first);
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
		delete _mapDownCast[name];
		_mapDownCast.erase(name);
	} else
		throw errHand::Error("deleteArea: obj doesn't exist in map");
	return true;
}

bool sfmlFramework::changeTexture(std::string name, std::string path)
{
	if (_mapTex.find(name) != _mapTex.end()) {
		if ((_mapType[name] == -1 && _colors.find(path) == _colors.end()) ||
			_mapType[name] != -1 && _colors.find(path) != _colors.end())
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

extern "C" IGraphic* create() {
	return new sfmlFramework();
}

extern "C" void destroy(IGraphic* p) {
	delete p;
}
