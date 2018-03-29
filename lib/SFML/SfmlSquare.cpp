//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#include "SFML/SfmlSquare.hpp"

SfmlSquare::SfmlSquare(sf::Vector2f vec, sf::Color color)
{
	_rectangle.setSize(vec);
	_rectangle.setOutlineColor(color);
	_rectangle.setOutlineThickness(3);
	_rectangle.setFillColor(sf::Color::Transparent);
}

SfmlSquare::~SfmlSquare()
{}

bool SfmlSquare::setPos(int x, int y)
{
	_rectangle.setPosition(x, y);
	return true;
}

bool SfmlSquare::setDim(int x, int y)
{
	_rectangle.setSize(sf::Vector2f(x, y));
	return true;
}

std::pair<int, int> SfmlSquare::getPos()
{
	return std::make_pair(_rectangle.getPosition().x, _rectangle.getPosition().y);
}

std::pair<int, int> SfmlSquare::getDim()
{
	return std::make_pair(_rectangle.getSize().x, _rectangle.getSize().y);
}

sf::RectangleShape SfmlSquare::getShape()
{
	return _rectangle;
}