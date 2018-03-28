//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#ifndef _SFMLTEXT_
# define _SFMLTEXT_

#include <SFML/Graphics.hpp>
#include <iostream>
#include <utility>
#include "IShape.hpp"

class SfmlText : public IShape
{
public:
	SfmlText(std::pair<int, int> dim, std::pair<int, int> pos, std::string name);
	~SfmlText();
	bool setPos(int, int);
	bool setDim(int, int);
	std::pair<int, int> getPos();
	std::pair<int, int> getDim();
	sf::Text getShape();
private:
	sf::Font _font;
	sf::Text _text;
	std::pair<int, int> _pos;
};

#endif /* !_SFMLTEXT */