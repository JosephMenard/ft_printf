# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joseph <joseph@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/30 17:53:36 by joseph            #+#    #+#              #
#    Updated: 2024/06/18 21:15:17 by joseph           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf

INCLUDES = ft_printf.h

SRC = ft_printf.c ft_strs_printf.c ft_nbr_printf.c \
	ft_hex_printf.c ft_ptr_printf.c ft_strlen.c

OBJ = $(SRC:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.c $(INCLUDES)
	$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
