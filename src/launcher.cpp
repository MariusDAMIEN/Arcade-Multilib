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
	closedir(dir);
}

bool launcher::loop()
{
	change_lib("./lib");
	_igraph->createArea(std::make_pair(200, 200), std::make_pair(10, 10)
			    , std::make_pair(marius, "blue"), IGraphic::TYPE::CHARAC);
	_igraph->createArea(std::make_pair(50, 200), std::make_pair(300, 10)
			    , std::make_pair("Name", "trop fort chieffff marius"), IGraphic::TYPE::TEXT)	while (1) {
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
