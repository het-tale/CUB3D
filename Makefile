# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aheddak <aheddak@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/09 22:29:31 by het-tale          #+#    #+#              #
#    Updated: 2023/01/19 00:45:16 by aheddak          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    =    cub3D

SRCS    =   src/main.c \
			src/init.c src/math.c src/keys.c src/key_utils.c src/map.c src/walls.c src/raycasting.c src/ft_free.c src/textures.c \
			parser/libft/ft_isalpha.c parser/libft/ft_memchr.c parser/libft/ft_putchar_fd.c parser/libft/ft_strchr.c parser/libft/ft_strlcpy.c parser/libft/ft_strrchr.c \
			parser/libft/ft_atoi.c parser/libft/ft_isascii.c parser/libft/ft_memcmp.c parser/libft/ft_putendl_fd.c parser/libft/ft_strdup.c parser/libft/ft_strlen.c parser/libft/ft_strtrim.c \
			parser/libft/ft_bzero.c parser/libft/ft_isdigit.c parser/libft/ft_memcpy.c parser/libft/ft_putnbr_fd.c parser/libft/ft_striteri.c parser/libft/ft_strmapi.c parser/libft/ft_substr.c \
			parser/libft/ft_calloc.c parser/libft/ft_isprint.c parser/libft/ft_memmove.c parser/libft/ft_putstr_fd.c parser/libft/ft_strjoin.c parser/libft/ft_strncmp.c parser/libft/ft_tolower.c \
			parser/libft/ft_isalnum.c parser/libft/ft_itoa.c parser/libft/ft_memset.c parser/libft/ft_split.c parser/libft/ft_strlcat.c parser/libft/ft_strnstr.c parser/libft/ft_toupper.c \
			parser/get_next_line/get_next_line.c parser/get_next_line/get_next_line_utils.c parser/parser/parsing.c parser/parser/check_file.c parser/parser/get_map.c parser/parser/get_path.c\
			parser/parser/parsing_utils.c parser/parser/textures.c parser/parser/colors.c

OBJ    =    ${SRCS:.c=.o}

FLAGS    =    -Wall -Wextra -Werror -I /usr/local/include -O3 -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit

RM        =    rm -f

CC        =    gcc

all : $(NAME)

$(NAME) : $(SRCS)
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)

clean :
	${RM} ${OBJ}

fclean : clean
	${RM} ${NAME}

re : fclean all