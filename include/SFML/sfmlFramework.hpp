//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#ifndef _SFMLFRAMEWORK_HPP_
# define _SFMLFRAMEWORK_HPP_

#include <SFML/Graphics.hpp>
#include <memory>
#include <unordered_map>
#include <functional>
#include <string>
#include <iostream>
#include "IGraphic.hpp"
#include "SFML/SfmlSquare.hpp"

class sfmlFramework : public IGraphic
{
public:
	sfmlFramework();
	~sfmlFramework();
	// display all result at end and this is for update
	void displayOnWindow() override;
	// destroy all obj
	void destroy() override;
	void character() override;
	void wall() override;
	void score() override;
	void time() override;
	void characterName() override;
	void item() override;
	// init the window | done
	void createWindow(std::size_t, std::size_t, const std::string &) override;
	// open that winwow | done
	bool isOpenWindow() const override;
	// clear that window | done
	void clearWindow() override;
	// destroy that window
	void destroyWindow() override;
	// get the key pressed | done
	bool isKeyPressed(std::string) override;
	// draw a square | done
	std::unique_ptr<IShape> drawRectangle(const std::size_t, const std::size_t, std::string, std::string) override;
	// template<typename T>
	void drawInBuff(IShape &shape, std::string type) override;
private:
	void _strLower(std::string &);
	std::unique_ptr<IShape> _mySquare(const std::size_t, const std::size_t, sf::Color, sf::Color);
	sf::RectangleShape _getRectangle();

	std::unique_ptr<sf::RenderWindow> _window;
	sf::Event _event;
	std::unordered_map<std::string, sf::Keyboard::Key> _key;
	std::unordered_map<std::string, sf::Color> _colors;
	std::unordered_map<std::string, std::function<void (void)> > _cast;
	IShape *_myShape;
	sf::RectangleShape _rectangle;
};

// extern "C" void libsf()
// {
// 	return (new sfmlFramework());
// }


#endif /* !_SFMLFRAMEWORK_HPP_ */