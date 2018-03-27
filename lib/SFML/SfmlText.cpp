//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#include "SFML/SfmlText.hpp"

SfmlText::SfmlText(std::pair<int, int> dim, std::pair<int, int> pos, std::string name)
{
	_font.loadFromFile("fonts/arcade.ttf");
	_text.setFont(_font);
	_text.setCharacterSize(dim.first);
	_pos = std::make_pair(dim.first, dim.second);
	_text.setPosition(pos.first, pos.second);
	_text.setString(name);
}

SfmlText::~SfmlText()
{}

bool SfmlText::setPos(int x, int y)
{
	_text.setPosition(x, y);
	return true;
}

bool SfmlText::setDim(int x, int y)
{
	_pos.second = y;
	_text.setCharacterSize(x);
	return true;
}

std::pair<int, int> SfmlText::getPos()
{
	return std::make_pair(_text.getPosition().x, _text.getPosition().y);
}

std::pair<int, int> SfmlText::getDim()
{
	return std::make_pair(_text.getCharacterSize(), _pos.second);
}

sf::Text SfmlText::getShape()
{
	return _text;
}