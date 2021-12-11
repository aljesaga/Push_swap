# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alsanche <alsanche@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/17 18:35:04 by alsanche          #+#    #+#              #
#    Updated: 2021/12/11 16:28:11 by alsanche         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC	= push_swap.c push_swap_solution.c push_error.c \
	push_swap_utils.c push_swap_utils2.c push_swap_utils3.c \
	push_swap_solution_100_500.c selec_nbr.c

OBJS = $(SRC:.c=.o)

CC	= gcc

RM	= rm -f

OFLAG	= -fsanitize=address

CFLAGS	= -Wall -Wextra -Werror $(OFLAG) -g3

$(NAME): $(OBJS)
		make -sC libft
		$(CC) -o $@ $(CFLAGS) $(OBJS) libft/libft.a

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	@rm -f $(OBJS)

cleanlibft:
	@Make fclean -sC libft
	
fclean: clean cleanlibft
	@rm -f $(NAME)


re: fclean all

PHONY.: clean cleanlibtf all fclean re