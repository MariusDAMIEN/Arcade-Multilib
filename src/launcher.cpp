//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#include <unistd.h>
#include "NCURSE/ncurseFramework.hpp"
#include "launcher.hpp"

launcher::launcher(const char *lib)
{
	_lib = "./lib/" + std::string(lib);
}

launcher::~launcher()
{
	dlclose((void *)_handle);
}

int launcher::load_first_lib()
{
	void* handle = dlopen(_lib.c_str(), RTLD_LAZY);
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

bool launcher::loop()
{
	char marius[] = "chief marius\n";

	_igraph->createWindow(std::make_pair(1200, 500), marius);
	_igraph->createArea(std::make_pair(100, 100), std::make_pair(30, 300),
		std::make_pair("Name", "trop fort chieffff marius"), IGraphic::TYPE::TEXT);
	_igraph->createArea(std::make_pair(20, 20), std::make_pair(0, 0),
		std::make_pair("lol", "red"), IGraphic::TYPE::RECT);
	while (1) {
		_igraph->clearWindow();
		if (_igraph->isKeyPressed("escape") == true)
			exit(6);
		if (_igraph->isKeyPressed("a") == true)
			exit(6);
		if (_igraph->isKeyPressed("b") == true)
			exit(6);
		if (_igraph->isKeyPressed("c") == true)
			exit(6);
		_igraph->displayObj();
	}
}

void launcher::windowcreation()
{
	_igraph->createWindow(std::make_pair(2000, 500), "oklm");
}


int launch(char *lib)
{
	launcher go(lib);
	go.load_first_lib();
	// go.windowcreation();
	go.loop();
	return (0);
}
