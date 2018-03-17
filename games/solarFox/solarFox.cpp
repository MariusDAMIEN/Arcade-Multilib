//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#include "SFML/sfmlFramework.hpp"
#include "SFML/SfmlSquare.hpp"

void solarFox()
{
	// linked lib
	IGraphic *p = new sfmlFramework();
	IShape *rectangle;
	// il faut arriver a templater le IShape et la function drawInBuff


	p->createWindow(200, 200, "my window");
	while (p->isOpenWindow()) {
		p->clearWindow();
		rectangle = p->drawRectangle(100, 100, "red", "blue");
		// obj2 = p->drawSquare(100, 100, "red", "blue");
		rectangle->setPos(20, 20);
		p->drawInBuff(rectangle, "rectangle");
		p->displayOnWindow();
	}
}