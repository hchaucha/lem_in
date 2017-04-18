#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: hchaucha <hugues.chauchat@gmail.com>       +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2016/10/20 14:22:33 by hchaucha          #+#    #+#             *#
#*   Updated: 2016/11/17 01:00:52 by                   ###   ########.fr      *#
#*                                                                            *#
#* ************************************************************************** *#

SRC_PATH = ./srcs/
SRC_NAME =\
	 		basics/strings/create/ft_strdup.c\
		   	basics/strings/create/ft_strjoin.c\
			basics/strings/create/ft_strmap.c\
			basics/strings/create/ft_strmapi.c\
			basics/strings/create/ft_strnew.c\
			basics/strings/create/ft_strsplit.c\
			basics/strings/create/ft_strsub.c\
			basics/strings/create/ft_strtrim.c\
			basics/strings/create/ft_strunsplit.c\
			basics/strings/create/get_next_line.c\
		   	basics/strings/delete/ft_strdel.c\
		   	basics/strings/iterate/ft_alnumcount.c\
		   	basics/strings/iterate/ft_strchr.c\
		   	basics/strings/iterate/ft_strcmp.c\
		   	basics/strings/iterate/ft_strequ.c\
		   	basics/strings/iterate/ft_striter.c\
		   	basics/strings/iterate/ft_striteri.c\
		   	basics/strings/iterate/ft_strlen.c\
		   	basics/strings/iterate/ft_strlen_utf8.c\
		   	basics/strings/iterate/ft_strncmp.c\
		   	basics/strings/iterate/ft_strnequ.c\
		   	basics/strings/iterate/ft_strnoccu.c\
		   	basics/strings/iterate/ft_strnstr.c\
		   	basics/strings/iterate/ft_isnumber.c\
		   	basics/strings/iterate/ft_stroccu.c\
		   	basics/strings/iterate/ft_strrchr.c\
		   	basics/strings/iterate/ft_strstr.c\
		   	basics/strings/output/ft_putendl.c\
		   	basics/strings/output/ft_putendl_fd.c\
		   	basics/strings/output/ft_putstr.c\
		   	basics/strings/output/ft_putstr_fd.c\
		   	basics/strings/transform/ft_strcat.c\
		   	basics/strings/transform/ft_strclr.c\
		   	basics/strings/transform/ft_strcpy.c\
		   	basics/strings/transform/ft_strlcat.c\
		   	basics/strings/transform/ft_strmerge.c\
		   	basics/strings/transform/ft_strncat.c\
		   	basics/strings/transform/ft_strncpy.c\
		   	basics/strings/transform/ft_strrev.c\
		   	basics/strings/transform/ft_strtolower.c\
		   	basics/strings/transform/ft_str_add_char.c\
		   	basics/numbers/convers/ft_atoi.c\
		   	basics/numbers/convers/ft_atoi_base.c\
		   	basics/numbers/convers/ft_itoa.c\
		   	basics/numbers/convers/ft_itoa_base.c\
		   	basics/numbers/convers/ft_itoa_base.c\
		   	basics/numbers/output/ft_putnbr.c\
		   	basics/numbers/output/ft_putnbr_fd.c\
		   	basics/chars/check/ft_isalnum.c\
		   	basics/chars/check/ft_isalpha.c\
		   	basics/chars/check/ft_isascii.c\
		   	basics/chars/check/ft_isdigit.c\
		   	basics/chars/check/ft_isprint.c\
		   	basics/chars/output/ft_putchar.c\
		   	basics/chars/output/ft_putchar_fd.c\
		   	basics/chars/transform/ft_tolower.c\
		   	basics/chars/transform/ft_toupper.c\
		   	basics/memory/create/ft_memalloc.c\
		   	basics/memory/delete/ft_memdel.c\
		   	basics/memory/delete/ft_memdel2.c\
		   	basics/memory/iterate/ft_memchr.c\
		   	basics/memory/iterate/ft_memcmp.c\
		   	basics/memory/transform/ft_bzero.c\
		   	basics/memory/transform/ft_memccpy.c\
		   	basics/memory/transform/ft_memcpy.c\
		   	basics/memory/transform/ft_memmove.c\
		   	basics/memory/transform/ft_memset.c\
		   	basics/maths/operations/ft_abs.c\
		   	containers/list/simple/ft_lstadd.c\
		   	containers/list/simple/ft_lstadd_back.c\
		   	containers/list/simple/ft_lstcount.c\
		   	containers/list/simple/ft_lstdel.c\
		   	containers/list/simple/ft_lstdelone.c\
		   	containers/list/simple/ft_lstiter.c\
		   	containers/list/simple/ft_lstmap.c\
		   	containers/list/simple/ft_lstnew.c\
		   	containers/list/simple/ft_lstpushback.c\
		   	containers/list/simple/ft_lstsort.c\
			containers/list/double/ft_dlstnew.c\
			containers/list/double/ft_dlstpushback.c\
			containers/list/double/ft_dlstpushfront.c\
			containers/list/double/ft_dlstfree.c\
			containers/list/double/ft_dlstdisplay.c\
			ft_printf/add_char.c\
		   	ft_printf/apply_modifs.c\
		   	ft_printf/apply_precision.c\
		   	ft_printf/buffer.c\
		   	ft_printf/check.c\
		   	ft_printf/check2.c\
		   	ft_printf/ft_printf.c\
		   	ft_printf/opts.c\
		   	ft_printf/opts_analyse.c\
		   	ft_printf/opts_precision.c\
		   	ft_printf/opts_width.c\
		   	ft_printf/print.c\
		   	ft_printf/print_wchar.c\
		   	ft_printf/render.c\
		   	ft_printf/render_numeric.c\
		   	ft_printf/utils.c\
		   	ft_printf/wchar.c

OBJ_PATH = ./objs/
OBJ_NAME = $(SRC_NAME:.c=.o)

INC_PATH = ./includes/
INC_NAME = libft.h

LIB_PATH = ./libft/

# **************************************************************************#

# COMPILATION
NAME = libft.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra

# SPECIAL CHARS
LOG_CLEAR		= \033[2K 
LOG_UP			= \033[A
LOG_NOCOLOR		= \033[0m
LOG_BLACK		= \033[1;30m
LOG_RED			= \033[1;31m
LOG_GREEN		= \033[1;32m
LOG_YELLOW		= \033[1;33m
LOG_BLUE		= \033[1;34m
LOG_VIOLET		= \033[1;35m
LOG_CYAN		= \033[1;36m
LOG_WHITE		= \033[1;37m

# **************************************************************************#

SRCS = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJS = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC = $(addprefix -I, $(INC_PATH))
OBJS_DIRS = $(sort $(dir $(OBJS)))

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "$(LOG_WHITE)Compilation de la libft [$(LOG_GREEN)OK$(LOG_NOCOLOR)]"

clean:
	@rm -rf $(OBJS)
	@rm -rf $(OBJ_PATH)
fclean: clean
	@rm -f $(NAME)
	@echo "$(LOG_WHITE)Suppression de la libft [$(LOG_GREEN)OK$(LOG_NOCOLOR)]"

re: fclean all

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@mkdir -p $(OBJS_DIRS)
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<
