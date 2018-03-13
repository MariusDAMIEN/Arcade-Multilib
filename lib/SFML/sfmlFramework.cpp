//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#include <iostream>
#include <cctype>
#include <exception>
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


