//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#ifndef _CENTIPEDE_HPP_
# define _CENTIPEDE_HPP_

#include "CENTIPEDE/bodyGestion.hpp"
#include "CENTIPEDE/player.hpp"

class Centipede : public IGame
{
public:
        Centipede(IGraphic *);
        ~Centipede();
        int loop();
        void changeLib(IGraphic *) override;
        void displayMush();
	void algo();
	void initCent();
	void movCent();
private:
	IGraphic *_igraph;
	std::vector< std::pair<int, int> > _posMush;
	std::vector<Bug> _bodies;
	std::vector<Player> _player;
	bool _init;
	bool _meaning;
};

#endif /* !_CENTIPEDE_HPP_*/
