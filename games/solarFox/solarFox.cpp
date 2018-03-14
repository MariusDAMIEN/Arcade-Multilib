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
	std::unique_ptr<IShape> pS;

	p->createWindow(200, 200, "my window");
	while (p->openWindow()) {
		pS = p->drawSquare(100, 100, "red", "blue");
		// obj2 = p->drawSquare(100, 100, "red", "blue");
		// obj->setPos()
		p->display();
	}
}