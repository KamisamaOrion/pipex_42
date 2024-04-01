# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhervoch <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/02 13:55:03 by mhervoch          #+#    #+#              #
#    Updated: 2024/04/01 21:20:31 by mhervoch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex_bonus

CC = clang

CFLAGS = -Wall -Wextra -Werror -g

SRCS =	./utils_bonus/ft_memcpy.c \
		./utils_bonus/path.c \
		./utils_bonus/ft_memmove.c \
		./utils_bonus/ft_split.c \
		./utils_bonus/ft_strjoin.c \
		./utils_bonus/ft_strlcpy.c \
		./utils_bonus/ft_free_tab.c \
		./pipex_bonus.c \
		./utils_bonus/pipex_bonus_utils.c \

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
