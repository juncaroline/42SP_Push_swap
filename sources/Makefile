# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cabo-ram <cabo-ram@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/02 09:23:15 by cabo-ram          #+#    #+#              #
#    Updated: 2025/01/07 16:03:45 by cabo-ram         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = main.c utils.c operations.c sort.c \

OBJS = $(SRC:.c=.o)
HEADER = ../includes
LIBFT = ../libraries/libft

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I$(HEADER)/includes -g3

RM = rm -rf

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBFT) -lft

clean:
	@$(RM) $(OBJS)
	@make -C $(LIBFT) clean

fclean: clean
	@$(RM) $(NAME)
	@make -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re