//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#ifndef _IGRAPHIC_HPP_
# define _IGRAPHIC_HPP_

#include <memory>
#include <unordered_map>
#include <utility>
// #include "IShape.hpp"

class IGraphic
{
 public:
	//nouvelle interface

	// pour createArea il faut verifier le deuxieme parametre de nameTex
	// si il a un nom de couleur ex: red, green il faut faire une forme
	// sinon il faut faire une sprite avec texture
 	enum TYPE {
 		RECT,
 		CICLE,
 		CHARAC,
 		ENEMY,
		TEXT,
		ITEM,
		OBSTACLE
 	};

 	virtual ~IGraphic() = default;
	virtual	bool createWindow(std::pair<int, int> dim, std::string name) = 0;
	virtual	bool clearWindow() = 0;
	virtual	bool createArea(std::pair<int, int> dim, std::pair<int, int> pos,
		std::pair<std::string, std::string> nameTex, TYPE type) = 0;
	virtual	std::pair<int, int> getpos(std::string name) = 0;
	virtual	std::pair<int, int> getdim(std::string name) = 0;
	virtual IGraphic::TYPE getType(std::string name) = 0;
	virtual	bool setpos(std::pair<int, int> pos, std::string name) = 0;
	virtual	bool setdim(std::pair<int, int> dim, std::string name) = 0;
	virtual	bool isKeyPressed(std::string key) = 0;
	virtual	bool displayObj() = 0;
	virtual	bool deleteArea(std::string name) = 0;
	virtual bool changeTexture(std::string name, std::string path) = 0;
	virtual bool destroyWindow() = 0;
	virtual bool destroyAllArea() = 0;
};

#endif /* !_IGRAPHIC_HPP_ */
