# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yaandria <yaandria@student.42antananari    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/25 16:03:47 by yaandria          #+#    #+#              #
#    Updated: 2026/02/25 16:03:49 by yaandria         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -I./includes/
RM = rm -rf
NAME = libftprintf.a

SRCS = ft_printf.c srcs/ft_putchar_ba.c srcs/ft_putstr_ba.c srcs/ft_puthex_ba.c srcs/ft_putnbr_ba.c srcs/print_basics.c
OBJS = $(SRCS:.c=.o)

LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Merging libft.a into $(NAME)..."
	ar x $(LIBFT)       # extract libft objects into current folder
	ar rcs $(NAME) $(OBJS) *.o
	@echo "$(NAME) created successfully!"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
.SILENT: