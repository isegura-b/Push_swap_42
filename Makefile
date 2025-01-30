# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: isegura- <isegura-@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/18 14:30:56 by isegura-          #+#    #+#              #
#    Updated: 2025/01/14 16:37:26 by isegura-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc -g
CFLAGS = -Wall -Wextra -Werror -fsanitize=address

SRC_DIR = ./src
OBJ_DIR = ./obj

SRC = $(SRC_DIR)/lst_utils.c \
	  $(SRC_DIR)/main.c \
	  $(SRC_DIR)/parsing.c \
	  $(SRC_DIR)/print_stack.c \
	  $(SRC_DIR)/push.c \
	  $(SRC_DIR)/rev_rotate.c \
	  $(SRC_DIR)/rotate.c \
	  $(SRC_DIR)/small_sort.c \
	  $(SRC_DIR)/stacks.c \
	  $(SRC_DIR)/swap.c \
	  $(SRC_DIR)/algorithm_sort.c \
	  $(SRC_DIR)/cheapest.c \
	  $(SRC_DIR)/best_moves.c \
	  $(SRC_DIR)/clean.c \
	  $(SRC_DIR)/moves.c \

OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))

DEP = $(OBJ:.o=.d)

RM = rm -rf

all : $(NAME)

#%.o: %.c Makefile push_swap.h
		#$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(SRC_DIR)/push_swap.h Makefile
		mkdir -p $(OBJ_DIR)
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		$(RM) $(OBJ_DIR)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
