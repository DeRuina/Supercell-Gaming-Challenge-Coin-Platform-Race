NAME = Coin_Race

SRC = main.cpp Game.cpp Coins.cpp Player.cpp

FLAGS = -O3 -std=c++17

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(SRC)
	@g++ $(FLAGS) -o $(NAME) $(SRC) -lsfml-graphics -lsfml-window -lsfml-system

clean:
	@rm -f $(NAME)

fclean: clean
	@rm -f $(NAME)

re: fclean all

debug: FLAGS += -g
debug: re

