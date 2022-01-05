# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gucamuze <gucamuze@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/15 02:21:09 by gucamuze          #+#    #+#              #
#    Updated: 2022/01/03 21:03:53 by gucamuze         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME			=	fract-ol
CC				=	clang -Wall -Wextra -Werror -Ofast
RM				=	rm -f

SRCS_PATH		=	./srcs/
LIBFT_PATH		=	./libft/
LIBFT			=	./libft/libft.a
MLX				=	./mlx_linux/libmlx_Linux.a

INCLUDES		=	./includes/fract_ol.h \
					./includes/libft.h
					
FRACTOL_FILES	=	${SRCS_PATH}main.c \
					${SRCS_PATH}colors.c \
					${SRCS_PATH}camera_moves.c \
					${SRCS_PATH}camera_misc.c \
					${SRCS_PATH}hooks.c \
					${SRCS_PATH}fractals_tools.c \
					${SRCS_PATH}utils.c \
					${SRCS_PATH}setup.c \
					${SRCS_PATH}mlx_utils.c \
					${SRCS_PATH}burning_ship.c
FRACTOL_OFILES	= 	$(FRACTOL_FILES:.c=.o)

LIBFT_FILES		=	$(LIBFT_PATH)ft_memset.c \
					$(LIBFT_PATH)ft_bzero.c \
					$(LIBFT_PATH)ft_memcpy.c \
					$(LIBFT_PATH)ft_memccpy.c \
					$(LIBFT_PATH)ft_memmove.c \
					$(LIBFT_PATH)ft_calloc.c \
					$(LIBFT_PATH)ft_atoi.c \
					$(LIBFT_PATH)ft_atol.c \
					$(LIBFT_PATH)ft_isdigit.c \
					$(LIBFT_PATH)ft_strlen.c \
					$(LIBFT_PATH)ft_strdup.c \
					$(LIBFT_PATH)ft_substr.c \
					$(LIBFT_PATH)ft_strjoin.c \
					$(LIBFT_PATH)ft_strtrim.c \
					$(LIBFT_PATH)ft_split.c \
					$(LIBFT_PATH)ft_strmapi.c \
					$(LIBFT_PATH)ft_putchar_fd.c \
					$(LIBFT_PATH)ft_putstr_fd.c \
					$(LIBFT_PATH)ft_isalpha.c \
					$(LIBFT_PATH)ft_isalnum.c \
					$(LIBFT_PATH)ft_isascii.c \
					$(LIBFT_PATH)ft_isprint.c \
					$(LIBFT_PATH)ft_itoa.c \
					$(LIBFT_PATH)ft_memchr.c \
					$(LIBFT_PATH)ft_memcmp.c \
					$(LIBFT_PATH)ft_tolower.c \
					$(LIBFT_PATH)ft_toupper.c \
					$(LIBFT_PATH)ft_strchr.c \
					$(LIBFT_PATH)ft_strrchr.c \
					$(LIBFT_PATH)ft_strncmp.c \
					$(LIBFT_PATH)ft_strnstr.c \
					$(LIBFT_PATH)ft_strlcpy.c \
					$(LIBFT_PATH)ft_strlcat.c \
					$(LIBFT_PATH)ft_putendl_fd.c \
					$(LIBFT_PATH)ft_putnbr_fd.c \
					$(LIBFT_PATH)ft_lstnew.c \
					$(LIBFT_PATH)ft_lstadd_front.c \
					$(LIBFT_PATH)ft_lstsize.c \
					$(LIBFT_PATH)ft_lstlast.c \
					$(LIBFT_PATH)ft_lstadd_back.c \
					$(LIBFT_PATH)ft_lstdelone.c \
					$(LIBFT_PATH)ft_lstclear.c \
					$(LIBFT_PATH)ft_lstiter.c \
					$(LIBFT_PATH)ft_lstmap.c
LIBFT_OFILES	= 	$(LIBFT_FILES:.c=.o)

%.o: %.c
				$(CC) -I/usr/include -Imlx_linux -Iincludes -Ilibft -c $< -o $@

all:			$(NAME)

$(NAME):		$(LIBFT) $(MLX) $(FRACTOL_OFILES)
				$(CC) $(FRACTOL_OFILES) -Iincludes -Imlx_linux $(LIBFT) -Lmlx_linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz -o $(NAME)
							
$(LIBFT):		$(LIBFT_OFILES)
				make --directory=libft

$(MLX):
				make --directory=mlx_linux

clean:
				make clean --directory=libft
				make clean --directory=mlx_linux
				$(RM) $(FRACTOL_OFILES)

fclean:		clean
				$(RM) $(LIBFT) ${MLX} ${NAME}

re:			fclean all

norminette:
			norminette srcs libft includes

.PHONY:	all clean fclean re norminette

