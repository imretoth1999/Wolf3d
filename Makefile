# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: itoth <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/03 20:04:32 by itoth             #+#    #+#              #
#    Updated: 2017/07/03 21:22:05 by itoth            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d
SRCS = read.c fov.c hooks.c main.c setup_camera.c move.c let_there_be_light.c raytracing.c 
OBJ = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) :
	make -C libft/ fclean
	make -C libft/
	gcc -Wall -Wextra -Werror -I libft -c $(SRCS)
	gcc -o $(NAME) $(OBJ) -L libft/ -lft -lmlx -framework OpenGL -framework AppKit
clean :
	/bin/rm -f $(OBJ)
	make -C libft/ clean

fclean : clean
	/bin/rm -f $(NAME)
	/bin/rm -f libft/libft.a

re : fclean all
