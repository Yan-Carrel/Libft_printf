# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yaandria <yaandria@student.42antananari    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/25 16:03:47 by yaandria          #+#    #+#              #
#    Updated: 2026/02/25 16:12:44 by yaandria         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -I./includes/ -I./_bonus/
RM = rm -rf
NAME = libftprintf.a
NAME_BONUS = libftprintf_bonus.a

# Basic sources
SRCS = ft_printf.c srcs/ft_putchar_ba.c srcs/ft_putstr_ba.c srcs/ft_puthex_ba.c srcs/ft_putnbr_ba.c srcs/print_basics.c
OBJS = $(SRCS:.c=.o)

# Bonus sources
BONUS_SRCS = _bonus/ft_printf_bonus.c \
	_bonus/print_bonus.c \
	_bonus/print_char_bonus.c \
	_bonus/print_str_bonus.c \
	_bonus/print_nbr_bonus.c \
	_bonus/print_hex_bonus.c \
	_bonus/print_pointer_bonus.c \
	_bonus/ft_put_n_nbr_bonus.c \
	_bonus/ft_puthex_bonus.c \
	_bonus/parse_all_bonus.c

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Merging libft.a into $(NAME)..."
	ar x $(LIBFT)
	ar rcs $(NAME) $(OBJS) *.o
	@echo "$(NAME) created successfully!"

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(BONUS_OBJS)
	@echo "Creating bonus library $(NAME_BONUS)..."
	ar x $(LIBFT)
	ar rcs $(NAME_BONUS) $(BONUS_OBJS) *.o
	@echo "$(NAME_BONUS) created successfully!"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(BONUS_OBJS) *.o

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)

re: fclean all

re_bonus: fclean bonus

.PHONY: all bonus clean fclean re re_bonus
.SILENT: