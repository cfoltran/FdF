# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clfoltra <clfoltra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/05 20:05:25 by clfoltra          #+#    #+#              #
#    Updated: 2019/01/28 13:23:09 by clfoltra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = fdf.c \

CC = gcc

CFLAGS = -Wall -Werror -Wextra

OBJ = $(SRC:.c=.o)

INC = -I libft/includes -L libft/ -lft

MLX = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJ)
		@printf "\n"
		@make -C ./libft/
		@make -C ./minilibx_macos
		
		@printf "\n\n"
			@$(CC) $(CFLAGS) $(INC) -o $@ $^ $(MLX)

clean:
		@make clean -C libft/
			@rm -f $(OBJ)

fclean: clean
		@make fclean -C libft/
			@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
