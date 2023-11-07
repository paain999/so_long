# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dajimene <dajimene@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/03 12:17:46 by dajimene          #+#    #+#              #
#    Updated: 2023/11/08 00:13:18 by dajimene         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# Variables
NAME := so_long
LIBFT_DIR = Libft
LIBFT = Libft/libft.a
MLX = mlx/
MLX_TARGET = mlx/
GNL_DIR = gnl/
SRC_DIR = src/
OBJ_DIR = obj/
INCLUDE = include
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I $(INCLUDE)
AR = ar rcs
RM = rm -f
LMLX = -lmlx -framework OpenGL -framework AppKit
LEAKS = -g3 -fsanitize=address

# Sources
SRC_FILES	= so_long check_map check_valid_path utils
SRC			= $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ			= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

.SILENT:
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $

$(OBJ_DIR)%.o: $(SRC_DIR)%.C
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I $(LIBFT_DIR) -c $< -o $@