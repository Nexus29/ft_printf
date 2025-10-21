# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glancell <glancell@student.42firenze.it    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/24 16:03:58 by glancell          #+#    #+#              #
#    Updated: 2025/09/29 22:17:30 by glancell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

SRCS =	src/ft_applier_bonus.c \
		src/ft_init.c \
		src/ft_parse_bonus.c \
		src/ft_put_utils.c \
		src/ft_support.c \
		src/ft_print_str_bonus.c \
		src/ft_print_pointer_bonus.c \
		src/ft_print_int_bonus.c \
		src/ft_print_unsigned_bonus.c \
		src/ft_print_hex_bonus.c 


OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

bonus: all

re: fclean all

.PHONY: all clean fclean re bonus
