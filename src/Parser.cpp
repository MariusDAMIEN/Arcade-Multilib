//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#include "../include/Parser.hpp"

Parser::Parser(std::string file_name) :_file(file_name)
{
	open();
}

Parser::~Parser()
{}

bool Parser::open()
{
	if (!_file.is_open())
		throw errHand::Error(std::string("Parse ERROR can not open file ")
				     + std::string("_file"));
	else
		start_parse();
	
}

bool Parser::fill_area()
{
	std::string line;
	int	i = 0;
	int	j = 0;

	while (_file.eof() && getline(_file, line)) {
		i = 0;
		for (char c : line) {
			if (c == 'x')
				create_area(i, j, )
		}
	}
}

bool Parser::start_parse()
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
		pos = _size;
	}
}

int main()
{
	Parser ok("../test");
	return 0;
}
