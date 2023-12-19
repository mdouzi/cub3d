# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ohachami <ohachami@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/08 20:02:09 by ohachami          #+#    #+#              #
#    Updated: 2023/04/08 20:10:10 by ohachami         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc 

HEADER = libft.h

CFLAGS = -Wall -Werror -Wextra

SRC = get_next_line/get_next_line_utils_bonus.c\
	get_next_line/get_next_line_bonus.c\
	ft_atoi.c\
	ft_bzero.c\
	ft_calloc.c\
	ft_isalnum.c\
	ft_isalpha.c\
	ft_isascii.c\
	ft_isdigit.c\
	ft_isprint.c\
	ft_itoa.c\
	ft_memchr.c\
	ft_memcmp.c\
	ft_memcpy.c\
	ft_memset.c\
	ft_putchar_fd.c\
	ft_putendl_fd.c\
	ft_putnbr_fd.c\
	ft_putstr_fd.c\
	ft_strchr.c\
	ft_strdup.c\
	ft_striteri.c\
	ft_strlcat.c\
	ft_strjoin.c\
	ft_strlcpy.c\
	ft_strlen.c\
	ft_strncmp.c\
	ft_strrchr.c\
	ft_substr.c\
	ft_split.c\
	ft_memmove.c\
	ft_strnstr.c\
	ft_tolower.c\
	ft_toupper.c\
	ft_strtrim.c\
	ft_strmapi.c\


OBJ = $(SRC:.c=.o)

all:$(NAME)

$(NAME):$(OBJ) $(HEADER)
	ar rc  $(NAME) $(OBJ)

clean:
	rm -f *.o print/*.o

fclean:clean
	rm -f $(NAME)

re:fclean all

.PHONY:all fclean clean re 
