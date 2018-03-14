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
#include "IGraphic.hpp"
#include "SFML/SfmlSquare.hpp"

class sfmlFramework : public IGraphic
{
public:
	sfmlFramework();
	~sfmlFramework();
	// display all result at end
	void display() override;
	// destroy all obj
	void destroy() override;
	void character() override;
	void wall() override;
	void score() override;
	void time() override;
	void characterName() override;
	void item() override;
	// init the window
	void createWindow(std::size_t, std::size_t, const std::string &) override;
	// open that winwow
	bool openWindow() const override;
	// clear that window
	void clearWindow() override;
	// destroy that window
	void destroyWindow() override;
	// get the key pressed
	bool getKey(std::string &) override;
	// draw a square
	std::unique_ptr<IShape> drawSquare(const std::size_t, const std::size_t, std::string, std::string) override;
private:
	void _strLower(std::string &);
	std::unique_ptr<IShape> _mySquare(const std::size_t, const std::size_t, sf::Color, sf::Color);
	std::unique_ptr<sf::RenderWindow> _window;
	sf::Event _event;
	std::unordered_map<std::string, sf::Keyboard::Key> _key;
	std::unordered_map<std::string, sf::Color> _colors;
};

#endif /* !_SFMLFRAMEWORK_HPP_ */