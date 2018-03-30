//
// EPITECH PROJECT, 2018
//
// File description:
//
//

#include <unistd.h>
#include "NCURSE/ncurseFramework.hpp"
#include "launcher.hpp"
#include <iostream>

launcher::launcher(const char *lib)
{
	_lib = "./lib/" + std::string(lib);
	change_lib("./lib");
	load_game("./games");
	_select.first = 700;
	_select.second = 550;
}

launcher::~launcher()
{
	dlclose((void *)_handle);
}

int launcher::load_first_lib()
{
	void* handle = dlopen(_lib.c_str(), RTLD_LAZY);
	std::cout << _lib << std::endl;
	if (!handle)
		throw errHand::Error(std::string("Cannot open library: ")
				     + std::string(dlerror()));
	dlerror();
	create_t *create = (create_t*) dlsym(handle, "create");
	const char *dlsym_error = dlerror();
	if (dlsym_error) {
		throw errHand::Error(std::string("Cannot load symbol 'create': ")
				     + std::string(dlsym_error));
		dlclose(handle);
		return 1;
	}
	_igraph = create();
	_handle = handle;
	return (0);
}

void launcher::next_lib()
{
	_igraph->destroyWindow();
	dlclose((void *)_handle);
	_libIt++;
	if (_libIt == _vectLib.end())
		_libIt = _vectLib.begin();
	_lib = *_libIt;
	std::cout << "on load : " + _lib << std::endl;
	load_first_lib();
	windowcreation();
	loop();
}

void launcher::load_game(const char *dir_name)
{
	DIR *dir = opendir(dir_name);
	struct dirent *entry;
	struct stat info;

	if (!dir)
		throw errHand::Error("Directory was not found\n");
	while ((entry = readdir(dir)) != NULL) {
		std::string str(entry->d_name);
		if(str.substr(str.find_last_of(".") + 1) == "so") {
			std::string path = std::string(dir_name) + '/' + std::string(entry->d_name);
			std::cout << "Entry : " << path << std::endl;
			_vectGame.push_back(path);
		}
	}
	closedir(dir);
}


void launcher::change_lib(const char *dir_name)
{
	DIR *dir = opendir(dir_name);
	struct dirent *entry;
	struct stat info;

	if (!dir)
		throw errHand::Error("Directory was not found\n");
	while ((entry = readdir(dir)) != NULL) {
		std::string str(entry->d_name);
		if(str.substr(str.find_last_of(".") + 1) == "so") {
			std::string path = std::string(dir_name) + '/' + std::string(entry->d_name);
			std::cout << "Entry : " << path << std::endl;
			_vectLib.push_back(path);
		}
	}
	_libIt = _vectLib.begin();
	closedir(dir);
}

bool  launcher::loop()
{
	_igraph->createWindow(std::make_pair(1200, 1200), "oklm");
	_igraph->createArea(std::make_pair(1200, 1200), std::make_pair(0, 0)
			    , std::make_pair("bg_menu", "bg_menu.png"), IGraphic::TYPE::RECT);
	int i = 550;
	for ( auto it : _vectLib ) {
		std::string name("name");
		name = name + it;
		it = it.substr(it.find_last_of("_") + 1);
		it = it.substr(0, it.find(".so"));
		transform(it.begin(), it.end(), it.begin(), toupper);
		std::cout << it << std::endl;
		_igraph->createArea(std::make_pair(40, 40), std::make_pair(700, i)
				    , std::make_pair(name, it)
				    , IGraphic::TYPE::TEXT);
		i = i + 50;
	}
	int j = 200;
	for ( auto it : _vectGame ) {
		std::string name("ame");
		name = name + it;
		it = it.substr(it.find_last_of("_") + 1);
		it = it.substr(0, it.find(".so"));
		transform(it.begin(), it.end(), it.begin(), toupper);
		std::cout << it << std::endl;
		_igraph->createArea(std::make_pair(40, 40), std::make_pair(700, j)
				    , std::make_pair(name, it)
				    , IGraphic::TYPE::TEXT);
		j += 50;
	}
	_igraph->createArea(std::make_pair(160, 40), _select
			    , std::make_pair("select", "red"), IGraphic::TYPE::RECT);
	_igraph->createArea(std::make_pair(200, 200), std::make_pair(250, 0)
			    , std::make_pair("Title", "ARCADE"), IGraphic::TYPE::TEXT);
	_igraph->createArea(std::make_pair(30, 30), std::make_pair(30, 300)
			    , std::make_pair("Readme", "To change lib\npress the key 'a'"), IGraphic::TYPE::TEXT);
	_igraph->createArea(std::make_pair(40, 40), std::make_pair(600, 500)
			    , std::make_pair("Libliste", "Libraries available :")
			    , IGraphic::TYPE::TEXT);
	while (1) {
		_igraph->clearWindow();
		if (_igraph->isKeyPressed("a") == true) {
			next_lib();
		}
		if (_igraph->isKeyPressed("t") == true) {
			_select.second += 50;
			_igraph->setpos(_select, "select");
		}
		if (_igraph->isKeyPressed("v") == true) {
			_select.second -= 50;
			_igraph->setpos(_select, "select");
			}
		if (_igraph->isKeyPressed("b") == true) {
			_igraph->destroyWindow();
			exit(5);
		}
		_igraph->displayObj();
	}
}

void launcher::windowcreation()
{
	_igraph->createWindow(std::make_pair(1200, 1200), "oklm");
}


int launch(char *lib)
{
	launcher go(lib);

	go.load_first_lib();
	//go.windowcreation();
	go.loop();
	return (0);
}
