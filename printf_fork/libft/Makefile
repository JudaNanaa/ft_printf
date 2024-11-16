# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: madamou <madamou@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/23 16:07:55 by madamou           #+#    #+#              #
#    Updated: 2024/11/16 04:54:24 by madamou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
       ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
       ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putchar.c ft_putendl_fd.c \
       ft_putendl.c ft_putnbr_fd.c ft_putnbr.c ft_putstr_fd.c ft_putstr.c \
       ft_split.c ft_strchr.c ft_strclr.c ft_strcpy.c ft_strdup.c ft_striteri.c \
       ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c \
       ft_strncpy.c ft_strnew.c ft_strrchr.c ft_strstr.c ft_strtrim.c \
       ft_substr.c ft_tolower.c ft_toupper.c ft_strmapi.c ft_strnstr.c \
       ft_strcmp.c ft_strcat.c ft_realloc.c get_next_line_bonus.c get_next_line_utils_bonus.c

OBJS = $(SRCS:.c=.o)

SRCS_BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstlast_bonus.c ft_lstsize_bonus.c \
              ft_lstadd_back_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c \
              ft_lstclear_bonus.c ft_lstdelone_bonus.c

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

NAME = libft.a

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -c -include ./libft.h $< -o $@

bonus: all $(OBJS_BONUS)
	ar rc $(NAME) $(OBJS_BONUS)

%.o : %.c
	$(CC) $(CFLAGS) -c -include ./libft.h $< -o $@

so:
	$(CC) -fPIC $(CFLAGS) $(SRCS)
	gcc -shared -o libft.so $(OBJS)

clean:
	rm -rf $(OBJS) $(OBJS_BONUS)
                                                                             
fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus test so
