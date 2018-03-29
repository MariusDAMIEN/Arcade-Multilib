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
#include <utility>
#include "../include/IGraphic.hpp"
#include "../include/ERROR/ErrorHandling.hpp"

class Parser {
public:
	Parser(std::string file_name);
	virtual ~Parser();

private:
	std::pair<int, int > _size;
	std::ifstream _file;
	bool start_parse();
	bool open();
	std::unordered_map< std::string, std::pair<int, int>  > _dim;
};

#endif /* !_PARSER_HPP_ */
