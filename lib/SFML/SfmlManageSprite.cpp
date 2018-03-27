//
// EPITECH PROJECT, 2018
//
// File description:
//
//

#include "SFML/SfmlManageSprite.hpp"

SfmlManageSprite::SfmlManageSprite(std::string file, std::pair<int, int> dim,
	std::pair<int, int> pos)
	: _saveDim(dim)
{
	_texture.loadFromFile(std::string(PATH_IMG) + file);
	_sprite.setTexture(_texture);
	_sprite.setTextureRect(sf::IntRect(0, 0, dim.first, dim.second));
	_sprite.setColor(sf::Color(255, 255, 255, 200));
	_sprite.setPosition(pos.first, pos.second);
}

SfmlManageSprite::~SfmlManageSprite()
{}

bool SfmlManageSprite::setPos(int x, int y)
{
	_sprite.setPosition(x, y);
	return true;
}

bool SfmlManageSprite::setDim(int x, int y)
{
	_sprite.setTextureRect(sf::IntRect(0, 0, x, y));
	_saveDim.first = x;
	_saveDim.second = y;
	return true;
}

std::pair<int, int> SfmlManageSprite::getPos()
{
	return std::make_pair(_sprite.getPosition().x, _sprite.getPosition().y);
}

std::pair<int, int> SfmlManageSprite::getDim()
{
	return _saveDim;
}

sf::Sprite SfmlManageSprite::getShape()
{
	return _sprite;
}