//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#ifndef _IGRAPHIC_HPP_
# define _IGRAPHIC_HPP_

class IGraphic
{
public:
	virtual ~IGraphic() = default;
	virtual void display() = 0;
	virtual void destroy() = 0;
	virtual void character() = 0;
	virtual void wall() = 0;
	virtual void score() = 0;
	virtual void time() = 0;
	virtual void characterName() = 0;
	virtual void item() = 0;
	virtual void createWindow(std::size_t, std::size_t, const std::string &) = 0;
	virtual bool openWindow() const = 0;
	virtual void clearWindow() = 0;
	virtual void destroyWindow() = 0;
	virtual bool getKey(std::string &) = 0;
};

#endif /* !_IGRAPHIC_HPP_ */
