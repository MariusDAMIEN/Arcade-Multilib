//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//
#include <exception>
#include "ALLEGRO/AllegroFramework.hpp"
#include "ERROR/ErrorHandling.hpp"

AllegroFramework::AllegroFramework()
{
	al_init();
	al_init_font_addon();
	al_init_ttf_addon();
	al_init_primitives_addon();
	al_install_keyboard();
	al_init_image_addon();
	_event_queue = al_create_event_queue();
	al_register_event_source(_event_queue, al_get_keyboard_event_source());
	_keys = {
		{"a", ALLEGRO_KEY_A},
		{"b", ALLEGRO_KEY_B},
		{"c", ALLEGRO_KEY_C},
		{"d", ALLEGRO_KEY_D},
		{"e", ALLEGRO_KEY_E},
		{"f", ALLEGRO_KEY_F},
		{"g", ALLEGRO_KEY_G},
		{"h", ALLEGRO_KEY_H},
		{"i", ALLEGRO_KEY_I},
		{"j", ALLEGRO_KEY_J},
		{"k", ALLEGRO_KEY_K},
		{"m", ALLEGRO_KEY_M},
		{"n", ALLEGRO_KEY_N},
		{"o", ALLEGRO_KEY_O},
		{"p", ALLEGRO_KEY_P},
		{"q", ALLEGRO_KEY_Q},
		{"r", ALLEGRO_KEY_R},
		{"s", ALLEGRO_KEY_S},
		{"t", ALLEGRO_KEY_T},
		{"u", ALLEGRO_KEY_U},
		{"v", ALLEGRO_KEY_V},
		{"w", ALLEGRO_KEY_W},
		{"x", ALLEGRO_KEY_X},
		{"y", ALLEGRO_KEY_Y},
		{"z", ALLEGRO_KEY_Z},
		{"escape", ALLEGRO_KEY_ESCAPE},
		{"left", ALLEGRO_KEY_LEFT},
		{"right", ALLEGRO_KEY_RIGHT},
		{"up", ALLEGRO_KEY_UP},
		{"down", ALLEGRO_KEY_DOWN}
	};
	_colors = {
		{"black", al_map_rgb(0, 0, 0)},
		{"white", al_map_rgb(255, 255, 255)},
		{"red", al_map_rgb(255, 0, 0)},
		{"green", al_map_rgb(0, 128, 0)},
		{"blue", al_map_rgb(0, 0, 255)},
		{"yellow", al_map_rgb(255, 255, 0)},
		{"magenta", al_map_rgb(219, 112, 147)},
		{"cyan", al_map_rgb(0, 255, 255)}
	};
	_pointerFunc.insert(std::make_pair(0, std::bind(&AllegroFramework::_makeArea,
		this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3,
		std::placeholders::_4)));
	_pointerFunc.insert(std::make_pair(4, std::bind(&AllegroFramework::_makeText,
		this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3,
		std::placeholders::_4)));
	_pointerFunc.insert(std::make_pair(1, std::bind(&AllegroFramework::_makeArea,
		this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3,
		std::placeholders::_4)));
	_pointerFunc.insert(std::make_pair(2, std::bind(&AllegroFramework::_makeArea,
		this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3,
		std::placeholders::_4)));
	_pointerFunc.insert(std::make_pair(3, std::bind(&AllegroFramework::_makeArea,
		this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3,
		std::placeholders::_4)));
	_pointerFunc.insert(std::make_pair(5, std::bind(&AllegroFramework::_makeArea,
		this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3,
		std::placeholders::_4)));
	_pointerFunc.insert(std::make_pair(6, std::bind(&AllegroFramework::_makeArea,
		this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3,
		std::placeholders::_4)));
}

AllegroFramework::~AllegroFramework()
{}

bool AllegroFramework::createWindow(std::pair<int, int> dim, std::string name)
{
	_window = al_create_display(dim.first, dim.second);
	al_set_window_title(_window, name.c_str());
	if (!_window)
		return false;
	return true;
}

bool AllegroFramework::clearWindow()
{
	al_clear_to_color(al_map_rgb(0, 0, 0));
	return true;
}

void AllegroFramework::_makeArea(std::pair<int, int> dim, std::pair<int, int> pos,
	std::pair<std::string, std::string> nameTex, IGraphic::TYPE type)
{
	_mapDim[nameTex.first] = dim;
	_mapPos[nameTex.first] = pos;
	_mapTex[nameTex.first] = nameTex.second;
	// _mapType[nameTex.first] = type;
	_mapType.push_back(std::make_pair(nameTex.first, type));
}

void AllegroFramework::_makeText(std::pair<int, int> dim, std::pair<int, int> pos,
	std::pair<std::string, std::string> nameTex, IGraphic::TYPE type)
{
	_mapDim[nameTex.first] = dim;
	_mapPos[nameTex.first] = pos;
	_mapTex[nameTex.first] = nameTex.second;
	// _mapType[nameTex.first] = type;
	_mapType.push_back(std::make_pair(nameTex.first, type));
	_mapFont[nameTex.first] = al_load_font("fonts/arcade.ttf", dim.first, 0);
}

bool AllegroFramework::_makeSpriteTex(std::pair<int, int> dim, std::pair<int, int> pos,
	std::pair<std::string, std::string> nameTex, IGraphic::TYPE type)
{
	(void)type;
	nameTex.second = std::string("assets/") + nameTex.second;
	_mapDim[nameTex.first] = dim;
	_mapPos[nameTex.first] = pos;
	_mapTex[nameTex.first] = nameTex.second;
	// _mapType[nameTex.first] = -1;
	_mapType.push_back(std::make_pair(nameTex.first, -1));
	if (!(_mapSprite[nameTex.first] = al_load_bitmap(nameTex.second.c_str())))
		return false;
	return true;
}

bool AllegroFramework::createArea(std::pair<int, int> dim, std::pair<int, int> pos,
	std::pair<std::string, std::string> nameTex, IGraphic::TYPE type)
{
	if (_mapTex.find(nameTex.first) == _mapTex.end() &&
		(_colors.find(nameTex.second) != _colors.end() ||
		type == IGraphic::TYPE::TEXT)) {
		_pointerFunc[type](dim, pos, nameTex, type);
	} else if (_mapTex.find(nameTex.first) == _mapTex.end())
		return _makeSpriteTex(dim, pos, nameTex, type);
	else {
		throw errHand::Error("createArea: doesn't work");
	}
	return true;
}

std::pair<int, int> AllegroFramework::getpos(std::string name)
{
	if (_mapPos.find(name) != _mapPos.end())
		return _mapPos[name];
	throw errHand::Error("getPos: invalid name");
}

std::pair<int, int> AllegroFramework::getdim(std::string name)
{
	if (_mapDim.find(name) != _mapDim.end())
		return _mapDim[name];
	throw errHand::Error("getDim: invalid name");
}

IGraphic::TYPE AllegroFramework::getType(std::string name)
{
	if (_mapTex.find(name) != _mapTex.end()) {
		int i = 0;
		for (std::vector<std::pair<std::string, int>>::iterator it = _mapType.begin();
			it != _mapType.end(); ++it) {
			if (it->first == name)
				break ;
			++i;
		}
		return (IGraphic::TYPE)_mapType[i].second;
	}
	throw errHand::Error("getType: invalid name");
}

bool AllegroFramework::setpos(std::pair<int, int> pos, std::string name)
{
	if (_mapTex.find(name) != _mapTex.end())
		_mapPos[name] = pos;
	else
		return false;
	return true;
}

bool AllegroFramework::setdim(std::pair<int, int> dim, std::string name)
{
	if (_mapTex.find(name) != _mapTex.end())
		_mapDim[name] = dim;
	else
		return false;
	return true;
}

void AllegroFramework::_strLower(std::string &str)
{
	for (unsigned int i = 0; i < str.length(); ++i)
		str[i] = tolower(str[i]);
}

bool AllegroFramework::isKeyPressed(std::string key)
{
	_strLower(key);
	if (_keys.find(key) != _keys.end()) {
		usleep(2000);
		al_get_keyboard_state(&stateKey);
		if (al_key_down(&stateKey, _keys[key])) {
			usleep(97000);
			return true;
		}
	}
	return false;
}

void AllegroFramework::_dispRect(std::string name)
{
	al_draw_filled_rectangle(_mapPos[name].first, _mapPos[name].second,
		_mapPos[name].first + _mapDim[name].first,
		_mapPos[name].second + _mapDim[name].second, _colors[_mapTex[name]]);
}

void AllegroFramework::_dispText(std::string name)
{
	al_draw_text(_mapFont[name], al_map_rgb(255, 255, 255), _mapPos[name].first,
		_mapPos[name].second, 0, _mapTex[name].c_str());
}

void AllegroFramework::_dispSprite(std::string name)
{
	al_draw_bitmap_region(_mapSprite[name], 0, 0,
		_mapDim[name].first, _mapDim[name].second,
		_mapPos[name].first, _mapPos[name].second, 0);
}

bool AllegroFramework::displayObj()
{
	for (auto it : _mapType) {
		switch (it.second) {
			case -1:
				_dispSprite(it.first);
				break ;
			case IGraphic::TYPE::RECT: case IGraphic::TYPE::CHARAC:
			case IGraphic::TYPE::ENEMY: case IGraphic::TYPE::ITEM:
			case IGraphic::TYPE::OBSTACLE:
				_dispRect(it.first);
				break ;
			case IGraphic::TYPE::TEXT:
				_dispText(it.first);
				break ;
			default:
				break ;
		}
	}
	al_flip_display();
	return true;
}

bool AllegroFramework::deleteArea(std::string name)
{
	if (_mapTex.find(name) != _mapTex.end()) {
		_mapDim.erase(name);
		_mapPos.erase(name);
		_mapTex.erase(name);
		for (std::vector<std::pair<std::string, int>>::iterator it = _mapType.begin();
			it != _mapType.end(); ++it) {
			if (it->first == name) {
				_mapType.erase(it);
				break ;
			}
		}
	} else
		return false;
	return true;
}

bool AllegroFramework::changeTexture(std::string name, std::string path)
{
	(void)name;
	(void)path;
	return false;
}

bool AllegroFramework::destroyWindow()
{
	al_destroy_display(_window);
	// al_destroy_font(font);
	// al_destroy_event_queue(event_queue);
	// al_destroy_bitmap(character);
	return true;
}

bool AllegroFramework::destroyAllArea()
{
	_mapDim.clear();
	_mapPos.clear();
	_mapTex.clear();
	_mapType.clear();
	_mapFont.clear();
	_mapSprite.clear();
	return true;
}

extern "C" IGraphic *create()
{
	return new AllegroFramework();
}