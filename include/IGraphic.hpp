//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#ifndef _IGRAPHIC_HPP_
# define _IGRAPHIC_HPP_

#include "memory"
#include "IShape.hpp"

// template<class T>
class IGraphic
{
public:
	virtual ~IGraphic() = default;
	virtual void displayOnWindow() = 0;
	virtual void destroy() = 0;
	virtual void character() = 0;
	virtual void wall() = 0;
	virtual void score() = 0;
	virtual void time() = 0;
	virtual void characterName() = 0;
	virtual void item() = 0;
	virtual void createWindow(std::size_t, std::size_t, const std::string &) = 0;
	virtual bool isOpenWindow() const = 0;
	virtual void clearWindow() = 0;
	virtual void destroyWindow() = 0;
	virtual bool isKeyPressed(std::string) = 0;
	virtual std::unique_ptr<IShape> drawRectangle(const std::size_t, const std::size_t, std::string, std::string) = 0;
	// template<typename T2>
	virtual void drawInBuff(IShape &shape, std::string) = 0;
};

#endif /* !_IGRAPHIC_HPP_ */
