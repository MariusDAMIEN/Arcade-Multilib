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

bool Parser::start_parse()
{
	std::string line;
	std::pair<int , int> pos(1, 2);
	int	i = 0;
	int	j = 0;

	if (getline(_file, line)) {
		if (line.empty())
			throw errHand::Error(std::string("Parse ERROR: first line empty ")
					     + std::string("_file"));
		for (char c : line) {
 			i++;
			if (isdigit(c)) {
				continue;
			}
			else {
				if (c != 'x') {
					throw errHand::Error(std::string("Parse ERROR: size must be separated by an 'x'")
							     + std::string("_file"));
					j = 1;
				}
				
				else {
					pos.first = atoi(line.c_str());
					line = line.substr(i + 1);
					continue;
					std::cout << pos.first << std::endl;
					std::cout << pos.second << std::endl;
				}
				
			}
		}
	}
/*	while (!_file.eof() && getline(_file, line)) {
		;
		}*/
}

int main()
{
	Parser ok("../test");
	return 0;
}
