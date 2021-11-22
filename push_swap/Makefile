# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alsanche <alsanche@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/17 18:35:04 by alsanche          #+#    #+#              #
#    Updated: 2021/11/22 17:30:45 by alsanche         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC	= push_swap.c push_swap_solution.c push_error.c \
	push_swap_utils.c push_swap_utils2.c push_swap_utils3.c 

OBJS = $(SRC:.c=.o)

CC	= gcc

RM	= rm -f

OFLAG	= -fsanitize=address

CFLAGS	= -Wall -Wextra -Werror $(OFLAG) -g3

$(NAME): $(OBJS)
		make -sC libft
		$(CC) $(CFLAGS) $(OBJS) libft/libft.a

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

PHONY.: clean all fclean re