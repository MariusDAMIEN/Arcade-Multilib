/*
** EPITECH PROJECT, 2018
** ErrorHandling
** File description:
** .cpp
*/


#include "ERROR/ErrorHandling.hpp"

const char* errHand::Error::what() const throw()
{
        return _errMsg.c_str();
}

errHand::Error::Error(std::string const &msg) throw()
        :_errMsg(msg)
{}

errHand::Error::~Error() throw()
{}