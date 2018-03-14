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

sfmlFramework::sfmlFramework()
{
	std::cout << "framwork sfml creating" << std::endl;
	_key = {
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
}

sfmlFramework::~sfmlFramework()
{}

void sfmlFramework::display()
{
	_window->display();
}

void sfmlFramework::destroy()
{}

void sfmlFramework::character()
{}

void sfmlFramework::wall()
{}

void sfmlFramework::score()
{}

void sfmlFramework::time()
{}

void sfmlFramework::characterName()
{}

void sfmlFramework::item()
{}

void sfmlFramework::createWindow(std::size_t x, std::size_t y, const std::string &name)
{
	_window = std::make_unique<sf::RenderWindow>(sf::VideoMode(x, y), name);
}

bool sfmlFramework::openWindow() const
{
	if (_window->isOpen())
		return true;
	return false;
}

void sfmlFramework::clearWindow()
{
	_window->clear();
}

void sfmlFramework::destroyWindow()
{
	_window->close();
}

bool sfmlFramework::getKey(std::string &c)
{
	_strLower(c);
	if (_key.find(c) != _key.end()) {
		if (_window->pollEvent(_event) && sf::Keyboard::isKeyPressed(_key[c])) {
			return true;
		}
	} else // "key doesn't exist in map _key"
		throw std::exception();
	return false;
}

void sfmlFramework::_strLower(std::string &str)
{
	for (unsigned int i = 0; i < str.length(); ++i)
		str[i] = tolower(str[i]);
}

std::unique_ptr<IShape> sfmlFramework::_mySquare(const std::size_t x, const std::size_t y, sf::Color color1, sf::Color color2)
{
	// retourner l'objet SfmlSquare avec le l'obj correspondant dans sfml
	// std::unique_ptr<SfmlSquare> p;

	// SfmlSquare square(sf::Vector2f(x, y), color1);

	(void)color2;
	// faire le cpp de sfmlSquare
	// square.setSize(sf::Vector2f(x, y));
	return std::make_unique<SfmlSquare>(sf::Vector2f(x, y), color1);
}

std::unique_ptr<IShape> sfmlFramework::drawSquare(const std::size_t x, const std::size_t y, std::string color1, std::string color2)
{
	_strLower(color1);
	_strLower(color2);
	if (_colors.find(color1) != _colors.end()) {
		if (_colors.find(color2) != _colors.end())
			return _mySquare(x, y, _colors[color1], _colors[color2]);
		else
			return _mySquare(x, y, _colors[color1], _colors[color1]);
	} else // color doesn't exist
		throw std::exception();
	// return nullptr;
}









