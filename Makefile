# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/14 13:43:18 by okraus            #+#    #+#              #
#    Updated: 2025/05/24 18:26:23 by okraus           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
SRC		= ft_isalpha.c\
		ft_toupper.c\
		ft_isdigit.c\
		ft_tolower.c\
		ft_isalnum.c\
		ft_strchr.c\
		ft_isascii.c\
		ft_strrchr.c\
		ft_isprint.c\
		ft_strncmp.c\
		ft_strlen.c\
		ft_memchr.c\
		ft_memset.c\
		ft_bzero.c\
		ft_memcpy.c\
		ft_memcmp.c\
		ft_memmove.c\
		ft_strnstr.c\
		ft_strlcpy.c\
		ft_atoi.c\
		ft_strlcat.c\
		ft_calloc.c\
		ft_strdup.c\
		ft_substr.c\
		ft_strjoin.c\
		ft_strtrim.c\
		ft_split.c\
		ft_itoa.c\
		ft_strmapi.c\
		ft_striteri.c\
		ft_putchar_fd.c\
		ft_putstr_fd.c\
		ft_putendl_fd.c\
		ft_putnbr_fd.c
BSRC	= ft_lstnew.c\
		ft_lstadd_front.c\
		ft_lstsize.c\
		ft_lstlast.c\
		ft_lstadd_back.c\
		ft_lstdelone.c\
		ft_lstclear.c\
		ft_lstiter.c\
		ft_lstmap.c
OBJ		= $(SRC:.c=.o)
BOBJ	= $(BSRC:.c=.o)
INCS	= libft.h
LIBC	= ar rcs
CC		= cc
CFLAGS	= -Wall -Wextra -Werror #-fPIC

all: $(NAME)

%.o: %.c $(INCS)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(LIBC) $(NAME) $(OBJ)

bonus: $(OBJ) $(BOBJ)
	$(LIBC) $(NAME) $(OBJ) $(BOBJ)

clean:
	rm -f $(OBJ) $(BOBJ)
#	rm -f *.so

fclean: clean
	rm -f $(NAME)

re: fclean all

# so:
# 	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRC) $(BSRC)
# 	gcc -nostartfiles -shared -o libft.so $(OBJ) $(BOBJ)

.PHONY: all clean fclean re bonus #so
