##
## EPITECH PROJECT, 2018
## 
## File description:
## 
##

NAME	= arcade

SFML	= lib_arcade_sfml.so

NCURSE	= lib_arcade_ncurse.so

SOLARFOX	= lib_arcade_solarfox.so

LDFLAGS	=	-l_arcade_sfml -l_arcade_ncurse

LDFLAGSGAME	=	-l_arcade_solarfox

CC	= g++

RM	= rm -f

DIR	= src/

DIRLIB	= lib/

DIRGAME	= games/

SRCS	=	$(DIR)main.cpp	\
		$(DIR)launcher.cpp	\
		$(DIR)SmartPointer/SmartPointer.cpp	\
		$(DIR)errorHandling.cpp	\


SRCSSFML	=	$(DIRLIB)SFML/sfmlFramework.cpp	\
			$(DIR)errorHandling.cpp	\
			$(DIRLIB)SFML/SfmlSquare.cpp	\
			$(DIRLIB)SFML/SfmlManageSprite.cpp

SRCSNCURSE	=	$(DIRLIB)NCURSE/ncurseFramework.cpp	\
			$(DIR)errorHandling.cpp	\

SRCSSOLAR	=	games/solarFox/solarFox.cpp

OBJS	= $(SRCS:.cpp=.o)

OBJSSFML	= $(SRCSSFML:.cpp=.o)

OBJSNCURSE	= $(SRCSNCURSE:.cpp=.o)

OBJSSOLAR	= $(SRCSSOLAR:.cpp=.o)

CXXFLAGS = -I./include

CXXFLAGS += -Wall -Wextra -lsfml-graphics -lsfml-window -lsfml-system -fPIC -std=c++14 -g3 -lncurses -Wfatal-errors

all: graphicals games core

graphicals: $(SFML) $(NCURSE)

games: $(SOLARFOX)

core: $(NAME)

$(SOLARFOX): $(OBJSSOLAR)
	$(CC) $(OBJSSOLAR) -shared -o $(DIRGAME)$(SOLARFOX) -L./lib/ $(LDFLAGS)

$(SFML): $(OBJSSFML)
	$(CC) $(OBJSSFML) -shared -o $(DIRLIB)$(SFML) -lsfml-graphics -lsfml-window -lsfml-system

$(NCURSE): $(OBJSNCURSE)
	$(CC) $(OBJSNCURSE) -shared -o $(DIRLIB)$(NCURSE) -lncurses

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) -ldl -L./lib/ $(LDFLAGS)  -L./games/ $(LDFLAGSGAME)

clean:
	$(RM) $(OBJS)
	$(RM) $(OBJSSFML)
	$(RM) $(OBJSNCURSE)
	$(RM) $(OBJSSOLAR)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(DIRLIB)$(SFML)
	$(RM) $(DIRLIB)$(NCURSE)
	$(RM) $(DIRGAME)$(SOLARFOX)

re: fclean all

.PHONY: all clean fclean re
