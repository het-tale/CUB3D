# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: het-tale <het-tale@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/09 22:29:31 by het-tale          #+#    #+#              #
#    Updated: 2023/01/08 15:13:12 by het-tale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    =    cub3d

SRCS    =    src/main.c parsing/parsing.c parsing/libft/*.c parsing/get_next_line/get_next_line.c parsing/get_next_line/get_next_line_utils.c \
			 src/init.c src/math.c src/keys.c src/key_utils.c src/map.c src/walls.c src/raycasting.c src/ft_free.c

#SRCS	= test.c
#linux
OBJ    =    ${SRCS:.c=.o}

# FLAGS    =    -Wall -Wextra -Werror -I /usr/local/include -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit

#mac
# OBJ    =    ${SRCS:.c=.o}

# FLAGS    =    -Wall -Wextra -Werror -I /usr/local/include -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit

RM        =    rm -f

CC        =    gcc

all : $(NAME)

#mac
# $(NAME) : $(SRCS)
# 	$(CC) $(FLAGS) $(SRCS) -o $(NAME)

#linux
%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)


clean :
	${RM} ${OBJ}

fclean : clean
	${RM} ${NAME}

re : fclean all