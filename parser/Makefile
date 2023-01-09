NAME		=	cub3d

UTILS		=	libft/ft_isalpha.c libft/ft_memchr.c libft/ft_putchar_fd.c libft/ft_strchr.c libft/ft_strlcpy.c libft/ft_strrchr.c \
				libft/ft_atoi.c libft/ft_isascii.c libft/ft_memcmp.c libft/ft_putendl_fd.c libft/ft_strdup.c libft/ft_strlen.c libft/ft_strtrim.c \
				libft/ft_bzero.c libft/ft_isdigit.c libft/ft_memcpy.c libft/ft_putnbr_fd.c libft/ft_striteri.c libft/ft_strmapi.c libft/ft_substr.c \
				libft/ft_calloc.c libft/ft_isprint.c libft/ft_memmove.c libft/ft_putstr_fd.c libft/ft_strjoin.c libft/ft_strncmp.c libft/ft_tolower.c \
				libft/ft_isalnum.c libft/ft_itoa.c libft/ft_memset.c libft/ft_split.c libft/ft_strlcat.c libft/ft_strnstr.c libft/ft_toupper.c \
				get_next_line/get_next_line.c get_next_line/get_next_line_utils.c parser/parsing.c parser/check_file.c parser/get_map.c parser/get_path.c\
				parser/parsing_utils.c parser/textures.c parser/colors.c
#libft/*.c get_next_line/*.c parsing/parsing.c

FLAGS		=	-Wall -Wextra -Werror

OBJCT		=	${UTILS:.c=.o}

RM			=	rm -f

CC			=	gcc

all		:	$(NAME)

$(NAME)	:	$(OBJCT)	
	@$(CC) $(FLAGS) $(MLX) $(UTILS) -o $(NAME)

clean :
	@${RM} $(OBJCT)

fclean : clean
	@${RM} ${NAME}

re : fclean all