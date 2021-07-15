HEADER	=	pipex.h
SRCS	=	pipex.c \
			pipex_cmd.c \
			pipex_redirect.c\

BIN		= objs
OBJS	= $(SRCS:.c=.o)
NAME	= pipex
LIBFT	= libft
LIBFT_FILE	= $(LIBFT)/libft.a
CC		= gcc
CFLAGS	= -g -Wall -Werror -Wextra
RM		= rm -rf

all:	init $(NAME)

$(NAME): $(OBJS)
	cp $(LIBFT_FILE) $(NAME)
	ar rc $(NAME) $(OBJS)

%.o:	%.c $(HEADER) $(LIBFT)/libft.h
	$(CC) $(CFLAGS) -c $< -Iincludes -Ilibft -o $@

init:
	$(MAKE) -C $(LIBFT)

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT) clean
	@ $(RM) objs

fclean:	clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT) fclean

re:	fclean all

.PHONY: all clean fclean re init