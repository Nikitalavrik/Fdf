# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/21 15:00:08 by nlavrine          #+#    #+#              #
#    Updated: 2019/10/22 16:49:34 by nlavrine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC =	main.c	\
		parse.c	\
		fdf.c	\
		sys_out.c	\
		error.c		\
		split.c		\
		vis.c	\

CC = gcc
FLAGS = -Wall -Wextra -Werror
SRC_DIR = srcs
H_DIR = includes
OBJ_DIR = obj
LIB = libft/libft.a
PRINTF = libft/ft_printf/libftprintf.a
MINILIBX = minilibx_macos/libmlx.a

SRCS = $(addprefix $(SRC_DIR)/,$(SRC))

OBJS = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

all: $(NAME) 

$(NAME): $(LIB) $(PRINTF) $(OBJS)
		@$(CC) $(FLAGS) -framework OpenGL -framework AppKit -lm $(OBJS) $(PRINTF) $(LIB) $(PRINTF) $(MINILIBX) -o $(NAME) 
	
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
		@mkdir -p $(OBJ_DIR)
		@$(CC) $(FLAGS) -o $@ -c $< -I $(H_DIR) 

$(LIB):
	@make -C ./libft/

$(PRINTF):
	@make -C ./libft/ft_printf/

clean:
	@rm -f $(OBJS)
	@rm -rf $(OBJ_DIR)
	@make -C ./libft/ clean
	@make -C ./libft/ft_printf/ clean

fclean: clean
	@rm -f $(NAME)
	@make -C ./libft/ fclean
	@make -C ./libft/ft_printf/ fclean

re: fclean all