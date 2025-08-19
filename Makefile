CXX			=	g++
CXXFLAGS	=	-Wall -Wextra -std=c++17 -fPIC -fno-gnu-unique -I./include
RM			=	rm -f

NAME		=	arcade_exec
SRC_CORE	=	Arcade/Core.cpp \
				Arcade/main.cpp
OBJ_CORE	=	$(SRC_CORE:.cpp=.o)
LDFLAGS_CORE=	-ldl

LIB_DIR			=	./lib/

GAMES_SO		=	$(LIB_DIR)arcade_nibbler.so \
					$(LIB_DIR)arcade_pacman.so

GRAPHICS_SO		=	$(LIB_DIR)arcade_ncurses.so \
					$(LIB_DIR)arcade_sdl2.so \
					$(LIB_DIR)arcade_sfml.so

NCURSES_LDFLAGS	=	-lncurses
SDL2_LDFLAGS	=	`sdl2-config --cflags --libs` -lSDL2_ttf
SFML_LDFLAGS	=	-lsfml-graphics -lsfml-window -lsfml-system

all:	$(NAME) $(GAMES_SO) $(GRAPHICS_SO)

$(NAME):	$(OBJ_CORE)
	$(CXX) -o $(NAME) $(OBJ_CORE) $(LDFLAGS_CORE)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

core:	$(NAME)

games:	$(GAMES_SO)

graphicals:	$(GRAPHICS_SO)

$(LIB_DIR):
	mkdir -p $(LIB_DIR)

$(LIB_DIR)arcade_nibbler.so: src/games/Nibbler/Nibbler.cpp | $(LIB_DIR)
	$(CXX) $(CXXFLAGS) -shared -o $@ $<

$(LIB_DIR)arcade_pacman.so: src/games/Pacman/Pacman.cpp | $(LIB_DIR)
	$(CXX) $(CXXFLAGS) -shared -o $@ $<

$(LIB_DIR)arcade_ncurses.so: src/graphicals/Ncurses/Ncurses.cpp | $(LIB_DIR)
	$(CXX) $(CXXFLAGS) -shared -o $@ $< $(NCURSES_LDFLAGS)

$(LIB_DIR)arcade_sdl2.so: src/graphicals/SDL2/SDL2.cpp | $(LIB_DIR)
	$(CXX) $(CXXFLAGS) -shared -o $@ $< $(SDL2_LDFLAGS)

$(LIB_DIR)arcade_sfml.so: src/graphicals/SFML/SFML.cpp | $(LIB_DIR)
	$(CXX) $(CXXFLAGS) -shared -o $@ $< $(SFML_LDFLAGS)

clean:
	$(RM) $(OBJ_CORE)
	$(RM) -r $(LIB_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all core games graphicals clean fclean re