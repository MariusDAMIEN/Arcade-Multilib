//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#ifndef _SFMLFRAMEWORK_HPP_
# define _SFMLFRAMEWORK_HPP_

#include "IGraphic.hpp"

class sfmlFramework : public IGraphic
{
public:
	sfmlFramework();
	~sfmlFramework();
	void display() override;
	void destroy() override;
	void character() override;
	void wall() override;
	void score() override;
	void time() override;
	void characterName() override;
	void item() override;
	void openWindow() override;
	void destroyWindow() override;
	void getKey() override;
};

#endif /* !_SFMLFRAMEWORK_HPP_ */