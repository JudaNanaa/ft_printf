# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibaby <ibaby@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/17 12:57:50 by madamou           #+#    #+#              #
#    Updated: 2024/10/10 05:07:1 by ibaby            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BLACK=	$(shell tput -Txterm setaf 0)
RED= 	$(shell tput -Txterm setaf 1)
GREEN= 	$(shell tput -Txterm setaf 2)
WHITE= 	$(shell tput -Txterm setaf 7)
YELLOW=	$(shell tput -Txterm setaf 3)
BLUE=	$(shell tput -Txterm setaf 6)
PURPLE=	$(shell tput -Txterm setaf 5)
END= 	$(shell tput -Txterm sgr0)

CC = cc

C_FLAGS = -Wall -Wextra -Werror -g3

SRCS_DIR = .

OBJS_DIR = .objets/

SRCS = main.c flags.c format.c ft_itoa_base.c ft_printf.c ft_atoi_base.c

SRCS := $(SRCS:%=$(SRCS_DIR)/%)

OBJS = $(SRCS:$(SRCS_DIR)%.c=$(OBJS_DIR)%.o)

DIR_DUP = mkdir -p $(@D)

G				= $(BLUE)
X 				= $(END)
BAR_SIZE		= 50

TOTAL_FILES		:= $(words $(SRCS))
COMPILED_FILES	:= 0

LIBFT = libft.a

NAME = libftprintf.a

EXEC = a.out

all : $(LIBFT) $(NAME)

$(LIBFT) :
	@echo
	@echo "👷$(GREEN)compiling libft$(END)👷"
	@make -sC ./libft
	@echo
	@echo "👷$(GREEN)libft compilation done$(END)👷"

$(NAME) : message $(OBJS)
	@ar rc $(NAME) $(OBJS) libft/*.o
	@$(CC) $(CFLAGS) $(OBJS) -L libft/ -lft -o $(EXEC)
	@echo
	@echo "💻$(BLUE)executable created >_$(END)✅"
	@echo

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
	@$(DIR_DUP)
	@$(CC) $(C_FLAGS) -c $< -o $@
	@$(eval COMPILED_FILES := $(shell echo $$(($(COMPILED_FILES)+1))))
	@echo -n ""
	@for i in `seq 1 $(shell echo "$$(($(COMPILED_FILES)*$(BAR_SIZE)/$(TOTAL_FILES)))")`; do \
		echo -n "$(G)▰$(X)" ; \
	done
	@for i in `seq 1 $(shell echo "$$(($(BAR_SIZE)-$(COMPILED_FILES)*$(BAR_SIZE)/$(TOTAL_FILES)))")`; do \
		echo -n "▱" ; \
	done
	@echo -n " [$(shell echo "scale=2; $(COMPILED_FILES)/$(TOTAL_FILES) * 100" | bc)%] "
# @echo -n ""
# @printf "%d/%d" $(COMPILED_FILES) $(TOTAL_FILES)
# @echo -n " "
# @printf "%s" $(notdir $<)
	@printf "\e[0K\r"

bonus : all

message :
	@echo
	@echo "$(BLUE)🔩compiling printf🔩$(END)"

clean : 
	@rm -rf $(OBJS_DIR)
	@make clean -sC ./libft
	@echo "🧼🧼$(PURPLE)objects cleaned$(END)🧼🧼"

fclean : clean
	@rm -rf $(NAME)
	@rm -rf $(EXEC)
	@make fclean -sC ./libft
	@echo "🧼🧼$(PURPLE)executable cleaned$(END)🧼🧼"

re : fclean all

.PHONY : all clean fclean re bonus
