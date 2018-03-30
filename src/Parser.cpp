//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#include "Parser.hpp"


Parser::Parser(IGraphic **igraph, std::string file_name, std::string tex)
        :_file(file_name), _tex(tex), _igraph(igraph)
{
	_id = 0;
        std::cout << "ID : "
                  << _id
                  << std::endl;
        open();
}

Parser::~Parser()
{}

void Parser::create_area(int i, int j)
{
        std::pair<int, int> dim[2];
        std::pair<std::string, std::string> ok;
        std::string wall("wall");
        wall = wall + std::to_string(_id);
        _id++;

        dim[0].first = (WIDTH / _size.first) * i;
        dim[0].second = (HEIGHT / _size.second) * j;;
        dim[1].first = (WIDTH / _size.first);
        dim[1].second = (HEIGHT / _size.second);
        (*_igraph)->createArea(dim[1], dim[0], std::make_pair(wall, _tex), IGraphic::TYPE::RECT);
}

void Parser::open()
{
        if (!_file.is_open())
                throw errHand::Error(std::string("Parse ERROR can not open file ")
                                     + std::string("_file"));
        else
                start_parse();
}

void Parser::fill_area()
{
        std::string line;
        int	i = 0;
        int	j = 0;

	while (!_file.eof() && getline(_file, line)) {
                i = 0;
                // if (line.npos() != _size.first)
                //         throw errHand::Error("ERROR: parse nb column incompatible");

                for (char c : line) {
                        if (c == 'x' || c == ' ' ) {
                          if (c == 'x')
                            create_area(i, j);
                        }
                        else
                          throw errHand::Error("ERROR PARSER :  symbole autorised 'x'");
                        i++;
                }
                j++;
  }
}

void Parser::start_parse()
{
        std::string line;
        std::pair<int , int> pos(1, 2);
        int	i = 0;

        if (getline(_file, line)) {
                if (line.empty())
                        throw errHand::Error(std::string("Parse ERROR: first line empty ")
                                             + std::string("_file"));
                for (char c : line) {
                        i++;
                        if (isdigit(c))
                                continue;
                        if (c != 'x')
                                throw errHand::Error(std::string("Parse ERROR: size must be separated by an 'x'")
                                                     + std::string("_file"));
                        pos.first = atoi(line.c_str());
                        line = line.substr(i);
                        break;
                }
                for (char c : line) {
                        if (isdigit(c))
                                continue;
                        else
                                throw errHand::Error(std::string("Parse ERROR: size must be digit"));
                }
                pos.second = atoi(line.c_str());
                _size = pos;
                fill_area();
        }
}
