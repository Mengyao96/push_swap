# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mezhang <mezhang@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/30 12:57:47 by mezhang           #+#    #+#              #
#    Updated: 2025/08/08 17:20:59 by mezhang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
LIBFT = libft/libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -I./libft/ -I.

SRCS = main.c
		ft_input_atoi.c \
		ft_input_split.c \
		ft_input.c \
		ft_push.c \
		ft_reverse_rotate.c \
		ft_rotate.c \
		ft_sorting_small.c \
		ft_stack_utils.c \
		ft_swap.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
		$(MAKE) -C ./libft
		$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean :
	$(MAKE) clean -C ./libft
	rm -f $(OBJS)

fclean : clean
	$(MAKE) fclean -C ./libft
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
