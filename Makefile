# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yaandria <yaandria@student.42antananari    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/25 16:03:47 by yaandria          #+#    #+#              #
#    Updated: 2026/02/27 14:08:18 by yaandria         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        := libftprintf.a

CC          := cc
CFLAGS      := -Wall -Wextra -Werror

AR          := ar
ARFLAGS     := rcs
RM          := rm -f

SRC_DIR     := srcs
INC_DIR     := header/.
BONUS_DIR   := _bonus/.
LIBFT_DIR   := libft
LIBFT_A     := $(LIBFT_DIR)/libft.a

# ---------- Mandatory ----------
MAND_SRC    := ft_printf.c $(wildcard $(SRC_DIR)/*.c)
MAND_OBJ    := $(MAND_SRC:.c=.o)
MAND_INC    := -I$(INC_DIR) -I$(LIBFT_DIR)

# ---------- Bonus ----------
BONUS_SRC   := $(wildcard $(BONUS_DIR)/*.c)
BONUS_OBJ   := $(BONUS_SRC:.c=.o)
BONUS_INC   := -I$(BONUS_DIR) -I$(LIBFT_DIR)

BONUS_STAMP := .bonus

.PHONY: all bonus clean fclean re

all: $(NAME)

# Build mandatory library
$(NAME): $(LIBFT_A) $(MAND_OBJ)
	@cp $(LIBFT_A) $(NAME)
	@$(AR) $(ARFLAGS) $(NAME) $(MAND_OBJ)

# Build bonus: add bonus objects into the same NAME
bonus: $(BONUS_STAMP)

$(BONUS_STAMP): $(LIBFT_A) $(MAND_OBJ) $(BONUS_OBJ)
	@cp $(LIBFT_A) $(NAME)
	@$(AR) $(ARFLAGS) $(NAME) $(filter-out ft_printf.o, $(MAND_OBJ)) $(BONUS_OBJ)
	@touch $(BONUS_STAMP)

# Build libft using its own Makefile
$(LIBFT_A):
	@$(MAKE) -C $(LIBFT_DIR)

# Compile mandatory (root + srcs) using header/ft_printf.h
%.o: %.c $(INC_DIR)/ft_printf.h
	@$(CC) $(CFLAGS) $(MAND_INC) -c $< -o $@

# Compile bonus using _bonus/ft_printf.h
$(BONUS_DIR)/%.o: $(BONUS_DIR)/%.c $(BONUS_DIR)/ft_printf_bonus.h
	@$(CC) $(CFLAGS) $(BONUS_INC) -c $< -o $@

clean:
	@$(RM) $(MAND_OBJ) $(BONUS_OBJ) $(BONUS_STAMP)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all