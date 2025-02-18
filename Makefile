NAME = fractol

CC = cc

CFLAGS = #-Wall -Werror -Wextra -g 
MLXFLAGS = -L ./minilibx -lmlx -Ilmlx -lXext -lX11
LIBFT = ./includes/libft/libft.a

SRC = 	srcs/main.c \
		srcs/window.c \
		srcs/handlers.c \
		srcs/destroy.c \
		srcs/julia.c \
		srcs/convertr.c
# srcs/burning.c \
# srcs/complex_math.c \
# srcs/hooks.c \
# srcs/julia.c \
# srcs/mandelbrot.c \
# srcs/params.c


all: $(NAME)

$(NAME): $(SRC:.c=.o)
	$(MAKE) --no-print-directory -C ./includes/libft
	echo "LIBFT done"
	$(MAKE) --no-print-directory -C ./minilibx
	echo "MiniLibX done"
	$(CC) $(CFLAGS) -lm $(SRC) $(LIBFT) $(MLXFLAGS) -o $(NAME)
	echo "Ready to FRACT-OL"

clean:
	$(MAKE) clean -C ./includes/libft
	$(MAKE) clean -C ./minilibx
	rm -rf $(SRC:.c=.o)
	echo "OBJ deleted"

fclean: clean
	$(MAKE) fclean -C ./includes/libft
	$(MAKE) clean -C ./minilibx
	rm -rf $(NAME)
	echo "$(NAME) deleted"

re: fclean all

.PHONY: all, clean, fclean, re, bonus

.SILENT: