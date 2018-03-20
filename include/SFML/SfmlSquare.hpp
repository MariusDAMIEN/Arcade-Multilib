//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#ifndef _SFMLSQUARE_HPP_
# define _SFMLSQUARE_HPP_

#include <SFML/Graphics.hpp>
#include <utility>
#include "IShape.hpp"

class SfmlSquare : public IShape
{
public:
	SfmlSquare(sf::Vector2f, sf::Color);
	~SfmlSquare();
	bool setPos(int, int);
	bool setDim(int, int);
	std::pair<int, int> getPos();
	std::pair<int, int> getDim();
	sf::RectangleShape getShape();
private:
	sf::RectangleShape _rectangle;
};

#endif /* !_SFMLSQUARE_HPP_ */