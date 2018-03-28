//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

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
	char marius[11] = "trop fort\n";

	_igraph->createArea(std::make_pair(200, 200), std::make_pair(10, 10)
			    , std::make_pair(marius, "blue"), IGraphic::TYPE::CHARAC);
	_igraph->createArea(std::make_pair(50, 200), std::make_pair(300, 10)
			    , std::make_pair("Name", "trop fort chieffff marius"), IGraphic::TYPE::TEXT);
	while (1) {
		if (_igraph->isKeyPressed("a") == true)
			exit(6);
		_igraph->clearWindow();
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
	go.windowcreation();
	go.loop();
	return (0);
}
