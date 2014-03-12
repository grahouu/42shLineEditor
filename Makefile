# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acollin <acollin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/03/11 11:19:59 by acollin           #+#    #+#              #
#    Updated: 2014/03/11 17:27:49 by acollin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=ft_line_edit
VERSION=1.0.9
CFLAGS=-Wall -Werror -Wextra -g
INCLUDES=-I ./libft/includes
LIBS=-L ./libft -l ft -lcurses

SRC=global_newterm.c \
	global_oldterm.c \
	action_add_letter.c \
	action_key_backspace.c \
	action_key_left.c \
	action_key_right.c \
	key_arrow.c \
	key_ctrl.c \
	key_ctrl2.c \
	main.c \
	sh42_check_action.c \
	sh42_default_term.c \
	sh42_init_env.c \
	sh42_init_term.c \
	print_line.c \

OBJ=$(SRC:.c=.o)

all: build $(NAME) finish

build:
	@($(MAKE) -C ./libft)

$(NAME): $(OBJ) ./libft/libft.a
	gcc $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJ) $(LIBS)

%.o: %.c sh42.h ./libft/includes
	gcc $(CFLAGS) $(INCLUDES) -o $@ -c $<

clean:
	@(rm -rf $(OBJ))

fclean: clean
	@(rm -rf $(NAME))
	@($(MAKE) -C ./libft fclean)

re: fclean all

v:
	@(echo "version: $(VERSION)")

finish:
	@(echo "[\033[32m$(NAME)\033[00m]")

.PHONY: all build clean fclean re v

