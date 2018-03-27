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
#include "SFML/SfmlManageSprite.hpp"

typedef std::function<void (std::pair<int, int>, std::pair<int, int>,
		std::pair<std::string, std::string>, IGraphic::TYPE)> argsArea;

class sfmlFramework : public IGraphic
{
public:

	sfmlFramework();
	~sfmlFramework();
	bool createWindow(std::pair<int, int> dim, std::string name) override;
		// erease all of window
	bool clearWindow() override;
	bool createArea(std::pair<int, int> dim, std::pair<int, int> pos,
		std::pair<std::string, std::string> nameTex, TYPE type) override;
//	bool loop(void (*func)(void)) override;
	std::pair<int, int> getpos(std::string name) override;
	std::pair<int, int> getdim(std::string name) override;
	bool setpos(std::pair<int, int> pos, std::string name) override;
	bool setdim(std::pair<int, int> dim, std::string name) override;
	bool isKeyPressed(std::string key) override;
	bool displayObj() override;
	bool deleteArea(std::string name) override;
	bool changeTexture(std::string name, std::string path) override;
	bool destroyWindow() override;
private:
	void _strLower(std::string &str);
	void _rectangle(std::pair<int, int> dim, std::pair<int, int> pos,
		std::pair<std::string, std::string> nameTex, TYPE type);
	template<class T>
	std::pair<int, int> _getPosT(std::string);
	template<class T>
	std::pair<int, int> _getDimT(std::string);
	template<class T>
	bool _setPosT(std::pair<int, int> pos, std::string name);
	template<class T>
	bool _setDimT(std::pair<int, int> dim, std::string name);
	template<class T>
	bool _displayRec(std::string name);
	void _makeSpriteTex(std::pair<int, int> dim, std::pair<int, int> pos,
		std::pair<std::string, std::string> nameTex, TYPE type);

	std::unique_ptr<sf::RenderWindow> _window;
	std::unordered_map<std::string, sf::Keyboard::Key> _keys;
	std::unordered_map<std::string, sf::Event::EventType> _keys2;
	std::unordered_map<std::string, sf::Color> _colors;
	sf::Event _event;

	std::unordered_map<std::string, std::pair<int, int>> _mapDim;
	std::unordered_map<std::string, std::pair<int, int>> _mapPos;
	std::unordered_map<std::string, std::string> _mapTex;
	std::unordered_map<std::string, int> _mapType;
	// pour displayObj
	std::unordered_map<std::string, IShape *> _mapDownCast;
	std::unordered_map<int, argsArea> _pointerFunc;
	// pour displayObj
	// std::unordered_map<int, std::function<void (std::string)> > _downCast;
// pour le type: sprite le framework doit savoir que ca correspond a -1
};

// extern "C" void libsf()
// {
// 	return (new sfmlFramework());
// }


#endif /* !_SFMLFRAMEWORK_HPP_ */
