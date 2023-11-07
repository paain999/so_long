# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dajimene <dajimene@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/03 12:17:46 by dajimene          #+#    #+#              #
#    Updated: 2023/11/07 13:07:28 by dajimene         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Properties for MacOS
LEAKS = -g3 -fsanitize=address
GRATE = GAME_RATE=17

# Variables
CC = gcc -MD
CFLAGS = -Wall -Wextra -Werror
LMLX = -lmlx -framework OpenGL -framework AppKit
RM = rm -f
AR = ar rcs
GNL_DIR = gnl/
PRINTF = ft_printf
LIBFT_DIR = libft/
LIBFT = Libft/libft.a
SRC_DIR = src/
OBJ_DIR = obj/
INCLUDE = include/
BIN_DIR = bin/
BIN = so_long
NAME = $(BIN_DIR)/$(BIN)

# Sources
SRC_FILES	= so_long check_map check_valid_path utils
SRC			= $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ			= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))


# Game speeds defined during compilation
RATES = -D $(GRATE)