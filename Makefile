# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gucamuze <gucamuze@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/15 02:21:09 by gucamuze          #+#    #+#              #
#    Updated: 2022/01/02 16:16:46 by gucamuze         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME			= fract-ol
CC				= clang -Wall -Wextra -Werror -Ofast
RM				= rm -f

SRCS			=	./srcs/
LIBFT			=	./libft/libft.a
MLX				=	./mlx_linux/libmlx_linux.a
SRCS_FILES		=	${SRCS}main.c \
					${SRCS}colors.c \
					${SRCS}camera_moves.c \
					${SRCS}camera_misc.c \
					${SRCS}hooks.c \
					${SRCS}fractals_tools.c \
					${SRCS}utils.c \
					${SRCS}setup.c \
					${SRCS}mlx_utils.c \
					${SRCS}burning_ship.c
					
SRCS_OFILES		= 	$(SRCS_FILES:.c=.o)

%.o: %.c
				$(CC) -I/usr/include -Imlx_linux -Iincludes -Ilibft -c $< -o $@

all:			$(NAME)

$(NAME):		dependencies $(SRCS_OFILES)
				$(CC) $(SRCS_OFILES) -Iincludes -Imlx_linux $(LIBFT) -Lmlx_linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz -o $(NAME)
							
dependencies:
				make --directory=libft
				make --directory=mlx_linux

clean:
				make clean --directory=libft
				make clean --directory=mlx_linux
				$(RM) $(SRCS_OFILES)

fclean:		clean
				$(RM) $(LIBFT) ${MLX} ${NAME}

re:			fclean all

norminette:
			norminette srcs libft includes


.PHONY:	all clean fclean re dependencies bonus
