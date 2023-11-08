# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dajimene <dajimene@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/08 22:28:54 by dajimene          #+#    #+#              #
#    Updated: 2023/11/08 22:36:53 by dajimene         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= so_long

INCLUDE		:= 	include/so_long.h

LIBS		:= mlx
LIBS_TARGET	+= mlx/libmlx.a
LIBFT 		:= Libft/libft.a
MFLAGS		:= -framework OpenGL -framework AppKit

SRC_DIR     := src
SRCS		:= so_long.c check_map.c check_valid_path.c \
			controls.c graphics.c utils.c

SRCS		:= $(SRCS:%=$(SRC_DIR)/%)
BUILD_DIR	:= obj
OBJS		:= $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

CC			:= cc
CFLAGS		:= -g3 -Wall -Wextra -Werror 
CPPFLAGS	:= $(addprefix -I,$(INCLUDE))
LDFLAGS		:= $(addprefix -L,$(dir $(LIBS_TARGET)))
LDLIBS		:= $(addprefix -l,$(LIBS))

RM			:= rm -f
RF			:= rm -rf
DIR_DUP		= mkdir -p $(@D)

.SILENT:
all: $(NAME)

$(NAME): $(OBJS) $(LIBS_TARGET)
	@$(CC) $(LDFLAGS) $(OBJS) $(LDLIBS) $(MFLAGS) -o $(NAME)
	@echo "$(GREEN)░██████╗░█████╗░██╗░░░░░░█████╗░███╗░░██╗░██████╗░"
	@echo "$(GREEN)██╔════╝██╔══██╗██║░░░░░██╔══██╗████╗░██║██╔════╝░"
	@echo "$(GREEN)╚█████╗░██║░░██║██║░░░░░██║░░██║██╔██╗██║██║░░██╗░"
	@echo "$(GREEN)░╚═══██╗██║░░██║██║░░░░░██║░░██║██║╚████║██║░░╚██╗"
	@echo "$(GREEN)██████╔╝╚█████╔╝███████╗╚█████╔╝██║░╚███║╚██████╔╝"
	@echo "$(GREEN)╚═════╝░░╚════╝░╚══════╝░╚════╝░╚═╝░░╚══╝░╚═════╝░"
	@echo "$(YELLOW)\n !Use this command ./so_long assets/maps/<map_name>.ber\n$(DEF_COLOR)"

$(LIBS_TARGET):
	@$(MAKE) -C $(@D) 2> /dev/null
	
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@$(DIR_DUP)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<