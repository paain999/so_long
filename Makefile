# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dajimene <dajimene@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/08 22:28:54 by dajimene          #+#    #+#              #
#    Updated: 2023/11/10 01:54:18 by dajimene         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
PURPLE = \033[1;35m
DEF_COLOR = \033[0;39m
UNDER = \033[4m

NAME		:= so_long

INCLUDE		:= 	include/

MLX			:= mlx/
LINKS		:= -Lmlx -lmlx -framework OpenGL -framework AppKit
X11_FLAGS	:= -L/usr/X11/lib -lXext -lX11

GNL_DIR		:= gnl/
SRC_DIR		:= src/
SRCS		:= $(SRC_DIR)so_long.c $(SRC_DIR)check_map.c $(SRC_DIR)check_valid_path.c \
			$(SRC_DIR)controls.c $(SRC_DIR)graphics.c $(SRC_DIR)utils.c \
			$(SRC_DIR)ft_memset.c $(SRC_DIR)ft_putchar_fd.c $(SRC_DIR)ft_putstr_fd.c \
			$(SRC_DIR)ft_putnbr_fd.c $(SRC_DIR)ft_strchr.c $(SRC_DIR)ft_strdup.c $(SRC_DIR)ft_strjoin.c \
			$(SRC_DIR)ft_strlcpy.c $(SRC_DIR)ft_strlen.c $(SRC_DIR)ft_strnstr.c $(SRC_DIR)ft_substr.c $(SRC_DIR)ft_split.c \
			$(SRC_DIR)$(GNL_DIR)get_next_line.c $(SRC_DIR)$(GNL_DIR)get_next_line_utils.c
			
OBJ_DIR		:= obj/
OBJS		:= $(SRCS:.c=.o)

CC			:= cc
CFLAGS		:= -g3 -Wall -Wextra -Werror 
MFLAG		:= -fsanitize=address

RM			:= rm -f
RF			:= rm -rf

PREFIXED	:= $(addprefix $(OBJ_DIR), $(OBJS))

.SILENT:
all: $(NAME)

$(NAME): $(PREFIXED)
	@make -C $(MLX)
	@cp mlx/libmlx.a $(NAME)
	@$(CC) $(CFLAGS) $(LINKS) -o $(NAME) $(PREFIXED)
	@echo "$(GREEN)░██████╗░█████╗░██╗░░░░░░█████╗░███╗░░██╗░██████╗░"
	@echo "$(GREEN)██╔════╝██╔══██╗██║░░░░░██╔══██╗████╗░██║██╔════╝░"
	@echo "$(GREEN)╚█████╗░██║░░██║██║░░░░░██║░░██║██╔██╗██║██║░░██╗░"
	@echo "$(GREEN)░╚═══██╗██║░░██║██║░░░░░██║░░██║██║╚████║██║░░╚██╗"
	@echo "$(GREEN)██████╔╝╚█████╔╝███████╗╚█████╔╝██║░╚███║╚██████╔╝"
	@echo "$(GREEN)╚═════╝░░╚════╝░╚══════╝░╚════╝░╚═╝░░╚══╝░╚═════╝░"
	@echo "\n$(GREEN)$(UNDER)All files are compiled!$(DEF_COLOR)\n"
	@echo "$(YELLOW)\n !Use this command ./so_long maps/<map_name>.ber\n$(DEF_COLOR)"

$(OBJ_DIR)%.o:	%.c
	@mkdir -p $(OBJ_DIR)$(SRC_DIR)
	@mkdir -p $(OBJ_DIR)$(SRC_DIR)$(GNL_DIR)
	@echo "$(YELLOW)Compiling with >>$(DEF_COLOR) $(CC) $(CFLAGS):\t $<"
	@$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@rm -rf $(OBJS) $(OBJ_DIR)
	@echo "$(YELLOW)Cleaning!"

fclean:		clean
	@make clean -C mlx
	@rm -rf $(NAME)
	@rm -rf so_long
	@rm -rf libmlx.a
	@echo "$(RED)All deleted!$(DEF_COLOR)\n"
	
sanitize:
	$(CC) $(CFLAGS) $(MFLAG) $(SRCS) $(LINKS)
	
re: fclean all

.PHONY: all clean re