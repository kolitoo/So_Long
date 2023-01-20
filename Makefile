# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/13 16:57:12 by abourdon          #+#    #+#              #
#    Updated: 2023/01/20 13:29:42 by abourdon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Wall -Werror -Wextra -g3
Ldflags = -lmlx -lX11 -lXext -lz -lm
LIBFT_PATH = ./libft/
MLX_PATH = ./mlx_linux/
Libs = -L./mlx_linux
LIBFT = libft/libft.a
RM = rm -rf

SRC =	main.c \
	fonctions/map.c \
	fonctions/render.c \
	fonctions/move.c \
	fonctions/check.c \
	fonctions/event.c \
	fonctions/utils.c \
	fonctions/backtracking.c \
	fonctions/utils2.c \
	fonctions/backtrackingC.c \
	fonctions/lst_chaine.c \

OBJ = $(SRC:.c=.o)

$(NAME): init $(OBJ)
	$(CC) $(CFLAGS) $(Libs) $(OBJ) $(LIBFT) -o $(NAME) $(Ldflags)

all: $(NAME)

init: 
	make -C $(LIBFT_PATH)
	make -C $(MLX_PATH)

clean: $(clean)
	$(RM) $(OBJ)
	make clean -C $(LIBFT_PATH)
	make clean -C $(MLX_PATH)

fclean: clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT_PATH)

re: fclean all

.PHONY: init all clean fclean re