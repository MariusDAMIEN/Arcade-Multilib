// 
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#ifndef _PARSER_HPP_
# define _PARSER_HPP_

#include <iostream>
#include <fstream>
#include <unordered_map>
#include <map>
#include <utility>
#include "IGraphic.hpp"
#include "ERROR/ErrorHandling.hpp"

#ifndef WIDTH
#define WIDTH 1200
#endif /* !WIDTH */

#ifndef WEIGHT
#define HEIGHT 800
#endif /* !WEIGHT */

class Parser {
public:
        Parser(IGraphic **igraph, std::string file_name, std::string tex);
        virtual ~Parser();

private:
        std::pair<int, int > _size;
        std::ifstream _file;
        void start_parse();
        void fill_area();
        void create_area(int i, int j);
        void open();
        std::string _tex;
        unsigned int _id;
        IGraphic **_igraph;
};

#endif /* !_PARSER_HPP_ */
