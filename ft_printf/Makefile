# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dajimene <dajimene@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/28 13:35:01 by dajimene          #+#    #+#              #
#    Updated: 2023/10/31 13:46:39 by dajimene         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#VARIABLES:
NAME		=libftprintf.a
LIBFT_DIR	=../Libft
LIBFT		=../Libft/libft.a
INCLUDE		=../include
SRC_DIR		=src/
OBJ_DIR		=obj/
CC			=gcc
CFLAGS		= -Wall -Wextra -Werror -I
RM			= rm -f
AR			 = ar rcs

#SOURCES
SRC_FILES	= ft_printf utils ft_print_hex ft_print_ptr ft_print_unsigned main
SRC			= $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ			= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

#OBJSF		=.cache_exists

all: 		$(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@$(AR) $(NAME) $(OBJ)

$(LIBFT):
	@make -C $(LIBFT_DIR)
	@cp $(LIBFT) $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDE) -I $(LIBFT_DIR) -c $< -o $@	
			
#$(OBJSF):
#	@mkdir -p $(OBJ_DIR)
clean:
	$(RM) -rf $(OBJ_DIR)
	@make clean -C $(LIBFT_DIR)
	$(RM) $(OBJSF)
	
fclean:		clean
	$(RM) $(NAME)
	$(RM) $(LIBFT)
			
re:	fclean all

.PHONY: all clean fclean