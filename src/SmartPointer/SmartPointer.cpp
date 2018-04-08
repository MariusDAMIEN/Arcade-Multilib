//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#include <memory>
#include "SmartPointer.hpp"

SmartPointer::SmartPointer(std::string str)
	: ok(str)
{
	std::cout << "pointer creation" << std::endl;
}

SmartPointer::~SmartPointer()
{
	std::cout << ok << std::endl;
	std::cout << "pointer desctruction" << std::endl;
}
