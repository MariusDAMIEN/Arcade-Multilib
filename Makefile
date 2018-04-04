##
## EPITECH PROJECT, 2018
## 
## File description:
## 
##

export MAKEFLAGS="-i"

NAME	= arcade

SFML	= lib_arcade_sfml.so

NCURSE	= lib_arcade_ncurse.so

ALLEGRO	= lib_arcade_allegro.so

SOLARFOX	= lib_arcade_solarfox.so

CENTIPEDE	= lib_arcade_centipede.so

LDFLAGS	=	-l_arcade_sfml -l_arcade_ncurse -l_arcade_allegro

LDFLAGSGAME	=	-l_arcade_solarfox -l_arcade_centipede

CC	= g++

RM	= rm -f

DIR	= src/

DIRLIB	= lib/

DIRGAME	= games/

SRCS	=	$(DIR)main.cpp	\
		$(DIR)launcher.cpp	\
		$(DIR)SmartPointer/SmartPointer.cpp	\
		$(DIR)errorHandling.cpp	\
		$(DIR)Parser.cpp						\


SRCSSFML	=	$(DIRLIB)SFML/sfmlFramework.cpp	\
			$(DIR)errorHandling.cpp	\
			$(DIRLIB)SFML/SfmlSquare.cpp	\
			$(DIRLIB)SFML/SfmlText.cpp	\
			$(DIRLIB)SFML/SfmlCircle.cpp	\
			$(DIRLIB)SFML/SfmlManageSprite.cpp

SRCSNCURSE	=	$(DIRLIB)NCURSE2/ncurseFramework.cpp	\
			$(DIR)errorHandling.cpp	\
			$(DIRLIB)NCURSE2/ShapeN.cpp

SRCSALLEGRO	=	$(DIRLIB)ALLEGRO/AllegroFramework.cpp	\
			$(DIR)errorHandling.cpp

SRCSSOLAR	=	$(DIRGAME)solarFox/solarFox.cpp

SRCSCENTI	=	$(DIRGAME)centipede/centipede.cpp

OBJS	= $(SRCS:.cpp=.o)

OBJSSFML	= $(SRCSSFML:.cpp=.o)

OBJSNCURSE	= $(SRCSNCURSE:.cpp=.o)

OBJSALLEGRO	= $(SRCSALLEGRO:.cpp=.o)

OBJSSOLAR	= $(SRCSSOLAR:.cpp=.o)

OBJSCENTI	= $(SRCSCENTI:.cpp=.o)

CXXFLAGS = -I./include

CXXFLAGS += -Wall -Wextra -fPIC -std=c++14 -g3 -ldl

all: core graphicals games

graphicals: $(SFML) $(NCURSE) $(ALLEGRO)

games: $(SOLARFOX) $(CENTIPEDE)

core: $(NAME)

$(SOLARFOX): $(OBJSSOLAR)
	$(CC) $(OBJSSOLAR) -shared -o $(DIRGAME)$(SOLARFOX)

$(CENTIPEDE): $(OBJSCENTI)
	$(CC) $(OBJSCENTI) -shared -o $(DIRGAME)$(CENTIPEDE)

$(SFML): $(OBJSSFML)
	$(CC) $(OBJSSFML) -shared -o $(DIRLIB)$(SFML) -lsfml-graphics -lsfml-window -lsfml-system

$(NCURSE): $(OBJSNCURSE)
	$(CC) $(OBJSNCURSE) -shared -o $(DIRLIB)$(NCURSE) -lncurses

$(ALLEGRO): $(OBJSALLEGRO)
	$(CC) $(OBJSALLEGRO) -shared -o $(DIRLIB)$(ALLEGRO) -lallegro -lallegro_dialog -lallegro_font -lallegro_ttf -lallegro_primitives -lallegro_image

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) -ldl  -L./games/ $(LDFLAGSGAME)

clean:
	$(RM) $(OBJS)
	$(RM) $(OBJSSFML)
	$(RM) $(OBJSNCURSE)
	$(RM) $(OBJSALLEGRO)
	$(RM) $(OBJSSOLAR)
	$(RM) $(OBJSCENTI)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(DIRLIB)$(SFML)
	$(RM) $(DIRLIB)$(NCURSE)
	$(RM) $(DIRLIB)$(ALLEGRO)
	$(RM) $(DIRGAME)$(SOLARFOX)
	$(RM) $(DIRGAME)$(CENTIPEDE)

re: fclean all

.PHONY: all clean fclean re
