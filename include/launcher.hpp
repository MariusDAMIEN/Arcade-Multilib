//
// EPITECH PROJECT, 2018
//
// File description:
//
//

#ifndef _LAUNCHER_HPP_
# define _LAUNCHER_HPP_

# include <cctype>
#include <dlfcn.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
#include <vector>
#include <algorithm>
#include "arcade.hpp"
#include "SmartPointer.hpp"
#include "ERROR/ErrorHandling.hpp"
# include "IGraphic.hpp"
#include "IGame.hpp"

typedef IGraphic* create_t();
typedef IGame* start_t(IGraphic*);

class launcher {
public:
        launcher(const char *lib);
        ~launcher();
        int load_first_lib();
        int load_first_game();
        void windowcreation();
        bool loop();
        void load_game(const char *lib);
        void change_lib(const char *lib);
        void  display_lib();
        void  display_game();
        void  catch_game();
        void input_name();
        void printName();
private:
        void next_lib();
        std::string _lib;
        void const *_handleGame;
        std::vector<std::string> _vectLib;
        std::vector<std::string> _vectGame;
        std::vector<std::string>::iterator _libIt;
        std::pair<int, int> _select;
        void const * _handle;
        IGraphic *_igraph;
        IGame   *_game;
        int	_sel;
        bool _initName;
        std::pair<int, int> _posName;
        std::string _name;
        int	_gameIndex;
        int	_nbGame;
        std::string _nameGame;
};

#endif /* !_LAUNCHER_HPP_ */
