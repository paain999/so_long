# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dajimene <dajimene@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/08 22:28:54 by dajimene          #+#    #+#              #
#    Updated: 2023/11/13 20:02:06 by dajimene         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME		:= so_long

INCLUDE		:= include/

MLX			:= mlx
MLX_TARGET	+= mlx/libmlx.a
MFLAGS		:= -framework OpenGL -framework AppKit

RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
PURPLE = \033[1;35m
DEF_COLOR = \033[0;39m
UNDER = \033[4m

SRC_DIR		:= src
SRCS		:= so_long.c check_map.c check_valid_path.c controls.c\
			graphics.c init_game.c playermovement.c utils.c ft_split.c ft_itoa.c \
			libft.c libft_str.c get_next_line.c get_next_line_utils.c

SRCS		:= $(SRCS:%=$(SRC_DIR)/%)

OBJ_DIR		:= obj
OBJS		:= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CC			:= cc
CFLAGS		:= -g3 -Wall -Wextra -Werror 
CPPFLAGS	:= $(addprefix -I,$(INCLUDE))
LDFLAGS		:= $(addprefix -L,$(dir $(MLX_TARGET)))
LDLIBS		:= $(addprefix -l,$(MLX))

RM			:= rm -f
RF			:= rm -rf

DIR_DUP		= mkdir -p $(@D)

.SILENT:
all: $(NAME)

$(NAME): $(OBJS) $(MLX_TARGET)
	@$(CC) $(LDFLAGS) $(OBJS) $(LDLIBS) $(MFLAGS) -o $(NAME)
	@echo "$(GREEN)░██████╗░█████╗░██╗░░░░░░█████╗░███╗░░██╗░██████╗░"
	@echo "$(GREEN)██╔════╝██╔══██╗██║░░░░░██╔══██╗████╗░██║██╔════╝░"
	@echo "$(GREEN)╚█████╗░██║░░██║██║░░░░░██║░░██║██╔██╗██║██║░░██╗░"
	@echo "$(GREEN)░╚═══██╗██║░░██║██║░░░░░██║░░██║██║╚████║██║░░╚██╗"
	@echo "$(GREEN)██████╔╝╚█████╔╝███████╗╚█████╔╝██║░╚███║╚██████╔╝"
	@echo "$(GREEN)╚═════╝░░╚════╝░╚══════╝░╚════╝░╚═╝░░╚══╝░╚═════╝░"
	@echo "\n$(GREEN)$(UNDER)All files are compiled!$(DEF_COLOR)\n"
	@echo "$(YELLOW)\n !Use this command ./so_long maps/<map_name>.ber\n$(DEF_COLOR)"

$(MLX_TARGET):
	@make -C $(@D) 2> /dev/null

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(DIR_DUP)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

clean:
	for f in $(dir $(MLX_TARGET)); do $(MAKE) -C $$f clean; done
	$(RM) $(OBJS)
	@echo "$(YELLOW)CLEANED!"

fclean:		clean
	$(RM) $(NAME)
	$(RF) ./a.out.dSYM
	$(RF) $(OBJ_DIR)
	@echo "$(RED)ALL DELETED!$(DEF_COLOR)\n"
	
sanitize:
	$(CC) $(CFLAGS) $(DFLAGS) $(SRCS) -Lmlx -lmlx $(MFLAGS)
	
re: fclean all

.PHONY: all clean re