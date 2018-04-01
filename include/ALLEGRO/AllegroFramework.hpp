//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#ifndef _ALLEGROFRAMEWORK_HPP_
# define _ALLEGROFRAMEWORK_HPP_

#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <string.h>
#include <stdlib.h>
#include "IGraphic.hpp"

typedef std::function<void (std::pair<int, int>, std::pair<int, int>,
		std::pair<std::string, std::string>, IGraphic::TYPE)> argsArea;

class AllegroFramework : public IGraphic
{
public:
	AllegroFramework();
	~AllegroFramework();
	bool createWindow(std::pair<int, int> dim, std::string name);
	bool clearWindow();
	bool createArea(std::pair<int, int> dim, std::pair<int, int> pos,
		std::pair<std::string, std::string> nameTex, TYPE type);
	std::pair<int, int> getpos(std::string name);
	std::pair<int, int> getdim(std::string name);
	IGraphic::TYPE getType(std::string name);
	bool setpos(std::pair<int, int> pos, std::string name);
	bool setdim(std::pair<int, int> dim, std::string name);
	bool isKeyPressed(std::string key);
	bool displayObj();
	bool deleteArea(std::string name);
	bool changeTexture(std::string name, std::string path);
	bool destroyWindow();
private:
	void _dispSprite(std::string name);
	bool _makeSpriteTex(std::pair<int, int> dim, std::pair<int, int> pos,
		std::pair<std::string, std::string> nameTex, IGraphic::TYPE type);
	void _makeText(std::pair<int, int> dim, std::pair<int, int> pos,
		std::pair<std::string, std::string> nameTex, IGraphic::TYPE type);
	void _dispText(std::string name);
	void _strLower(std::string &str);
	void _makeArea(std::pair<int, int> dim, std::pair<int, int> pos,
		std::pair<std::string, std::string> nameTex, IGraphic::TYPE type);
	void _dispRect(std::string name);
	ALLEGRO_DISPLAY *_window;
	ALLEGRO_EVENT_QUEUE *_event_queue;
	ALLEGRO_EVENT _event;
	ALLEGRO_FONT *_font;
	std::unordered_map<std::string, int> _keys;
	std::unordered_map<std::string, ALLEGRO_COLOR> _colors;
	ALLEGRO_COLOR *_allColors;

	std::unordered_map<std::string, std::pair<int, int>> _mapDim;
	std::unordered_map<std::string, std::pair<int, int>> _mapPos;
	std::unordered_map<std::string, std::string> _mapTex;
	std::vector< std::pair<std::string, int> > _mapType;
	std::unordered_map<std::string, ALLEGRO_FONT *> _mapFont;
	std::unordered_map<std::string, ALLEGRO_BITMAP *> _mapSprite;

	std::unordered_map<int, argsArea> _pointerFunc;
};

#endif /* !_ALLEGROFRAMEWORK_HPP_ */