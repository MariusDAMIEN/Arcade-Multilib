//
// EPITECH PROJECT, 2018
//
// File description:
//
//

#ifndef _SFMLMANAGESPRITE_
# define _SFMLMANAGESPRITE_

#include <SFML/Graphics.hpp>
#include <iostream>
#include <utility>
#include "IShape.hpp"

class SfmlManageSprite : public IShape
{
public:
	SfmlManageSprite(std::string file, std::pair<int, int> dim,
		std::pair<int, int> pos);
	~SfmlManageSprite();
	bool setPos(int, int);
	bool setDim(int, int);
	std::pair<int, int> getPos();
	std::pair<int, int> getDim();
	sf::Sprite getShape();
private:
	sf::Texture _texture;
	sf::Sprite _sprite;
	std::pair<int, int> _saveDim;
};

#endif /* !_SFMLMANAGESPRITE_ */