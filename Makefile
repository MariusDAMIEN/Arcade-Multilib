##
## EPITECH PROJECT, 2018
## 
## File description:
## 
##

NAME	= arcade

SFML	= lib_arcade_sfml.so

SOLARFOX	= lib_arcade_solarfox.so

LDFLAGS	=	-l_arcade_sfml 

LDFLAGSGAME	=	-l_arcade_solarfox

CC	= g++

RM	= rm -f

DIR	= src/

DIRLIB	= lib/

DIRGAME	= games/

SRCS	=	$(DIR)main.cpp	\
		$(DIR)errorHandling.cpp
		

SRCSSFML	=	$(DIRLIB)SFML/SfmlSquare.cpp \
			$(DIRLIB)SFML/sfmlFramework.cpp

SRCSSOLAR	=	games/solarFox/solarFox.cpp

OBJS	= $(SRCS:.cpp=.o)

OBJSSFML	= $(SRCSSFML:.cpp=.o)

OBJSSOLAR	= $(SRCSSOLAR:.cpp=.o)

CXXFLAGS = -I./include

CXXFLAGS += -Wall -Wextra -lsfml-graphics -lsfml-window -lsfml-system -fPIC -std=c++14

all: graphicals games core

graphicals: $(SFML)

games: $(SOLARFOX)

core: $(NAME)

$(SOLARFOX): $(OBJSSOLAR)
	$(CC) $(OBJSSOLAR) -shared -o $(DIRGAME)$(SOLARFOX) -L./lib/ $(LDFLAGS)

$(SFML): $(OBJSSFML)
	$(CC) $(OBJSSFML) -shared -o $(DIRLIB)$(SFML) -lsfml-graphics -lsfml-window -lsfml-system

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) -L./lib/ $(LDFLAGS)  -L./games/ $(LDFLAGSGAME)

clean:
	$(RM) $(OBJS)
	$(RM) $(OBJSSFML)
	$(RM) $(OBJSSOLAR)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(DIRLIB)$(SFML)
	$(RM) $(DIRGAME)$(SOLARFOX)

re: fclean all

.PHONY: all clean fclean re
