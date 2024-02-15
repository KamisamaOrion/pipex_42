# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhervoch <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/02 13:55:03 by mhervoch          #+#    #+#              #
#    Updated: 2024/02/03 20:50:06 by mhervoch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = clang

CFLAGS = -Wall -Wextra -Werror -g

SRCS =	./ft_memcpy.c \
		./ft_memmove.c \
		./ft_split.c \
		./ft_strjoin.c \
		./ft_strlcpy.c \
		./pipex.c \
		./pipex_utils.c \

HEAD =	pipex.h

OBJS = $(SRCS:.c=.o)

all:$(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -I ./  -c $< -o $@ 

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -lm

fclean: clean
	rm -f $(NAME)

clean:
	rm -f $(OBJS)

re: fclean all

.PHONY: all fclean clean re
