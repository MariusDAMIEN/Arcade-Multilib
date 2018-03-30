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

private:
	std::string _lib;
        void const * _handle;
	IGraphic *_igraph;
};

#endif /* !_LAUNCHER_HPP_ */
