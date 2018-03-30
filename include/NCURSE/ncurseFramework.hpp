//
// EPITECH PROJECT, 2018
//
// File description:
//
//

#ifndef _NCURSEFRAMEWORK_HPP_
# define _NCURSEFRAMEWORK_HPP_

#include <utility>
#include <ncurses.h>
#include <curses.h>
#include <memory>
#include <unordered_map>
#include <functional>
#include <map>
#include <string>
#include <iostream>
#include <vector>
#include "ERROR/ErrorHandling.hpp"
#include "IGraphic.hpp"

typedef struct s_area {
	IGraphic::TYPE _type;
	std::pair<int, int>_dim;
	std::pair<int, int>_pos;
	std::pair<std::string, std::string>_nameTex;
}t_area;

class ncurseFramework : public IGraphic
{
public:

	ncurseFramework();
	~ncurseFramework();
	bool createWindow(std::pair<int, int>, std::string) override;
	// erease all of window
	bool clearWindow() override;
	bool createArea(std::pair<int, int>, std::pair<int, int>,
			std::pair<std::string, std::string>, TYPE) override;
	std::pair<int, int> getpos(std::string) override;
	std::pair<int, int> getdim(std::string) override;
	bool setpos(std::pair<int, int>, std::string) override;
	bool setdim(std::pair<int, int>, std::string) override;
	IGraphic::TYPE getType(std::string name);
	bool isKeyPressed(std::string) override;
	bool displayObj() override;
	bool deleteArea(std::string) override;
	bool changeTexture(std::string, std::string) override;
	bool destroyWindow() override;
private:
	void modifWin();
	void printWin();
	void crWin(std::pair<int, int>);
	void _strLower(std::string &str);
	std::unordered_map<std::string, char> _keys;
	void init() const;
	int _ch;
	std::vector<t_area *> _areasVec;
	char** _mainWin;
};

extern "C" IGraphic *create()
{
 return (new ncurseFramework());
}


#endif /* !_NCURSEFRAMEWORK_HPP_ */
