##
## EPITECH PROJECT, 2018
## 
## File description:
## 
##

NAME	= arcade

SFML	= libsfml.so

LDFLAGS	=	-lsfml

CC	= g++

RM	= rm -f

DIR	= src/

DIRLIB	= lib/

SRCS	=	games/solarFox/solarFox.cpp \
		$(DIR)main.cpp	\
		$(DIR)errorHandling.cpp
		

SRCSSFML	=	$(DIRLIB)SFML/SfmlSquare.cpp \
			$(DIRLIB)SFML/sfmlFramework.cpp
			

OBJS	= $(SRCS:.cpp=.o)

OBJSSFML	= $(SRCSSFML:.cpp=.o)

CXXFLAGS = -I./include

CXXFLAGS += -Wall -Wextra -lsfml-graphics -lsfml-window -lsfml-system -fPIC -std=c++14

all: $(SFML) $(NAME)

$(SFML): $(OBJSSFML)
	$(CC) $(OBJSSFML) -shared -o $(DIRLIB)$(SFML) -lsfml-graphics -lsfml-window -lsfml-system

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) -L./lib/ $(LDFLAGS)

clean:
	$(RM) $(OBJS)
	$(RM) $(OBJSSFML)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(DIRLIB)$(SFML)

re: fclean all

.PHONY: all clean fclean re
