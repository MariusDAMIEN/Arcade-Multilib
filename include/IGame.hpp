//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#ifndef _IGAME_HPP_
#define _IGAME_HPP_

#include "IGraphic.hpp"

class IGame
{
public:
        virtual ~IGame() = default;
        virtual void changeLib(IGraphic *) = 0;
        virtual int loop() = 0;
};



#endif /* !_IGAME_HPP_ */
