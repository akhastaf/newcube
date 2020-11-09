C = gcc -I /usr/local/include
DEP = -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit
# C = gcc
MLX = -L mlx_lib -lmlx 
# DEP = -framework OpenGL -framework AppKit
FLAGS = -Wall -Wextra -Werror
NAME = cub3D
D = -g
SRC = ./src/*.c ./src/utils/*.c ./src/load/*.c

all: $(NAME)

$(NAME):
	@./compile.sh 2 LCF main.c gcc -o $(NAME) $(SRC) $(DEP) -include malloc.h
	#@$(C) $(FLAGS) -o $(NAME) $(SRC) $(DEP)

clean:
	@rm -f $(NAME)
re: clean all