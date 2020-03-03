# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdoze <gdoze@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/20 14:33:40 by gdoze             #+#    #+#              #
#    Updated: 2020/03/03 19:31:57 by gdoze            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra
#INC = -I includes

# PFT_HEADER = includes/ft_printf.h
# LIB_HEADER = includes/libgit ft.h

SRC_DIR = src
INC_DIR = includes
OBJ_DIR = $(SRC_DIR)/obj
PFT_DIR = $(SRC_DIR)/ft_printf

_SRC =            ft_atoi.c \
                     ft_bzero.c \
                     ft_ftoa.c \
                     ft_isalnum.c \
                     ft_isalpha.c \
                     ft_isascii.c \
                     ft_isdigit.c \
                     ft_isprint.c \
                     ft_itoa.c \
                     ft_itoa_base.c \
                     ft_itoa_big.c \
                     ft_lstadd.c \
                     ft_lstdel.c \
                     ft_lstdelone.c \
                     ft_lstiter.c \
                     ft_lstmap.c \
                     ft_lstnew.c \
                     ft_memalloc.c \
                     ft_memccpy.c \
                     ft_memchr.c \
                     ft_memcmp.c \
                     ft_memcpy.c \
                     ft_memdel.c \
                     ft_memdup.c \
                     ft_memmove.c \
                     ft_memset.c \
                     ft_putchar.c \
                     ft_putchar_fd.c \
                     ft_putendl.c \
                     ft_putendl_fd.c \
                     ft_putnbr.c \
                     ft_putnbr_fd.c \
                     ft_putstr.c \
                     ft_putstr_fd.c \
                     ft_stradd.c \
                     ft_strcat.c \
                     ft_strchr.c \
                     ft_strclr.c \
                     ft_strcmp.c \
                     ft_strcpy.c \
                     ft_strdel.c \
                     ft_strdup.c \
                     ft_strequ.c \
                     ft_strindex.c \
                     ft_striter.c \
                     ft_striteri.c \
                     ft_strjoin.c \
                     ft_strjoin_free.c \
                     ft_strlcat.c \
                     ft_strlen.c \
                     ft_strlower.c \
                     ft_strmap.c \
                     ft_strmapi.c \
                     ft_strncat.c \
                     ft_strncmp.c \
                     ft_strncpy.c \
                     ft_strnequ.c \
                     ft_strnew.c \
                     ft_strnstr.c \
                     ft_strrchr.c \
                     ft_strsplit.c \
                     ft_strstr.c \
                     ft_strsub.c \
                     ft_strtrim.c \
                     ft_strupper.c \
                     ft_swap.c \
                     ft_tolower.c \
                     ft_toupper.c \
                     ft_wdcounter.c \
                     get_next_line.c
SRC    = $(patsubst %,$(SRC_DIR)/%,$(_SRC))

PFT_SRC = color_redactor.c \
          digit_redactor.c \
          flag_analazer.c \
          flags.c \
          ft_printf.c \
          specificator.c \
          str_redactor.c

SRC   += $(patsubst %,$(PFT_DIR)/%,$(PFT_SRC))


# PFT_OBJ = $(PFT_SRC:.c=.o)
# OBJS = $(SRC:.c=.o)
# OBJS = $(addprefix $(SRC_DIR)/,$(OBJ))
# OBJS_PFT = $(addprefix $(PFT_DIR)/,$(PFT_OBJ))
_OBJ = $(_SRC:.c=.o)
_OBJ += $(PFT_SRC:.c=.o)
OBJ = $(patsubst %,$(OBJ_DIR)/%,$(_OBJ))

# COLORS

NC = \033[0m
GREEN = \033[1;32m
RED = \033[1;31m

.PHONY: all clean fclean re

# RULES

all: $(NAME)

$(NAME):
	@mkdir -p $(OBJ_DIR)
	@echo "$(GREEN)compiling object$(NC)"
	@$(CC) $(CFLAGS) -c $(SRC) -I $(INC_DIR)
	@mv *.o $(OBJ_DIR)
	@echo compiling $(NAME)
	@ar -rcs $(NAME) $(OBJ)
	@echo done

# $(NAME): $(OBJS_PFT) $(OBJS)
# 	@ar -rcs $@ $(OBJ_DIR)/$(OBJ)
# 	@echo "$(GREEN)DONE$(NC)"
#
# $(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(PFT_DIR)/%.c $(PFT_HEADER) $(LIB_HEADER)
# 	@mkdir -p $(OBJ_DIR)
# 	@$(CC) $(CFLAGS) $(INC) -c $< -o $@


clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)$(NAME) removed$(NC)"

re: fclean all



