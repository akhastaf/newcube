C = gcc -I /usr/local/include
DEP = -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit
# C = gcc
MLX = -L mlx_lib -lmlx 
# DEP = -framework OpenGL -framework AppKit
FLAGS = -Wall -Wextra -Werror
NAME = cub3D
D = -g
SRC = ./src/*.c main.c

all: $(NAME)

$(NAME):
	$(C) $(FLAGS) -o $(NAME) $(SRC) $(DEP)
debug:
	$(C) $(FLAGS) -o $(NAME) $(SRC) $(MLX) $(DEP) $(D) -fsanitize=address
	#lldb $(NAME)
run:
	./$(NAME)

clean:
	rm -f $(NAME)
re: clean all