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
}

SfmlSquare::~SfmlSquare()
{}

void SfmlSquare::setPos(int x, int y)
{
	_rectangle.setPosition(x, y);
}

sf::RectangleShape SfmlSquare::getShape()
{
	return _rectangle;
}