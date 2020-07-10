# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: antbarbi <antbarbi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/07 14:13:55 by antbarbi          #+#    #+#              #
#    Updated: 2020/07/07 14:13:55 by antbarbi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

NAME = libftprintf.a
SRC = ft_printf.c ft_buffer.c ft_printf_parse.c ft_printf_conv_nb.c \
		ft_printf_conv_str.c

SRC_DIR = srcs
LIB_DIRS = Libft
INCLUDE_DIRS = $(LIB_DIRS) Includes

IFLAGS = $(INCLUDE_DIRS:%=-I%)
OBJ_DIR = obj
OBJS := $(SRC:%.c=$(OBJ_DIR)/%.o)

all : $(NAME)

$(NAME) : $(OBJS)
		@mkdir -p $(OBJ_DIR)
		@$(MAKE) -C libft
		@cp ./Libft/libft.a $(NAME)
		@ar rcs $(NAME) $(OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
		@mkdir -p $(OBJ_DIR)
		@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

debug: CFLAGS += -g3
debug: all

clean:
	$(RM) $(OBJ_DIR)
	@$(MAKE) -j -C libft clean

fclean: clean
	$(RM) $(NAME)
	@$(MAKE) -j -C libft fclean

re: fclean $(NAME) all

main:
	CC -ILibft main.c libftprintf.a

.PHONY: clean fclean re debug make