//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#ifndef _SFMLCIRCLE
# define _SFMLCIRCLE

#include <SFML/Graphics.hpp>
#include <iostream>
#include <utility>
#include "IShape.hpp"

//  nameTex | color:file.png
class SfmlCircle : public IShape
{
public:
	SfmlCircle(std::pair<int, int> dim, std::pair<int, int> pos, sf::Color color);
	~SfmlCircle();
	bool setPos(int, int);
	bool setDim(int, int);
	std::pair<int, int> getPos();
	std::pair<int, int> getDim();
	sf::CircleShape getShape();
private:
	sf::CircleShape _circle;
};

#endif /* !_SFMLCIRCLE */