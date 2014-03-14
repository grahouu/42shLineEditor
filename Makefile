# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/03/02 14:37:36 by cfeijoo           #+#    #+#              #
#    Updated: 2014/03/14 15:47:06 by acollin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = 42sh_line_editor

INCLUDEFOLDERS = -I./includes/ -I./libft/includes/ -g
LIBFOLDERS = -L./libft/
LIBS =  -lft -lncurses

CC = clang
CFLAGS = -Wall -Werror -Wextra

SOURCES_FOLDER = sources/
OBJECTS_FOLDER = objects/

SOURCES =	\
			line_editor.c							\
			display_init.c							\
			display_restore.c						\
													\
			keyboard/keyboard.c						\
			keyboard/key_escape.c					\
			keyboard/key_backspace.c				\
			keyboard/key_delete.c					\
			keyboard/key_left.c						\
			keyboard/key_right.c					\
													\
			actions/action_add_char.c				\
			actions/action_remove_char.c			\
			actions/action_remove_next_char.c		\
			actions/action_key_escape.c				\
			actions/action_move_cursor_right.c		\
			actions/action_move_cursor_left.c		\
			actions/action_move_cursor_word.c		\
													\
			print_line.c							\
			main.c									\

OBJECTS= $(SOURCES:.c=.o)
OBJECTS := $(subst /,__,$(OBJECTS))
OBJECTS := $(addprefix $(OBJECTS_FOLDER), $(OBJECTS))
SOURCES := $(addprefix $(SOURCES_FOLDER),$(SOURCES))

# Colors
NO_COLOR =		\x1b[0m
OK_COLOR =		\x1b[32;01m
ERROR_COLOR =	\x1b[31;01m
WARN_COLOR =	\x1b[33;01m
SILENT_COLOR =	\x1b[30;01m

.PHONY: all re clean fclean

all: complibs $(NAME)

$(OBJECTS_FOLDER)%.o:
	@$(CC) -c $(subst .o,.c,$(subst $(OBJECTS_FOLDER),$(SOURCES_FOLDER),$(subst __,/,$@))) $(INCLUDEFOLDERS) $(CFLAGS) $(MACROS) -o $@
	@printf "$(OK_COLOR)✓ $(NO_COLOR)"
	@echo "$(subst .o,.c,$(subst $(OBJECTS_FOLDER),$(SOURCES_FOLDER),$(subst __,/,$@)))"

$(NAME) : $(OBJECTS)
	@printf "$(SILENT_COLOR)Compiling $(NAME)...$(NO_COLOR)"
	@$(CC) $(OBJECTS) $(INCLUDEFOLDERS) $(LIBFOLDERS) $(LIBS) $(CFLAGS) -o $(NAME)
	@echo " $(OK_COLOR)Successful ✓$(NO_COLOR)"

getlibs :
	git clone https://bitbucket.org/vdefilip/libft/

updatelibs :
	@echo "$(SILENT_COLOR)Searching LibFt updates...$(NO_COLOR)"
	@cd libft/ && git pull

complibs :
	@make -C libft/

clean :
	@rm -f $(OBJECTS)
	@echo "$(SILENT_COLOR)$(NAME) : Cleaned Objects$(NO_COLOR)"

fclean : clean
	@rm -f $(NAME)
	@echo "$(SILENT_COLOR)$(NAME) : Cleaned Program$(NO_COLOR)"
	# @make -C "libft/" fclean

re : fclean all
