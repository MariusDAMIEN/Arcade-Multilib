//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

class gInterface
{
public:
	~gInterface() = default;
	virtual display();
	virtual destroy();
	virtual character();
	virtual wall();
	virtual score();
	virtual time();
	virtual characterName();
	virtual item();
	virtual openWindow();
	virtual destroyWindow();
	virtual getKey();
};