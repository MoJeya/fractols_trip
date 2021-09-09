# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mjeyavat <mjeyavat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/08 12:56:39 by mjeyavat          #+#    #+#              #
#    Updated: 2021/09/09 16:26:43 by mjeyavat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractols.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = fractols.c main.c \

OBJ = $(SRC:.c=.o);

LINKED_OBJ = ./libft/*.o ./mlx/*.o

all:linked_objects $(NAME)

$(NAME): $(OBJ)
	$(CC) $(SRC) -Lmlx -lmlx -framework OpenGL -framework AppKit mlx/libmlx.a -o $(NAME)

objects:
	$(CC) $(CFLAGS) $(OBJ)

linked_objects:
	make -C ./libft
	make -C ./mlx

clean:
	rm -f ./libft/*.a ./mlx/libmlx.a

fclean: clean
	rm -f $(NAME) ./libft/*.o ./mlx/*.o *.o

re: fclean all

