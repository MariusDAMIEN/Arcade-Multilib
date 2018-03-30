##
## EPITECH PROJECT, 2018
## 
## File description:
## 
##

NAME	= arcade

SFML	= lib_arcade_sfml.so

NCURSE	= lib_arcade_ncurse.so

ALLEGRO	= lib_arcade_allegro.so

SOLARFOX	= lib_arcade_solarfox.so

LDFLAGS	=	-l_arcade_sfml -l_arcade_ncurse -l_arcade_allegro

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
			$(DIRLIB)SFML/SfmlText.cpp	\
			$(DIRLIB)SFML/SfmlCircle.cpp	\
			$(DIRLIB)SFML/SfmlManageSprite.cpp

SRCSNCURSE	=	$(DIRLIB)NCURSE/ncurseFramework.cpp	\
			$(DIR)errorHandling.cpp	\

SRCSALLEGRO	=	$(DIRLIB)ALLEGRO/AllegroFramework.cpp	\
			$(DIR)errorHandling.cpp

SRCSSOLAR	=	$(DIRGAME)solarFox/solarFox.cpp

OBJS	= $(SRCS:.cpp=.o)

OBJSSFML	= $(SRCSSFML:.cpp=.o)

OBJSNCURSE	= $(SRCSNCURSE:.cpp=.o)

OBJSALLEGRO	= $(SRCSALLEGRO:.cpp=.o)

OBJSSOLAR	= $(SRCSSOLAR:.cpp=.o)

CXXFLAGS = -I./include

CXXFLAGS += -Wall -Wextra -fPIC -std=c++14 -g3 -ldl

all: graphicals games core

graphicals: $(SFML) $(NCURSE) $(ALLEGRO)

games: $(SOLARFOX)

core: $(NAME)

$(SOLARFOX): $(OBJSSOLAR)
	$(CC) $(OBJSSOLAR) -shared -o $(DIRGAME)$(SOLARFOX)

$(SFML): $(OBJSSFML)
	$(CC) $(OBJSSFML) -shared -o $(DIRLIB)$(SFML) -lsfml-graphics -lsfml-window -lsfml-system

$(NCURSE): $(OBJSNCURSE)
	$(CC) $(OBJSNCURSE) -shared -o $(DIRLIB)$(NCURSE) -lncurses

$(ALLEGRO): $(OBJSALLEGRO)
	$(CC) $(OBJSALLEGRO) -shared -o $(DIRLIB)$(ALLEGRO) -lallegro -lallegro_dialog -lallegro_font -lallegro_ttf -lallegro_primitives

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) -ldl  -L./games/ $(LDFLAGSGAME)

clean:
	$(RM) $(OBJS)
	$(RM) $(OBJSSFML)
	$(RM) $(OBJSNCURSE)
	$(RM) $(OBJSALLEGRO)
	$(RM) $(OBJSSOLAR)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(DIRLIB)$(SFML)
	$(RM) $(DIRLIB)$(NCURSE)
	$(RM) $(DIRLIB)$(ALLEGRO)
	$(RM) $(DIRGAME)$(SOLARFOX)

re: fclean all

.PHONY: all clean fclean re
