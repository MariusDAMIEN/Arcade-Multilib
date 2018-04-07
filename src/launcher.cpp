//
// EPITECH PROJECT, 2018
//
// File description:
//
//

#include <unistd.h>
#include "launcher.hpp"
#include "Parser.hpp"
#include "menu.hpp"

launcher::launcher(const char *lib)
{
        _lib = "./lib/" + std::string(lib);
        change_lib("./lib");
        load_game("./games");
        _select.first = 700;
        _select.second = 550;
        _sel = 0;
        _initName = false;
        _gameIndex = 1;
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

int launcher::load_first_game()
{
        void* handle = dlopen(_nameGame.c_str(), RTLD_LAZY);
        std::cout << _nameGame << std::endl;
        if (!handle)
                throw errHand::Error(std::string("Cannot open game: ")
                                     + std::string(dlerror()));
        dlerror();
        start_t *start = (start_t*) dlsym(handle, "start");
        const char *dlsym_error = dlerror();
        if (dlsym_error) {
                throw errHand::Error(std::string("Cannot load symbol 'start': ")
                                     + std::string(dlsym_error));
                dlclose(handle);
                return 1;
        }
        _igraph->destroyAllArea();
        _igraph->destroyWindow();
        _game = start(_igraph);
        _handleGame = handle;
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
//        windowcreation();
        loop();
}

void launcher::load_game(const char *dir_name)
{
        DIR *dir = opendir(dir_name);
        struct dirent *entry;

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

void  launcher::display_game()
{
  int i = 0;
        int j = 550;
        for ( auto it : _vectGame ) {
                std::string name("ame");
                name = name + std::to_string(i);

                it = it.substr(it.find_last_of("_") + 1);
                it = it.substr(0, it.find(".so"));
                transform(it.begin(), it.end(), it.begin(), toupper);
                std::cout << it << std::endl;
                _igraph->createArea(std::make_pair(40, 40), std::make_pair(700, j)
                                       , std::make_pair(name, it)
                                       , IGraphic::TYPE::TEXT);
                j += 50;
                i++;
        }
        _nbGame = i;
        _igraph->createArea(std::make_pair(50, 50)
                               , std::make_pair(30, 350)
                               , std::make_pair("seconde_validation"
                                                , "When you are select a GAME press 'right'")
                               , IGraphic::TYPE::TEXT);
        _igraph->createArea(std::make_pair(50, 50), std::make_pair(600, 500)
                               , std::make_pair("Gameliste", "Games available :")
                               , IGraphic::TYPE::TEXT);
}

void  launcher::display_lib()
{
        _igraph->createArea(std::make_pair(160, 40), _select
                            , std::make_pair("select", "red"), IGraphic::TYPE::RECT);
        int i = 500;
        for ( auto it : _vectLib ) {
                std::string name("name");
                name = name + it;
                it = it.substr(it.find_last_of("_") + 1);
                it = it.substr(0, it.find(".so"));
                transform(it.begin(), it.end(), it.begin(), toupper);
                std::cout << it << std::endl;
                _igraph->createArea(std::make_pair(50, 50), std::make_pair(30, i)
                                       , std::make_pair(name, it)
                                       , IGraphic::TYPE::TEXT);
                i = i + 50;
        }
        _igraph->createArea(std::make_pair(50, 50), std::make_pair(30, 300)
                               , std::make_pair("Readme", "To change lib press the key 'a'")
                               , IGraphic::TYPE::TEXT);
}

void  launcher::catch_game()
{
  _nameGame = _vectGame[_gameIndex - 1];
}

void launcher::printName()
{
  if (_initName)
      _igraph->deleteArea("NAme");
  _igraph->createArea(std::make_pair(180, 180), std::make_pair(50, 550)
                      , std::make_pair("NAme", _name)
                      , IGraphic::TYPE::TEXT);
  _initName = true;
}

void launcher::input_name()
{
   if (_sel != 1) {
     _igraph->destroyAllArea();
    _igraph->createArea(std::make_pair(50, 50), std::make_pair(30, 300)
                        , std::make_pair("inputname", "Please Input your name press \"up\" to continue : ")
                        , IGraphic::TYPE::TEXT);
    _sel = 1;
  }
  while (_igraph->isKeyPressed("up") == false) {
    if (_igraph->isKeyPressed("a")) {
      _name += "A";
      printName();
      }
    if (_igraph->isKeyPressed("b")) {
      _name += "B";
      printName();
    }
    if (_igraph->isKeyPressed("c")) {
      _name += "C";
      printName();
    }
    if (_igraph->isKeyPressed("d")) {
      _name += "D";
      printName();
    }
    if (_igraph->isKeyPressed("e")) {
      _name += "E";
      printName();
    }
    if (_igraph->isKeyPressed("f")) {
      _name += "F";
      printName();
    }
    if (_igraph->isKeyPressed("g")) {
      _name += "G";
      printName();
    }
    if (_igraph->isKeyPressed("h")) {
      _name += "H";
      printName();
    }
    if (_igraph->isKeyPressed("i")) {
      _name += "I";
      printName();
    }
    if (_igraph->isKeyPressed("j")) {
      _name += "J";
      printName();
      }
    if (_igraph->isKeyPressed("k")) {
      _name += "K";
      printName();
    }
    if (_igraph->isKeyPressed("l")) {
      _name += "L";
      printName();
      }
    if (_igraph->isKeyPressed("m")) {
      _name += "M";
      printName();
    }
    if (_igraph->isKeyPressed("n")) {
      _name += "N";
      printName();
    }
    if (_igraph->isKeyPressed("o")) {
      _name += "O";
      printName();
    }
    if (_igraph->isKeyPressed("p")) {
      _name += "P";
      printName();
    }
    if (_igraph->isKeyPressed("q")) {
      _name += "Q";
      printName();
    }
    if (_igraph->isKeyPressed("r")) {
      _name += "R";
      printName();
    }
    if (_igraph->isKeyPressed("s")) {
      _name += "S";
      printName();
    }
    if (_igraph->isKeyPressed("t")) {
      _name += "T";
      printName();
    }
    if (_igraph->isKeyPressed("u")) {
      _name += "U";
      printName();
    }
    if (_igraph->isKeyPressed("v")) {
      _name += "V";
      printName();
    }
    if (_igraph->isKeyPressed("w")) {
      _name += "W";
      printName();
    }
    if (_igraph->isKeyPressed("x")) {
      _name += "X";
      printName();
    }
    if (_igraph->isKeyPressed("y")) {
      _name += "Y";
      printName();
    }
    if (_igraph->isKeyPressed("z")) {
      _name += "Z";
      printName();
      }
    _igraph->displayObj();
    _igraph->clearWindow();
    }
  load_first_game();
}

bool  launcher::loop()
{
  _igraph->createWindow(std::make_pair(WIDTH, HEIGHT), "oklm");
  if (_sel == 0) {
    _igraph->createArea(std::make_pair(200, 200), std::make_pair(250, 0)
                        , std::make_pair("Title", "ARCADE"), IGraphic::TYPE::TEXT);
    display_lib();
    display_game();
  }
        while (1) {
                if (_igraph->isKeyPressed("a") == true) {
                  if (_sel == 1)
                    _sel = 2;
                  next_lib();
                }
                if (_igraph->isKeyPressed("b") == true) {
                        _igraph->destroyWindow();
                        exit(5);
                }
                if (_igraph->isKeyPressed("up") == true) {
                  if (_gameIndex != 1) {
                    _select.second -= 50;
                    _gameIndex--;
                  }
                  _igraph->setpos(_select, "select");
                }
                if (_igraph->isKeyPressed("down") == true) {
                  if (_gameIndex < _nbGame) {
                    _select.second += 50;
                    _gameIndex++;
                  }
                  _igraph->setpos(_select, "select");
                }
                if (_igraph->isKeyPressed("right") == true || _sel == 2) {
                  catch_game();
                  input_name();
                }
                _igraph->displayObj();
                _igraph->clearWindow();
        }
}

void launcher::windowcreation()
{
        _igraph->createWindow(std::make_pair(WIDTH, HEIGHT), "oklm");
}


int launch(char *lib)
{
        launcher go(lib);

        go.load_first_lib();
        //go.windowcreation();
        go.loop();
        return (0);
}
