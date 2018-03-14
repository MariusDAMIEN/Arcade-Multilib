//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#ifndef _ISHAPE_HPP_
# define _ISHAPE_HPP_

// template<class T>
class IShape
{
public:
	virtual ~IShape() = default;
	virtual void setPos(int, int) = 0;
	// virtual T getShape();
};

#endif /* !_ISHAPE_HPP_ */