//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#ifndef _ISHAPE_HPP_
# define _ISHAPE_HPP_

class IShape
{
public:
	~IShape() = default;
	virtual void setPos(int, int) = 0;
};

#endif /* !_ISHAPE_HPP_ */