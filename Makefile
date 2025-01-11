NAME = fractol

CC = cc

CFLAGS = #-Wall -Werror -Wextra -g 
MLXFLAGS = -L ./includes/minilibx -lmlx -Ilmlx -lXext -lX11
LIBFT = ./includes/libft/libft.a

SRC = srcs/main.c
# srcs/burning.c \
# srcs/complex_math.c \
# srcs/hooks.c \
# srcs/julia.c \
# srcs/mandelbrot.c \
# srcs/params.c


all: $(NAME)

$(NAME): $(SRC:.c=.o)
	$(MAKE) --no-print-directory -C ./includes/libft
	echo "\033[1m LIBFT done \033[0m"
	$(MAKE) --no-print-directory -C ./includes/minilibx
	echo "\033[1m MiniLibX done \033[0m"
	$(CC) $(CFLAGS) -lm $(SRC) $(LIBFT) $(MLXFLAGS) -o $(NAME)
	echo "\033[1m Ready to FRACT-OL \033[0m"

clean:
	$(MAKE) clean -C ./includes/libft
	rm -rf $(SRC:.c=.o)
	echo "OBJ deleted"

fclean: clean
	$(MAKE) fclean -C ./includes/libft
	rm -rf $(NAME)
	echo "$(NAME) deleted"

re: fclean all

.PHONY: all, clean, fclean, re, bonus

.SILENT: