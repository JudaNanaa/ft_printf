# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: madamou <madamou@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/04 19:12:30 by madamou           #+#    #+#              #
#    Updated: 2024/11/16 16:00:12 by madamou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra  -g3

SRCS = flags.c format.c ft_itoa_base.c ft_printf.c main.c ft_atoi_base.c

OBJS = $(SRCS:.c=.o)

LIBFT = libft.a

NAME = libftprintf.a

EXEC = a.out

all : $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS) libft/*.o
	$(CC) $(CFLAGS) $(OBJS) -L libft/ -lft -o $(EXEC)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT) :
	make -C libft/
	
bonus : all
	
clean:
	rm -rf $(OBJS)
	make clean -C libft/
fclean: clean
	rm -f $(NAME)
	make fclean -C libft/
re: fclean all

.PHONY: all clean fclean re bonus