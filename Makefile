# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egaborea <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/29 10:16:34 by egaborea          #+#    #+#              #
#*   Updated: 2016/10/20 15:14:38 by hchaucha         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

SRC_PATH = ./src/
SRC_NAME = algo.c\
		   ant_nb.c\
		   can_be_solved.c\
		   delete_path.c\
		   find_path.c\
		   ft_delete_map.c\
		   ft_mapdup.c\
		   ft_mapsize.c\
		   inputlst.c\
		   main.c\
		   parse_map.c\
		   path_length.c\
		   print.c\
			print_solution.c\
			roomlst.c\
			send_one_in_each.c\
			tube.c

OBJ_PATH = ./obj/
OBJ_NAME = $(SRC_NAME:.c=.o)

INC_PATH = ./includes/
INC_NAME = lem_in.h

LIB_PATH = ./libft/
LIB_NAME = -lft

INC_LIB_PATH = ./libft/includes

NAME = lem_in

CC = gcc
CFLAGS = -Werror -Wextra -Wall

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
LIB = $(addprefix -L, $(LIB_PATH))
INC = $(addprefix -I, $(INC_PATH))
INC_LIB = $(addprefix -I, $(INC_LIB_PATH))

GREEN = \033[0;32m
NC = \033[0m

all: lib $(NAME) $(CHK_NAME)

$(NAME): $(OBJ)
		@echo "Compilation du lem_in [${GREEN}OK${NC}]"
		@$(CC) $(CFLAGS) $(LIB) -lft -o $(NAME) $(OBJ) -g

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || echo "" > /dev/null
	@$(CC) $(CFLAGS) $(INC) $(INC_LIB) -o $@ -c $< -g

lib:
	@make -C $(LIB_PATH) all

clean:
	@rm -f $(OBJ)
	@make -C $(LIB_PATH) clean
	@rmdir $(OBJ_PATH) 2> /dev/null || echo "" > /dev/null

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIB_PATH) fclean
	@echo "Suppression du lem_in [${GREEN}OK${NC}]"

re: fclean all

push:
	@git add *
	@git commit -m "Commit By Makefile"
	@git push

norme:
	norminette $(SRC)
	norminette $(INC_PATH)$(INC_NAME)
