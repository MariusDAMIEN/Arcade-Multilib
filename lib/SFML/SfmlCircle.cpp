//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#include "SFML/SfmlCircle.hpp"

SfmlCircle::SfmlCircle(std::pair<int, int> dim, std::pair<int, int> pos, sf::Color color)
{
	_circle.setRadius(dim.first);
	_circle.setOutlineColor(color);
	_circle.setOutlineThickness(5);
	_circle.setPosition(pos.first, pos.second);
	_circle.setFillColor(sf::Color::Transparent);
}

SfmlCircle::~SfmlCircle()
{}

bool SfmlCircle::setPos(int x, int y)
{
	_circle.setPosition(x, y);
	return true;	
}

bool SfmlCircle::setDim(int x, int y)
{
	(void)y;
	_circle.setRadius(x);
	return true;
}

std::pair<int, int> SfmlCircle::getPos()
{
	return std::make_pair(_circle.getPosition().x, _circle.getPosition().y);
}

std::pair<int, int> SfmlCircle::getDim()
{
	return 	std::make_pair(_circle.getRadius(), _circle.getRadius());
}

sf::CircleShape SfmlCircle::getShape()
{
	return _circle;
}