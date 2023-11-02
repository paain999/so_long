# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dajimene <dajimene@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/03 12:17:46 by dajimene          #+#    #+#              #
#    Updated: 2023/10/26 17:32:33 by dajimene         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Key Codes for MacOS
ESC = KEY_ESC=53
W = KEY_W=13
A = KEY_A=0
S = KEY_S=1
D = KEY_D=2
UP = KEY_UP=126
DOWN = KEY_DOWN=125
LEFT = KEY_LEFT=123
RIGHT = KEY_RIGHT=124
R = KEY_R=15
Q = KEY_Q=12

SHELL=/bin/bash
UNAME = $(shell uname -s)

# Properties for MacOS
LEAKS = -g3 -fsanitize=address
GRATE = GAME_RATE=17
GAME = game_mac.c
RENDER = render_mac.c
LMLX = -lmlx -framework OpenGL -framework AppKit
ifeq ($(UNAME), Linux)
	#Properties for Linux
	LEAKS =  valgrind --leak-check=full --show-leak-kinds=all -s -q 
	GRATE = GAME_RATE=80
	GAME = game_linux.c
	RENDER = render_linux.c
	LMLX = -lmlx -lXext -lX11

	# Key Codes for Linux
	ESC = KEY_ESC=65307
	W = KEY_W=119
	A = KEY_A=97
	S = KEY_S=115
	D = KEY_D=100
	UP = KEY_UP=65362
	DOWN = KEY_DOWN=65364
	LEFT = KEY_LEFT=65361
	RIGHT = KEY_RIGHT=65363
	R = KEY_R=114
	Q = KEY_Q=113
endif

# Variables
CC = gcc -MD
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar rcs
GNL_DIR = gnl
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
SRC_FILES	= main check_map reading_map
SRC			= $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ			= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

# Keycodes defined during compilation
KEYCODES =  -D $(ESC) -D $(Q) -D $(R) -D $(W) -D $(A) -D $(S) -D $(D) -D $(UP) -D $(DOWN) -D $(LEFT) -D $(RIGHT)

# Game speeds defined during compilation
RATES = -D $(GRATE)