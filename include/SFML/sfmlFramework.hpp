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

class sfmlFramework : public IGraphic
{
public:
	sfmlFramework();
	~sfmlFramework();
	void display() override;
	void destroy() override;
	void character() override;
	void wall() override;
	void score() override;
	void time() override;
	void characterName() override;
	void item() override;
	void createWindow(std::size_t, std::size_t, const std::string &) override;
	bool openWindow() const override;
	void clearWindow() override;
	void destroyWindow() override;
	bool getKey(std::string &) override;
private:
	void _strLower(std::string &);
	std::unique_ptr<sf::RenderWindow> _window;
	sf::Event _event;
	std::unordered_map<std::string, sf::Keyboard::Key> _key;
};

#endif /* !_SFMLFRAMEWORK_HPP_ */