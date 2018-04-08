//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#ifndef _NCURCES2_FRAMEWORK_
# define _NCURCES2_FRAMEWORK_

#include <utility>
#include <vector>
#include <ncurses.h>
#include <curses.h>
#include <unistd.h>
#include <math.h>
#include <unordered_map>
#include "IGraphic.hpp"
#include "NCURSE2/ShapeN.hpp"

// # define GET_C(x, y, sw) ((y * sw) + (x))

// typedef struct info_s
// {
// 	int color;
// 	int px;
// 	int py;
// 	int sx;
// 	int sy;
// }	info_t; // faire plutot un obj

class ncurseFramework : public IGraphic
{
public:
	ncurseFramework();
	~ncurseFramework();
	bool createWindow(std::pair<int, int> dim, std::string name) override;
	bool clearWindow() override;
	bool createArea(std::pair<int, int> dim, std::pair<int, int> pos,
		std::pair<std::string, std::string> nameTex, TYPE type) override;
	std::pair<int, int> getpos(std::string name) override;
	std::pair<int, int> getdim(std::string name) override;
	IGraphic::TYPE getType(std::string name) override;
	bool setpos(std::pair<int, int> pos, std::string name) override;
	bool setdim(std::pair<int, int> dim, std::string name) override;
	bool isKeyPressed(std::string key) override;
	bool displayObj() override;
	bool deleteArea(std::string name) override;
	bool changeTexture(std::string name, std::string path) override;
	bool destroyWindow() override;
	bool destroyAllArea() override;
private:
	void _makeText(std::pair<int, int> dim, std::pair<int, int> pos,
		std::pair<std::string, std::string> nameTex, IGraphic::TYPE type);
	void _makeShape(std::pair<int, int> dim, std::pair<int, int> pos,
		std::pair<std::string, std::string> nameTex, IGraphic::TYPE type);
	std::vector<char> _mapWindow;
	WINDOW *_win;
	int _width;
	int _height;
	std::string _nameWindow;
	std::vector< std::pair<std::string, ShapeN *> > _mapShape;

	std::unordered_map<std::string, int> _colors;
	std::unordered_map<std::string, char> _keys;
	char _ch;
};

#endif /* !_NCURCES2_FRAMEWORK_ */