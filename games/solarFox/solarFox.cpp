//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#include "SFML/sfmlFramework.hpp"

void solarFox()
{
	// linked lib
	sfmlFramework *p = new sfmlFramework();

	p->createWindow(200, 200, "my window");
	while (p->openWindow()) {
		p->display();
	}
}