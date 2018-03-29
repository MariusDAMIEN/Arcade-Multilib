//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#ifndef _LAUNCHER_HPP_
# define _LAUNCHER_HPP_

#include <cctype>
#include <dlfcn.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
#include <vector>
#include <algorithm>
#include "IGraphic.hpp"
#include "arcade.hpp"
#include "SmartPointer.hpp"
#include "ERROR/ErrorHandling.hpp"

typedef IGraphic* create_t();

class launcher {
public:
	launcher(const char *lib);
	~launcher();
	int load_first_lib();
	void windowcreation();
	bool loop();
	void load_game(const char *lib);
	void change_lib(const char *lib);
private:
	void next_lib();
	std::string _lib;
	std::vector<std::string> _vectLib;
	std::vector<std::string> _vectGame;
	std::vector<std::string>::iterator _libIt;
	std::pair<int, int> _select;
        void const * _handle;
	IGraphic *_igraph;
};

#endif /* !_LAUNCHER_HPP_ */
