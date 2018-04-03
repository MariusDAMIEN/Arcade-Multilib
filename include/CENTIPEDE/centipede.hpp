//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#ifndef _CENTIPEDE_HPP_
# define _CENTIPEDE_HPP_

#include "IGame.hpp"
#include "IGraphic.hpp"

# define WIDTH 1200
# define HEIGHT 800

class Centipede : public IGame
{
public:
        Centipede(IGraphic *);
        ~Centipede();
        void loop();
        void changeLib(IGraphic *) override;
private:
	IGraphic *_igraph;
};

#endif /* !_CENTIPEDE_HPP_*/
