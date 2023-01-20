# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/17 13:37:51 by abourdon          #+#    #+#              #
#    Updated: 2023/01/17 13:38:03 by abourdon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Werror -Wextra -g3
AR = ar rcs
RM = rm -rf
SRC =		ft_strlenn.c \
	ft_strjoin.c \
	ft_split.c \
	ft_itoa.c \
	ft_calloc.c \
	get_next_line/get_next_line_utils.c \
	get_next_line/get_next_line.c \
	printf/ft_printf.c \
	printf/ft_putchar.c \
	printf/ft_putnb_base.c \
	printf/ft_putnbr_unsi.c \
	printf/ft_putnbr.c \
	printf/ft_putstr.c \
	printf/ft_putvoid.c \
	
OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re